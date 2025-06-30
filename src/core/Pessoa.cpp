#include "Pessoa.hpp"
#include <iostream>
using namespace std;

Pessoa::Pessoa(const string& nome, const int& idade, const string& cpf, const string& dataNascimento, const string& genero, const string& telefone)
{
  this->nome = nome;
  this->idade = idade;
  this->cpf = cpf;
  this->dataNascimento = dataNascimento;
  this->genero = genero;
  this->telefone = telefone;
}

Pessoa::~Pessoa() {}

string Pessoa::getNome() const
{
  return this->nome;
}

int Pessoa::getIdade() const
{
  return this->idade;
}

string Pessoa::getCPF() const
{
  return this->cpf;
}

string Pessoa::getDataNascimento() const
{
  return this->dataNascimento;
}

string Pessoa::getGenero() const
{
  return this->genero;
}

string Pessoa::getTelefone() const
{
  return this->telefone;
}

void Pessoa::setNome(const string& nome)
{
  this->nome = nome;
}

void Pessoa::setIdade(const int& idade)
{
  this->idade = idade;
}

void Pessoa::setTelefone(const string& telefone)
{
  this->telefone = telefone;
}

void Pessoa::exibirDados() const
{
  cout << "Nome: " << this->nome << endl;
  cout << "Idade: " << this->idade << endl;
  cout << "CPF: " << this->cpf << endl;
  cout << "Data de Nascimento: " << this->dataNascimento << endl;
  cout << "Gênero: " << this->genero << endl;
  cout << "Telefone: " << this->telefone << endl;
}