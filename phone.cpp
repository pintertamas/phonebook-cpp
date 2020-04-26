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

std::ostream &Private::toString(std::ostream &os) {
    // 19990330 -> 1999.03.30.
    int year = getBirthday() / 10000;
    int month = (getBirthday() - 10000 * year) / 100;
    int day = getBirthday() - 10000 * year - 100 * month;
    return os << getNickname() << " - number: +36" << getNumber() << ", address: " << getAddress() << ", birthday: "
              << year << "." << month << "." << day << "." << ", email: " << getEmail() << std::endl;
}