#ifndef CONSULTA_HPP
#define CONSULTA_HPP

#include <string>
#include <iostream>
using namespace std;

class Paciente; // Forward declaration
class Medico; // Forward declaration

class Consulta 
{
private:
  const Paciente* paciente;
  const Medico* medico;
  string dataHora;
  string status; // "Agendada", "Realizada", "Cancelada"

public:
  Consulta(const Paciente* pac, const Medico* med, const string& data);

  void exibir() const;

  string getCPFPaciente() const;
  string getCRMMedico() const;
};

#endif