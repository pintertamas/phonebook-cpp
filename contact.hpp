//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_CONTACT_HPP
#define MY_AWESOME_PHONEBOOK_CONTACT_HPP

#include "phone.hpp"

class Contact{
    Phone* phones;
    char* name;
    char* nickname;
    char* address;
    char* email;
public:
    Phone* searchByNumber(int);
    void addPhone(Phone*);
    void removePhone(int);
};

#endif //MY_AWESOME_PHONEBOOK_CONTACT_HPP
