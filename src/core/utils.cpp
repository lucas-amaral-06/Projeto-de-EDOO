#include "utils.hpp"
#include <regex>
#include <string>
#include <sstream> // Necessário para istringstream

bool validarCPF(const string& cpf) {
	// Verifica o tamanho da string
	if (cpf.length() != 14) {
		return false;
	}

	// Verifica as posições dos caracteres especiais
	if (cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-') {
		return false;
	}

	// Verifica se todos os outros caracteres são dígitos
	for (int i = 0; i < cpf.length(); i++) {
		// Pula a verificação nas posições dos caracteres especiais
		if (i == 3 || i == 7 || i == 11) {
			continue;
		}
		
		if (!isdigit(cpf[i])) {
			return false;
		}
	}

	return true;
}

bool validarData(const std::string& data) {
	if (data.length() != 10 || data[2] != '/' || data[5] != '/') {
		return false;
	}

	std::istringstream iss(data);
	int dia, mes, ano;
	char barra1, barra2;

	iss >> dia >> barra1 >> mes >> barra2 >> ano;

	if (iss.fail() || barra1 != '/' || barra2 != '/') {
		return false;
	}

	// Validação básica dos intervalos
	if (ano < 1900 || ano > 2024) return false; // Ano de nascimento improvável
	if (mes < 1 || mes > 12) return false;
	if (dia < 1 || dia > 31) return false;

	// Validações específicas de meses
	if (mes == 2) {
		bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
		if (bissexto) {
			if (dia > 29) return false;
		} else {
			if (dia > 28) return false;
		}
	} else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
		return false;
	}

	return true;
}

bool validarCRM(const std::string& crm) {
	// Regex para o formato "CRM/UF XXXXX" (com espaço)
	static const std::regex padraoCRM(R"(^CRM/[A-Za-z]{2} \d{5}$)");
	return std::regex_match(crm, padraoCRM);
}