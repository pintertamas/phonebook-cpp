//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_PHONE_HPP
#define MY_AWESOME_PHONEBOOK_PHONE_HPP

#include <iostream>

#include "contact.hpp"
#include "string5.h"

/**
 * @file phone.hpp
 * @brief Phone class fügvényei
 */
/**
 * @brief Work class létrehozása
 */
class Work : public Contact {
    String company;
    String website;
public:
    /**
     * @brief Work CTOR
     * A megadott adatokkal létrehoz egy work kontaktot
     */
    explicit Work(const String &number = "unknown", const String &name = "unknown", const String &email = "unknown",
                  const String &company = "unknown",
                  const String &website = "unknown") : Contact(number, name, email), company(company),
                                                       website(website) {}

    /**
     * @brief Company getter
     * @return company
     */
    String getCompany() const { return company; }

    /**
     * @brief Website getter
     * @return website
     */
    String getWebsite() const { return website; }

    /**
     * @brief Kiírja a megadott kimenetre a work adatait formázva
     * @return work adattagjai formázva
     */
    std::ostream &toString(std::ostream &) override;

    ~Work() override = default;
};

/**
 * @brief Private class létrehozása
 */
class Private : public Contact {
    String address;
    String nickname;
    int birthday;
public:
    /**
     * @brief Private CTOR
     * A megadott paraméterekkel létrehoöz egy private kontaktot
     */
    explicit Private(const String &number = "unknown", const String &name = "unknown",
                     const String &nickname = "unknown", const String &email = "unknown",
                     const String &address = "unknown",
                     int birthday = 18900101) : Contact(number, name, email), address(address), nickname(nickname),
                                                birthday(birthday) {}

    /**
     * @brief Birthday getter
     * @return birthday
     */
    int getBirthday() const { return birthday; }

    /**
     * @brief Nickname getter
     * @return nickname
     */
    String getNickname() const { return nickname; };

    /**
     * @brief Addressg getter
     * @return address
     */
    String getAddress() const { return address; }

    /**
    * @brief Kiírja a megadott kimenetre a private adatait formázva
    * @return private adattagjai formázva
    */
    std::ostream &toString(std::ostream &) override;

    ~Private() override = default;
};

#endif //MY_AWESOME_PHONEBOOK_PHONE_HPP
