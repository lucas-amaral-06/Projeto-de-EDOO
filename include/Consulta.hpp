#ifndef CONSULTA_HPP
#define CONSULTA_HPP

#include <string>
#include <iostream>
using namespace std;

class Paciente; // Forward declaration para evitar dependência circular já que com ponteiro não é necessário incluir o cabeçalho aqui
class Medico; // Forward declaration para evitar dependência circular já que com ponteiro não é necessário incluir o cabeçalho aqui

class Consulta 
{
private:
  const Paciente* paciente;
  const Medico* medico;
  string dataHora;
  string status; // "Agendada", "Realizada", "Cancelada"

public:
  // Construtor para inicializar uma consulta com paciente, médico e data/hora
  Consulta(const Paciente* pac, const Medico* med, const string& data);

  // Método para exibir os detalhes da consulta
  void exibir() const;

  // Getters
  string getCPFPaciente() const;
  string getCRMMedico() const;
};

#endif