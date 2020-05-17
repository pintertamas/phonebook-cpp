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

void Phonebook::listContactType(const Vector<Contact *> &contacts, std::ostream &os) {
    for (size_t i = 0; i < contacts.getSize(); ++i) {
        os << i + 1 << ". ";
        contacts[i]->toString(os);
    }
}

void Phonebook::listContacts(std::ostream &os) {
    int counter = 0;
    os << "*Work contacts*" << std::endl;
    for (size_t i = 0; i < contacts.getSize(); ++i) {
        if (contacts[i]->getContactId() == Work::getId()) {
            contacts[i]->toString(os);
            counter++;
        }
    }
    if (counter == 0)
        os << "*There are no work contacts*" << std::endl;

    counter = 0;
    os << "*Private contacts*" << std::endl;
    for (size_t i = 0; i < contacts.getSize(); ++i) {
        if (contacts[i]->getContactId() == Private::getId()) {
            contacts[i]->toString(os);
            counter++;
        }
    }
    if (counter == 0)
        os << "*There are no private contacts*" << std::endl;
}

void Phonebook::addContact(Contact *const &newContact) {
    contacts.push_back(newContact);
}

bool Phonebook::isFileEmpty(const char *filename) {
    std::ifstream file(filename, std::ios::in);

    // Read a character, test for end-of-file
    bool empty = (file.get(), file.eof());
    return empty;
}

void Phonebook::loadFromFile() {
    const char *filename = "database.txt";
    std::ifstream file(filename, std::ios::in);
    if (!file) {
        std::cerr << filename << " failed to open\n";
    } else {
        int id;
        while (file >> id) {
            Contact *contact;
            if (id == Work::getId()) {
                contact = new Work();
                contact->readFromFile(file);
                this->addContact(contact);
            } else if (id == Private::getId()) {
                contact = new Private();
                contact->readFromFile(file);
                this->addContact(contact);
            }
        }
        file.close();
    }
}

void Phonebook::saveToFile() {
    const char *filename = "database.txt";
    std::ofstream file(filename, std::ios::out);

    for (size_t i = 0; i < contacts.getSize(); ++i) {
        file << contacts[i]->getContactId() << std::endl;
        contacts[i]->writeToFile(file);
    }
    file.close();
}

void Phonebook::removeContact() {
    std::cout << "*Remove contact*" << std::endl;
    if (contacts.getSize() <= 0) {
        std::cout << "There are no contacts! Add contacts before you want to delete them!" << std::endl;
    } else {
        for (size_t i = 0; i < contacts.getSize(); ++i) {
            std::cout << i + 1 << ": ";
            contacts[i]->toString(std::cout);
        }
        std::cout << "Choose a contact that you want to remove by its ID!" << std::endl;
        int choice = 0;
        std::cin >> choice;
        if (contacts.getSize() < (unsigned) choice || choice <= 0) {
            std::cout << "There are no contacts matching this ID" << std::endl;
        } else {
            contacts.deleteItem(choice - 1);
        }
    }
}

bool equalFromHere(String const &str, String const &pattern) {
    for (size_t i = 0; i < pattern.size(); ++i) {
        if (tolower(str[i]) != tolower(pattern[i]))
            return false;
    }
    return true;
}

bool containsName(const Contact *contact, const String &pattern) {
    for (size_t i = 0; i < contact->getName().size(); ++i) {
        if (i + pattern.size() <= contact->getName().size()) {
            if (equalFromHere(String(contact->getName().c_str() + i), pattern)) {
                return true;
            }
        }
    }
    return false;
}

bool containsNumber(const Contact *contact, const String &pattern) {
    for (size_t i = 0; i < contact->getNumber().size(); ++i) {
        if (i + pattern.size() <= contact->getNumber().size()) {
            if (equalFromHere(String(contact->getNumber().c_str() + i), pattern)) {
                return true;
            }
        }
    }
    return false;
}

Vector<Contact *>
Phonebook::searchContactsFor(const Vector<Contact *> &contacts, bool (*searchCommand)(const Contact *, const String &),
                             const String &pattern) {
    Vector<Contact *> result;
    for (size_t i = 0; i < contacts.getSize(); ++i) {
        if (searchCommand(contacts[i], pattern)) {
            result.push_back(contacts[i]);
        }
    }
    return result;
}

Vector<Contact *> Phonebook::searchByName(String &name) {
    Vector<Contact *> result;
    for (size_t i = 0; i < contacts.getSize(); ++i) {
        result.push_back(contacts[i]);
    }
    return searchContactsFor(result, containsName, name);
}

Vector<Contact *> Phonebook::searchByNumber(String &number) {
    Vector<Contact *> result;
    for (size_t i = 0; i < contacts.getSize(); ++i) {
        result.push_back(contacts[i]);
    }
    return searchContactsFor(result, containsNumber, number);
}