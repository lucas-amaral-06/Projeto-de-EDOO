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
// Menu principal de Login (lógica do GitHub)
void login(InMemoryDB& db) {
  // Nota: Esta função depende da criação de 'exibirMenuLogin' em Menu.cpp
  int escolha = MenuUI::exibirMenuLogin(); 

  switch (escolha) {
      case 1:
          Login::loginMedico(db);
          break;
      case 2:
          Login::loginRecepcionista(db);
          break;
      case 3: // Voltar
          break;
  }
}


// --- FLUXOS DE TELAS (LÓGICA DA SUA VERSÃO LOCAL) ---

void fluxoDeListagens(InMemoryDB &db) {
    int escolha = MenuUI::exibirMenuListagens();

    switch (escolha) {
        case 1:
            ListagensUI::listarMedicos(db);
            break;
        case 2:
            ListagensUI::listarRecepcionistas(db);
            break;
        case 3:
            break;
    }

    if (escolha != 3) {
        cout << "Pressione Enter para continuar... ";
        cin.get();
    }
}

void fluxoDeRegistro(InMemoryDB &db) {
    int escolha = MenuUI::exibirMenuRegistro();

    clearScreen();
    MenuUI::exibirBanner();

    switch (escolha) {
        case 1: // Alterado para corresponder ao novo Menu.cpp (Recepcionista)
            Auth::registrarRecepcionista(db.recepcionistasDB);
            break;
        case 2: // Alterado para corresponder ao novo Menu.cpp (Médico)
            Auth::registrarMedico(db.medicosDB);
            break;
        case 3:
            cout << "Retornando ao menu inicial..." << endl;
            break;
    }

    if (escolha != 3) {
        cout << "Pressione Enter para continuar... ";
        cin.get();
    }
}


// --- FUNÇÃO MAIN ---

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
                login(db);
                break;
            case 2:
                fluxoDeRegistro(db);
                break;
            case 3:
                fluxoDeListagens(db);
                break;
            case 4:
                cout << "\nObrigado por usar o SysMed C++. Até logo!" << endl;
                executando = false;
                break;
        }
    }
    return 0;
}