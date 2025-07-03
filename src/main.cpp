#include <iostream>
#include <vector>
#include <limits> // Necessário para a nova função de login
#include "ui/Menu.hpp"
#include "ui/Auth.hpp"
#include "ui/Listagens.hpp"
#include "db/InMemoryDB.hpp"
#include "utils.hpp" 

using namespace std;

// --- FUNÇÕES DE LOGIN (LÓGICA COMBINADA) ---

// Função para login de recepcionista (vinda da versão do GitHub)
void loginRecepcionista(InMemoryDB& db) {
  while(true) {
    clearScreen();
    MenuUI::exibirBanner();
    cout << "\n--- LOGIN RECEPCIONISTA ---\n\n";
    
    cout << "Digite seu CPF (XXX.XXX.XXX-XX) ou '0' para voltar: ";
    string cpf;
    getline(cin, cpf);

    // Opção para sair
    if (cpf == "0") {
        return;

    }

    //Caso não respeite o formato do CPF, pede novamente
    else if (!(validarCPF(cpf))){
      cout << "\nERRO: Por favor, respeite o formato do CPF." << endl;
      cout << "Pressione Enter para continuar... ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } 
    
    //Caso respeite o formato do CPF, verificamos se ele está cadastrado
    else {
      
      Recepcionista* recepcionistaLogin = db.buscarRecepcionistaPorCPF(cpf);
      
      if(!recepcionistaLogin) {
          cout << "\nERRO: Recepcionista com CPF " << cpf << " não cadastrado.\n";
          cout << "Pressione Enter para continuar... ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } 
      
      // Se está cadastrado
      else {

        // Solicitar senha
        cout << "Digite sua senha ou '0' para voltar: ";
        string senha;
        getline(cin, senha);

        // Verificar se o usuário quer voltar
        if (senha == "0"){
          return;
        }

        // Se for a senha correta
        else if (senha == recepcionistaLogin->getSenha()) {
          
          // Verifica o código de acesso

          cout << "Digite seu código de acesso ou '0' para voltar: ";
          string codigoAcesso;
          getline(cin, codigoAcesso);

          // Verificar se o usuário quer voltar

          if (codigoAcesso == "0"){
            return;
          }

          // Se for o código de acesso correto

          if(codigoAcesso == recepcionistaLogin->getCodigoAcesso()) {

            cout << "\nLogin realizado com sucesso! Bem-vindo(a), " 
                  << recepcionistaLogin->getNome() << "!\n";
            
            // Futuramente, aqui entrará o menu do recepcionista
            cout << "Pressione Enter para continuar...";
            cin.get();
            return;
          } else {
              cout << "\nERRO: Código de acesso incorreto.\n";
              cout << "Pressione Enter para tentar novamente..s.";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
          }
                      
        } else {
            cout << "\nERRO: Senha incorreta.\n";
            cout << "Pressione Enter para tentar novamente... ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
      }
    }
  }
}

// Função para login do médico
void loginMedico(InMemoryDB& db) {
  while(true) {
    clearScreen();
    MenuUI::exibirBanner();
    cout << "\n--- LOGIN MÉDICO ---\n\n";
    
    cout << "Digite seu CRM (CRM/XX XXXXX) ou '0' para voltar: ";
    string crm;
    getline(cin, crm);

    // Opção para sair
    if (crm == "0") {
      return;
    }
    // Validação do formato do CRM
    else if (!validarCRM(crm)) {
      cout << "\nERRO: Por favor, respeite o formato do CRM (CRM/XX XXXXX)." << endl;
      cout << "Pressione Enter para continuar... ";
      cin.get();
    } 
    // Verificação se está cadastrado
    else {
      Medico* medicoLogin = db.buscarMedicoPorCRM(crm);
      
      if(!medicoLogin) {
          cout << "\nERRO: Médico com CRM " << crm << " não cadastrado.\n";
          cout << "Pressione Enter para continuar... ";
          cin.get();
      } 
      // Se está cadastrado
      else {
        // Solicitar senha
        cout << "Digite sua senha ou '0' para voltar: ";
        string senha;
        getline(cin, senha);

        // Verificar se o usuário quer voltar
        if (senha == "0") {
            return;
        }
        // Verificar senha
        else if (senha == medicoLogin->getSenha()) {
          
          menuMédico(medicoLogin);

          return;
        } 
        else {
          cout << "\nERRO: Senha incorreta.\n";
          cout << "Pressione Enter para tentar novamente... ";
          cin.get();
        }
      }
    }
  }
}

// Menu principal de Login (lógica do GitHub)
void login(InMemoryDB& db) {
  // Nota: Esta função depende da criação de 'exibirMenuLogin' em Menu.cpp
  int escolha = MenuUI::exibirMenuLogin(); 

  switch (escolha) {
      case 1:
          loginMedico(db);
          break;
      case 2:
          loginRecepcionista(db);
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
    // Você precisará adicionar o comando para corrigir a acentuação aqui
    // Ex: SetConsoleOutputCP(CP_UTF8); no Windows

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