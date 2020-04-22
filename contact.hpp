//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_CONTACT_HPP
#define MY_AWESOME_PHONEBOOK_CONTACT_HPP

#include "phone.hpp"

using namespace std;

class Contact{
    Phone* phones;
    const string name;
    const string nickname;
    const string address;
    const string email;
public:
    Contact(Phone* phones, string& name, string& nickname, string& address, string& email)
    : phones(phones), name(name), nickname(nickname), address(address), email(email) {};
    Phone* searchByNumber(int);
    void addPhone(Phone*);
    void removePhone(int);
};

#endif //MY_AWESOME_PHONEBOOK_CONTACT_HPP
