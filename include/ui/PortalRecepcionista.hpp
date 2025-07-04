#ifndef PORTALRECEPCIONISTA_HPP
#define PORTALRECEPCIONISTA_HPP

#include "db/InMemoryDB.hpp"
#include "Recepcionista.hpp"

namespace PortalRecepcionistaUI {
  // Exibe o menu principal do recepcionista
  void fluxoRecepcionista(Recepcionista& recepcionista, InMemoryDB& db);

  // Agenda uma nova consulta
  void agendarNovaConsulta(InMemoryDB& db);
}

#endif