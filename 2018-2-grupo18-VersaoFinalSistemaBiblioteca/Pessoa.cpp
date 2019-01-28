#include "Pessoa.hpp"

	Pessoa::Pessoa(){}
	
	Pessoa::Pessoa(string nome, string senha, int id){
		setNome(nome);
		setSenha(senha);
		setId(id);
			
	}
	
	void Pessoa::setNome(string nome){
		this->_nome = nome;
	}
		
	void Pessoa::setSenha(string senha){
		this->_senha = senha;
	}
		
	void Pessoa::setId(int id){
			
		this->_id = id;
	}
		
	string Pessoa::getNome(){
		return _nome;
	}
		
	string Pessoa::getSenha(){
		return _senha;
	}
		
	int Pessoa::getId(){
		return _id;
	}
	