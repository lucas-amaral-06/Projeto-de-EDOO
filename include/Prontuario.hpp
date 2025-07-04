#ifndef PRONTUARIO_HPP
#define PRONTUARIO_HPP

#include "Documentos.hpp" // inclui a definição das classes Evolucao, Receita e Atestado
#include <string>
#include <vector>
using namespace std;

class Paciente; // declaração antecipada da classe Paciente para evitar dependências circulares
class Evolucao; // declaração antecipada da classe Evolucao
class Receita; // declaração antecipada da classe Receita
class Atestado; // declaração antecipada da classe Atestado

class Prontuario
{
  private:
    string numero;
    string pacienteCPF;
    string dataCriacao;
    vector<Evolucao> historicoEvolucoes;
    vector<Receita> listaReceitas;
    vector<Atestado> listaAtestados;

  public:
    Prontuario(Paciente& paciente); // construtor que recebe um ponteiro para o paciente

    Prontuario(); // construtor padrão

    ~Prontuario();

    void adicionarEvolucao(const Evolucao& evolucao);
    void adicionarReceita(const Receita& receita);
    void adicionarAtestado(const Atestado& atestado);

    void getReceitas(vector<Receita>& receitas) const;
    void getEvolucoes(vector<Evolucao>& evolucoes) const;
    void getAtestados(vector<Atestado>& atestados) const;

    void exibirHistorico() const;
    void exibirResumo() const;

    string getNumero() const;
};

#endif