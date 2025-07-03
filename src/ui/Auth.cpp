#include "ui/Auth.hpp"
#include "utils.hpp" // Inclui nossas funções de validação
#include <iostream>
#include "Paciente.hpp"
#include "Recepcionista.hpp"
#include "Medico.hpp"

using namespace std;

namespace Auth
{
    // Função registrarPaciente com validações completas
    void registrarPaciente(vector<Paciente> &pacienteDB)
    {
        string nome, cpf, dataNascimento, genero, telefone;

        cout << "\n--- Cadastro de Novo Paciente ---\n" << endl;

        // Validação para não deixar o nome em branco
        while (true) {
            cout << "Digite o nome completo do paciente: ";
            getline(cin, nome);
            if (!nome.empty()) break;
            cout << "\nERRO: O nome não pode ficar em branco. Tente novamente.\n";
        }

        // Loop de validação para CPF com feedback
        while (true) {
            cout << "Digite o CPF do paciente (XXX.XXX.XXX-XX): ";
            getline(cin, cpf);
            if (validarCPF(cpf)) break;
            cout << "\nERRO: Formato de CPF inválido. Use o formato XXX.XXX.XXX-XX. Tente novamente.\n";
        }

        // Loop de validação para Data de Nascimento com feedback
        while (true) {
            cout << "Digite a data de nascimento do paciente (DD/MM/AAAA): ";
            getline(cin, dataNascimento);
            if (validarData(dataNascimento)) break;
            cout << "\nERRO: Data inválida. Use o formato DD/MM/AAAA com valores válidos. Tente novamente.\n";
        }

        // Validação para não deixar o gênero em branco
        while (true) {
            cout << "Digite o gênero do paciente: ";
            getline(cin, genero);
            if (!genero.empty()) break;
            cout << "\nERRO: O gênero não pode ficar em branco. Tente novamente.\n";
        }
        
        // Validação para não deixar o telefone em branco
        while (true) {
            cout << "Digite o telefone do paciente (formato: (XX) XXXXX-XXXX): ";
            getline(cin, telefone);
            if (!telefone.empty()) break;
            cout << "\nERRO: O telefone não pode ficar em branco. Tente novamente.\n";
        }

        try {
            pacienteDB.emplace_back(nome, cpf, dataNascimento, genero, telefone);
            cout << "\nSUCESSO: Paciente " << nome << " cadastrado com sucesso!" << endl;
        } catch (const exception &e) {
            cerr << "\nERRO: " << e.what() << endl;
            cerr << "Falha ao cadastrar o paciente. Verifique os dados informados." << endl;
        }
    }

    // Função registrarRecepcionista com validações completas
    void registrarRecepcionista(vector<Recepcionista>& recepcionistaDB)
    {
        string nome, cpf, dataNascimento, genero, telefone, senha, turno, codigoAcesso;

        cout << "\n--- CADASTRO DE NOVO(A) RECEPCIONISTA ---\n\n";
        
        // Validação de campos em branco e formatos
        while (true) {
            cout << "Digite o nome completo: ";
            getline(cin, nome);
            if (!nome.empty()) break;
            cout << "\nERRO: O nome não pode ficar em branco. Tente novamente.\n";
        }

        while (true) {
            cout << "Digite o CPF (XXX.XXX.XXX-XX): ";
            getline(cin, cpf);
            if (validarCPF(cpf)) break;
            cout << "\nERRO: Formato de CPF inválido. Use o formato XXX.XXX.XXX-XX. Tente novamente.\n";
        }

        while (true) {
            cout << "Digite a data de nascimento (DD/MM/AAAA): ";
            getline(cin, dataNascimento);
            if (validarData(dataNascimento)) break;
            cout << "\nERRO: Data inválida. Use o formato DD/MM/AAAA com valores válidos. Tente novamente.\n";
        }

        while (true) {
            cout << "Digite o gênero: ";
            getline(cin, genero);
            if (!genero.empty()) break;
            cout << "\nERRO: O gênero não pode ficar em branco. Tente novamente.\n";
        }
        
        while (true) {
            cout << "Digite o telefone (XX) XXXXX-XXXX: ";
            getline(cin, telefone);
            if (!telefone.empty()) break;
            cout << "\nERRO: O telefone não pode ficar em branco. Tente novamente.\n";
        }
        
        while (true) {
            cout << "Crie uma senha de acesso: ";
            getline(cin, senha);
            if (!senha.empty()) break;
            cout << "\nERRO: A senha não pode ficar em branco. Tente novamente.\n";
        }
        
        while (true) {
            cout << "Digite o turno de trabalho (Manhã, Tarde, Noite): ";
            getline(cin, turno);
            if (!turno.empty()) break;
            cout << "\nERRO: O turno não pode ficar em branco. Tente novamente.\n";
        }

        while (true) {
            cout << "Digite o código de acesso (ex: REC004): ";
            getline(cin, codigoAcesso);
            if (!codigoAcesso.empty()) break;
            cout << "\nERRO: O código de acesso não pode ficar em branco. Tente novamente.\n";
        }

        try {
            recepcionistaDB.emplace_back(nome, cpf, dataNascimento, genero, telefone, senha, turno, codigoAcesso);
            cout << "\nSUCESSO: Recepcionista " << nome << " cadastrado(a) com sucesso!" << endl;
        } catch (const exception &e) {
            cerr << "\nERRO: " << e.what() << endl;
            cerr << "Falha ao cadastrar o(a) recepcionista. Verifique os dados informados." << endl;
        }
    }

