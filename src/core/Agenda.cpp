#include "Agenda.hpp"
#include <iostream>
#include <stdexcept>

// Implementações de Horario
Agenda::Horario::Horario(const std::string& interv) : intervalo(interv), consulta(nullptr) {}

void Agenda::Horario::marcarConsulta(Consulta* c) { consulta = c; }
void Agenda::Horario::cancelarConsulta() { consulta = nullptr; }
Consulta* Agenda::Horario::getConsulta() const { return consulta; }
std::string Agenda::Horario::getIntervalo() const { return intervalo; }
bool Agenda::Horario::estaLivre() const { return consulta == nullptr; }

// Implementações de Dia
Agenda::Dia::Dia(const std::string nome) : nomeDia(nome), 
    horarios{Horario("08h00~09h00"), Horario("09h00~10h00"), 
            Horario("10h00~11h00"), Horario("11h00~12h00"),
            Horario("14h00~15h00"), Horario("15h00~16h00"),
            Horario("16h00~17h00"), Horario("17h00~18h00")} {}

std::string Agenda::Dia::getNomeDia() const { return nomeDia; }

std::array<Agenda::Horario, 8> Agenda::Dia::getHorarios() { return horarios; }

// Implementações de Agenda
Agenda::Agenda() : diasUteis{
    Dia("Segunda-feira"),
    Dia("Terça-feira"),
    Dia("Quarta-feira"),
    Dia("Quinta-feira"),
    Dia("Sexta-feira")
} {}


const std::array<Agenda::Dia, 5> Agenda::getDiasUteis() const {
    return diasUteis;
}