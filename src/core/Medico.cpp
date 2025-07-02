#include "Medico.hpp"
#include <iostream>
using namespace std;

Medico::Medico(const string& nome,
               const string& cpf,
               const string& dataNascimento,
               const string& genero,
               const string& telefone,
               const string& crm,
               const string& especialidade,
               const string& senha)
    : Pessoa(nome, cpf, dataNascimento, genero, telefone),
      crm(crm),
      especialidade(especialidade),
      senha(senha) {}

Medico::~Medico() {}

string Medico::getCRM() const {
    return crm;
}

string Medico::getEspecialidade() const {
    return especialidade;
}

string Medico::getSenha() const {
    return senha;
}

void Medico::setEspecialidade(const string& especialidade) {
    this->especialidade = especialidade;
}

void Medico::setSenha(const string& novaSenha) {
    this->senha = novaSenha;
}

void Medico::exibirDados() const {
    Pessoa::exibirDados();
    cout << "CRM: " << crm << endl;
    cout << "Especialidade: " << especialidade << endl;
}