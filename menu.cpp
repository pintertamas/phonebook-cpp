//
// Created by Tomi on 17/04/2020.
//

#include <iostream>

#include "menu.hpp"
#include "memtrace.h"

void Menu::run(Phonebook &phonebook) {
    bool isRunning = true;
    char chosenItem = 0;

    while (isRunning) {
        showMenu();
        std::cout << "*Choose one!*\n";
        std::cin >> chosenItem;
        if(toascii(chosenItem) > 48 && toascii(chosenItem) < 55)
            runItem(toascii(chosenItem), &isRunning, phonebook);
        else
            std::cout << "*Choose again please*" << std::endl;
    }
}

void Menu::showMenu() {
    std::cout << std::endl;
    std::cout << "Choose from these options:" << std::endl;
    std::cout << "1. List All" << std::endl;
    std::cout << "2. Search by name" << std::endl;
    std::cout << "3. Search by number" << std::endl;
    std::cout << "4. Add contact" << std::endl;
    std::cout << "5. Remove contact" << std::endl;
    std::cout << "6. EXIT" << std::endl;
}

void Menu::runItem(int index, bool *isRunning, Phonebook &phonebook) {
    switch (index) {
        case 49:
            listAll(phonebook);
            break;
        case 50:
            searchByName(phonebook);
            break;
        case 51:
            searchByNumber(phonebook);
            break;
        case 52:
            addContact(phonebook);
            break;
        case 53:
            removeContact(phonebook);
            break;
        case 54:
            *isRunning = false;
            std::cout << "*Exiting the program*\n";
            break;
        default:
            std::cout << "*returning to the menu*\n";
            showMenu();
            break;
    }
}

void Menu::listAll(Phonebook &phonebook) {
    phonebook.listContacts(std::cout);
}

void Menu::searchByName(Phonebook &phonebook) {
    std::cout << "*DEBUG* searchByName\n";
}

void Menu::searchByNumber(Phonebook &phonebook) {
    std::cout << "*DEBUG* searchByNumber\n";
}

void Menu::addContact(Phonebook &phonebook) {
    std::cout << "*DEBUG* addContact\n";
    std::cout << "*Choose from the following options: *" << std::endl;
    std::cout << "1. Add work contact" << std::endl;
    std::cout << "2. Add private contact" << std::endl;
    std::cout << "3. EXIT" << std::endl;
    char choice; // majd ide kell rakni hogy =0, csak idegesít hogy szürke lesz tőle az editor
    while (toascii(choice) < 49 || choice > 51) {
        std::cin >> choice;
        if (toascii(choice) < 49 || choice > 51)
            std::cout << "Choose again!" << std::endl;
        if (choice == 51)
            break;
    }
    if (choice == 49) {
        std::cout << "*Creating work contact...*" << std::endl;
        String number, name, company, email, website;
        std::cout << "number: ";
        std::cin >> number;
        std::cout << "\nname: ";
        std::cin >> name;
        std::cout << "\ncompany: ";
        std::cin >> company;
        std::cout << "\nemail: ";
        std::cin >> email;
        std::cout << "\nwebsite: ";
        std::cin >> website;
        std::cout << std::endl;

        Work *newWorkContact = new Work(number, name, email, company, website);
        phonebook.addContact(newWorkContact);
    }

    if(choice == 50) {
        std::cout << "*Creating private contact...*" << std::endl;
        String number, name, nickname, email, address;
        int birthday;
        std::cout << "number: ";
        std::cin >> number;
        std::cout << "\nname: ";
        std::cin >> name;
        std::cout << "\nnickname: ";
        std::cin >> nickname;
        std::cout << "\nbirthday: ";
        std::cin >> birthday;
        std::cout << "\nemail: ";
        std::cin >> email;
        std::cout << "\naddress: ";
        std::cin >> address;
        std::cout << std::endl;

        Private *newPrivateContact = new Private(number, name, nickname, email, address, birthday);
        newPrivateContact->toString(std::cout);
        phonebook.addContact(newPrivateContact);
    }
}

void Menu::removeContact(Phonebook &phonebook) {
    std::cout << "*DEBUG* removeContact\n";
}