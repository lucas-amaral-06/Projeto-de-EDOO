#ifndef AUTH_HPP
#define AUTH_HPP

#include <vector>
#include "Paciente.hpp"
#include "Medico.hpp"
using namespace std;

namespace Auth {
  // Função para registrar pacientes, passamos a referência do vetor que atua como nosso DB inline para modificá-lo
  void registrarPaciente(vector<Paciente>& db);
  
  // Função para registrar médicos, passamos a referência do vetor que atua como nosso DB inline para modificá-lo
  void registrarMedico(vector<Medico>& db);
}

#endif