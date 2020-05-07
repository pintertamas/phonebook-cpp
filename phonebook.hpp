//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_PHONEBOOK_HPP
#define MY_AWESOME_PHONEBOOK_PHONEBOOK_HPP

#include "contact.hpp"
#include "phone.hpp"
#include "vector.hpp"

/**
 * @file phonebook.hpp
 * @brief Phonebook class
 */

class Phonebook {
    Vector<Work *> workContacts;
    Vector<Private *> privateContacts;
public:
    /**
     * @brief Phonebook CTOR
     */
    Phonebook() : workContacts(0), privateContacts(0) {};

    /**
     * @brief Kilistázza azokat a kontaktokat amik nevében szerepel a "name" szó
     * @param name ez alapján a név alapján listáz
     * @return a keresésnek megfelelt kontaktokat
     */
    Vector<Contact *> searchByName(std::string &name);

    /**
     * @brief Kilistázza azokat a kontaktokat amik telefonszámában szerepel a "number" szám
     * @param name ez alapján a név alapján listáz
     * @return a keresésnek megfelelt kontaktokat
     */
    Vector<Contact *> searchByNumber(std::string &number);

    /**
     * @brief Konvertál Vector<Work *>-ről Vector<Contact*>-ra
     * @param workContacts ezt a Vectort konvertálja
     * @return átkonvertált Vector
     */
    static Vector<Contact *> convertToContact(Vector<Work *> const &workContacts);

    /**
     * @brief Konvertál Vector<Private *>-ról Vector<Contact*>-ra
     * @param privateContacts ezt a Vectort konvertálja
     * @return átkonvertált Vector
     */
    static Vector<Contact *> convertToContact(Vector<Private *> const &privateContacts);

    /**
     * @brief Kereső függvény
     * @param contacts Ebben a Vectorban keres
     * @param searchCommand Ezzel a kereső függvénnyel
     * @param pattern Ez alapján
     * @return Keresésnek megfelelt Vector
     */
    static Vector<Contact *>
    searchContactsFor(const Vector<Contact *> &contacts, bool (*searchCommand)(const Contact *, const std::string &),
                      const std::string &pattern);

    /**
     * @brief Visszatér a workContacts egy elemével
     * @param index Ezzel az elemével tér vissza
     * @return workContacts[index]
     */
    Work *getWorkContacts(size_t index) const {
        return workContacts[index];
    }

    /**
     * @brief Visszatér a workContacts egy elemével
     * @param index Ezzel az elemével tér vissza
     * @return privateContacts[i]
     */
    Private *getPrivateContacts(size_t index) const {
        return privateContacts[index];
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
     * @brief hozzáad egy work Vectort a telefonkünyvhöz
     */
    void addContact(Work *const &);

    /**
     * @brief Hozzáad egy private Vectort a telefonkönyvhöz
     */
    void addContact(Private *const &);

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
     * @brief Ha nem talált a loadFromFile adatokat a database.txt-ben, akkor feltölti üres adatokkal a telefonkönyvet
     */
     void loadFromEmpty();

    /**
     * @brief Elmenti a database.txt fileba a worn kontaktokat
     */
    static void saveContactsToDB(std::ostream &, Work *);

    /**
     * @brief Elmenti a database.txt fileba a private kontaktokat
     */
    static void saveContactsToDB(std::ostream &, Private *);

    /**
     * @brief Elmenti az összes kontaktot a database.txt fileba
     */
    void saveToFile();

    /**
     * @brief Phonebook DTOR
     * Kitörli az összes kontaktot a memóriából
     */
    ~Phonebook() {
        for (size_t i = 0; i < workContacts.getSize(); ++i) {
            delete workContacts[i];
        }
        for (size_t i = 0; i < privateContacts.getSize(); ++i) {
            delete privateContacts[i];
        }
    }
};

#endif //MY_AWESOME_PHONEBOOK_PHONEBOOK_HPP
