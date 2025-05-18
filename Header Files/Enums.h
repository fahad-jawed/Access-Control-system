#ifndef ENUMS.H
#define ENUMS.H

enum class SecurityLevel
{
    MAINTENANCE = 0,
    LOW,
    MEDIUM,
    HIGH,
    CRITICAL
};

enum class ROLEID {
    MAINTENANCE = 0,
    REGULAR,
    GUEST,
    ADMIN
};

#endif
