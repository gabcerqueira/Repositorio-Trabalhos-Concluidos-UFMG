#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <exception>
#include <string.h>

#include "Funcionario.hpp"
#include "Gerencia.hpp"
#include "Usuario.hpp"
#include "Acervo.hpp"
#include "Item.hpp"
#include "Pessoa.hpp"
#include "Multimidia.hpp"
#include "Livro.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Biblioteca{

private:

	Usuario *usuario;
	Funcionario *funcionario;
	Gerencia *administrador;
	Acervo *acervo;	

public:
	
	Biblioteca();
	void interfacePrincipal();
	int determinaInterface();
	void interfaceUsuario();
	int telaInicial(int tipoUsuario);
	void menuUsuario();
	void menuFuncionario();
	int login(int tipoUsuario);
	void desalocaDados();
	~Biblioteca();
};
class LoginInvalido: public std::exception{

        virtual const char* what()const throw(){

            return "LoginInvalido";
        }
};

#endif

