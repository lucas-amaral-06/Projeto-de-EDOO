#include "Recepcionista.hpp"
#include <iostream>

Recepcionista::Recepcionista(const string& nome, 
                           const string& cpf, 
                           const string& dataNascimento,
                           const string& genero,
                           const string& telefone,
                           const string& senha,
                           const string& turno,
                           const string& codigoAcesso)
    : Pessoa(nome, cpf, dataNascimento, genero, telefone),
      senha(senha),
      turno(turno),
      codigoAcesso(codigoAcesso) {}

Recepcionista::~Recepcionista() {
    // Destruidor pode ser mantido vazio ou adicionar lógica se necessário
}

// Getters
string Recepcionista::getSenha() const {
    return senha;
}

string Recepcionista::getTurno() const {
    return turno;
}

string Recepcionista::getCodigoAcesso() const {
    return codigoAcesso;
}

// Setters
void Recepcionista::setSenha(const string& novaSenha) {
    senha = novaSenha;
}

void Recepcionista::setTurno(const string& novoTurno) {
    turno = novoTurno;
}

// Método para exibir todos os dados
void Recepcionista::exibirDados() const {
    cout << "Nome: " << getNome() << endl;
    cout << "CPF: " << getCPF() << endl;
    cout << "Data de Nascimento: " << getDataNascimento() << endl;
    cout << "Gênero: " << getGenero() << endl;
    cout << "Telefone: " << getTelefone() << endl;
    cout << "Turno: " << turno << endl;
    cout << "Código de Acesso: " << codigoAcesso << endl;
    // Nota: A senha não é exibida por questões de segurança
}