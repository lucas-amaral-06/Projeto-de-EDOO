#ifndef MEDICO_HPP
#define MEDICO_HPP

#include "Pessoa.hpp"

class Medico : public Pessoa
{
  private:
    string crm;
    string especialidade;

  public:
    Medico(const string& nome, const int& idade, const string& cpf, const string& dataNascimento, const string& genero, const string& telefone, const string& crm, const string& especialidade);

    ~Medico() override;

    string getCRM() const;
    string getEspecialidade() const;

    void setEspecialidade(const string& especialidade);
    void exibirDados() const override;
};

#endif