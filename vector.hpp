//
// Created by Tomi on 25/04/2020.
//

#ifndef MY_AWESOME_PHONEBOOK_VECTOR_HPP
#define MY_AWESOME_PHONEBOOK_VECTOR_HPP

#include <cstdlib>
#include "memtrace.h"

/**
 * @file vector.hpp
 * @brief Vector class
 */

template<typename T>
class Vector {
    T *array;           /// T típusú elemek tömbje
    size_t size;        /// ennyi elemet tárolunk benne éppen
public:
    /**
     * @brief Vector CTOR
     * @param size size of the vector
     */
    Vector(size_t size = 0) : array(NULL), size(size) {
        array = new T[size];
        for (size_t i = 0; i < size; ++i) {
            array[i] = NULL;
        }
    }

    /**
     * @brief Vector DTOR
     */
    ~Vector() {
        delete[] array;
    }

    /**
     * @brief Copy CTOR
     * @param vector ezt a vektort másoljuk le
     */
    Vector(const Vector &vector) : array(NULL), size(vector.size) {
        array = new T[size];
        for (size_t i = 0; i < size; ++i) {
            array[i] = vector.array[i];
        }
    }

    /**
     * @brief Ertekado operator
     * @param vector ezt az értéket adjuk át
     * @return *this
     */
    Vector &operator=(const Vector &vector) {
        if (this != &vector) {
            delete[] array;
            size = vector.size;
            array = new T[size];
            for (size_t i = 0; i < size; ++i) {
                array[i] = vector[i];
            }
        }
        return *this;
    }

    /**
     * @brief Indexelő operátor
     * @param index ennél az indexnél lévő adatot adjuk vissza
     * @return array[index]
     */
    T &operator[](size_t index) const {
        if (index > size)
            return array[size];
        return array[index];
    }

    /**
     * @brief méret getter
     * @return méret
     */
    size_t getSize() const { return size; }

    /**
     * @brief Átméretezi a vektort egyel nagyobbra
     */
    void increaseSize() {
        T *newArray = new T[size + 1];

        for (size_t i = 0; i < size; i++)
            newArray[i] = array[i];

        newArray[size] = NULL;

        delete[] array;
        array = newArray;
        size++;
    }

    /**
     * @brief hozzárak egy elemet a tárolóhoz
     * @param t A kapott elem referenciája.
     */
    void push_back(const T &item) {
        increaseSize();
        array[size - 1] = item;
    }

    /**
     * @brief megcserél két tárolt elemet az indexeik alapján
     * @param index1 1. elem
     * @param index2 2. elem
     */
    void swap(size_t index1, size_t index2) {
        T tmp = array[index1];
        array[index1] = array[index2];
        array[index2] = tmp;
    }

    /**
     * @brief kitöröl egy elemet a tárolóbol
     * @param index ezt az indexű tagot törli
     */
    void deleteItem(size_t index) {
        swap(index, (size - 1));
        delete array[size-1];
        size--;
    }
};

#endif //MY_AWESOME_PHONEBOOK_VECTOR_HPP
