//
// Created by Tomi on 17/04/2020.
//

#include "phone.hpp"
#include "memtrace.h"

/**
 * @file phone.cpp
 * @brief Phone class fügvényei
 */

std::ostream &Work::toString(std::ostream &os) {
    return os << getName() << ", " << getCompany() << " - number: +36" << getNumber() << ", website: " << getWebsite()
              << ", email: " << getEmail() << std::endl;
}

void Work::writeToFile(std::ostream &os) {
    os << getName() << "\n" << getCompany() << "\n" << getNumber() << "\n" << getWebsite() << "\n" << getEmail() << std::endl;
}

void Work::readFromFile(std::ifstream &os) {
    os >> this->number;
    os.ignore(1, '\n');
    os >> this->name;
    os.ignore(1, '\n');
    os >> this->email;
    os.ignore(1, '\n');
    os >> this->company;
    os.ignore(1, '\n');
    os >> this->website;
    os.ignore(1, '\n');
}

std::ostream &Private::toString(std::ostream &os) {
    // 19990330 -> 1999.03.30.
    int year = getBirthday() / 10000;
    int month = (getBirthday() - 10000 * year) / 100;
    int day = getBirthday() - 10000 * year - 100 * month;
    return os << getName() << ", " << getNickname() << " - number: +36" << getNumber() << ", address: " << getAddress()
              << ", birthday: "
              << year << "." << month << "." << day << "." << ", email: " << getEmail() << std::endl;
}

void Private::writeToFile(std::ostream &os) {
    os << getName() << "\n" << getNickname() << "\n" << getNumber() << "\n" << getAddress() << "\n" << getBirthday() << "\n"
       << getEmail() << std::endl;
}

void Private::readFromFile(std::ifstream &os) {
    os >> this->name;
    os.ignore(1, '\n');
    os >> this->nickname;
    os.ignore(1, '\n');
    os >> this->number;
    os.ignore(1, '\n');
    os >> this->address;
    os.ignore(1, '\n');
    os >> this->birthday;
    os.ignore(1, '\n');
    os >> this->email;
}