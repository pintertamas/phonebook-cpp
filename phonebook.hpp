//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_PHONEBOOK_HPP
#define MY_AWESOME_PHONEBOOK_PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook{
    Contact *contacts;
public:
    Contact* searchByName(char*);
    Contact* searchByNumber(char*);
    void addContact(Contact);
    void removeContact(char*);
};

#endif //MY_AWESOME_PHONEBOOK_PHONEBOOK_HPP
