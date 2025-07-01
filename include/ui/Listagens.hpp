#ifndef LISTAGENS_HPP
#define LISTAGENS_HPP

#include "db/InMemoryDB.hpp"

namespace ListagensUI {
  // @brief Itera sobre o banco de dados e exibe os detalhes dos médicos.
  void listarMedicos(const InMemoryDB& db);

  // @brief Itera sobre o banco de dados e exibe os detalhes dos pacientes.
  void listarPacientes(const InMemoryDB& db);
}

#endif