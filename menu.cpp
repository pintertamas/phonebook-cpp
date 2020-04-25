//
// Created by Tomi on 17/04/2020.
//

#include <iostream>

#include "menu.hpp"
#include "memtrace.h"

void Menu::run() {
    bool isRunning = true;
    int chosenItem = 0;

    showMenu();
    while(isRunning) {
        std::cout << "*Choose one!*\n";
        std::cin>>chosenItem;
        runItem(chosenItem, &isRunning);
    }
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

void Menu::runItem(int index, bool *isRunning) {
    switch(index) {
        case 1:
            listAll();
            break;
        case 2:
            searchByName();
            break;
        case 3:
            searchByNumber();
            break;
        case 4:
            addContact();
            break;
        case 5:
            removeContact();
            break;
        case 6:
            *isRunning = false;
            std::cout << "*Exiting the program*\n";
            break;
        default:
            std::cout << "*returning to the menu*\n";
            showMenu();
            break;
    }
}

void Menu::listAll() {
    std::cout << "listAll\n";
}

void Menu::searchByName() {
    std::cout << "searchByName\n";
}

void Menu::searchByNumber() {
    std::cout << "searchByNumber\n";
}

void Menu::addContact() {
    std::cout << "addContact\n";
}

void Menu::removeContact() {
    std::cout << "removeContact\n";
}