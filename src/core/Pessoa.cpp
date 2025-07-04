#include "Pessoa.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <chrono>
#include <iomanip>
using namespace std;

Pessoa::Pessoa(const string& nome, const string& cpf, const string& dataNascimento, const string& genero, const string& telefone)
{
  this->nome = nome;
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
  tm tmNascimento = {};
  stringstream ss(this->dataNascimento);
  ss >> get_time(&tmNascimento, "%d/%m/%Y");

  // Data atual (ajuste conforme necessário, aqui usa a data do sistema)
  time_t t = time(nullptr);
  tm tmHoje = *localtime(&t);

  int anos = tmHoje.tm_year + 1900 - (tmNascimento.tm_year + 1900);

  if ((tmHoje.tm_mon < tmNascimento.tm_mon) ||
      (tmHoje.tm_mon == tmNascimento.tm_mon && tmHoje.tm_mday < tmNascimento.tm_mday)) {
    anos--;
  }
  return anos;
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
  cout << "Idade: " << getIdade() << endl;
  cout << "CPF: " << this->cpf << endl;
  cout << "Data de Nascimento: " << this->dataNascimento << endl;
  cout << "Gênero: " << this->genero << endl;
  cout << "Telefone: " << this->telefone << endl;
}