//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_PHONEBOOK_HPP
#define MY_AWESOME_PHONEBOOK_PHONEBOOK_HPP

#include "contact.hpp"
#include "phone.hpp"
#include "string5.h"
#include "vector.hpp"

/**
 * @file phonebook.hpp
 * @brief Phonebook class
 */

class Phonebook {
    Vector<Contact *> contacts;
public:
    /**
     * @brief Phonebook CTOR
     */
    Phonebook() : contacts(0) {};

    /**
     * @brief Kilistázza azokat a kontaktokat amik nevében szerepel a "name" szó
     * @param name ez alapján a név alapján listáz
     * @return a keresésnek megfelelt kontaktokat
     */
    Vector<Contact *> searchByName(String &name);

    /**
     * @brief Kilistázza azokat a kontaktokat amik telefonszámában szerepel a "number" szám
     * @param name ez alapján a név alapján listáz
     * @return a keresésnek megfelelt kontaktokat
     */
    Vector<Contact *> searchByNumber(String &number);

    /**
     * @brief Kereső függvény
     * @param contacts Ebben a Vectorban keres
     * @param searchCommand Ezzel a kereső függvénnyel
     * @param pattern Ez alapján
     * @return Keresésnek megfelelt Vector
     */
    static Vector<Contact *>
    searchContactsFor(const Vector<Contact *> &contacts, bool (*searchCommand)(const Contact *, const String &),
                      const String &pattern);

    /**
     * @brief Visszatér a megfelelő típusú kontaktokkal
     * @param id Ilyen kontakt típusú Vektorral tér vissza
     */
    Vector<Contact *> getContactsWithId(int id) const {
        Vector<Contact *> tmp;
        for (size_t i = 0; i < contacts.getSize(); ++i) {
            if (contacts[i]->getContactId() == id)
                tmp.push_back(contacts[i]);
        }
        return tmp;
    }

    /**
     * @brief Kilistázza a kontaktokat a megadott ostreamre
     * @param contacts Ezeket listázza
     */
    static void listContactType(const Vector<Contact *> &contacts, std::ostream &);

    /**
     * @brief Kilistázza a work és private Vectorok adatait a megadott ostreamre
     */
    void listContacts(std::ostream &);

    /**
     * @brief Hozzáad egy contactot a telefonkönyvhöz
     */
    void addContact(Contact *const &);

    /**
     * @brief Kitöröl egy kontaktot az indexe alapján (ezt a futása közben kéri be)
     */
    void removeContact();

    /**
     * @brief Megmondja hogy az adott file üres-e
     * @param filename ezt a filet teszteli
     * @return üres-e a file
     */
    static bool isFileEmpty(const char *filename);

    /**
     * @brief Felveszi a database.txt-ben talált kontaktokat a telefonkönyvbe
     */
    void loadFromFile();

    /**
     * @brief Elmenti az összes kontaktot a database.txt fileba
     */
    void saveToFile();

    /**
     * @brief Phonebook DTOR
     * Kitörli az összes kontaktot a memóriából
     */
    ~Phonebook() {
        for (size_t i = 0; i < contacts.getSize(); ++i) {
            delete contacts[i];
        }
    }
};

#endif //MY_AWESOME_PHONEBOOK_PHONEBOOK_HPP
