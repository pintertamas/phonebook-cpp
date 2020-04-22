//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_PHONE_HPP
#define MY_AWESOME_PHONEBOOK_PHONE_HPP

#include <iostream>
using namespace std;

class Phone {
protected:
    int number;
public:
    virtual string toString() = 0;
};

class Work : public Phone {
    int workID;
public:
    int getWorkID() { return workID; };
    string toString();
};

class Private : public Phone {
    int ID;
public:
    int getWorkID() { return ID; };
    string toString();
};

#endif //MY_AWESOME_PHONEBOOK_PHONE_HPP
