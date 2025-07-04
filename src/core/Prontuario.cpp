#include "Prontuario.hpp"
#include "Paciente.hpp"
#include <iostream>
using namespace std;

Prontuario::Prontuario(){
  this->numero = "PRONT-0000"; // Número padrão
  this->dataCriacao = "01/01/1999"; // Data padrão
  this->pacienteCPF = "123.456.789-10"; // CPF do paciente vazio
}

Prontuario::Prontuario(Paciente& paciente) {
  this->pacienteCPF = paciente.getCPF(); // Obtém o CPF do paciente
  this->numero = "PRONT-" + to_string(rand() % 10000);
  
  time_t now = time(0);
  tm* tempoLocal = localtime(&now);
  
  this->dataCriacao = to_string(tempoLocal->tm_mday) + "/" + to_string(tempoLocal->tm_mon + 1) + "/" + to_string(tempoLocal->tm_year + 1900);
}

Prontuario::~Prontuario() {}

void Prontuario::adicionarEvolucao(const Evolucao& evolucao) {
  this->historicoEvolucoes.push_back(evolucao);
}

void Prontuario::adicionarReceita(const Receita& receita) {
  this->listaReceitas.push_back(receita);
}

void Prontuario::adicionarAtestado(const Atestado& atestado) {
  this->listaAtestados.push_back(atestado);
}

string Prontuario::getNumero() const {
  return this->numero;
}

void Prontuario::exibirResumo() const {
  cout << "\n=============================================" << endl;
  cout << "RESUMO DO PRONTUÁRIO" << endl;
  cout << "=============================================" << endl;
  cout << "Número: " << this->numero << endl;
  cout << "CPF do Paciente: " << this->pacienteCPF << endl;
  cout << "Data de Abertura: " << this->dataCriacao << endl;
  cout << "Registros: " << endl;
  cout << " - Evoluções: " << this->historicoEvolucoes.size() << endl;
  cout << " - Receitas: " << this->listaReceitas.size() << endl;
  cout << " - Atestados: " << this->listaAtestados.size() << endl;
  cout << "=============================================" << endl;
}

void Prontuario::exibirHistorico() const 
{
  exibirResumo();
  if (historicoEvolucoes.empty() && listaReceitas.empty() && listaAtestados.empty()) 
  {
    cout << "\nNenhum documento registrado neste prontuário." << endl;
    return;
  }
  
  for (const auto& evolucao : historicoEvolucoes) 
  {
    evolucao.exibir();
  }

  for (const auto& receita : listaReceitas) 
  {
    receita.exibir();
  }

  for (const auto& atestado : listaAtestados) 
  {
    atestado.exibir();
  }
  cout << "\n--- Fim do Prontuário ---" << endl;
}