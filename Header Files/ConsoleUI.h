#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "../Header Files/AccessControlSystem.h"
#include <iostream>
#include <string>

class ConsoleUI {
private:
AccessControlSystem& system;
User* current_user;

std::string getStringInput(const std::string& prompt) const;

public:

void displayMainMenu();
void displayLoginScreen();
void displayAdminMenu();
void displayUserMenu();
void displayAllGuests();
void displayDoors();
void handleUserManagement();
};



#endif