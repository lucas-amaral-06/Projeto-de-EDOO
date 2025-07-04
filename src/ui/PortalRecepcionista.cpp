#include "ui/PortalRecepcionista.hpp"
#include "ui/Menu.hpp"
#include "ui/Auth.hpp"
#include "ui/Listagens.hpp"
#include "Consulta.hpp"
#include "utils.hpp"

#include <iostream>
#include <limits>
using namespace std;


namespace PortalRecepcionistaUI {
  void agendarNovaConsulta(InMemoryDB& db){
    cout << "\n--- Agendamento de Consulta ---" << endl;

    // Selecionar o paciente
    cout << "Selecione o paciente:" << endl;
    for (size_t i = 0; i < db.pacientesDB.size(); ++i) {
      cout << i + 1 << ". " << db.pacientesDB[i].getNome() << " (CPF: " << db.pacientesDB[i].getCPF() << ")" << endl;
    }
    cout << "Digite o número do paciente: ";
    size_t pacienteIndex;
    cin >> pacienteIndex;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (pacienteIndex < 1 || pacienteIndex > db.pacientesDB.size()) {
      cout << "ERRO: Índice de paciente inválido." << endl;
      return;
    }
    Paciente& pacienteEscolhido = db.pacientesDB[pacienteIndex - 1];

    // Selecionar o médico
    cout << "Selecione o médico:" << endl;
    for (size_t i = 0; i < db.medicosDB.size(); ++i) {
      cout << i + 1 << ". " << db.medicosDB[i]->getNome() << " (" << db.medicosDB[i]->getEspecialidade() << ")" << endl;
    }
    cout << "Digite o número do médico: ";
    size_t medicoIndex;
    cin >> medicoIndex;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (medicoIndex < 1 || medicoIndex > db.medicosDB.size()) {
      cout << "ERRO: Índice de médico inválido." << endl;
      return;
    }
    Medico* medicoEscolhido = db.medicosDB[medicoIndex - 1].get();

    // Selecionar a data e hora
    cout << "\nDigite o dia da semana par a agendar a consulta (ex: Segunda-feira): ";
    string diaSemana;
    getline(cin, diaSemana);

    cout << "Digite o horário da consulta (ex: 08h00~09h00): ";
    string intervalo;
    getline(cin, intervalo);

    auto novaConsulta = make_unique<Consulta>(&pacienteEscolhido, medicoEscolhido, diaSemana + " " + intervalo);
    medicoEscolhido->getAgenda().adicionarConsulta(diaSemana, intervalo, move(novaConsulta));
  }

  void fluxoRecepcionista(Recepcionista& recepcionista, InMemoryDB& db){
    bool logado = true;
    while (logado) {
      int escolha = MenuUI::exibirMenuRecepcionista(recepcionista.getNome());
      switch (escolha) {
        case 1:
          Auth::registrarPaciente(db.pacientesDB);
          break;
        case 2:
          ListagensUI::listarPacientes(db);
          break;
        case 3:
          agendarNovaConsulta(db);
          break;
        case 4:
          logado = false; // Sair do fluxo do recepcionista
          cout << "Saindo do portal do recepcionista." << endl;
          break;
        default:
          cout << "ERRO: Opção inválida." << endl;
      }
      if (logado) {
        cout << "\nPressione Enter para continuar...";
        cin.get();
      }
    }
  }
}