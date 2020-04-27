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
/**
 * @brief test_1 Teszt a konstruktorokhoz
 * Teszteli, hogy a konstruktorok rendes adatokkal hoznak-e a létre kontaktokat
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

/**
 * @brief test_2 Teszteset a függvényekhez
 * Leteszteli, hogy a függvények jó adatokkal térnek-e vissza
 */
void test_2() {
    String testString = String("test");

    Phonebook pb;
    Private *priv = new Private(testString, testString, testString, testString, testString, 20000101);
    pb.addContact(priv);
    Vector<Contact *> testResultName, testResultNumber;
    testResultName = pb.searchByName(testString);
    testResultNumber = pb.searchByNumber(testString);

    TEST(Phonebook teszt, searchByName)
        {
            EXPECT_EQ(*priv->getName().c_str(), *testResultName[0]->getName().c_str());
        }
    END

    TEST(Phonebook teszt, searchByNumber)
        {
            EXPECT_EQ(*priv->getNumber().c_str(), *testResultNumber[0]->getNumber().c_str());
        }
    END

}

int main() {
#ifndef CPORTA
    system("cls");
#endif          //CPORTA
    GTINIT(std::cin);

    test_1();
    test_2();

    Phonebook phonebook;
    if (!Phonebook::isFileEmpty("../database.txt"))
        phonebook.loadFromFile();
    Menu *menu = new Menu(phonebook);

    menu->run();
    return 0;
}