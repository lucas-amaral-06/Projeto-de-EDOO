#ifndef AGENDA_HPP
#define AGENDA_HPP

#include <array>
#include <string>
#include <vector>
#include "Consulta.hpp"

class Agenda {
private:
    class Horario {
    private:
        string intervalo;
        Consulta* consulta;
        
    public:
        Horario(const string& interv);
        
        void marcarConsulta(Consulta* c);
        void cancelarConsulta();
        Consulta* getConsulta() const;
        string getIntervalo() const;
        bool estaLivre() const;
    };

    class Dia {
    private:
        string nomeDia;
        array<Horario, 8> horarios;
        
    public:
        Dia(const string& nome);
        
        string getNomeDia() const;
        array<Horario, 8>& getHorarios();
        const array<Horario, 8>& getHorarios() const;
        
        bool agendarConsulta(int index, Consulta* consulta);
        bool cancelarConsulta(int index);
    };

    array<Dia, 5> diasUteis;

public:
    Agenda();
    
    bool agendarConsulta(int diaSemana, int horario, Consulta* consulta);
    bool cancelarConsulta(int diaSemana, int horario);
    void exibir() const;
    
    Consulta* getConsulta(int diaSemana, int horario) const;
    const array<Horario, 8>& getHorariosDia(int diaSemana) const;
    const array<Dia, 5>& getDiasUteis() const;
};

#endif