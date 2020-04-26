//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_MENU_HPP
#define MY_AWESOME_PHONEBOOK_MENU_HPP

#include "phonebook.hpp"

class Menu{
    const Phonebook& phonebook;
    static void listAll(Phonebook&);
    void searchByName(Phonebook&);
    void searchByNumber(Phonebook&);
    void addContact(Phonebook&);
    void removeContact(Phonebook&);
public:
    Menu(Phonebook& phonebook) :phonebook(phonebook) {}
    void run(Phonebook&);
    static void showMenu();
    void runItem(int, bool*, Phonebook&);
};

#endif //MY_AWESOME_PHONEBOOK_MENU_HPP
