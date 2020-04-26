//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_CONTACT_HPP
#define MY_AWESOME_PHONEBOOK_CONTACT_HPP

#include "string5.h"

class Contact{
protected:
    String number;
    String name;
    String email;
public:
    Contact(const String &number, const String &name, const String& email)
    : number(number), name(name), email(email) {};
    String getNumber() { return number; };
    String getName() { return name; };
    String getEmail() { return email; };
    virtual std::ostream& toString(std::ostream&) = 0;
};

#endif //MY_AWESOME_PHONEBOOK_CONTACT_HPP
