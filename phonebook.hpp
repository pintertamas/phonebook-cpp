//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_PHONEBOOK_HPP
#define MY_AWESOME_PHONEBOOK_PHONEBOOK_HPP

#include "contact.hpp"

using namespace std;

class Phonebook{
    Contact *contacts;
public:
    explicit Phonebook(Contact* contacts) : contacts(contacts) {};
    Contact* searchByName(string);
    Contact* searchByNumber(string);
    void addContact(Contact);
    void removeContact(string);
};

#endif //MY_AWESOME_PHONEBOOK_PHONEBOOK_HPP
