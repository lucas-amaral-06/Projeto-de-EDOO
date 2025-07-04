#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <limits>
#include "utils.hpp"

using namespace std;

namespace MenuUI {
  // Exibe o banner/logo da aplicação
  void exibirBanner();

  // Mostra o menu inicial e recebe a escolha do user.
  // @return 1 -> Entrar 2 -> Registrar, 3 -> Ver cadastros e 4 -> Sair
  int exibirMenuInicial();

  // @brief Exibe o menu para escolher quem registrar
  // @return 1 -> Paciente, 2 -> Médico e 3 -> Voltar)
  int exibirMenuRegistro();

  // @brief Exibe o menu de listagens
  // @return 1 -> Listar Pacientes, 2 -> Listar Médicos
  int exibirMenuListagens();

  // @brief Exibe o menu de login
  // @return 1 -> Login Recepcionista, 2 -> Login Médico, 3 -> Voltar
  int exibirMenuLogin();

  // @brief Exibe o menu principal do médico
  // @return 1 -> Meus Agendamentos, 2 -> Acessar Prontuário de Paciente, 3 -> Registrar Novo Documento, 4 -> Sair
  int exibirMenuMedico(const string& nomeMedico);

  // @brief Exibe o menu de criação de documentos
  // @return 1 -> Evolução Clínica, 2 -> Receita Médica, 3 -> Atestado Médico, 4 -> Voltar
  // @note O retorno é usado para identificar o tipo de documento a ser criado
  //       e o fluxo de criação
  //       de documentos é gerenciado no PortalMedico.cpp
  //       com o fluxoCriarDocumento
  //       que chama as funções específicas de criação de cada documento.
  int exibirMenuCriarDocumento();

  // @brief Exibe o menu principal do recepcionista
  // @return 1 -> Cadastrar Paciente, 2 -> Listar Pacientes
  // @return 3 -> Agendar Consulta, 4 -> Sair
  int exibirMenuRecepcionista(const string& nomeRecepcionista);
}

#endif