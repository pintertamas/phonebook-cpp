//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_CONTACT_HPP
#define MY_AWESOME_PHONEBOOK_CONTACT_HPP

#include "string5.h"

/**
 * @file contact.hpp
 * @brief Contact class
 */
/**
 * @brief Contact class létrehozása
 */
class Contact {
    /**
     * @brief A közös tulajdonságok
     * number, name, email
     */
protected:
    int id;
    String number;
    String name;
    String email;
public:
    /**
     * @brief Contact CTOR
     * A megadott értékekkel létrehoz egy Contactot
     */
    Contact(const int &id, const String &number, const String &name, const String &email)
            : id(id), number(number), name(name), email(email) {};

    /**
     * @brief id getter
     * @return id
     */
    int const& getContactId() const { return id; };

    /**
     * @brief Number getter
     * @return number
     */
    String const& getNumber() const { return number; };

    /**
     * @brief Name getter
     * @return name
     */
    String const& getName() const { return name; };

    /**
     * @brief Email getter
     * @return email
     */
    String const& getEmail() const { return email; };

    /**
     * @brief A toString tiszta virtuális függvénye
     */
    virtual std::ostream &toString(std::ostream &) = 0;

    /**
     * @brief A writeToFile tiszta virtuális függvénye
     */
    virtual void writeToFile(std::ostream &) = 0;

    /**
     * @brief LoadFromFile tiszta virtuális függvénye
     */
    virtual void readFromFile(std::ifstream &) = 0;

    /**
     * @brief Contact DTOR
     */
    virtual ~Contact() = default;
};

#endif //MY_AWESOME_PHONEBOOK_CONTACT_HPP
