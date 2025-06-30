#include "Documentos.hpp"
#include "Medico.hpp"
#include <iostream>
using namespace std;

DocumentoClinico::DocumentoClinico(const string& data, const Medico* medico)
{
  this->data = data;
  this->medicoResponsavel = medico;
}

DocumentoClinico::~DocumentoClinico() {}

string DocumentoClinico::getData() const
{
  return data;
}

const Medico* DocumentoClinico::getMedicoResponsavel() const
{
  return medicoResponsavel;
}

// --- Classes Derivadas ---
// -- Evolução --

Evolucao::Evolucao(const string& data, const Medico* medico, const string& descricao): DocumentoClinico(data, medico)
{
  this->descricao = descricao;
}

void Evolucao::exibir() const {
  cout << "\n--- Evolução Clínica ---" << endl;
  cout << "Data: " << getData() << endl;
  cout << "Médico: " << getMedicoResponsavel()->getNome() << " (CRM: " << getMedicoResponsavel()->getCRM() << ")" << endl;
  cout << "Descrição: " << descricao << endl;
}

// -- Atestado --
Atestado::Atestado(const string& data, const Medico* medico, const int& dias, const string& motivo): DocumentoClinico(data, medico)
{
  this->diasDeAfastamento = dias;
  this->motivo = motivo;
}

void Atestado::exibir() const {
  cout << "\n--- Atestado Médico ---" << endl;
  cout << "Data: " << getData() << endl;
  cout << "Médico: " << getMedicoResponsavel()->getNome() << " (CRM: " << getMedicoResponsavel()->getCRM() << ")" << endl;
  cout << "Motivo: " << motivo << endl;
  cout << "Dias de Afastamento: " << diasDeAfastamento << endl;
}

// -- Receita --
Receita::Receita(const string& data, const Medico* medico, const vector<string>& medicamentos): DocumentoClinico(data, medico)
{
  this->medicamentos = medicamentos;
}

void Receita::exibir() const {
  cout << "\n--- Receita Médica ---" << endl;
  cout << "Data: " << getData() << endl;
  cout << "Médico: " << getMedicoResponsavel()->getNome() << " (CRM: " << getMedicoResponsavel()->getCRM() << ")" << endl;
  cout << "Medicamentos Prescritos:" << endl;
  for (const auto& medicamento : medicamentos) {
    cout << "- " << medicamento << endl;
  }
}
