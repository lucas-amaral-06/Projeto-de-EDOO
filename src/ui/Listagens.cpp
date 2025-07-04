#include "ui/Listagens.hpp"
#include "ui/Menu.hpp"
#include <iostream>
#include "utils.hpp"

using namespace std;

namespace ListagensUI {
  void listarMedicos(const InMemoryDB& db) {

    clearScreen();
    MenuUI::exibirBanner();

    cout << "\n--- MÉDICOS CADASTRADOS ---\n";

    if(db.medicosDB.empty()) {
      cout << "Nenhum médico cadastrado." << endl;
    }else{
      for (const auto& medico : db.medicosDB) {
        cout << "\n\n\n";
        medico.exibirDados();
      }

      cout << "\n\n\n";
    }

  }

  void listarRecepcionistas(const InMemoryDB& db) {
      clearScreen();
      MenuUI::exibirBanner();

      cout << "\n--- RECEPCIONISTAS CADASTRADOS ---\n";

      if(db.recepcionistasDB.empty()) {
          cout << "Nenhum recepcionista cadastrado." << endl;
      } else {
          for (const auto& recepcionista : db.recepcionistasDB) {
              cout << "\n\n\n";
              recepcionista.exibirDados();
          }
          cout << "\n\n\n";
      }
  }
}