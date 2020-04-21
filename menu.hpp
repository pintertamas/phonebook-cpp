//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_MENU_HPP
#define MY_AWESOME_PHONEBOOK_MENU_HPP

#include "phonebook.hpp"

class Menu{
    void listAll();
    void searchByName();
    void searchByNumber();
    void addContact();
    void removeContact();

public:
    Phonebook phonebook();
    static void run();
    static void showMenu();
    void runItem(int);

    static void loadFromFile();
    static void saveToFile();
};


#endif //MY_AWESOME_PHONEBOOK_MENU_HPP
