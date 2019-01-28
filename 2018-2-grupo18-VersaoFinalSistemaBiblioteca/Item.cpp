#include "Item.hpp"

Item::Item(){}

Item::Item(string titulo, string autor, string editora, bool disponibilidade){
	this->_titulo = titulo;
	this->_autor = autor;
	this->_editora = editora;
	this->_disponibilidade = disponibilidade;
}

void Item::setTitulo(string titulo){
		this->_titulo = titulo;
}
		
void Item::setAutor(string autor){
		this->_autor = autor;
}
		
void Item::setEditora(string editora){
		this->_editora = editora;
}

string Item::getTitulo(){
		return _titulo;
}
		
string Item::getAutor(){
		return _autor;
}
		
string Item::getEditora(){
		return _editora;
}
bool Item::isDisponivel(){
		return this->_disponibilidade;
}			
void Item::imprimeCampos(){

	cout<<"\nTitulo : "<<getTitulo()<<endl;
	cout<<"\nAutor : "<<getAutor()<<endl;
	cout<<"\nEditora : "<<getEditora()<<endl;
}