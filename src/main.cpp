#include <iostream>
#include <vector>
#include <limits> // Necessário para a nova função de login
#include "ui/Menu.hpp"
#include "ui/Auth.hpp"
#include "ui/Listagens.hpp"
#include "db/InMemoryDB.hpp"
#include "utils.hpp" 
#include "ui/Login.hpp"

using namespace std;

int main() {
  clearScreen();
  MenuUI::exibirBanner();

  InMemoryDB db; // Inicializa o banco de dados em memória

  cout << "\nPressione Enter para iniciar o sistema... ";
  cin.get();

  bool executando = true;
  while (executando) {
    clearScreen();
    int escolha = MenuUI::exibirMenuInicial();

    switch (escolha) {
      case 1:
        Login::login(db);
        break;
      case 2:
        Auth::fluxoDeRegistro(db);
        break;
      case 3:
        ListagensUI::fluxoDeListagens(db);
        break;
      case 4:
        cout << "\nObrigado por usar o SysMed C++. Até logo!" << endl;
        executando = false;
        break;
    }
  }
  return 0;
}