#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>
#include "Pessoa.hpp"
using namespace std;

class Prontuario; // declaração antecipada da classe Prontuario para evitar dependências circulares

class Paciente : public Pessoa
{
  private:  
    Prontuario* prontuario; // ponteiro para o prontuário do paciente

  public:
    Paciente(const string& nome, const int& idade, const string& cpf, const string& dataNascimento, const string& genero, const string& telefone);

    ~Paciente() override; // destrutor virtual para garantir a destruição correta do prontuário

    Prontuario* getProntuario() const; // método para obter o prontuário do paciente

    void exibirDados() const override; // sobrescrita do método exibirDados da classe Pessoa
};


#endif