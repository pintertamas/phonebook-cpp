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
    Work(String &number, String &name, String &email, String &company,
         String &website) : Contact(number, name, email), company(company), website(website) {}

    String getCompany() { return company; }

    String getWebsite() { return website; }

    std::ostream &toString(std::ostream&) override;
};

class Private : public Contact {
    String address;
    const String nickname;
    int birthday;
public:
    Private(String &number, String &name, String &nickname, String &email, String &address,
            int birthday) : Contact(number, name, email), address(address), nickname(nickname), birthday(birthday) {}

    int getBirthday() const { return birthday; }

    String getNickname() const { return nickname; };

    String getAddress() const { return address; }

    std::ostream &toString(std::ostream&) override;
};

#endif //MY_AWESOME_PHONEBOOK_PHONE_HPP
