#include "Paciente.hpp"
#include "Prontuario.hpp"
#include <iostream>
using namespace std;

Paciente::Paciente(const string& nome, const int& idade, const string& cpf, const string& dataNascimento, const string& genero, const string& telefone)
    : Pessoa(nome, idade, cpf, dataNascimento, genero, telefone), prontuario(new Prontuario(this)) // Inicializa o prontuário com o paciente
{}

Paciente::~Paciente() {
  delete prontuario; // Libera a memória do prontuário
}

Prontuario* Paciente::getProntuario() const {
  return prontuario; // Retorna o prontuário do paciente
}

void Paciente::exibirDados() const {
  cout << "Dados do Paciente:" << this->getNome() << endl;
  Pessoa::exibirDados();
  cout << "Nº Prontuário: " << prontuario->getNumero() << endl;
}