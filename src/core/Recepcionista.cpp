#include "Recepcionista.hpp"
#include <iostream>

Recepcionista::Recepcionista(const string& nome, const string& cpf, const string& dataNascimento, const string& genero, const string& telefone, const string& senha, const string& turno, const string& codigoAcesso): Pessoa(nome, cpf, dataNascimento, genero, telefone), senha(senha), turno(turno), codigoAcesso(codigoAcesso) {}

Recepcionista::~Recepcionista() {}

// Getters
string Recepcionista::getSenha() const {
	return senha;
}

string Recepcionista::getTurno() const {
	return turno;
}

string Recepcionista::getCodigoAcesso() const {
	return codigoAcesso;
}

// Setters
void Recepcionista::setSenha(const string& novaSenha) {
	senha = novaSenha;
}

void Recepcionista::setTurno(const string& novoTurno) {
	turno = novoTurno;
}

// Método para exibir todos os dados
void Recepcionista::exibirDados() const {
	Pessoa::exibirDados(); // Chama o método da classe base para exibir os dados comuns
	cout << "Turno: " << turno << endl;
	cout << "Código de Acesso: " << codigoAcesso << endl;
	// Nota: A senha não é exibida por questões de segurança
}