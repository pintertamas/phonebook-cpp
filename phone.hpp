//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_PHONE_HPP
#define MY_AWESOME_PHONEBOOK_PHONE_HPP

#include <iostream>

#include "contact.hpp"
#include "string5.h"

class Work : public Contact {
    String company;
    String website;
public:
    Work(const String &number = "unknown", const String &name = "unknown", const String &email = "unknown", const String &company = "unknown",
         const String &website = "unknown") : Contact(number, name, email), company(company), website(website) {}

    String getCompany() { return company; }

    String getWebsite() { return website; }

    std::ostream &toString(std::ostream&) override;
};

class Private : public Contact {
    String address;
    String nickname;
    int birthday;
public:
    Private(const String &number = "unknown", const String &name = "unknown", const String &nickname = "unknown", const String &email = "unknown", const String &address = "unknown",
            int birthday = 0) : Contact(number, name, email), address(address), nickname(nickname), birthday(birthday) {}

    int getBirthday() const { return birthday; }

    String getNickname() const { return nickname; };

    String getAddress() const { return address; }

    std::ostream &toString(std::ostream&) override;
};

#endif //MY_AWESOME_PHONEBOOK_PHONE_HPP
