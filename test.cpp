//
// Created by Tomi on 27/04/2020.
//
#include <iostream>
#include "gtest_lite.h"

#include "menu.hpp"
#include "test.hpp"
#include "memtrace.h"

/**
 * @brief test_1 Teszt a konstruktorokhoz
 * Teszteli, hogy a konstruktorok rendes adatokkal hoznak-e a létre kontaktokat,
 * és amikor nem adunk meg minden adatot akkor a megfelelő default értéket veszik-e fel
 */
void test_1() {

    /**
     * @brief Teszteli, hogy jó adatokkal jön-e létre a Work class a konstruktor hívásakor
     */
    TEST(Constructor test, fully set Work CTOR)
        {
            String testString = String("test");
            Work work(testString, testString, testString, testString, testString);

            EXPECT_EQ(*testString.c_str(), *work.getNumber().c_str());
            EXPECT_EQ(*testString.c_str(), *work.getName().c_str());
            EXPECT_EQ(*testString.c_str(), *work.getEmail().c_str());
            EXPECT_EQ(*testString.c_str(), *work.getCompany().c_str());
            EXPECT_EQ(*testString.c_str(), *work.getWebsite().c_str());
        }
    END
    /**
     * @brief Teszteli, hogy jó adatokkal jön-e létre a Work class részben üres konstruktor hívásakor
     */
    TEST(Constructor test, empty Work CTOR)
        {
            String testString = String("test");
            String unknown = "unknown";
            Work work(testString);

            EXPECT_EQ(*unknown.c_str(), *work.getWebsite().c_str());
        }
    END
    /**
     * @brief Teszteli, hogy jó adatokkal jön-e létre a Private class a konstruktor hívásakor
     */
    TEST(Constructor test, Private)
        {
            String testString = String("test");
            Private priv(testString, testString, testString, testString, testString, 20000101);

            EXPECT_EQ(*testString.c_str(), *priv.getNumber().c_str());
            EXPECT_EQ(*testString.c_str(), *priv.getName().c_str());
            EXPECT_EQ(*testString.c_str(), *priv.getEmail().c_str());
            EXPECT_EQ(*testString.c_str(), *priv.getNickname().c_str());
            EXPECT_EQ(20000101, priv.getBirthday());
        }
    END
    /**
     * @brief Teszteli, hogy jó adatokkal jön-e létre a Private class részben üres konstruktor hívásakor
     */
    TEST(Constructor test, empty Work CTOR)
        {
            String testString = String("test");
            String unknown = "unknown";
            Private priv(testString);

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
    Contact *priv = new Private(testString, testString, testString, testString, testString, 20000101);

    pb.addContact(priv);
    Vector<Contact *> testResult;

    testResult = pb.searchByName(testString);
    /**
     * @brief Teszteli hogy jó nevet talált-e meg a kereső
     */
    TEST(Phonebook test, searchByName)
        {
            EXPECT_EQ(*priv->getName().c_str(), *testResult[0]->getName().c_str());
        }
    END

    testResult = pb.searchByNumber(testString);
    /**
     * @brief Teszteli, hogy jó számot talált-e meg a kereső
     */
    TEST(Phonebook test, searchByNumber)
        {
            EXPECT_EQ(*priv->getNumber().c_str(), *testResult[0]->getNumber().c_str());
        }
    END
}
/**
 * @brief test_3 Teszteset a Phonebook függvényeihez
 * Leteszteli, hogy a függvények jó adatokkal térnek-e vissza
 */
void test_3() {
    String testString = String("test");

    Phonebook pb;
    Contact *priv = new Private(testString, testString, testString, testString, testString, 20000101);
    Contact *work = new Work(testString, testString, testString, testString, testString);

    Vector<Contact *> contacts;
    contacts.push_back(priv);
    contacts.push_back(work);

    /**
     * @brief Teszteli, hogy az eltávolítás előtt 2-e a Vector mérete
     */
    TEST(Phonebook test, removeContact before deleting)
        {
            EXPECT_EQ(2, (int) contacts.getSize());
        }
    END

    contacts.deleteItem(0);
    contacts.deleteItem(0);

    /**
     * @brief Teszteli, hogy eltávolítás után 0-e a Vector mérete
     */
    TEST(Phonebook test, removeContact after deleting)
        {
            EXPECT_EQ(0, (int) contacts.getSize());
        }
    END

    /**
     * @brief Teszteli, hogy az erre a célra létrehozott üres emptyfile.txt üres-e.
     */
    TEST(Phonebook test, isFileEmpty)
        {
            const char *filename = "emptyfile.txt";

            EXPECT_TRUE(pb.isFileEmpty(filename));
        }
    END
}