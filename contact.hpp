//
// Created by Tomi on 17/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_CONTACT_HPP
#define MY_AWESOME_PHONEBOOK_CONTACT_HPP

#include <string>
#include <utility>

/**
 * @file contact.hpp
 * @brief Contact class
 */
/**
 * @brief Contact class létrehozása
 */
class Contact {
    /**
     * @brief A közös tulajdonságok
     * number, name, email
     */
protected:
    std::string number;
    std::string name;
    std::string email;
public:
    /**
     * @brief Contact CTOR
     * A megadott értékekkel létrehoz egy Contactot
     */
    Contact(std::string number, std::string name, std::string email)
            : number(std::move(number)), name(std::move(name)), email(std::move(email)) {};

    /**
     * @brief Number getter
     * @return number
     */
    std::string getNumber() const { return number; };

    /**
     * @brief Name getter
     * @return name
     */
    std::string getName() const { return name; };

    /**
     * @brief Email getter
     * @return email
     */
    std::string getEmail() const { return email; };

    /**
     * @brief A toString tiszta virtuális függvénye
     */
    virtual std::ostream &toString(std::ostream &) = 0;

    /**
     * @brief Contact DTOR
     */
    virtual ~Contact() = default;
};

#endif //MY_AWESOME_PHONEBOOK_CONTACT_HPP
