//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_PHONE_HPP
#define MY_AWESOME_PHONEBOOK_PHONE_HPP

#include <iostream>

using namespace std;

class Phone {
protected:
    long long number;
public:
    explicit Phone(long long num) : number(num) {}

    virtual string toString() = 0;
};

class Work : public Phone {
    int workID;
public:
    Work(long long num, int id) : workID(id), Phone(num) {}

    void setWorkID(int id) { workID = id; }
    int getWorkID() { return workID; };

    string toString() override;
};

class Private : public Phone {
    int ID;
public:
    Private(long long num, int id) : ID(id), Phone(num) {}

    void setID(int id) { ID = id; }
    int getID() { return ID; };

    string toString() override;
};

#endif //MY_AWESOME_PHONEBOOK_PHONE_HPP
