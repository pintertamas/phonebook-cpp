//
// Created by Tomi on 17/04/2020.
//

#include <iostream>

#include "menu.hpp"
#include "memtrace.h"

/**
 * @file menu.cpp
 * @brief Menu class fügvényei
 */

void Menu::run() {
    bool isRunning = true;
    char chosenItem = 0;

    while (isRunning) {
        showMenu();
        std::cout << "*Choose one!*\n";
        std::cin >> chosenItem;
        if (toascii(chosenItem) > 48 && toascii(chosenItem) < 55)
            runItem(toascii(chosenItem), &isRunning);
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

void Menu::runItem(int index, bool *isRunning) {
    switch (index) {
        case 49:
            listAll();
            break;
        case 50:
            searchByName();
            break;
        case 51:
            searchByNumber();
            break;
        case 52:
            addContact();
            break;
        case 53:
            removeContact();
            break;
        case 54:
            *isRunning = false;
            std::cout << "*Exiting the program*\n";
            phonebook.saveToFile();
            break;
        default:
            std::cout << "*returning to the menu*\n";
            showMenu();
            break;
    }
}

void Menu::listAll() {
    phonebook.listContacts(std::cout);
}

void Menu::searchByName() {
    std::cout << "*Search for a contact with a name*" << std::endl;
    std::cout << "Type a name!" << std::endl;
    String name;
    std::cin >> name;
    Vector<Contact *> matchedContacts = phonebook.searchByName(name);
    std::cout << "*Results:*" << std::endl;
    if (matchedContacts.getSize() != 0)
        Phonebook::listContactType(matchedContacts, std::cout);
    else std::cout << "*No matching contact was found*" << std::endl;
}

void Menu::searchByNumber() {
    std::cout << "*Search for a contact with a number*" << std::endl;
    std::cout << "Type a number!" << std::endl;
    String number;
    std::cin >> number;
    Vector<Contact *> matchedContacts = phonebook.searchByNumber(number);
    std::cout << "*Results:*" << std::endl;
    if (matchedContacts.getSize() != 0)
        Phonebook::listContactType(matchedContacts, std::cout);
    else std::cout << "*No matching contact was found*" << std::endl;
}

void Menu::addContact() {
    std::cout << "*Choose from the following options: *" << std::endl;
    std::cout << "1. Add work contact" << std::endl;
    std::cout << "2. Add private contact" << std::endl;
    std::cout << "3. EXIT" << std::endl;
    char choice = 0;
    while (toascii(choice) < 49 || toascii(choice) > 51) {
        std::cin >> choice;
        if (toascii(choice) < 49 || toascii(choice) > 51)
            std::cout << "Choose again!" << std::endl;
        if (toascii(choice) == 51)
            break;
        if (choice == 49) {
            std::cout << "*Creating work contact...*" << std::endl;
            String number, name, company, email, website;
            std::cout << "number: +36";
            std::cin >> number;

            while (atoi(number.c_str()) < 200000000 || atoi(number.c_str()) > 709999999) {
                std::cout << "Wrong format, try again!" << std::endl;
                std::cout << "The phone number must contain only numbers, and the length should be 9 digits long)"
                          << std::endl;
                std::cout << "number: +36";
                std::cin >> number;
            }

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
            newWorkContact->toString(std::cout);
            phonebook.addContact(newWorkContact);
            phonebook.saveToFile();
        }

        if (choice == 50) {
            std::cout << "*Creating private contact...*" << std::endl;
            String number, name, nickname, birthday, email, address;

            std::cout << "number: +36";
            std::cin >> number;

            while (atoi(number.c_str()) < 200000000 || atoi(number.c_str()) > 709999999) {
                std::cout << "Wrong format, try again!" << std::endl;
                std::cout << "The phone number must contain only numbers, and the length should be 9 digits long)"
                          << std::endl;
                std::cout << "number: +36";
                std::cin >> number;
            }

            std::cout << "\nname: ";
            std::cin >> name;
            std::cout << "\nnickname: ";
            std::cin >> nickname;
            std::cout << "\nFormat:YYYYMMDD\nbirthday: ";
            std::cin >> birthday;

            while (atoi(birthday.c_str()) < 18900101 || atoi(birthday.c_str()) > 21000101) {
                std::cout << "Wrong format, try again!" << std::endl;
                std::cout << "The birthday must be between 1890.01.01 and 2100.01.01" << std::endl;
                std::cin >> birthday;
            }

            std::cout << "\nemail: ";
            std::cin >> email;
            std::cout << "\naddress: ";
            std::cin >> address;
            std::cout << std::endl;

            Private *newPrivateContact = new Private(number, name, nickname, email, address,
                                                     atoi(birthday.c_str()));
            newPrivateContact->toString(std::cout);
            phonebook.addContact(newPrivateContact);
            phonebook.saveToFile();
        }
    }
}

void Menu::removeContact() {
    phonebook.removeContact();
}