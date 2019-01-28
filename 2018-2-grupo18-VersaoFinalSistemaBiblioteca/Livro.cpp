#include "Livro.hpp"

Livro::Livro(){}

Livro::Livro(string titulo, string autor, string editora, bool disponibilidade) : Item(titulo,autor,editora,disponibilidade){}

bool Livro::isDisponivel(){
	return this->_disponibilidade;
}

void Livro::mudarDisponibilidade(){
	_disponibilidade = true ? _disponibilidade = false :  _disponibilidade = true;
}

void Livro::imprimeCampos(){
	cout<<"\nTitulo : "<<getTitulo()<<endl;
	cout<<"\nAutor : "<<getAutor()<<endl;
	cout<<"\nEditora : "<<getEditora()<<endl;
}