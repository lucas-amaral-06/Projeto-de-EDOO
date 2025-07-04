#ifndef INMEMORYDB_HPP
#define INMEMORYDB_HPP

#include "Paciente.hpp"
#include "Medico.hpp"
#include "Recepcionista.hpp"
#include <vector>
#include <string>

using namespace std;

class InMemoryDB 
{
  public:
    vector<Paciente> pacientesDB;
    vector<Medico> medicosDB;
    vector<Recepcionista> recepcionistasDB;
        vector<Consulta> consultasDB; 

    // @brief Construtor que popula o banco de dados com dados de simulaçao.
    InMemoryDB();

    // @brief Encontra o usuário pelo seu dado correspondente.
    // @return Um ponteiro para o paciente encontrado ou nullptr se não encontrado.
    Paciente* buscarPacientePorCPF(const string& cpf);
    Medico* buscarMedicoPorCRM(const string& crm);
    Recepcionista* buscarRecepcionistaPorCPF(const string& cpf); // Novo método
};

#endif