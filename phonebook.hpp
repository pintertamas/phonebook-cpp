//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_PHONEBOOK_HPP
#define MY_AWESOME_PHONEBOOK_PHONEBOOK_HPP

#include "contact.hpp"
#include "phone.hpp"
#include "string5.h"
#include "vector.hpp"

/**
 * @file phonebook.hpp
 * @brief Phonebook class
 */

class Phonebook{
    Vector<Work*> workContacts;
    Vector<Private*> privateContacts;
public:
    Phonebook() : workContacts(0), privateContacts(0) {};
    Contact* searchByName(String);
    Contact* searchByNumber(String);
    Work* getWorkContacts(size_t index) const {
        return workContacts[index];
    }
    Private* getPrivateContacts(size_t index) const {
        return privateContacts[index];
    }
    void listContacts(std::ostream&);
    void addContact(Work* const&);
    void addContact(Private* const&);
    void removeContact(String);
    void loadFromFile();
    void saveContactsToDB(std::ostream&, Work*);
    void saveContactsToDB(std::ostream&, Private*);
    void saveToFile();
    ~Phonebook() {
        for (size_t i = 0; i < workContacts.getSize(); ++i) {
            delete workContacts[i];
        }
        for (size_t i = 0; i < privateContacts.getSize(); ++i) {
            delete privateContacts[i];
        }
    }
};

#endif //MY_AWESOME_PHONEBOOK_PHONEBOOK_HPP
