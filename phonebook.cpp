//
// Created by Tomi on 17/04/2020.
//

#include "phonebook.hpp"

#include "memtrace.h"

void Phonebook::listContacts(std::ostream &os) {
    os << "*Work Contacts*" << std::endl;
    if (workContacts.getSize() != 0) {
        for (size_t i = 0; i < workContacts.getSize(); ++i) {
            getWorkContacts(i)->toString(os);
        }
    } else {
        os << "*There are no work contacts*" << std::endl;
    }
    os << std::endl;
    os << "*Private Contacts*" << std::endl;
    if (privateContacts.getSize() != 0) {
        for (size_t i = 0; i < privateContacts.getSize(); ++i) {
            getPrivateContacts(i)->toString(os);
        }
    } else {
        os << "*There are no private contacts*" << std::endl;
    }
}

void Phonebook::addContact(Work *const &newContact) {
    workContacts.push_back(newContact);
}

void Phonebook::addContact(Private *const &newContact) {
    privateContacts.push_back(newContact);
}