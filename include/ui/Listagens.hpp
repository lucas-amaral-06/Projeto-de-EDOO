#ifndef LISTAGENS_HPP
#define LISTAGENS_HPP

#include "db/InMemoryDB.hpp"

namespace ListagensUI {
  // Função do fluxo de listagem
  void fluxoDeListagens(InMemoryDB &db);

  // @brief Itera sobre o banco de dados e exibe os detalhes dos médicos.
  void listarMedicos(const InMemoryDB& db);

  // @brief Itera sobre o banco de dados e exibe os detalhes dos pacientes.
  void listarPacientes(const InMemoryDB& db);

  // @brief Itera sobre o banco de dados e exibe os detalhes dos recepcionistas.
  void listarRecepcionistas(const InMemoryDB& db);


  void listarConsultasPorMedico(Medico* medico, const InMemoryDB& db);
}


#endif