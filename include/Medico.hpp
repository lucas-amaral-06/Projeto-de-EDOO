#ifndef MEDICO_HPP
#define MEDICO_HPP

#include "Pessoa.hpp"
#include <string>

class Medico : public Pessoa
{
private:
    string crm;
    string especialidade;
    string senha;
  
public:
    Medico(const string& nome, 
           const string& cpf, 
           const string& dataNascimento, 
           const string& genero, 
           const string& telefone,
           const string& crm, 
           const string& especialidade,
           const string& senha);

    ~Medico() override;

    // Getters
    string getCRM() const;
    string getEspecialidade() const;
    string getSenha() const;

    // Setters
    void setEspecialidade(const string& especialidade);
    void setSenha(const string& novaSenha);
    
    void exibirDados() const override;
};

#endif