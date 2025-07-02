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

        if (cpf == "0") return;

        if (!validarCPF(cpf)) { // Usando a função de validação de utils.hpp
            cout << "\nPressione Enter para continuar... ";
            cin.get();
            continue; // Volta ao início do loop
        }
        
        Recepcionista* recepcionistaLogin = db.buscarRecepcionistaPorCPF(cpf);
        
        if(!recepcionistaLogin) {
            cout << "\nERRO: Recepcionista com CPF " << cpf << " não cadastrado.\n";
            cout << "Pressione Enter para continuar... ";
            cin.get();
        } else {
            cout << "Digite seu código de acesso: ";
            string codigoAcesso;
            getline(cin, codigoAcesso);

            if(recepcionistaLogin->getCodigoAcesso() == codigoAcesso) {
                cout << "\nLogin realizado com sucesso! Bem-vindo(a), " 
                     << recepcionistaLogin->getNome() << "!\n";
                cout << "Turno: " << recepcionistaLogin->getTurno() << "\n\n";
                
                // Futuramente, aqui entrará o menu do recepcionista
                cout << "Pressione Enter para continuar...";
                cin.get();
                return;
            } else {
                cout << "\nERRO: Código de acesso incorreto.\n";
            }
            cout << "\nPressione Enter para tentar novamente...";
            cin.get();
        }
    }
}

// Função para login de paciente (adaptada da sua versão local)
void loginPaciente(InMemoryDB& db) {
    clearScreen();
    MenuUI::exibirBanner();
    cout << "\n--- LOGIN PACIENTE ---\n\n";
    cout << "Digite seu CPF (ex: XXX.XXX.XXX-XX): ";
    string cpf;
    getline(cin, cpf);

    if (!validarCPF(cpf)) {
        cout << "\nPressione Enter para continuar..." << endl;
        cin.get();
        return;
    }

    Paciente *pacienteLogin = db.buscarPacientePorCPF(cpf);

    if (pacienteLogin) {
        cout << "\nLogin realizado com sucesso! Bem vindo(a), " << pacienteLogin->getNome() << "!" << endl;
    } else {
        cout << "\nERRO: Paciente com CPF " << cpf << " não encontrado." << endl;
    }
    cout << "Pressione Enter para continuar..." << endl;
    cin.get();
}

// Menu principal de Login (lógica do GitHub)
void login(InMemoryDB& db) {
    // Nota: Esta função depende da criação de 'exibirMenuLogin' em Menu.cpp
    int escolha = MenuUI::exibirMenuLogin(); 

    switch (escolha) {
        case 1:
            loginPaciente(db);
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
        cout << "Pressione Enter para continuar..." << endl;
        cin.get();
    }
}


// --- FUNÇÃO MAIN ---

int main() {
    clearScreen();
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