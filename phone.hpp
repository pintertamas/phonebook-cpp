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
                  const String &website = "unknown") : Contact(getId(), number, name, email), company(company),
                                                       website(website) {}

    /**
     * @brief id getter
     * @return id
     */
    static int getId() { return 1; }

    /**
     * @brief Company getter
     * @return company
     */
    String const &getCompany() const { return company; }

    /**
     * @brief Website getter
     * @return website
     */
    String const &getWebsite() const { return website; }

    /**
     * @brief Kiírja a megadott kimenetre a work adatait formázva
     * @return work adattagjai formázva
     */
    std::ostream &toString(std::ostream &) override;

    /**
    * @brief Kiírja a megadott kimenetre a work adatait formázatlanul
    * @return work adattagjai formázatlanul
    */
    void writeToFile(std::ostream &) override;

    /**
     * @brief Beolvas a megadott kimenetről
     * @return
     */
    void readFromFile(std::ifstream &) override;

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
                     int birthday = 18900101) : Contact(getId(), number, name, email), address(address),
                                                nickname(nickname),
                                                birthday(birthday) {}


    /**
     * @brief id getter
     * @return id
     */
    static int getId() { return 2; }

    /**
     * @brief Birthday getter
     * @return birthday
     */
    int const &getBirthday() const { return birthday; }

    /**
     * @brief Nickname getter
     * @return nickname
     */
    String const &getNickname() const { return nickname; };

    /**
     * @brief Addressg getter
     * @return address
     */
    String const &getAddress() const { return address; }

    /**
    * @brief Kiírja a megadott kimenetre a private adatait formázva
    * @return private adattagjai formázva
    */
    std::ostream &toString(std::ostream &) override;

    /**
    * @brief Kiírja a megadott kimenetre a private adatait formázatlanul
    * @return private adattagjai formázatlanul
    */
    void writeToFile(std::ostream &) override;

    /**
     * @brief Beolvas a megadott kimenetről
     * @return
     */
    void readFromFile(std::ifstream &) override;

    ~Private() override = default;
};

#endif //MY_AWESOME_PHONEBOOK_PHONE_HPP
