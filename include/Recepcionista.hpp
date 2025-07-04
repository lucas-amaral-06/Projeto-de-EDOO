#ifndef RECEPCIONISTA_HPP
#define RECEPCIONISTA_HPP

#include "Pessoa.hpp"
#include <string>

class Recepcionista : public Pessoa
{
  private:
    string senha;  // Senha para autenticação
    string turno;  // Turno de trabalho (ex: "manhã", "tarde", "noite")
    string codigoAcesso;  // Código interno do recepcionista

  public:
    Recepcionista(const string& nome, const string& cpf, const string& dataNascimento, const string& genero, const string& telefone, const string& senha, const string& turno, const string& codigoAcesso);

    ~Recepcionista() override;

    // Getters
    string getSenha() const;
    string getTurno() const;
    string getCodigoAcesso() const;

    // Setters
    void setSenha(const string& novaSenha);
    void setTurno(const string& novoTurno);

    void exibirDados() const override;
};

#endif