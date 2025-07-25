#include "Medico.hpp"
#include <iostream>
using namespace std;

Medico::Medico(const string& nome, const string& cpf, const string& dataNascimento, const string& genero, const string& telefone, const string& crm, const string& especialidade, const string& senha): Pessoa(nome, cpf, dataNascimento, genero, telefone), crm(crm), especialidade(especialidade), senha(senha), agenda() {}

Medico::~Medico() {}

string Medico::getCRM() const {
	return crm;
}

string Medico::getEspecialidade() const {
	return especialidade;
}

string Medico::getSenha() const {
	return senha;
}

Agenda& Medico::getAgenda() {
	return agenda;
}

const Agenda& Medico::getAgenda() const {
	return agenda;
}

void Medico::setEspecialidade(const string& especialidade) {
	this->especialidade = especialidade;
}

void Medico::setSenha(const string& novaSenha) {
	this->senha = novaSenha;
}

void Medico::exibirDados() const {
	Pessoa::exibirDados();
	cout << "CRM: " << crm << endl;
	cout << "Especialidade: " << especialidade << endl;
}