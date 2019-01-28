#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include "Pessoa.hpp"
#include "Acervo.hpp"
#include "Usuario.hpp"

class Funcionario : public Pessoa{

    public:
		Funcionario();
		Funcionario(string,string,int);
		void adicionarLivros(Acervo*,string,string,string);
		void removerLivros(Acervo*,string,string,string);
		void adicionarMultimidias(Acervo*,string,string,string,string);
		void removerMultimidias(Acervo*,string,string,string,string);
		Usuario cadastrarUsuario(string,string,int);
		Funcionario cadastrarFuncionario(string,string,int);
};

#endif