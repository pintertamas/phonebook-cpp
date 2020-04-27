//
// Created by Tomi on 27/04/2020.
//
#include <iostream>
#include "gtest_lite.h"
#include "memtrace.h"

#include "menu.hpp"
#include "test.hpp"

/**
 * @brief test_1 Teszt a konstruktorokhoz
 * Teszteli, hogy a konstruktorok rendes adatokkal hoznak-e a létre kontaktokat,
 * és amikor nem adunk meg minden adatot akkor a megfelelő default értéket veszik-e fel
 */
void test_1() {
    String testString = String("test");

    TEST(Constructor test, fully set Work CTOR)
        {
            Work work(testString, testString, testString, testString, testString);

            EXPECT_EQ(*testString.c_str(), *work.getNumber().c_str());
            EXPECT_EQ(*testString.c_str(), *work.getName().c_str());
            EXPECT_EQ(*testString.c_str(), *work.getEmail().c_str());
            EXPECT_EQ(*testString.c_str(), *work.getCompany().c_str());
            EXPECT_EQ(*testString.c_str(), *work.getWebsite().c_str());
        }
    END
    TEST(Constructor test, empty Work CTOR)
        {
            String unknown = "unknown";
            Work work(testString, testString, testString, testString);

            EXPECT_EQ(*unknown.c_str(), *work.getWebsite().c_str());
        }
    END
    TEST(Constructor test, Private)
        {
            Private priv(testString, testString, testString, testString, testString, 20000101);

            EXPECT_EQ(*testString.c_str(), *priv.getNumber().c_str());
            EXPECT_EQ(*testString.c_str(), *priv.getName().c_str());
            EXPECT_EQ(*testString.c_str(), *priv.getEmail().c_str());
            EXPECT_EQ(*testString.c_str(), *priv.getNickname().c_str());
            EXPECT_EQ(20000101, priv.getBirthday());
        }
    END
    TEST(Constructor test, empty Work CTOR)
        {
            String unknown = "unknown";
            Private priv(testString, testString, testString, testString);

            EXPECT_EQ(*unknown.c_str(), *priv.getAddress().c_str());
            EXPECT_EQ(18900101, priv.getBirthday());

        }
    END
}

/**
 * @brief test_2 Teszteset a Phonebook függvényeihez
 * Leteszteli, hogy a függvények jó adatokkal térnek-e vissza
 */
void test_2() {
    String testString = String("test");

    Phonebook pb;
    Private *priv = new Private(testString, testString, testString, testString, testString, 20000101);
    Work *work = new Work(testString, testString, testString, testString, testString);

    pb.addContact(priv);
    Vector<Contact *> testResult;

    testResult = pb.searchByName(testString);
    TEST(Phonebook test, searchByName)
        {
            EXPECT_EQ(*priv->getName().c_str(), *testResult[0]->getName().c_str());
        }
    END

    testResult = pb.searchByNumber(testString);
    TEST(Phonebook test, searchByNumber)
        {
            EXPECT_EQ(*priv->getNumber().c_str(), *testResult[0]->getNumber().c_str());
        }
    END

    Vector<Private *> privateContacts;
    Vector<Work *> workContacts;
    privateContacts.push_back(priv);
    workContacts.push_back(work);
    TEST(Phonebook test, convertToContact)
        {
            EXPECT_EQ(*priv->getName().c_str(), *Phonebook::convertToContact(privateContacts)[0]->getName().c_str());
            EXPECT_EQ(*priv->getName().c_str(), *Phonebook::convertToContact(workContacts)[0]->getName().c_str());
        }
    END

    TEST(Phonebook test, removeContact before deleting)
        {
            EXPECT_EQ(1, (int) privateContacts.getSize());
        }
    END

    privateContacts.deleteItem(0);

    TEST(Phonebook test, removeContact after deleting)
        {
            EXPECT_EQ(0, (int) privateContacts.getSize());
        }
    END

    TEST(Phonebook test, isFileEmpty)
        {
            const char *filename = "../emptyfile.txt";

            EXPECT_TRUE(pb.isFileEmpty(filename));
        }
    END
}