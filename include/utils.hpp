// utils.hpp
#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdlib> // Necessário para system()
#include <cctype>
#include <iostream>

using namespace std;

// Função para limpar a tela do console
inline void clearScreen() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

// Função para validar CPF
bool validarCPF(const string& cpf);

// Função para validar Data
bool validarData(const string& data);

// Função para validar CRM
bool validarCRM(const string& crm);

#endif