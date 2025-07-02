#include <iostream>
#include <vector>
#include "ui/Menu.hpp"
#include "ui/Auth.hpp"
#include "ui/Listagens.hpp"
#include "db/InMemoryDB.hpp"
#include "utils.hpp"

using namespace std;

void loginRecepcionista(InMemoryDB& db) {
  while(true) {
      clearScreen();
      MenuUI::exibirBanner();

      cout << "\n--- LOGIN RECEPCIONISTA ---\n\n";
      
      // Solicitar CPF
      cout << "Digite seu CPF (XXX.XXX.XXX-XX) ou '0' para voltar: ";
      string cpf;
      getline(cin, cpf);

      // Opção para sair
      if (cpf == "0") {
          return;
      //Caso não respeite o formato do CPF, pede novamente
      } else if (!(validarFormatoCPF(cpf))){
        cout << "\nERRO: Por favor, respeite o formato do CPF." << endl;
        cout << "Pressione Enter para continuar... ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      //Caso respeite, verificamos se o CPF está cadastrado
      } else {
        // Verificar se o CPF está cadastrado
        Recepcionista* recepcionistaLogin = db.buscarRecepcionistaPorCPF(cpf);
        
        // Se o CPF não está cadastrado
        if(!recepcionistaLogin) {

          cout << "\nERRO: Recepcionista com CPF " << cpf << " não cadastrado.\n";
          cout << "Pressione Enter para continuar... ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Se está cadastrado
        }else{

          // Solicitar senha
          cout << "Digite seu código de acesso: ";
          string codigoAcesso;
          getline(cin, codigoAcesso);

          // Verificar senha
          if(recepcionistaLogin->getCodigoAcesso() == codigoAcesso) {
              cout << "\nLogin realizado com sucesso! Bem-vindo(a), " 
                    << recepcionistaLogin->getNome() << "!\n";
              cout << "Turno: " << recepcionistaLogin->getTurno() << "\n\n";
              
              // Aqui você implementaria:
              // menuRecepcionista(*recepcionistaLogin, db);
              // return;
              
              cout << "Pressione Enter para continuar...";
              cin.ignore();
              return;
          } else {
              cout << "\nERRO: Código de acesso incorreto.\n";
          }

          cout << "\nPressione Enter para tentar novamente...";
          cin.ignore();
          
        }
      }
  }
}

void login(InMemoryDB& db) {

  clearScreen();

  int escolha = MenuUI::exibirMenuLogin();

  switch (escolha) {
    case 1:
      break;
    case 2:
      loginRecepcionista(db);
      break;
  }
  
}

void fluxoDeListagens(InMemoryDB& db) {

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

  if(escolha != 3) {
    cout << "Pressione Enter para continuar... ";
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
  MenuUI::exibirBanner();

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
        cout << "\nObrigado por usar o SysMed++. Até logo!" << endl;
        executando = false;
        break;
    }
  }
  return 0;
}