#include <iostream>
#include "gtest_lite.h"
#include "memtrace.h"

#include "menu.hpp"
#include "phonebook.hpp"
#include "contact.hpp"
#include "phone.hpp"

/**
 * @file mail.cpp
 * \mainpage A program leírása:
 * A program egy telefonkönyvként funkcionál.
 * Két féle kontaktot lehet benne tárolni, munkahelyi számokat, és otthoni számokat.
 * Hozzá lehet adni kontaktokat, és kitörölni, lehet listázni ezeket,
 * aztán az adatokat lementeni egy fájlba, ahonnan ezek később visszatölthetőek lesznek.
 * Keresni is lehet név vagy telefonszám szerint.
 * Pintér Tamás - JY4D5L
 */

void test_1() {
    String testString = String("test");

    TEST(Konstruktor teszt, Work)
        {
            Work work(testString, testString, testString, testString, testString);

            EXPECT_EQ(*testString.c_str(), *work.getNumber().c_str());
            EXPECT_EQ(*testString.c_str(), *work.getName().c_str());
            EXPECT_EQ(*testString.c_str(), *work.getEmail().c_str());
            EXPECT_EQ(*testString.c_str(), *work.getCompany().c_str());
            EXPECT_EQ(*testString.c_str(), *work.getWebsite().c_str());
        }
    END
    TEST(Konstruktor teszt, Private)
        {
            Private priv(testString, testString, testString, testString, testString, 20000101);

            EXPECT_EQ(*testString.c_str(), *priv.getNumber().c_str());
            EXPECT_EQ(*testString.c_str(), *priv.getName().c_str());
            EXPECT_EQ(*testString.c_str(), *priv.getEmail().c_str());
            EXPECT_EQ(*testString.c_str(), *priv.getNickname().c_str());
            EXPECT_EQ(20000101, priv.getBirthday());
        }
    END
}

void test_2() {

}

int main() {
    GTINIT(std::cin);

    test_1();

    Phonebook phonebook;
    phonebook.loadFromFile();
    Menu *menu = new Menu(phonebook);

    menu->run();
    return 0;
}