    // Função registrarMedico com validações completas
    void registrarMedico(vector<Medico> &medicoDB)
    {
        string nome, cpf, dataNascimento, genero, telefone, crm, especialidade, senha;

        cout << "\n--- CADASTRO DE NOVO MÉDICO ---\n\n";

        while (true) {
            cout << "Digite o nome completo do médico: ";
            getline(cin, nome);
            if (!nome.empty()) break;
            cout << "\nERRO: O nome não pode ficar em branco. Tente novamente.\n";
        }

        while (true) {
            cout << "Digite o CPF do médico (XXX.XXX.XXX-XX): ";
            getline(cin, cpf);
            if (validarCPF(cpf)) break;
            cout << "\nERRO: Formato de CPF inválido. Use o formato XXX.XXX.XXX-XX. Tente novamente.\n";
        }

        while (true) {
            cout << "Digite a data de nascimento do médico (DD/MM/AAAA): ";
            getline(cin, dataNascimento);
            if (validarData(dataNascimento)) break;
            cout << "\nERRO: Data inválida. Use o formato DD/MM/AAAA com valores válidos. Tente novamente.\n";
        }

        while (true) {
            cout << "Digite o gênero do médico: ";
            getline(cin, genero);
            if (!genero.empty()) break;
            cout << "\nERRO: O gênero não pode ficar em branco. Tente novamente.\n";
        }

        while (true) {
            cout << "Digite o telefone do médico (XX) XXXXX-XXXX): ";
            getline(cin, telefone);
            if (!telefone.empty()) break;
            cout << "\nERRO: O telefone não pode ficar em branco. Tente novamente.\n";
        }

        while (true) {
            cout << "Digite o CRM do médico (CRM/UF XXXXX): ";
            getline(cin, crm);
            if (validarCRM(crm)) break;
            cout << "\nERRO: Formato de CRM inválido. Use o formato CRM/UF XXXXX (ex: CRM/PE 12345). Tente novamente.\n";
        }

        while (true) {
            cout << "Digite a especialidade do médico: ";
            getline(cin, especialidade);
            if (!especialidade.empty()) break;
            cout << "\nERRO: A especialidade não pode ficar em branco. Tente novamente.\n";
        }

        while (true) {
            cout << "Crie uma senha de acesso: ";
            getline(cin, senha);
            if (!senha.empty()) break;
            cout << "\nERRO: A senha não pode ficar em branco. Tente novamente.\n";
        }

        try {
            medicoDB.emplace_back(nome, cpf, dataNascimento, genero, telefone, crm, especialidade, senha);
            cout << "\nSUCESSO: Médico " << nome << " cadastrado com sucesso!" << endl;
        } catch (const exception &e) {
            cerr << "\nERRO: " << e.what() << endl;
            cerr << "Falha ao cadastrar o médico. Verifique os dados informados." << endl;
        }
    }
}