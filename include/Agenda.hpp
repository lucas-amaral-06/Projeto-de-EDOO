#ifndef AGENDA_HPP
#define AGENDA_HPP

#include <array>
#include <string>
#include <vector>
#include "Consulta.hpp"
#include <memory>
using namespace std;

class Agenda {
public: // <- Mova as classes para cá
	class Horario {
	private:
    string intervalo;
    Consulta* consulta; // <- Alterado para ponteiro

  public:
    Horario(const string& interv);

    // Método para marcar uma consulta
    void marcarConsulta(Consulta* c); // <- Alterado para receber ponteiro
    
    // Método para cancelar a consulta
    void cancelarConsulta();
    
    // Método para obter a consulta agendada
    Consulta* getConsulta() const; // <- Alterado para retornar ponteiro
    
    // Método para obter o intervalo de horário
    string getIntervalo() const;
    
    // Método para verificar se o horário está livre
    bool estaLivre() const;
  };

  class Dia {
  private:
    string nomeDia;
    array<Horario, 8> horarios;
    vector<unique_ptr<Consulta>> todasAsConsultas; // <- Vetor de ponteiros inteligentes

  public:
    Dia(const string nome);
    ~Dia();

    // Disable copy
    Dia(const Dia&) = delete;
    Dia& operator=(const Dia&) = delete;

    string getNomeDia() const;
    array<Horario, 8>& getHorarios();
    const array<Horario, 8>& getHorarios() const;

    // Método para adicionar uma nova consulta ao dia
    void adicionarConsulta(unique_ptr<Consulta> novaConsulta);
  };

  private: // <- O membro diasUteis continua privado
    array<Dia, 5> diasUteis;

  public:
    // Disable copy
    Agenda(const Agenda&) = delete;
    Agenda& operator=(const Agenda&) = delete;
    Agenda();
    ~Agenda();

    void exibir() const;

    // Método para obter os dias úteis da agenda
    const array<Dia, 5>& getDiasUteis() const;

    /**
     * @brief Encontra um dia e horário e agenda uma nova consulta.
     * @param diaSemana O nome do dia (ex: "Segunda-feira").
     * @param intervalo O intervalo de horário (ex: "08h00~09h00").
     * @param novaConsulta O ponteiro inteligente para a nova consulta a ser agendada.
     * @return true se o agendamento foi bem-sucedido, false caso contrário.
     */
    bool adicionarConsulta(const string& diaSemana, const string& intervalo, unique_ptr<Consulta> novaConsulta);
};

#endif