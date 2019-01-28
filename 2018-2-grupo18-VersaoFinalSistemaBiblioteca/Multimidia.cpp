#include "Multimidia.hpp"

Multimidia::Multimidia(){}

Multimidia::Multimidia(string titulo, string autor, string editora,string tipo, bool disponibilidade) : Item(titulo,autor,editora,disponibilidade){
	setTipo(tipo);
}

void Multimidia::setTipo(string tipo){
	this->_tipoMultimidia=tipo;
}
string Multimidia::getTipo(){
	return this->_tipoMultimidia;
}

bool Multimidia::isDisponivel(){
	return this->_disponibilidade;
}

void Multimidia::mudarDisponibilidade(){
	_disponibilidade = true ? _disponibilidade = false :  _disponibilidade = true;
}

void Multimidia::imprimeCampos(){

	cout<<"\nTitulo : "<<getTitulo()<<endl;
	cout<<"\nAutor : "<<getAutor()<<endl;
	cout<<"\nProdutora : "<<getEditora()<<endl;
	cout<<"\nTipo : "<<getTipo()<<endl;
	
}
