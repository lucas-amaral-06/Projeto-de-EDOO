#include "Recepcionista.hpp"
#include <iostream>

Recepcionista::Recepcionista(const std::string& nome, 
                           const std::string& cpf, 
                           const std::string& dataNascimento,
                           const std::string& genero,
                           const std::string& telefone,
                           const std::string& senha,
                           const std::string& turno,
                           const std::string& codigoAcesso)
    : Pessoa(nome, cpf, dataNascimento, genero, telefone),
      senha(senha),
      turno(turno),
      codigoAcesso(codigoAcesso) {}

Recepcionista::~Recepcionista() {
    // Destruidor pode ser mantido vazio ou adicionar lógica se necessário
}

// Getters
std::string Recepcionista::getSenha() const {
    return senha;
}

std::string Recepcionista::getTurno() const {
    return turno;
}

std::string Recepcionista::getCodigoAcesso() const {
    return codigoAcesso;
}

// Setters
void Recepcionista::setSenha(const std::string& novaSenha) {
    senha = novaSenha;
}

void Recepcionista::setTurno(const std::string& novoTurno) {
    turno = novoTurno;
}

// Método para exibir todos os dados
void Recepcionista::exibirDados() const {
    std::cout << "\n=== Dados do Recepcionista ===" << std::endl;
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "CPF: " << getCPF() << std::endl;
    std::cout << "Data de Nascimento: " << getDataNascimento() << std::endl;
    std::cout << "Gênero: " << getGenero() << std::endl;
    std::cout << "Telefone: " << getTelefone() << std::endl;
    std::cout << "Turno: " << turno << std::endl;
    std::cout << "Código de Acesso: " << codigoAcesso << std::endl;
    // Nota: A senha não é exibida por questões de segurança
}