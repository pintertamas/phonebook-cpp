//
// Created by Tomi on 17/04/2020.
//

#include "phone.hpp"

#include "memtrace.h"

std::ostream &Work::toString(std::ostream &os) {
    return os << getCompany() << " - number: " <<getNumber() << ", website: " << getWebsite();
}

std::ostream &Private::toString(std::ostream &os) {
    // 19990330 -> 1999.03.30.
    int year = getBirthday() / 10000;
    int month = (getBirthday() - 10000 * year) / 100;
    int day = getBirthday() - 10000 * year - 100 * month;
    return os << getNickname() << " - number: " << getNumber() << ", address: " << getAddress() << ", birthday: " << year << "." << month << "." << day << "." << std::endl;
}