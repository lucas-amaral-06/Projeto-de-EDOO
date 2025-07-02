#include "Medico.hpp"
#include <iostream>
using namespace std;

Medico::Medico(const string& nome, const string& cpf, const string& dataNascimento, const string& genero, const string& telefone, const string& crm, const string& especialidade): Pessoa(nome, cpf, dataNascimento, genero, telefone)
{
  this->crm = crm;
  this->especialidade = especialidade;
}

Medico::~Medico() {}

string Medico::getCRM() const {
  return crm;
}

string Medico::getEspecialidade() const {
  return especialidade;
}

void Medico::setEspecialidade(const string& especialidade) {
  this->especialidade = especialidade;
}

void Medico::exibirDados() const {
  cout << "Dados do Médico:" << this->getNome() << endl;
  Pessoa::exibirDados();
  cout << "CRM: " << crm << endl;
  cout << "Especialidade: " << this->especialidade << endl;
}