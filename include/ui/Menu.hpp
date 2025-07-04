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

  int exibirMenuLogin();
}

#endif