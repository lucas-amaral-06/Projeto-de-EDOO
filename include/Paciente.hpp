#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>
#include "Pessoa.hpp"
#include "Prontuario.hpp" // Preciso incluir o cabeçalho para usar a classe Prontuario na composição
using namespace std;

class Paciente : public Pessoa
{
  private:  
    Prontuario prontuario; // Composição: o paciente TEM um prontuário

  public:
    Paciente(const string& nome, const string& cpf, const string& dataNascimento, const string& genero, const string& telefone);

    const Prontuario& getProntuario() const; // método para obter o prontuário do paciente
    Prontuario& getProntuario(); // versão não-const para permitir modificações

    void exibirDados() const override; // sobrescrita do método exibirDados da classe Pessoa
};


#endif