#ifndef GERENCIA_HPP
#define GERENCIA_HPP

#include "Pessoa.hpp"
#include "Usuario.hpp"
#include "Funcionario.hpp"
#include "Acervo.hpp"
#include <vector>

class Gerencia{
	
	private:
		vector <Usuario> _usuariosCadastrados;
		vector <Funcionario> _funcionariosCadastrados;
		
	public:
		Gerencia();
		void setUsuarioCadastrado(Usuario);
		void setFuncionarioCadastrado(Funcionario);
		int pesquisaFuncionario(int,string);
		int pesquisaUsuario(int,string);
		void atribuiParametrosUsuario(Usuario*);
		void atribuiParametrosFuncionario(Funcionario*);

};

#endif
