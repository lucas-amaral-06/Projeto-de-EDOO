#include "ui/Listagens.hpp"
#include <iostream>
using namespace std;

namespace ListagensUI {
  void listarMedicos(const InMemoryDB& db) {

    #ifdef _WIN32
      system('cls');
    #else
      system("clear");
    #endif

    cout << "\n--- Lista de Médicos Cadastrados ---" << endl;

    if(db.medicosDB.empty()) {
      cout << "Nenhum médico cadastrado." << endl;
      return;
    }

    for (const auto& medico : db.medicosDB) {
      cout << "----------------------------------------" << endl;
      medico.exibirDados();
    }
    cout << "----------------------------------------" << endl;
  }

  void listarPacientes(const InMemoryDB& db) {
    
    #ifdef _WIN32
      system('cls');
    #else
      system("clear");
    #endif

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