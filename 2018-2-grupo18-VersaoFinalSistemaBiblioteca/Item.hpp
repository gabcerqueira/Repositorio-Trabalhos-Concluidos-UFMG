#ifndef ITEM_HPP
#define ITEM_HPP

#include <stdbool.h>
#include <string.h>
#include <iostream>

using namespace std;

class Item{

	private:
	
		string _titulo;
		string _autor;
		string _editora;
		bool _disponibilidade;
		
	public:
		
		Item();
		Item(string,string,string,bool);
		void setTitulo(string);
		void setAutor(string autor);	
		void setEditora(string);
		string getTitulo();		
		string getAutor();		
		string getEditora();			
		virtual void imprimeCampos();
		virtual bool isDisponivel();

};

#endif