#include "Agenda.hpp"
#include "Consulta.hpp"
#include <iostream>
using namespace std;

void Agenda::adicionarConsulta(const Consulta& novaConsulta) 
{
  listaDeConsultas.push_back(novaConsulta);
  cout << "INFO: Consulta agendada com sucesso!" << endl;
}

void Agenda::exibir() const 
{
  if (listaDeConsultas.empty()) {
    cout << "INFO: Não há consultas agendadas." << endl;
    return;
  }

  cout << "Lista de Consultas:" << endl;
  for (const auto& consulta : listaDeConsultas) {
    consulta.exibir();
  }
}

const vector<Consulta>& Agenda::getConsultas() const 
{
  return listaDeConsultas;
}