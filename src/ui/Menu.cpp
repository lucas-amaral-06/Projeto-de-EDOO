#include "ui/Menu.hpp"

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
		int escolha = 0;

		while (true) {
			clearScreen();
			exibirBanner();

			cout << "\n--- MENU DE REGISTRO ---\n\n";
			cout << "1. Novo Recepcionista" << endl;
			cout << "2. Novo Médico" << endl;
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

	int exibirMenuLogin() {
		int escolha = 0;

		while (true) {
			clearScreen();
			MenuUI::exibirBanner();

			cout << "\n--- LOGIN NO SISTEMA ---\n\n";
			cout << "1. Médico" << endl;
			cout << "2. Recepcionista" << endl;
			cout << "3. Voltar ao menu anterior\n\n";  // Nova opção adicionada
			cout << "Sua escolha: ";

			cin >> escolha;

			if (cin.fail()) {
				cout << "\nERRO: Por favor, digite apenas números." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			} else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				if (escolha >= 1 and escolha <= 3){
					return escolha;
				} else {
					cout << "\nERRO: Opção inválida. Escolha 1, 2 ou 3." << endl;  // Mensagem atualizada
				}
			}

		cout << "Pressione Enter para continuar... ";
		cin.get();
		}
	}

	int exibirMenuMedico(const string& nomeMedico) {
		int escolha = 0;

		while (true) {
			clearScreen();
			exibirBanner();

			cout << "\nBem-vindo(a), " << nomeMedico <<"!" << endl;
			cout << "\n--- MENU MÉDICO ---\n\n";
			cout << "1. Meus Agendamentos" << endl;
			cout << "2. Acessar Prontuário de Paciente" << endl;
			cout << "3. Registrar Novo Documento" << endl;
			cout << "4. Sair\n\n";
			cout << "Sua escolha: ";

			cin >> escolha;

			if (cin.fail() || escolha < 1 || escolha > 4) {
				cout << "\nERRO: Opção Inválida." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Pressione Enter para continuar... ";
				cin.get();
			} else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return escolha;
			}
		}
	}

	int exibirMenuCriarDocumento() {
		int escolha = 0;

		while (true) {
			clearScreen();
			exibirBanner();

			cout << "\n--- MENU DE CRIAÇÃO DE DOCUMENTOS ---\n\n";
			cout << "Qual tipo de documento deseja criar?" << endl;
			cout << "1. Evolução Clínica" << endl;
			cout << "2. Receita Médica" << endl;
			cout << "3. Atestado Médico" << endl;
			cout << "4. Voltar ao menu anterior\n\n";
			cout << "Sua escolha: ";

			cin >> escolha;

			if (cin.fail() || escolha < 1 || escolha > 4) {
				cout << "\nERRO: Opção Inválida." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Pressione Enter para continuar... ";
				cin.get();
			} else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return escolha;
			}
		}
	}

	int exibirMenuRecepcionista(const string& nomeRecepcionista) {
		int escolha = 0;

		while (true) {
			clearScreen();
			exibirBanner();

			cout << "\nBem-vindo(a), " << nomeRecepcionista << "!" << endl;
			cout << "\n--- MENU RECEPCIONISTA ---\n\n";
			cout << "1. Cadastrar Paciente" << endl;
			cout << "2. Listar Pacientes" << endl;
			cout << "3. Agendar Consulta" << endl;
			cout << "4. Sair" << endl;
			cout << "Sua escolha: ";

			cin >> escolha;

			if (cin.fail() || escolha < 1 || escolha > 4) {
				cout << "\nERRO: Opção Inválida." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Pressione Enter para continuar... ";
				cin.get();
			} else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return escolha;
			}
		}
	}
}