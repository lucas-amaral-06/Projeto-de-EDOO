#ifndef INMEMORYDB_HPP
#define INMEMORYDB_HPP

#include "Paciente.hpp"
#include "Medico.hpp"
#include <vector>
#include <string>

using namespace std;

class InMemoryDB 
{

  public:
    
    vector<Paciente> pacientesDB;
    vector<Medico> medicosDB;

    // @brief Construtor que popula o banco de dados com dados de simulaçao.
    InMemoryDB();

    // @brief Encontra um paciente pelo CPF.
    // @return Um ponteiro para o paciente encontrado ou nullptr se não encontrado.
    Paciente* buscarPacientePorCPF(const string& cpf);

    // @brief Busca um médico pelo CRM.
    // @return Um ponteiro para o médico encontrado ou nullptr se não encontrado.
    Medico* buscarMedicoPorCRM(const string& crm);
    
};

#endif