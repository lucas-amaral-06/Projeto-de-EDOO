#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>
#include "Pessoa.hpp"
#include "Prontuario.hpp" // inclui a definição da classe Prontuario
using namespace std;

class Paciente : public Pessoa
{
  private:  
    Prontuario prontuario; // ponteiro para o prontuário do paciente

  public:
    Paciente(const string& nome, const string& cpf, const string& dataNascimento, const string& genero, const string& telefone);

    const Prontuario& getProntuario() const; // método para obter o prontuário do paciente
    Prontuario& getProntuario(); // versão não-const para permitir modificações

    void exibirDados() const override; // sobrescrita do método exibirDados da classe Pessoa
};


#endif