#include "db/InMemoryDB.hpp"
#include "Documentos.hpp"
#include <iostream>
#include "Prontuario.hpp"
using namespace std;

InMemoryDB::InMemoryDB() {
  cout << "Inicializando banco de dados em memória..." << endl;

  // --- CRIANDO MÉDICOS ---
  medicosDB.emplace_back("Ana Souza", "543.123.456-78", "20/02/1980", "Feminino", "(81) 97766-5544", "CRM/PE 12345", "Cardiologia");
  medicosDB.emplace_back("Carlos Silva", "123.456.789-00", "15/03/1975", "Masculino", "(11) 98888-7777", "CRM/SP 67890", "Pediatria");
  medicosDB.emplace_back("Fernanda Lima", "987.654.321-00", "10/04/1990", "Feminino", "(21) 99999-8888", "CRM/RJ 11223", "Neurologia");
  medicosDB.emplace_back("Roberto Costa", "321.654.987-00", "05/05/1985", "Masculino", "(31) 95555-4444", "CRM/MG 44556", "Ortopedia");
  medicosDB.emplace_back("Mariana Oliveira", "654.321.987-00", "30/06/1992", "Feminino", "(41) 92222-3333", "CRM/PR 77889", "Ginecologia");

  cout << "Médicos criados com sucesso!" << endl;

  // --- CRIANDO PACIENTES ---
  pacientesDB.emplace_back("João da Silva", "123.456.789-00", "01/01/1990", "Masculino", "(11) 98765-4321");
  pacientesDB.emplace_back("Maria Santos", "234.567.890-11", "02/02/1992", "Feminino", "(21) 97654-3210");
  pacientesDB.emplace_back("Pedro Almeida", "345.678.901-22", "03/03/1988", "Masculino", "(31) 96543-2109");
  pacientesDB.emplace_back("Ana Pereira", "456.789.012-33", "04/04/1995", "Feminino", "(41) 95432-1098");
  pacientesDB.emplace_back("Lucas Costa", "567.890.123-44", "05/05/1987", "Masculino", "(51) 94321-0987");

  cout << "Pacientes criados com sucesso!" << endl;

  // --- CRIANDO RELAÇÕES ENTRE PONTEIROS ---
  Paciente* pacienteJoão = buscarPacientePorCPF("123.456.789-00");
  Paciente* pacienteMaria = buscarPacientePorCPF("234.567.890-11");
  Paciente* pacientePedro = buscarPacientePorCPF("345.678.901-22");
  Paciente* pacienteAna = buscarPacientePorCPF("456.789.012-33");
  Paciente* pacienteLucas = buscarPacientePorCPF("567.890.123-44");

  Medico* medicoAna = buscarMedicoPorCRM("CRM/PE 12345");
  Medico* medicoCarlos = buscarMedicoPorCRM("CRM/SP 67890");
  Medico* medicoFernanda = buscarMedicoPorCRM("CRM/RJ 11223");
  Medico* medicoRoberto = buscarMedicoPorCRM("CRM/MG 44556");
  Medico* medicoMariana = buscarMedicoPorCRM("CRM/PR 77889");
  
  // --- CRIANDO PRONTUÁRIOS ---
  if (pacienteLucas && medicoAna) {
    Evolucao evolucao1("2023-10-01", medicoAna, "Paciente apresenta sintomas leves de resfriado.");
    pacienteLucas->getProntuario().adicionarEvolucao(evolucao1);
  }

  cout << "Banco de dados em memória inicializado com sucesso!" << endl;
}

Paciente* InMemoryDB::buscarPacientePorCPF(const string& cpf) {
  for (auto& paciente : this->pacientesDB) {
    if (paciente.getCPF() == cpf) {
      return &paciente;
    }
  }
  return nullptr; // Retorna nullptr se não encontrar o paciente
}

Medico* InMemoryDB::buscarMedicoPorCRM(const string& crm) {
  for (auto& medico : this->medicosDB) {
    if (medico.getCRM() == crm) {
      return &medico;
    }
  }
  return nullptr; // Retorna nullptr se não encontrar o médico
}