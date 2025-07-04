#include "ui/PortalMedico.hpp"
#include "utils/DataUtils.hpp"
#include "ui/Menu.hpp"
#include "Documentos.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace PortalMedicoUI {
  Paciente* encontrarPacienteParaAtendimento(InMemoryDB& db){
    cout << "`\nDigite o CPF do paciente que deseja atender: ";
    string cpf;
    getline(cin, cpf);

    if (!validarCPF(cpf)) {
      cout << "ERRO: CPF inválido." << endl;
      return nullptr;
    }

    Paciente* paciente = db.buscarPacientePorCPF(cpf);
    if (!paciente){
      cout << "ERRO: Paciente com CPF " << cpf << " não encontrado." << endl;
    }
    return paciente;
  }

  void listarAgendamentos(const Medico& medico) {
    cout << "Agendamentos do médico " << medico.getNome() << ":" << endl;
    medico.getAgenda().exibir();
  }

  void acessarProntuarioDePaciente(InMemoryDB& db) {
    cout << "\n--- Acessar Prontuário ---" << endl;
    cout << "Digite o CPF do paciente: ";
    string cpf;
    getline(cin, cpf);

    if (!validarCPF(cpf)) {
      cout << "ERRO: CPF inválido." << endl;
      return;
    }

    Paciente* paciente = db.buscarPacientePorCPF(cpf);
    if (paciente) {
      paciente->getProntuario().exibirHistorico();
    } else {
      cout << "ERRO: Paciente com CPF " << cpf << " não encontrado." << endl;
    }
  }

  void listarDocumentosDoMedico(const Medico& medico, const InMemoryDB& db, const string& tipo) {
    cout << "\n--- Lista de " << tipo << "s Emitidos por " << medico.getNome() << " ---" << endl;

    bool encontrou = false;

    cout << "A implementar" << endl;
  }

  void criarNovaEvolucao(Medico& medico, InMemoryDB& db) {
    Paciente* paciente = encontrarPacienteParaAtendimento(db);
    if (!paciente) return;

    cout << "Digite a evolução do paciente: ";
    string evolucao;
    getline(cin, evolucao);

    if (evolucao.empty()) {
      cout << "ERRO: Evolução não pode ser vazia." << endl;
      return;
    }

    Evolucao novaEvolucao(DataUtils::getDataAtualFormatada(), &medico, evolucao);
    paciente->getProntuario().adicionarEvolucao(novaEvolucao);
    cout << "Evolução registrada com sucesso!" << endl;
  }

  void criarNovaReceita(Medico& medico, InMemoryDB& db) {
    Paciente* paciente = encontrarPacienteParaAtendimento(db);
    if (!paciente) return;

    vector<string> medicamentos;
    string medicamento;

    cout << "Digite os medicamentos (um por linha, digite 'fim' para terminar),." << endl;
    while(true){
      cout << "> ";
      getline(cin, medicamento);
      if (medicamento == "fim") {
        break;
      }

      medicamentos.push_back(medicamento);
    }

    if (!medicamentos.empty()) {
      Receita novaReceita(DataUtils::getDataAtualFormatada(), &medico, medicamentos);
      paciente->getProntuario().adicionarReceita(novaReceita);
    } else {
      cout << "ERRO: Nenhum medicamento foi adicionado. Receita não criada." << endl;
    }
  }


// Aqui o Médico conseguir criar o atestado do Paciente
  void criarNovoAtestado(Medico& medico, InMemoryDB& db) {
    Paciente* paciente = encontrarPacienteParaAtendimento(db);
    if (!paciente) return;

    cout << "Digite o motivo do atestado: ";
    string motivo;
    getline(cin, motivo);

    cout << "Digite a duração do atestado (em dias): ";
    int dias;
    cin >> dias;
    
    while (cin.fail() || dias <= 0) {
      cin.clear(); // Limpa o estado de erro
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora a entrada inválida
      cout << "ERRO: Entrada inválida. Digite um número positivo para os dias: ";
      cin >> dias;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer de entrada

    Atestado novoAtestado(DataUtils::getDataAtualFormatada(), &medico, dias, motivo);

        paciente->getProntuario().adicionarAtestado(novoAtestado);

        cout << "Atestado registrado com sucesso!" << endl;
  }

  void fluxoCriarDocumento(Medico& medico, InMemoryDB& db){
    int escolha = MenuUI::exibirMenuCriarDocumento();
    switch (escolha) {
      case 1:
        criarNovaEvolucao(medico, db);
        break;
      case 2:
        criarNovaReceita(medico, db);
        break;
      case 3:
        criarNovoAtestado(medico, db);
        break;
      case 4: return; // Voltar ao menu anterior
    }
  }

  void fluxoMedico(Medico& medico, InMemoryDB& db){
    bool logado = true;
    while (logado) {
      int escolha = MenuUI::exibirMenuMedico(medico.getNome());
      switch (escolha) {
        case 1:
          listarAgendamentos(medico);
          break;
        case 2:
          acessarProntuarioDePaciente(db);
          break;
        case 3:
          fluxoCriarDocumento(medico, db);
          break;
        case 4:
          logado = false; // Sair do fluxo do médico
          cout << "Saindo do portal do médico." << endl;
          break;
      }
      if (logado) {
        cout << "Pressione Enter para voltar ao menu do médico" << endl;
        cin.get();
      }
    }
  }
}