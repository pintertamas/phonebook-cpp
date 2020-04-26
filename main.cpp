#include <iostream>

#include "menu.hpp"

/**
 * @file mail.cpp
 */

int main() {
    Phonebook phonebook;
    phonebook.loadFromFile();
    Menu *menu = new Menu(phonebook);

    /*
     * String txt = String("234");
    if(!isdigit(atoi(txt.c_str())))
        std::cout << atoi(txt.c_str())-1;
    */

    menu->run(phonebook);
    return 0;
}