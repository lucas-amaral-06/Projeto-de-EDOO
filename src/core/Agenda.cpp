#include "Agenda.hpp"
#include <iostream>
#include <stdexcept>

// Implementações de Horario
Agenda::Horario::Horario(const std::string& interv) : intervalo(interv), consulta(nullptr) {}

void Agenda::Horario::marcarConsulta(Consulta* c) {
    consulta = c;
}

void Agenda::Horario::cancelarConsulta() {
    consulta = nullptr;
}

Consulta* Agenda::Horario::getConsulta() const {
    return consulta;
}

std::string Agenda::Horario::getIntervalo() const {
    return intervalo;
}

bool Agenda::Horario::estaLivre() const {
    // Agora a comparação funciona, pois 'consulta' é um ponteiro
    return consulta == nullptr;
}

// Implementações de Dia
Agenda::Dia::Dia(const std::string nome) : nomeDia(nome),
    horarios{Horario("08h00~09h00"), Horario("09h00~10h00"),
             Horario("10h00~11h00"), Horario("11h00~12h00"),
             Horario("14h00~15h00"), Horario("15h00~16h00"),
             Horario("16h00~17h00"), Horario("17h00~18h00")} {}

void Agenda::Dia::adicionarConsulta(std::unique_ptr<Consulta> novaConsulta) {
    todasAsConsultas.push_back(std::move(novaConsulta));
}

// É preciso ter a implementação do destrutor que foi declarado no .hpp
Agenda::Dia::~Dia() {}

std::string Agenda::Dia::getNomeDia() const {
    return nomeDia;
}

std::array<Agenda::Horario, 8>& Agenda::Dia::getHorarios() {
    return horarios;
}

const std::array<Agenda::Horario, 8>& Agenda::Dia::getHorarios() const {
    return horarios;
}

// Implementações de Agenda
Agenda::Agenda() : diasUteis{
    Dia("Segunda-feira"),
    Dia("Terça-feira"),
    Dia("Quarta-feira"),
    Dia("Quinta-feira"),
    Dia("Sexta-feira")
} {}

// É preciso ter a implementação do destrutor que foi declarado no .hpp
Agenda::~Agenda() {}

const std::array<Agenda::Dia, 5>& Agenda::getDiasUteis() const {
    return diasUteis;
}

// Você pode adicionar a lógica de exibição aqui depois
void Agenda::exibir() const {
    for (const auto& dia : diasUteis) {
        std::cout << "Agenda para " << dia.getNomeDia() << ":\n";
        for (const auto& horario : dia.getHorarios()) {
            std::cout << "  " << horario.getIntervalo();
            if (horario.estaLivre()) {
                std::cout << " - Livre\n";
            } else {
                std::cout << " - Ocupado\n";
            }
        }
    }
}

bool Agenda::adicionarConsulta(const std::string& diaSemana, const std::string& intervalo, std::unique_ptr<Consulta> novaConsulta) {
	for (auto& dia : diasUteis) {
		if (dia.getNomeDia() == diaSemana) {
			for (auto& horario : dia.getHorarios()) {
				if (horario.getIntervalo() == intervalo && horario.estaLivre()) {
					Consulta* ptrConsulta = novaConsulta.get();
					dia.adicionarConsulta(std::move(novaConsulta));
					horario.marcarConsulta(ptrConsulta); // Marca o horário com a nova consulta
					cout << "Consulta agendada para " << diaSemana << " no horário " << intervalo << ".\n";
					return true;
				} else {
					cout << "Horário " << intervalo << " já está ocupado no dia " << diaSemana << ".\n";
					return false;
				}
			}

			cout << "ERRO: Horário " << intervalo << " inválido no dia " << diaSemana << ".\n";
			return false;
		}
	}
	std::cout << "ERRO: Dia " << diaSemana << " não inválido na agenda.\n";
	return false;
}