cmake_minimum_required(VERSION 3.15)
project(my_awesome_phonebook)

set(CMAKE_CXX_STANDARD 14)

add_executable(my_awesome_phonebook
        main.cpp
        menu.cpp menu.hpp
        phonebook.cpp phonebook.hpp
        contact.cpp contact.hpp
        phone.cpp phone.hpp
        gtest_lite.h
        memtrace.cpp memtrace.h)