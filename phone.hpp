//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_PHONE_HPP
#define MY_AWESOME_PHONEBOOK_PHONE_HPP

#include <iostream>

#include "contact.hpp"

/**
 * @file phone.hpp
 * @brief Phone class fügvényei
 */
/**
 * @brief Work class létrehozása
 */
class Work : public Contact {
    std::string company;
    std::string website;
public:
    /**
     * @brief Work CTOR
     * A megadott adatokkal létrehoz egy work kontaktot
     */
    explicit Work(const std::string &number = "unknown", const std::string &name = "unknown",
                  const std::string &email = "unknown",
                  const std::string &company = "unknown",
                  const std::string &website = "unknown") : Contact(number, name, email), company(company),
                                                            website(website) {}

    /**
     * @brief Company getter
     * @return company
     */
    std::string getCompany() const { return company; }

    /**
     * @brief Website getter
     * @return website
     */
    std::string getWebsite() const { return website; }

    /**
     * @brief Kiírja a megadott kimenetre a work adatait formázva
     * @return work adattagjai formázva
     */
    std::ostream &toString(std::ostream &) override;
};

/**
 * @brief Private class létrehozása
 */
class Private : public Contact {
    std::string address;
    std::string nickname;
    int birthday;
public:
    /**
     * @brief Private CTOR
     * A megadott paraméterekkel létrehoöz egy private kontaktot
     */
    explicit Private(const std::string &number = "unknown", const std::string &name = "unknown",
                     std::string nickname = "unknown", const std::string &email = "unknown",
                     std::string address = "unknown",
                     int birthday = 18900101) : Contact(number, name, email), address(std::move(address)), nickname(std::move(nickname)),
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
    std::string getNickname() const { return nickname; };

    /**
     * @brief Addressg getter
     * @return address
     */
    std::string getAddress() const { return address; }

    /**
    * @brief Kiírja a megadott kimenetre a private adatait formázva
    * @return private adattagjai formázva
    */
    std::ostream &toString(std::ostream &) override;
};

#endif //MY_AWESOME_PHONEBOOK_PHONE_HPP
