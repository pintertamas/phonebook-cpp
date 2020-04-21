//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_PHONE_HPP
#define MY_AWESOME_PHONEBOOK_PHONE_HPP

class Phone {
    int number;
public:
    virtual char *toString() = 0;
};

class Work : public Phone {
    int workID;
public:
    int getWorkID() { return workID; };
    char* toString();
};

class Private : public Phone {
    int ID;
public:
    int getWorkID() { return ID; };
    char* toString();
};

#endif //MY_AWESOME_PHONEBOOK_PHONE_HPP
