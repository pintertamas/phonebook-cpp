//
// Created by Tomi on 17/04/2020.
//

#include <iostream>

#include "menu.hpp"

void Menu::run() {
    showMenu();
}

void Menu::showMenu() {
    std::cout << "Choose from these options:" << std::endl;
    std::cout << "1. List All" << std::endl;
    std::cout << "2. Search by name" << std::endl;
    std::cout << "3. Search by number" << std::endl;
    std::cout << "4. Add contact" << std::endl;
    std::cout << "5. Remove contact" << std::endl;
    std::cout << "6. EXIT" << std::endl;
}