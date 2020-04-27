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

/**
 * @brief Menu class létrehozása
 */
class Menu{
    Phonebook& phonebook;
    void listAll();
    void searchByName();
    void searchByNumber();
    void addContact();
    void removeContact();
public:
    /**
     * @brief Menu CTOR
     * Létrehoz egy Menüt egy telefonkönyvvel
     * @param phonebook ezt kapja meg telefonkönyvnek
     */
    explicit Menu(Phonebook& phonebook) :phonebook(phonebook) {}
    /**
     * @brief Futtatja a menüt
     */
    void run();
    /**
     * @brief Kiírja a menüt a felhasználónak
     */
    static void showMenu();
    /**
     * @brief Futtat egy menüpontot
     * @param index ezzel a sorszámmal
     * @param isRunning megkapja, hogy a programnak kell-e még futnia
     */
    void runItem(int index, bool* isRunning);
};

#endif //MY_AWESOME_PHONEBOOK_MENU_HPP
