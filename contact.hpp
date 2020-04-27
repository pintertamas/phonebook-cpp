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
    String number;
    String name;
    String email;
public:
    /**
     * @brief Contact CTOR
     * A megadott értékekkel létrehoz egy Contactot
     */
    Contact(const String &number, const String &name, const String &email)
            : number(number), name(name), email(email) {};

    /**
     * @brief Number getter
     * @return number
     */
    String getNumber() const { return number; };

    /**
     * @brief Name getter
     * @return name
     */
    String getName() const { return name; };

    /**
     * @brief Email getter
     * @return email
     */
    String getEmail() const { return email; };

    /**
     * @brief A toString tiszta virtuális függvénye
     */
    virtual std::ostream &toString(std::ostream &) = 0;

    /**
     * @brief Contact DTOR
     */
    virtual ~Contact() = default;
};

#endif //MY_AWESOME_PHONEBOOK_CONTACT_HPP
