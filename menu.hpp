//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_MENU_HPP
#define MY_AWESOME_PHONEBOOK_MENU_HPP

#include "phonebook.hpp"

/**
 * @file menu.hpp
 * @brief Menu class
 */

class Menu{
    Phonebook& phonebook;
    void listAll();
    void searchByName();
    void searchByNumber();
    void addContact();
    void removeContact();
public:
    Menu(Phonebook& phonebook) :phonebook(phonebook) {}
    void run();
    static void showMenu();
    void runItem(int, bool*);
};

#endif //MY_AWESOME_PHONEBOOK_MENU_HPP
