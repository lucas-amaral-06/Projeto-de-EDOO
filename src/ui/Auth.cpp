#include "ui/Auth.hpp"
#include "utils/utils.hpp" // Inclui nossas funções de validação
#include <iostream>
#include "Paciente.hpp"
#include "Recepcionista.hpp"
#include "Medico.hpp"

using namespace std;

namespace Auth
{
    // A função registrarPaciente permanece sem as validações por enquanto,
    void registrarPaciente(vector<Paciente> &pacienteDB)
    {
        string nome, cpf, dataNascimento, genero, telefone;

        cout << "\n--- Cadastro de Novo Paciente ---" << endl;
        cout << "Digite o nome completo do paciente: ";
        getline(cin, nome);
        cout << "Digite o CPF do paciente (XXX.XXX.XXX-XX): ";
        getline(cin, cpf);
        cout << "Digite a data de nascimento do paciente (DD/MM/AAAA): ";
        getline(cin, dataNascimento);
        cout << "Digite o gênero do paciente: ";
        getline(cin, genero);
        cout << "Digite o telefone do paciente (formato: (XX) XXXXX-XXXX): ";
        getline(cin, telefone);

        try {
            pacienteDB.emplace_back(nome, cpf, dataNascimento, genero, telefone);
            cout << "\nSUCESSO: Paciente " << nome << " cadastrado com sucesso!" << endl;
        } catch (const exception &e) {
            cerr << "\nERRO: " << e.what() << endl;
            cerr << "Falha ao cadastrar o paciente. Verifique os dados informados." << endl;
        }
    }

    void registrarRecepcionista(vector<Recepcionista>& recepcionistaDB)
    {
        string nome, cpf, dataNascimento, genero, telefone, senha, turno, codigoAcesso;

        cout << "\n--- Cadastro de Novo(a) Recepcionista ---" << endl;
        cout << "Digite o nome completo: ";
        getline(cin, nome);

        // Loop de validação para CPF
        while (true) {
            cout << "Digite o CPF (XXX.XXX.XXX-XX): ";
            getline(cin, cpf);
            if (validarFormatoCPF(cpf)) {
                break; // Sai do loop se o CPF for válido
            }
        }

        // Loop de validação para Data de Nascimento
        while (true) {
            cout << "Digite a data de nascimento (DD/MM/AAAA): ";
            getline(cin, dataNascimento);
            if (validarData(dataNascimento)) {
                break; // Sai do loop se a data for válida
            }
        }

        cout << "Digite o gênero: ";
        getline(cin, genero);
        cout << "Digite o telefone (XX) XXXXX-XXXX: ";
        getline(cin, telefone);
        cout << "Crie uma senha de acesso: ";
        getline(cin, senha);
        cout << "Digite o turno de trabalho (Manhã, Tarde, Noite): ";
        getline(cin, turno);
        cout << "Digite o código de acesso (ex: REC004): ";
        getline(cin, codigoAcesso);

        try {
            recepcionistaDB.emplace_back(nome, cpf, dataNascimento, genero, telefone, senha, turno, codigoAcesso);
            cout << "\nSUCESSO: Recepcionista " << nome << " cadastrado(a) com sucesso!" << endl;
        } catch (const exception &e) {
            cerr << "\nERRO: " << e.what() << endl;
            cerr << "Falha ao cadastrar o(a) recepcionista. Verifique os dados informados." << endl;
        }
    }

    void registrarMedico(vector<Medico> &medicoDB)
    {
        string nome, cpf, dataNascimento, genero, telefone, crm, especialidade;

        cout << "\n--- Cadastro de Novo Médico ---" << endl;
        cout << "Digite o nome completo do médico: ";
        getline(cin, nome);

        // Loop de validação para CPF
        while (true) {
            cout << "Digite o CPF do médico (XXX.XXX.XXX-XX): ";
            getline(cin, cpf);
            if (validarFormatoCPF(cpf)) {
                break;
            }
        }

        // Loop de validação para Data de Nascimento
        while (true) {
            cout << "Digite a data de nascimento do médico (DD/MM/AAAA): ";
            getline(cin, dataNascimento);
            if (validarData(dataNascimento)) {
                break;
            }
        }

        cout << "Digite o gênero do médico: ";
        getline(cin, genero);
        cout << "Digite o telefone do médico (formato: (XX) XXXXX-XXXX): ";
        getline(cin, telefone);

        // Loop de validação para CRM
        while (true) {
            cout << "Digite o CRM do médico (ex: CRM/PE 12345): ";
            getline(cin, crm);
            if (validarCRM(crm)) {
                break;
            }
        }

        cout << "Digite a especialidade do médico: ";
        getline(cin, especialidade);

        try {
            medicoDB.emplace_back(nome, cpf, dataNascimento, genero, telefone, crm, especialidade);
            cout << "\nSUCESSO: Med " << nome << " cadastrado com sucesso!" << endl;
        } catch (const exception &e) {
            cerr << "\nERRO: " << e.what() << endl;
            cerr << "Falha ao cadastrar o médico. Verifique os dados informados." << endl;
        }
    }
}