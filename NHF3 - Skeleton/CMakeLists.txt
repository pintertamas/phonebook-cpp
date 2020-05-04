cmake_minimum_required(VERSION 3.15)
project(my_awesome_phonebook)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_executable(my_awesome_phonebook
        main.cpp
        menu.cpp menu.hpp
        phonebook.cpp phonebook.hpp
        contact.hpp
        phone.cpp phone.hpp
        gtest_lite.h
        memtrace.cpp memtrace.h
        std::string5.cpp std::string5.h vector.hpp test.cpp test.hpp)