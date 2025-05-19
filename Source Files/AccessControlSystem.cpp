#include "../Header Files/AccessControlSystem.h"

AccessControlSystem &AccessControlSystem::getInstance()
{
    static AccessControlSystem instance;
    return instance;
}

Door *AccessControlSystem::findDoor(const std::string& door_id) const
{
    for (const auto &door : doors)
    {
        if (door->getDoorID() == door_id)
        {
            return door.get();
        }
    }
    return nullptr;
}
User *AccessControlSystem::findUser(const std::string& user_id) const
{
    for (const auto &user : users)
    {
        if (user->getUserID() == user_id)
        {
            return user.get();
        }
    }
    return nullptr;
}

bool AccessControlSystem::processAccessRequest(
    const User &authenticatedUser,
    const std::string &door_id)
{

    DateTime current_time = DateTime::getCurrentDateTime();
    if (!authenticatedUser.isAccountCurrentlyActive(current_time))
    {

        return false;
    }

    Door *door = findDoor(door_id);
    if (!door)
    {
        return false;
    }

    if (!door->checkBasicConditions(current_time.DateTimetoTime()))
    {
        return false;
    }
    std::set<std::shared_ptr<Role>> userRoles = authenticatedUser.getRoles();
    if (userRoles.empty())
    {
        return false;
    }

    bool accessGrantedByStrategy = false;
    for (const auto &role : userRoles)
    {
        if (role)
        {
            AccessStrategy *strategy = role->getAccessStrategy();
            if (strategy)
            {

                if (strategy->checkAccess(authenticatedUser, *door, current_time))
                {
                    accessGrantedByStrategy = true;
                    break;
                }
            }
        }
    }

    if (accessGrantedByStrategy)
    {
        door->setLockedStatus(false);
        return true;
    }
    else
    {
        return false;
    }
}

bool AccessControlSystem::addUser(
    ROLEID userType,
    const std::string &name,
    const std::string &password,
    const DateTime* expiry_date = nullptr)
{

    std::unique_ptr<User> new_user = nullptr;

    switch (userType)
    {
    case ROLEID::ADMIN:
        new_user = UserFactory::getInstance().createAdminUser(name, password);
        break;
    case ROLEID::REGULAR:
        new_user = UserFactory::getInstance().createRegularUser(name, password);
        break;
    case ROLEID::MAINTENANCE:
        new_user = UserFactory::getInstance().createMaintenanceUser(name, password);
        break;
    case ROLEID::GUEST:
        if (expiry_date == nullptr)
        {
            throw std::invalid_argument("Guest user can not be created without an expiry date");
        }
        new_user = UserFactory::getInstance().createGuestUser(name, password, *expiry_date);
        break;
    default:
        throw std::invalid_argument("Invalid user type specified for addUser.");
    }

    if (new_user)
    {
        this->users.push_back(std::move(new_user));
        return true;
    }
    return false;
}

bool AccessControlSystem::addDoor(
    const std::string &location,
    SecurityLevel security_level,
    const TimeRange &allowed_times)
{

    this->doors.push_back(std::make_unique<Door>(location, security_level, allowed_times));
    return true; // If make_unique fails, it throws std::bad_alloc
}

const std::vector<std::unique_ptr<User>>& AccessControlSystem::getAllUsers() const {
    return users;
}
const std::vector<std::unique_ptr<Door>>& AccessControlSystem::getAllDoors() const {
    return doors;
}

User* AccessControlSystem::authenticateUser(
    const std::string& userID,
    const std::string& password) {

    User* user = findUser(userID);

    if (!user) {
        return nullptr;
    }

    if (!user->authenticate(password)) {
        return nullptr;
    }

    DateTime currentTime = DateTime::getCurrentDateTime();
    if (!user->isAccountCurrentlyActive(currentTime)) {
        return nullptr;
    }

   return user;
}

bool AccessControlSystem::lockAccount(const std::string& user_id) {
    User* user = findUser(user_id);
    if (user) {
        user->lockAccount();
        return true;
    }
    return false;
}
bool AccessControlSystem::unlockAccount(const std::string& user_id) {
    User* user = findUser(user_id);
    if (user) {
        user->unlockAccount();
        return true;
    }
    return false;
}
bool AccessControlSystem::resetFailedLoginAttempts(const std::string& user_id) {
    User* user = findUser(user_id);
    if (user) {
        user->resetFailedLoginAttempts();
        return true;
    }
    return false;
}