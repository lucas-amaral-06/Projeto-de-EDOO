// utils.hpp
#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdlib> // Necessário para system()

inline void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

#endif