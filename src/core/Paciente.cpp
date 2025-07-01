#include "Paciente.hpp"
#include "Prontuario.hpp"
#include <iostream>
using namespace std;

Paciente::Paciente(const string& nome, const string& cpf, const string& dataNascimento, const string& genero, const string& telefone)
    : Pessoa(nome, cpf, dataNascimento, genero, telefone), prontuario(*this) // Inicializa o prontuário com o paciente
{}

const Prontuario& Paciente::getProntuario() const {
  return this->prontuario; // Retorna o prontuário do paciente
}

Prontuario& Paciente::getProntuario() {
  return this->prontuario; // Retorna o prontuário do paciente (versão não-const)
}

void Paciente::exibirDados() const {
  cout << "Dados do Paciente:" << this->getNome() << endl;
  Pessoa::exibirDados();
  cout << "Nº Prontuário: " << this->prontuario.getNumero() << endl;
}