#include "ui/Menu.hpp"
#include <iostream>
#include <limits> // Validação de entrada
#include "utils.hpp"

using namespace std;

namespace MenuUI {
  void exibirBanner(){
    cout << "=================================================" << endl;
    cout << "||                                             ||" << endl;
    cout << "||                   SysMed C++                ||" << endl;
    cout << "||                                             ||" << endl;
    cout << "=================================================" << endl;
  }

  int exibirMenuInicial(){
    int escolha = 0;

    while (true) {
      exibirBanner();
      cout << "\nSeja bem-vindo(a)!" << endl;
      cout << "Por favor, escolha uma opção:" << endl;
      cout << "1. Login" << endl;
      cout << "2. Registrar-se" << endl;
      cout << "3. Ver cadastros" << endl;
      cout << "4. Sair" << endl;
      cout << "\nSua escolha: " << endl;

      cin >> escolha;

      // Tratamento de erro se o user nao digitar um número
      if (cin.fail()) {
        cout << "\nERRO: Por favor, digite apenas números." << endl;
        cin.clear(); // Limpa o estado de erro
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        escolha = 0;
      } else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (escolha >= 1 && escolha <= 4) {
          return escolha;
        } else {
          cout << "\nERRO: Opção inválida. Escolha entre 1 e 4." << endl;
        }
      } 

      cout << "Pressione Enter para continuar";
      cin.get();

      clearScreen();

    }
  }

  int exibirMenuRegistro(){
    int escolha = 0;

    while (true) {
      clearScreen();

      cout << "\n--- Menu de Registro ---" << endl;
      cout << "Você deseja registrar um novo:" << endl;
      cout << "1. Paciente" << endl;
      cout << "2. Médico" << endl;
      cout << "3. Voltar ao Menu Principal" << endl;
      cout << "\nSua escolha:" << endl;

      cin >> escolha;

      if (cin.fail()){
        cout << "\nERRO: Por favor, digite apenas números." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Pressione Enter para tentar novamente..." << endl;
        cin.get();
      } else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(escolha >= 1 && escolha <= 3) {
          return escolha;
        } else {
          cout << "\nERRO: Opção inválida. Escolha entre 1 e 3." << endl;
          cout << "Pressione Enter para tentar novamente..." << endl;
          cin.get();
        }
      }
    }
  }

  int exibirMenuListagens(){
    int escolha = 0;

    while (true) {
      clearScreen();

      cout << "\n--- Menu de Visualização ---" << endl;
      cout << "Você deseja listar:" << endl;
      cout << "1. Pacientes" << endl;
      cout << "2. Médicos" << endl;
      cout << "3. Voltar ao Menu Principal" << endl;
      cout << "\nSua escolha:" << endl;

      cin >> escolha;

      if (cin.fail()) {
        cout << "\nERRO: Por favor, digite apenas números." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Pressione Enter para tentar novamente..." << endl;
        cin.get();
      } else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(escolha >= 1 && escolha <= 3) {
          return escolha;
        } else {
          cout << "\nERRO: Opção inválida. Escolha entre 1 e 3." << endl;
          cout << "Pressione Enter para tentar novamente..." << endl;
          cin.get();
        }
      }
    }
  }
}
