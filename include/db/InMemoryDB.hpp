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
    // Aqui os vetores são declarados como públicos para acesso direto
    // Mas é uma prática melhor encapsular o acesso a esses dados (Para uso mais simplificado eles são públicos)
    vector<Paciente> pacientesDB;
    vector<unique_ptr<Medico>> medicosDB;
    vector<Recepcionista> recepcionistasDB;
    vector<Consulta> consultasDB; 

    // @brief Construtor que popula o banco de dados com dados de simulaçao.
    InMemoryDB();

    // @brief Encontra o usuário pelo seu dado correspondente.
    // @return Um ponteiro para o paciente encontrado ou nullptr se não encontrado.
    Paciente* buscarPacientePorCPF(const string& cpf);

    // @brief Encontra o médico pelo seu CRM.
    // @return Um ponteiro para o médico encontrado ou nullptr se não encontrado.
    Medico* buscarMedicoPorCRM(const string& crm);
    
    // @brief Encontra o recepcionista pelo seu CPF.
    // @return Um ponteiro para o recepcionista encontrado ou nullptr se não encontrado.
    Recepcionista* buscarRecepcionistaPorCPF(const string& cpf); // Novo método
};

#endif