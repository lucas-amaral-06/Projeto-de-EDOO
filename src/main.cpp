#include <iostream>
#include "Paciente.hpp"
#include "Prontuario.hpp"
#include "Pessoa.hpp"
#include "Documentos.hpp"
#include "Medico.hpp"
#include "Consulta.hpp"
#include "Agenda.hpp"

using namespace std;

int main() {
    // Create a prontuario for a patient
    Paciente paciente("Maria Oliveira", 28, "123.456.789-01", "15/03/1995", "Feminino", "(11) 98765-4321");
    Prontuario prontuario(&paciente);

    // Create a doctor
    Medico medico("Dr. Carlos Pereira", 40, "987.654.321-01", "20/07/1983", "Masculino", "(11) 12345-6789", "CRM987654", "Neurologia");

    // Create medical documents
    Evolucao evolucao("10/10/2023", &medico, "Paciente apresenta sintomas de enxaqueca.");
    Atestado atestado("10/10/2023", &medico, 3, "Enxaqueca aguda.");
    vector<string> medicamentos = {"Dipirona 500mg", "Aspirina 100mg"};
    Receita receita("10/10/2023", &medico, medicamentos);
    Receita receita2("10/10/2323", &medico, medicamentos);
    Receita receita3("10/10/2323", &medico, medicamentos);

    // Add documents to the prontuario
    paciente.getProntuario()->adicionarEvolucao(evolucao);
    paciente.getProntuario()->adicionarAtestado(atestado);
    paciente.getProntuario()->adicionarReceita(receita);
    paciente.getProntuario()->adicionarReceita(receita2);
    paciente.getProntuario()->adicionarReceita(receita3);

    // Display the patient's medical record summary
    cout << "Resumo do Prontuário de " << paciente.getNome() << ":"<< endl;
    paciente.getProntuario()->exibirHistorico();

    // Create a consultation
    Consulta consulta(&paciente, &medico, "10/10/2023 14:00");
    consulta.exibir();
    // Create an agenda and add the consultation
    Agenda agenda;
    agenda.adicionarConsulta(consulta);
    cout << "Agenda de Consultas:" << endl;
    agenda.exibir();

  return 0;
}