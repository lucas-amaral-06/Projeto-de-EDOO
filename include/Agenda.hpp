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
        Consulta consulta;
        
    public:
        Horario(const string& interv);
        
        void marcarConsulta(Consulta c);
        void cancelarConsulta();
        Consulta getConsulta() const;
        string getIntervalo() const;
        bool estaLivre() const;
    };

    class Dia {
    private:
        string nomeDia;
        array<Horario, 8> horarios;
            
    public:
        Dia(const string nome);
        ~Dia();  // Declaração do destrutor
            
        string getNomeDia() const;
        array<Horario, 8>& getHorarios();
        const array<Horario, 8>& getHorarios() const;
    };

    array<Dia, 5> diasUteis;

public:
    Agenda();
    ~Agenda();
    
    void exibir() const;
    
    const array<Dia, 5> getDiasUteis() const;
};

#endif