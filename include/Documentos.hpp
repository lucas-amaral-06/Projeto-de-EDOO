#ifndef DOCUMENTOS_HPP
#define DOCUMENTOS_HPP

#include <string>
#include <vector>
using namespace std;

class Medico;

class DocumentoClinico // CLASSE ABSTRATA que serve como base para outros documentos clínicos
{
  private:
    string data;
    const Medico* medicoResponsavel; // Composição: o documento TEM um médico

  public:
    DocumentoClinico(const string& data, const Medico* medico);

    virtual ~DocumentoClinico();

    // Método virtual puro para exibir o documento, deve ser implementado pelas classes derivadas
    virtual void exibir() const = 0;

    string getData() const;
    const Medico* getMedicoResponsavel() const;
};

// --- Classes Derivadas ---

class Evolucao : public DocumentoClinico
{
  private:
    string descricao;

  public:
    Evolucao(const string& data, const Medico* medico, const string& descricao);

    // Implementação do método exibir
    void exibir() const override;
};

class Atestado : public DocumentoClinico
{
  private:
    int diasDeAfastamento;
    string motivo;

  public:
    Atestado(const string& data, const Medico* medico, const int& dias, const string& motivo);

    // Implementação do método exibir
    void exibir() const override;
};

class Receita : public DocumentoClinico
{
  private:
    // Lista de medicamentos prescritos
    vector<string> medicamentos;

  public:
    Receita(const string& data, const Medico* medico, const vector<string>& medicamentos);

    // Implementação do método exibir
    void exibir() const override;
};

#endif