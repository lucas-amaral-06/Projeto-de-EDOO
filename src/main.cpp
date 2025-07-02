#include <iostream>
#include <vector>
#include "ui/Menu.hpp"
#include "ui/Auth.hpp"
#include "ui/Listagens.hpp"
#include "db/InMemoryDB.hpp"
#include "utils.hpp"

using namespace std;

void login(InMemoryDB& db) {

  clearScreen();
  
  cout << "\n--- Login no Sistema ---" << endl;
  cout << "Digite seu CPF (ex: XXX.XXX.XXX-XX): ";
  string cpf;
  getline(cin, cpf);

  Paciente* pacienteLogin = db.buscarPacientePorCPF(cpf);
  
  if(pacienteLogin) {
    cout << "\nLogin realizado com sucesso! Bem vindo(a), " << pacienteLogin->getNome() << "!" << endl;
  } else {
    cout << "\nERRO: Paciente com CPF " << cpf << " não encontrado."<< endl;
  }

  cout << "Pressione Enter para continuar..." << endl;
  cin.get();
}

void fluxoDeListagens(InMemoryDB& db) {
  int escolha = MenuUI::exibirMenuListagens();

  switch (escolha) {
    case 1:
      ListagensUI::listarPacientes(db);
      break;
    case 2:
      ListagensUI::listarMedicos(db);
      break;
    case 3:
      break;
  }

  if(escolha != 3) {
    cout << "Pressione Enter para continuar..." << endl;
    cin.get();
  }
}

void fluxoDeRegistro(InMemoryDB& db) {
  int escolha = MenuUI::exibirMenuRegistro();

  switch (escolha){
    case 1:
      Auth::registrarPaciente(db.pacientesDB);
      break;
    case 2:
      Auth::registrarMedico(db.medicosDB);  
      break;
    case 3:
      cout << "Retornando ao menu inicial..." << endl;
      break;
  }

  if(escolha != 3) {
    cout << "Pressione Enter para continuar..." << endl;
    cin.get();
  }
}

int main() {

  clearScreen();

  InMemoryDB db; // Inicializa o banco de dados em memória

  cout << "\nPressione Enter para continuar... ";
  cin.get();

  bool executando = true;
  while (executando){
    
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