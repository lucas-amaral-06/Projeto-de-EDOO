#ifndef DOCUMENTOS_HPP
#define DOCUMENTOS_HPP

#include <string>
#include <vector>
using namespace std;

class Medico;

class DocumentoClinico
{
  private:
    string data;
    const Medico* medicoResponsavel; // Composição: o documento TEM um médico

  public:
    DocumentoClinico(const string& data, const Medico* medico);

    virtual ~DocumentoClinico();

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

    void exibir() const override;
};

class Atestado : public DocumentoClinico
{
  private:
    int diasDeAfastamento;
    string motivo;

  public:
    Atestado(const string& data, const Medico* medico, const int& dias, const string& motivo);

    void exibir() const override;
};

class Receita : public DocumentoClinico
{
  private:
    vector<string> medicamentos;

  public:
    Receita(const string& data, const Medico* medico, const vector<string>& medicamentos);

    void exibir() const override;
};

#endif