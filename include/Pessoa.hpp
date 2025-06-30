#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
using namespace std;

class Pessoa
{
  private:
    string nome;
    int idade;
    string cpf;
    string dataNascimento;
    string genero;
    string telefone;

  public:
    Pessoa(const string& nome, const int& idade, const string& cpf, const string& dataNascimento, const string& genero, const string& telefone);

    virtual ~Pessoa();

    string getNome() const;
    int getIdade() const;
    string getCPF() const;
    string getDataNascimento() const;
    string getGenero() const;
    string getTelefone() const;

    void setNome(const string& nome);
    void setIdade(const int& idade);
    void setTelefone(const string& telefone);

    virtual void exibirDados() const;
};

#endif