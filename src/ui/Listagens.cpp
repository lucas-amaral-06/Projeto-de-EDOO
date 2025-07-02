#include "ui/Listagens.hpp"
#include "ui/Menu.hpp"
#include <iostream>
#include "utils.hpp"

using namespace std;

namespace ListagensUI {
  void listarMedicos(const InMemoryDB& db) {

    clearScreen();
    MenuUI::exibirBanner();

    cout << "\n--- Lista de Médicos Cadastrados ---\n";

    if(db.medicosDB.empty()) {
      cout << "Nenhum médico cadastrado." << endl;
    }else{
      for (const auto& medico : db.medicosDB) {
        cout << "\n----------------------------------------\n\n";
        medico.exibirDados();
      }

      cout << "\n----------------------------------------\n\n";
    }

  }

  void listarRecepcionistas(const InMemoryDB& db) {

      clearScreen();
      MenuUI::exibirBanner();

      cout << "\n--- LISTA DE RECEPCIONISTAS CADASTRADOS ---\n";

      if(db.recepcionistasDB.empty()) {
          cout << "Nenhum recepcionista cadastrado no sistema." << endl;
      } else {
          cout << "\nTotal de recepcionistas: " << db.recepcionistasDB.size() << "\n" << endl;
          
          for (const auto& recepcionista : db.recepcionistasDB) {
              cout << "========================================" << endl;
              recepcionista.exibirDados();
              // Mostra apenas informações básicas de segurança
              cout << "Turno: " << recepcionista.getTurno() << endl;
              cout << "Código de Acesso: " << recepcionista.getCodigoAcesso() << endl;
              // Não mostra a senha por segurança
          }
          cout << "========================================" << endl;
      }

      cout << "\nPressione Enter para voltar...";
      cin.ignore();
      cin.get();
  }
}