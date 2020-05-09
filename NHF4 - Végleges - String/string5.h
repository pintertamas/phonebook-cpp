#ifndef std::string_H
#define std::string_H
/**
 * \file std::string5.h
 *
 * Ez a fájl tartalmazza a std::string osztály deklarációját és inline függvényeit.
 */

#include <iostream>

/**
 * std::string osztály.
 * A pData-ban vannak a karakterek (a lezáró nullával együtt),
 * len a hossz.A hosszba nem számít bele a lezáró nulla.
 */
class std::string {
    char *pData;    ///< pointer az adatra
    size_t len;     ///< hossz lezáró nulla nélkül
public:
    /// Hossz lekérdezése.
    /// @return Sztring hossza
	size_t size() const { return len; }


    /// Default konstruktor
    /// std::string() :pData(0), len(0) {}
    /// helyett ""-val inicializáljuk a const char*-osban

    /// C-sztringet ad vissza
    /// @return pinter egy '\0'-val lezárt (C) sztringre
    const char* c_str() const { return pData;}

    /// Konstruktor egy char karakterből
    /// @param ch - karakter
    std::string(char ch);

    /// Konstruktor egy nullával lezárt char sorozatból
    /// Ez a deafault is!
    /// @param p - pointer egy C sztringre
    std::string(const char *p = "");

    /// Másoló konstruktor
    /// @param s1 - std::string, amiből létrehozzuk az új std::string-et
    std::string(const std::string& s1);

    /// Destruktor
    virtual ~std::string() { delete[] pData; }

    /// Kiírunk egy std::stringet (debug célokra)
    /// Előtte kiírunk egy tetszőleges szöveget.
    /// @param txt - nullával lezárt szövegre mutató pointer
    void printDbg(const char *txt = "") const {
        std::cout << txt << "[" << len << "], "
                  << (pData ? pData : "(NULL)") << std::endl;
    }

    /// Értékadó operátor.
    /// @param rhs_s - jobboldali std::string
    /// @return baoldali (módosított) std::string (referenciája)
    std::string& operator=(const std::string& rhs_s);

    /// Két std::stringet összefűz
    /// @param rhs_s - jobboldali std::string
    /// @return új std::string, ami tartalmazza a két std::stringet egmás után
    std::string operator+(const std::string& rhs_s) const ;

    /// Sztrinhez karaktert összefűz
    /// @param rhs_c - jobboldali karakter
    /// @return új std::string, ami tartalmazza a sztringet és a karaktert egymás után
    std::string operator+(char rhs_c) const { return *this + std::string(rhs_c);}

    /// A std::string egy megadott indexű elemének REFERENCIÁJÁVAL tér vissza.
    /// @param idx - charakter indexe
    /// @return karakter (referencia)
    ///         Indexelési hiba esetén const char* kivételt dob.
    char& operator[](unsigned int idx);

    /// A std::string egy megadott indexű elemének REFERENCIÁJÁVAL tér vissza.
    /// @param idx - karakter indexe
    /// @return karakter (referencia)
    ///         Indexelési hiba esetén const char* kivételt dob (assert helyett).
    const char& operator[](unsigned int idx) const;
};

/// Globális függvények:
/// kiír az ostream-re
/// @param os - ostream típusú objektum
/// @param s0 - std::string, amit kiírunk
/// @return os
std::ostream& operator<<(std::ostream& os, const std::string& s0);

/// Beolvas az istream-ről egy szót egy std::string-be.
/// @param is - istream típusú objektum
/// @param s0 - std::string, amibe beolvas
/// @return is
std::istream& operator>>(std::istream& is, std::string& s0);

/// Karakterhez sztringet fűz
/// @param ch - karakter
/// @param str - std::string
/// @return új std::string, ami tartalmazza a karaktert és a sztringet egymás után
inline std::string operator+(char ch, const std::string& str) { return std::string(ch) + str; }



#endif
