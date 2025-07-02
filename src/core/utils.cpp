#include "utils.hpp"
#include <regex>
#include <string>

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
    // Implementação da validação de data
    if (data.length() != 10 || data[2] != '/' || data[5] != '/') {
        return false;
    }
    return true;
}

bool validarCRM(const std::string& crm) {
    static const std::regex padraoCRM(R"(^CRM/[A-Za-z]{2} \d{5}$)");
    return std::regex_match(crm, padraoCRM);
}