//
// Created by Tomi on 17/04/2020.
//

#include "phonebook.hpp"

#include "memtrace.h"

void Phonebook::listContacts(std::ostream &os) {
    os << "*Work Contacts*" << std::endl;
    for (size_t i = 0; i < workContacts.getSize(); ++i) {
        getWorkContacts(i)->toString(os);
        os << workContacts[i] << std::endl;
        //workContacts[i]->toString(os);
    }
    os << std::endl;
    os << "*Private Contacts*" << std::endl;
    for (size_t i = 0; i < privateContacts.getSize(); ++i) {
        getPrivateContacts(i)->toString(os);
        os << privateContacts[i] << std::endl;
        //privateContacts[i]->toString(os);
    }
}

void Phonebook::addContact(Work *const &newContact) {
    workContacts.push_back(newContact);
}

void Phonebook::addContact(Private *const &newContact) {
    privateContacts.push_back(newContact);
}