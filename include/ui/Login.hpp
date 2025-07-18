#ifndef LOGIN_HPP
#define LOGIN_HPP

#include "../db/InMemoryDB.hpp"

namespace Login 
{ 
  // Função para login de recepcionista
  void loginRecepcionista(InMemoryDB& db);

  // Função para login do médico
  void loginMedico(InMemoryDB& db);

  // Função o fluxo do menu login
  void login(InMemoryDB& db);
}

#endif