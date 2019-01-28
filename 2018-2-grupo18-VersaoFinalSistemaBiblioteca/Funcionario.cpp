#include "Funcionario.hpp"

Funcionario :: Funcionario(){}

Funcionario :: Funcionario(string nome, string senha, int id) : Pessoa(nome,senha,id){}

//Adiciona novos livros ao acervo da biblioteca
void Funcionario::adicionarLivros(Acervo *acervo,string titulo, string autor, string prod){
	
	Livro novo(titulo,autor,prod,true);
	acervo->adicionarLivro(novo);
}

//Remove novos livros do acervo da biblioteca
void Funcionario::removerLivros(Acervo *acervo,string titulo, string autor, string prod){
	
	Livro livro(titulo,autor, prod,true);
	acervo->removerLivro(livro);
}
//Adiciona novas multimidias ao acervo da biblioteca
void Funcionario::adicionarMultimidias(Acervo *acervo,string titulo, string autor, string produtora, string tipo){
	
	Multimidia nova(titulo,autor,produtora,tipo,true);
	acervo->adicionarMultimidia(nova);
}

//Remove multimidia do acervo da biblioteca
void Funcionario::removerMultimidias(Acervo *acervo,string titulo, string autor,string produtora, string tipo){
	
	Multimidia retirada(titulo,autor,produtora,tipo,true);
	acervo->removerMultimidia(retirada);
}

//Cadastra novos usuários e os adiciona à gerencia
Usuario Funcionario::cadastrarUsuario( string nome, string senha, int id){
	
	Usuario novo(nome, senha, id);
	return novo;
}

//Cadastra novos usuários e os adiciona à gerencia
Funcionario Funcionario::cadastrarFuncionario( string nome, string senha, int id){
	
	Funcionario novo(nome, senha, id);
	return novo;
}
