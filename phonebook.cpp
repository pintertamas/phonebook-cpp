//
// Created by Tomi on 17/04/2020.
//

#include "phonebook.hpp"
#include <fstream>
#include "memtrace.h"

/**
 * @file phonebook.cpp
 * @brief Phonebook class fügvényei
 */

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

void Phonebook::loadFromFile() {
    std::ifstream file("database.txt", std::ios::in);

    int num1, num2; // size of workContacts and privateContacts
    String number, name, email, company, website, address, nickname;
    int birthday;

    file >> num1;
    if (num1 != 0)
        for (int i = 0; i < num1; ++i) {
            file >> number;
            file.ignore(1, '\n');
            file >> name;
            file.ignore(1, '\n');
            file >> email;
            file.ignore(1, '\n');
            file >> company;
            file.ignore(1, '\n');
            file >> website;
            file.ignore(1, '\n');
            this->addContact(new Work(number, name, email, company, website));
        }
    file >> num2;
    if (num2 != 0)
        for (int i = 0; i < num2; ++i) {
            file >> number;
            file.ignore(1, '\n');
            file >> name;
            file.ignore(1, '\n');
            file >> email;
            file.ignore(1, '\n');
            file >> address;
            file.ignore(1, '\n');
            file >> nickname;
            file.ignore(1, '\n');
            file >> birthday;
            file.ignore(1, '\n');
            this->addContact(new Private(number, name, nickname, email, address, birthday));
        }
    file.close();
}

void Phonebook::saveContactsToDB(std::ostream &file, Work *work) {
    file << work->getNumber() << std::endl << work->getName() << std::endl << work->getEmail() << std::endl
         << work->getCompany() << std::endl << work->getWebsite() << std::endl;
}

void Phonebook::saveContactsToDB(std::ostream &file, Private *priv) {
    file << priv->getNumber() << std::endl << priv->getName() << std::endl << priv->getNickname() << std::endl
         << priv->getAddress() << std::endl << priv->getNickname() << std::endl << priv->getBirthday();
}

void Phonebook::saveToFile() {
    std::ofstream file("database.txt", std::ios::out);

    file << workContacts.getSize() << std::endl;
    for (size_t i = 0; i < workContacts.getSize(); ++i) {
        saveContactsToDB(file, workContacts[i]);
    }
    file << privateContacts.getSize() << std::endl;
    for (size_t i = 0; i < privateContacts.getSize(); ++i) {
        saveContactsToDB(file, privateContacts[i]);
    }
    file.close();
}