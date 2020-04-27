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
    os << "*Work Contacts*" << std::endl;
    if (workContacts.getSize() != 0) {
        for (size_t i = 0; i < workContacts.getSize(); ++i) {
            os << i + 1 << ". ";
            getWorkContacts(i)->toString(os);
        }
    } else {
        os << "*There are no work contacts*" << std::endl;
    }
    os << std::endl;
    os << "*Private Contacts*" << std::endl;
    if (privateContacts.getSize() != 0) {
        for (size_t i = 0; i < privateContacts.getSize(); ++i) {
            os << i + 1 << ". ";
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
    std::ifstream file("../database.txt", std::ios::in);

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
         << priv->getAddress() << std::endl << priv->getEmail() << std::endl << priv->getBirthday() << std::endl;
}

void Phonebook::saveToFile() {
    std::ofstream file("../database.txt", std::ios::out);

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

void Phonebook::removeContact() {
    std::cout << "*Remove contact*" << std::endl;
    std::cout << "Do you want to remove a work contact or a private contact?" << std::endl;
    std::cout << "1. Work\n2. Private\n3. EXIT" << std::endl;
    char choice = 0;
    while (toascii(choice) < '1' || toascii(choice) > '3') {
        std::cin >> choice;
        if (toascii(choice) < '1' || toascii(choice) > '3')
            std::cout << "Choose again!" << std::endl;
        if (toascii(choice) == '3')
            break;
        if (toascii(choice) == '1' && workContacts.getSize() > 0) {
            listContactType(convertToContact(workContacts), std::cout);
            std::cout << "Choose an item with its index that you want to remove!" << std::endl;
            String indexChoice;
            std::cin >> indexChoice;
            if (atoi(indexChoice.c_str()) <= workContacts.getSize() && atoi(indexChoice.c_str()) != 0) {
                std::cout << atoi(indexChoice.c_str()) << std::endl;
                std::cout << getWorkContacts(atoi(indexChoice.c_str())) << std::endl;
                std::cout << "This contact was successfully deleted:\n";
                getWorkContacts(atoi(indexChoice.c_str()) - 1)->toString(std::cout) << std::endl;
                workContacts.deleteItem(atoi(indexChoice.c_str()) - 1);
                this->saveToFile();
            } else std::cout << "Couldn't find contact with this index" << std::endl;
        }
        if (toascii(choice) == '2' && privateContacts.getSize() > 0) {
            listContactType(convertToContact(privateContacts), std::cout);
            std::cout << "Choose an item with its index that you want to remove!" << std::endl;
            String indexChoice;
            std::cin >> indexChoice;
            if (atoi(indexChoice.c_str()) <= privateContacts.getSize() && atoi(indexChoice.c_str()) != 0) {
                std::cout << atoi(indexChoice.c_str()) << std::endl;
                std::cout << "This contact was successfully deleted:\n";
                getPrivateContacts(atoi(indexChoice.c_str()) - 1)->toString(std::cout) << std::endl;
                privateContacts.deleteItem(atoi(indexChoice.c_str()) - 1);
                this->saveToFile();
            } else std::cout << "Couldn't find contact with this index" << std::endl;
        }
    }
}

bool equalFromHere(String const &str, String const &pattern) {
    for (size_t i = 0; i < pattern.size(); ++i) {
        if (tolower(str[i+1]) != tolower(pattern[i]))
            return false;
    }
    return true;
}

bool containsName(const Contact *contact, const String &pattern) {
    for (size_t i = 0; i < contact->getName().size(); ++i) {
        if (i + pattern.size() < contact->getName().size()) {
            if (equalFromHere(String(contact->getName().c_str() + i), pattern)) {
                return true;
            }
        }
    }
    return false;
}

bool containsNumber(const Contact *contact, const String &pattern) {
    for (size_t i = 0; i < contact->getNumber().size(); ++i) {
        if (i + pattern.size() < contact->getNumber().size()) {
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

Vector<Contact *> Phonebook::convertToContact(Vector<Work *> const &work) {
    Vector<Contact *> allContacts;
    for (size_t i = 0; i < work.getSize(); ++i) {
        allContacts.push_back(work[i]);
    }
    return allContacts;
}

Vector<Contact *> Phonebook::convertToContact(Vector<Private *> const &priv) {
    Vector<Contact *> allContacts;
    for (size_t i = 0; i < priv.getSize(); ++i) {
        allContacts.push_back(priv[i]);
    }
    return allContacts;
}

Vector<Contact *> Phonebook::searchByName(String &name) {
    Vector<Contact *> allContacts;
    for (size_t i = 0; i < workContacts.getSize(); ++i) {
        allContacts.push_back(workContacts[i]);
    }
    for (size_t i = 0; i < privateContacts.getSize(); ++i) {
        allContacts.push_back(privateContacts[i]);
    }

    return searchContactsFor(allContacts, containsName, name);
}

Vector<Contact *> Phonebook::searchByNumber(String &name) {
    Vector<Contact *> allContacts;
    for (size_t i = 0; i < workContacts.getSize(); ++i) {
        allContacts.push_back(workContacts[i]);
    }
    for (size_t i = 0; i < privateContacts.getSize(); ++i) {
        allContacts.push_back(privateContacts[i]);
    }

    return searchContactsFor(allContacts, containsNumber, name);
}