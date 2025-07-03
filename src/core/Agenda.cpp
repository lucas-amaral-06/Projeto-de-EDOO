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
Agenda::Dia::Dia(const std::string& nome) : nomeDia(nome), 
    horarios{Horario("08h00~09h00"), Horario("09h00~10h00"), 
            Horario("10h00~11h00"), Horario("11h00~12h00"),
            Horario("14h00~15h00"), Horario("15h00~16h00"),
            Horario("16h00~17h00"), Horario("17h00~18h00")} {}

std::string Agenda::Dia::getNomeDia() const { return nomeDia; }
std::array<Agenda::Horario, 8>& Agenda::Dia::getHorarios() { return horarios; }
const std::array<Agenda::Horario, 8>& Agenda::Dia::getHorarios() const { return horarios; }

bool Agenda::Dia::agendarConsulta(int index, Consulta* consulta) {
    if (index < 0 || index >= 8) return false;
    if (!horarios[index].estaLivre()) return false;
    horarios[index].marcarConsulta(consulta);
    return true;
}

bool Agenda::Dia::cancelarConsulta(int index) {
    if (index < 0 || index >= 8) return false;
    horarios[index].cancelarConsulta();
    return true;
}

// Implementações de Agenda
Agenda::Agenda() : diasUteis{
    Dia("Segunda-feira"),
    Dia("Terça-feira"),
    Dia("Quarta-feira"),
    Dia("Quinta-feira"),
    Dia("Sexta-feira")
} {}

bool Agenda::agendarConsulta(int diaSemana, int horario, Consulta* consulta) {
    if (diaSemana < 0 || diaSemana >= 5) return false;
    return diasUteis[diaSemana].agendarConsulta(horario, consulta);
}

bool Agenda::cancelarConsulta(int diaSemana, int horario) {
    if (diaSemana < 0 || diaSemana >= 5) return false;
    return diasUteis[diaSemana].cancelarConsulta(horario);
}

void Agenda::exibir() const {
    for (const auto& dia : diasUteis) {
        std::cout << "\n" << dia.getNomeDia() << ":\n";
        for (const auto& horario : dia.getHorarios()) {
            std::cout << horario.getIntervalo() << ": ";
            if (horario.getConsulta() != nullptr) {
                std::cout << "Consulta agendada";
            } else {
                std::cout << "Livre";
            }
            std::cout << std::endl;
        }
    }
}

Consulta* Agenda::getConsulta(int diaSemana, int horario) const {
    if (diaSemana < 0 || diaSemana >= 5 || horario < 0 || horario >= 8) {
        return nullptr;
    }
    return diasUteis[diaSemana].getHorarios()[horario].getConsulta();
}

const std::array<Agenda::Horario, 8>& Agenda::getHorariosDia(int diaSemana) const {
    if (diaSemana < 0 || diaSemana >= 5) {
        throw std::out_of_range("Dia da semana inválido");
    }
    return diasUteis[diaSemana].getHorarios();
}

const std::array<Agenda::Dia, 5>& Agenda::getDiasUteis() const {
    return diasUteis;
}