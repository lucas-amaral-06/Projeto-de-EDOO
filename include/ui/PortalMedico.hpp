#ifndef PORTAL_MEDICO_HPP
#define PORTAL_MEDICO_HPP

#include "db/InMemoryDB.hpp"
#include "Medico.hpp"

class Paciente; // Forward declaration

namespace PortalMedicoUI {
  // Função que executa o fluxo principal do portal do médico Recebe o médico logado e o banco de dados em memória
  void fluxoMedico(Medico& medico, InMemoryDB& db);

  // Funções auxiliares para o portal do médico
  
  // Encontra um paciente para atendimento, retorna um ponteiro para o paciente ou nullptr se não encontrado
  Paciente* encontrarPacienteParaAtendimento(InMemoryDB& db);

  // Lista os agendamentos do médico
  void listarAgendamentos(const Medico& medico);

  // Acessa o prontuário de um paciente, recebe o banco de dados em memória e exibe o histórico de atendimentos do paciente
  void acessarProntuarioDePaciente(InMemoryDB& db);

  // Lista os documentos emitidos pelo médico, recebe o tipo de documento (evolução, receita, atestado)
  void listarDocumentosDoMedico(const Medico& medico, const InMemoryDB& db, const std::string& tipo);

  // Funções para criar novos documentos

  // Função que executa o fluxo principal da criação de documentos
  void fluxoCriarDocumento(Medico& medico, InMemoryDB& db);

  // Cria uma nova evolução clínica, recebe o médico e o banco de dados em memória
  void criarNovaEvolucao(Medico& medico, InMemoryDB& db);

  // Cria uma nova receita médica, recebe o médico e o banco de dados em memória
  void criarNovaReceita(Medico& medico, InMemoryDB& db);

  // Cria um novo atestado médico, recebe o médico e o banco de dados em memória
  void criarNovoAtestado(Medico& medico, InMemoryDB& db);
}

#endif