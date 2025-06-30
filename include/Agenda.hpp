#ifndef AGENDA_HPP
#define AGENDA_HPP

#include <vector>
#include "Consulta.hpp"
using namespace std;

class Agenda {
private:
  vector<Consulta> listaDeConsultas;

public:
  void adicionarConsulta(const Consulta& novaConsulta);

  void exibir() const;

  const vector<Consulta>& getConsultas() const;
};

#endif