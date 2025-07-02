#include "utils.hpp"

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
        std::cout << "\nERRO: Formato de data inválido. Use DD/MM/AAAA." << std::endl;
        return false;
    }
    return true;
}

bool validarCRM(const std::string& crm) {
    // Implementação da validação de CRM
    if (crm.rfind("CRM/", 0) != 0) {
        std::cout << "\nERRO: Formato de CRM inválido. Deve iniciar com 'CRM/'." << std::endl;
        return false;
    }
    return true;
}