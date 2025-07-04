#include "ui/Login.hpp"
#include "utils.hpp" 
using namespace std;
#include "ui/Menu.hpp"
#include "ui/PortalMedico.hpp"
#include "ui/PortalRecepcionista.hpp"


namespace Login 
{
  void login(InMemoryDB& db){
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

  void loginRecepcionista(InMemoryDB& db){
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
            PortalRecepcionistaUI::fluxoRecepcionista(*recepcionistaLogin, db);
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

  void loginMedico(InMemoryDB& db){
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
            PortalMedicoUI::fluxoMedico(*medicoLogin, db);
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
}