#ifndef MULTIMIDIA_HPP
#define MULTIMIDIA_HPP

#include "Item.hpp"

class Multimidia : public Item{
	
	private:
		bool _disponibilidade = true;
		string _tipoMultimidia;
	
	public:

		Multimidia();
		Multimidia(string,string,string,string,bool);
		void setTipo(string);
		string getTipo();
		bool isDisponivel();
		void mudarDisponibilidade();
		void imprimeCampos();
};

#endif