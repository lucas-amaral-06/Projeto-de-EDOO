#include "ui/Menu.hpp"
#include <iostream>
#include <limits>
#include "utils.hpp"

using namespace std;

namespace MenuUI {
    void exibirBanner(){
        cout << "=================================================" << endl;
        cout << "||                                             ||" << endl;
        cout << "||              SysMed++                       ||" << endl;
        cout << "||        Sistema de Atendimento Médico        ||" << endl;
        cout << "||                                             ||" << endl;
        cout << "=================================================" << endl;
    }

    int exibirMenuInicial(){

        exibirBanner();
        cout << "\n--- MENU INICIAL ---\n";
        int escolha = 0;

        while (true) {

            cout << "\n1. Login" << endl;
            cout << "2. Registrar-se" << endl;
            cout << "3. Ver cadastros" << endl;
            cout << "4. Sair\n\n";
            cout << "Sua escolha: ";

            cin >> escolha;

            if (cin.fail()) {
                cout << "\nERRO: Por favor, digite apenas números." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                escolha = 0;
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                if (escolha >= 1 && escolha <= 4) {
                    return escolha;
                } else {
                    cout << "\nERRO: Opção inválida. Escolha um número de 1 a 4." << endl;
                }
            } 

            cout << "Pressione Enter para continuar";
            cin.get();
            clearScreen();
        }
    }

    int exibirMenuPrincipal(string tipoUsuario){
        int escolha = 0;
        string menuTitle = (tipoUsuario == "MEDICO") ? "MENU MÉDICO" : "MENU RECEPCIONISTA";

        while (true) {
            clearScreen();
            exibirBanner();
            cout << "\n" << menuTitle << "\n\n";
            
            // Opções comuns
            cout << "1. Ver meus dados" << endl;
            
            // Opções específicas
            if (tipoUsuario == "MEDICO") {
                cout << "2. Visualizar prontuários" << endl;
                cout << "3. Registrar evolução" << endl;
            } else { // Recepcionista
                cout << "2. Cadastrar novo paciente" << endl;
                cout << "3. Agendar consulta" << endl;
                cout << "4. Listar pacientes" << endl;
            }
            
            cout << "9. Sair\n\n";
            cout << "Sua escolha: ";

            cin >> escolha;

            if (cin.fail()) {
                cout << "\nERRO: Digite apenas números." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
                // Validação dinâmica baseada no tipo de usuário
                bool escolhaValida = (tipoUsuario == "MEDICO") 
                    ? (escolha >=1 && escolha <=3) || escolha ==9
                    : (escolha >=1 && escolha <=4) || escolha ==9;
                
                if (escolhaValida) {
                    return escolha;
                } else {
                    cout << "\nERRO: Opção inválida." << endl;
                }
            }

            cout << "Pressione Enter para continuar";
            cin.get();
        }
    }

    int exibirMenuListagens() {
      int escolha = 0;

      while (true) {
        clearScreen();
        exibirBanner();
        
        cout << "\n--- LISTAGEM DE CADASTROS ---\n\n";
        cout << "1. Listar médicos" << endl;
        cout << "2. Listar recepcionistas" << endl;
        cout << "3. Voltar ao menu anterior\n\n";
        cout << "Sua escolha: ";

        cin >> escolha;

        if (cin.fail()) {
            cout << "\nERRO: Por favor, digite apenas números." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Pressione Enter para tentar novamente...";
            cin.get();
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (escolha >= 1 && escolha <= 3) {
                return escolha;
            } else {
                cout << "\nERRO: Opção inválida. Escolha entre 1 e 3." << endl;
                cout << "Pressione Enter para tentar novamente...";
                cin.get();
            }
        }
      }
    }

    int exibirMenuRegistro() {


    }
}