#include "ui/Listagens.hpp"
#include "ui/Menu.hpp"
#include <iostream>
#include "utils.hpp"

using namespace std;

namespace ListagensUI {
  void fluxoDeListagens(InMemoryDB &db){
    int escolha = MenuUI::exibirMenuListagens();

  switch (escolha) {
    case 1:
      listarMedicos(db);
      break;
    case 2:
      listarRecepcionistas(db);
      break;
    case 3:
      break;
  }

  if (escolha != 3) {
    cout << "Pressione Enter para continuar... ";
    cin.get();
  }
  }

  void listarMedicos(const InMemoryDB& db) {

    clearScreen();
    MenuUI::exibirBanner();

    cout << "\n--- MÉDICOS CADASTRADOS ---\n";

    if(db.medicosDB.empty()) {
      cout << "Nenhum médico cadastrado." << endl;
    }else{
      for (const auto& medico : db.medicosDB) {
        cout << "\n\n\n";
        medico->exibirDados();
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

  void listarPacientes(const InMemoryDB& db) {
    cout << "\n--- Lista de Pacientes Cadastrados ---" << endl;

    if(db.pacientesDB.empty()) {
      cout << "Nenhum paciente cadastrado." << endl;
      return;
    }

    for (const auto& paciente : db.pacientesDB) {
      cout << "----------------------------------------" << endl;
      paciente.exibirDados();
    }
    cout << "----------------------------------------" << endl;
  }
}