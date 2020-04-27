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

class Contact {
protected:
    String number;
    String name;
    String email;
public:
    Contact(const String &number, const String &name, const String &email)
            : number(number), name(name), email(email) {};

    String getNumber() const { return number; };

    String getName() const { return name; };

    String getEmail() const { return email; };

    virtual std::ostream &toString(std::ostream &) = 0;

    virtual ~Contact() = default;
};

#endif //MY_AWESOME_PHONEBOOK_CONTACT_HPP
