#ifndef ACERVO_HPP
#define ACERVO_HPP

#include "Livro.hpp"
#include "Multimidia.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>

using std::vector;
using std::string;
using std::stringstream;
using std::ifstream;

class Acervo{
	
	private:
		int _acervoTotalLivro;
		int _acervoTotalMultimidia;
		vector <Livro> _acervoLivro;
		vector <Multimidia> _acervoMultimidia;

	public:

		Acervo();
		void inicializarAcervo();
		void adicionarMultimidia(Multimidia);
		void adicionarLivro(Livro);
		void removerLivro(Livro);
		void removerMultimidia(Multimidia);
		void setAcervoTotal(int,int);
		void setAcervoTotalLivro(int);
		void setAcervoTotalMultimidia(int);
		int getAcervoTotal();
		int getAcervoTotalLivro();
		int getAcervoTotalMultimidia();
		void listarLivros();
		void listarMultimidia();
		void procuraLivro(string,int);
		void procuraMultimidia(string,int);
		int pesquisaLivro(Livro);
		int pesquisaMultimidia(Multimidia);
		void mudarDisponibilidadeLivro(Livro);
		void mudarDisponibilidadeMultimidia(Multimidia);	
};

#endif
