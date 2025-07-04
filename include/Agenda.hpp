#ifndef AGENDA_HPP
#define AGENDA_HPP

#include <array>
#include <string>
#include <vector>
#include "Consulta.hpp"

// Use std para evitar ter que escrever std:: repetidamente
using namespace std;

class Agenda {
public: // <- Mova as classes para cá
    class Horario {
    private:
        string intervalo;
        Consulta* consulta; // <- Alterado para ponteiro

    public:
        Horario(const string& interv);

        void marcarConsulta(Consulta* c); // <- Alterado para receber ponteiro
        void cancelarConsulta();
        Consulta* getConsulta() const; // <- Alterado para retornar ponteiro
        string getIntervalo() const;
        bool estaLivre() const;
    };

    class Dia {
    private:
        string nomeDia;
        array<Horario, 8> horarios;

    public:
        Dia(const string nome);
        ~Dia();

        string getNomeDia() const;
        array<Horario, 8>& getHorarios();
        const array<Horario, 8>& getHorarios() const;
    };

private: // <- O membro diasUteis continua privado
    array<Dia, 5> diasUteis;

public:
    Agenda();
    ~Agenda();

    void exibir() const;

    const array<Dia, 5>& getDiasUteis() const;
};

#endif