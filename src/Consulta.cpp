#include "Consulta.hpp"
#include "Paciente.hpp"
#include "Medico.hpp"

Consulta::Consulta(const Paciente* pac, const Medico* med, const string& data)
{
  this->paciente = pac;
  this->medico = med;
  this->dataHora = data;
  this->status = "Agendada";
}

void Consulta::exibir() const 
{
  cout << "Data: " << dataHora
  << " | Paciente: " << paciente->getNome()
  << " | Médico: " << medico->getNome()
  << " (" << medico->getEspecialidade() << ")"
  << " | Status: " << status << endl;
}

string Consulta::getCPFPaciente() const 
{
  return paciente->getCPF();
}

string Consulta::getCRMMedico() const 
{
  return medico->getCRM();
}