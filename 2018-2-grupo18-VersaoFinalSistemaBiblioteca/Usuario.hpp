#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "Pessoa.hpp"
#include "Item.hpp"
#include "Multimidia.hpp"
#include "Livro.hpp"
#include <vector>

using std::vector;

class Usuario : public Pessoa{

	private:

		vector<Livro> _livrosAlugados;
		vector<Multimidia> _multimidiaAlugados;
		vector<Livro> _livrosReservados;
		vector<Multimidia> _multimidiaReservados;

	public:

		Usuario();
		Usuario(string,string,int);
		void alugarLivro(Livro);
		void reservarLivro(Livro);
		void devolverLivro(string);
		void alugarMultimidia(Multimidia);
		void reservarMultimidia(Multimidia);
		void devolverMultimidia(string);
		void imprimeLivrosAlugados();
		void imprimeLivrosReservados();
		void imprimeMultimidiaAlugados();
		void imprimeMultimidiaReservados();
		void atribuiItens(Usuario*);
};

#endif