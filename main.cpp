#include <iostream>
#include "gtest_lite.h"
#include "memtrace.h"

#include "menu.hpp"
#include "phonebook.hpp"
#include "contact.hpp"
#include "phone.hpp"
#include "test.hpp"

/**
 * @file mail.cpp
 * \mainpage A program leírása:
 * A program egy telefonkönyvként funkcionál.
 * Két féle kontaktot lehet benne tárolni, munkahelyi számokat, és otthoni számokat.
 * Hozzá lehet adni kontaktokat, és kitörölni, lehet listázni ezeket,
 * aztán az adatokat lementeni egy fájlba, ahonnan ezek később visszatölthetőek lesznek.
 * Keresni is lehet név vagy telefonszám szerint.
 * Pintér Tamás - JY4D5L
 */

int main() {
#ifndef CPORTA
    system("cls");
#endif          //CPORTA
    GTINIT(std::cin);

    test_1();
    test_2();

    Phonebook phonebook;
    if (!Phonebook::isFileEmpty("../database.txt"))
        phonebook.loadFromFile();
    Menu *menu = new Menu(phonebook);

    menu->run();
    return 0;
}