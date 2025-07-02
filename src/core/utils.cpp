#include "utils.hpp"

bool validarFormatoCPF(const string& cpf) {
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