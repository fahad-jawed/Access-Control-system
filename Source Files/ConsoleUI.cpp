#include "../Header Files/ConsoleUI.h"

std::string ConsoleUI::getStringInput(const std::string& prompt) const {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);
        return input;
    }

void ConsoleUI::displayMainMenu() {
    int choice = 5;
    do {
    std::cout << "1. Login Screen\n";  
    std::cout << "0. Exit\n";  
    std::cout << "Choice: ";
    std::cin >> choice;

    switch (choice) {
        case 0:
        std::cout << "Program exited.." << std::endl;
        break;
        case 1:
        displayLoginScreen();
        break;
        default:
        std::cout << "Invalid input. Please choose a valid option." << std::endl;
    }
    } while (choice != 0);
}

void ConsoleUI::displayLoginScreen() {
std::cout << "\n--- Login ---\n";
        std::string userID = getStringInput("Enter User ID: ");
        std::string password = getStringInput("Enter Password: ");

        current_user = system.authenticateUser(userID, password);

        if (current_user) {
            std::cout << "\nLogin successful.\n";
        } else {
            std::cout << "\nLogin failed.";
            if (current_user->checkLockStatus()) {
                std::cout << "User ID: " << current_user->getUserID() << " has been locked out due to continous unsuccessful login attempts." << std::endl;
        }

        if (current_user->) {

        }

}



