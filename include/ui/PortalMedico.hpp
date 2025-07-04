#ifndef PORTAL_MEDICO_HPP
#define PORTAL_MEDICO_HPP

#include "db/InMemoryDB.hpp"
#include "Medico.hpp"

class Paciente; // Forward declaration

namespace PortalMedicoUI {
  void fluxoMedico(Medico& medico, InMemoryDB& db);

  Paciente* encontrarPacienteParaAtendimento(InMemoryDB& db);
  void listarAgendamentos(const Medico& medico);
  void acessarProntuarioDePaciente(InMemoryDB& db);
  void listarDocumentosDoMedico(const Medico& medico, const InMemoryDB& db, const std::string& tipo);
  void fluxoCriarDocumento(Medico& medico, InMemoryDB& db);
  void criarNovaEvolucao(Medico& medico, InMemoryDB& db);
  void criarNovaReceita(Medico& medico, InMemoryDB& db);
  void criarNovoAtestado(Medico& medico, InMemoryDB& db);
}

#endif