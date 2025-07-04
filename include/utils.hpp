// utils.hpp
#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdlib> // Necessário para system()
#include <cctype>
#include <iostream>

using namespace std;

inline void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

bool validarCPF(const string& cpf);
bool validarData(const string& data);
bool validarCRM(const string& crm);

#endif