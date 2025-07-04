#ifndef MEDICO_HPP
#define MEDICO_HPP

#include "Pessoa.hpp"
#include "Agenda.hpp"
#include <string>

class Medico : public Pessoa
{
private:
	std::string crm;
	std::string especialidade;
	std::string senha;
	Agenda agenda; // Composição: o médico TEM uma agenda

public:
	Medico(const std::string& nome, const std::string& cpf, const std::string& dataNascimento, const std::string& genero, const std::string& telefone, const std::string& crm, const std::string& especialidade, const std::string& senha);

	~Medico() override;

	// Getters
	std::string getCRM() const;
	std::string getEspecialidade() const;
	std::string getSenha() const;
	Agenda& getAgenda();
	const Agenda& getAgenda() const;

	// Setters
	void setEspecialidade(const std::string& especialidade);
	void setSenha(const std::string& novaSenha);
    
	void exibirDados() const override;
};

#endif