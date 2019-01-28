#include "Gerencia.hpp"

Gerencia::Gerencia(){}

void Gerencia::setUsuarioCadastrado(Usuario novo){
	
	_usuariosCadastrados.push_back(novo);
}

void Gerencia::setFuncionarioCadastrado(Funcionario novo){
	
	_funcionariosCadastrados.push_back(novo);
}

int Gerencia::pesquisaFuncionario(int idCadastro, string senhaCadastro){
	
	for(int i=0; i < _funcionariosCadastrados.size(); i++){
		
		if(_funcionariosCadastrados[i].getId() == idCadastro && _funcionariosCadastrados[i].getSenha() == senhaCadastro){
			return 1;	
		}
	}
	return 0;
}

int Gerencia::pesquisaUsuario(int idCadastro, string senhaCadastro){
	
	for(int i=0; i < _usuariosCadastrados.size(); i++){
		
		if(_usuariosCadastrados[i].getId() == idCadastro && _usuariosCadastrados[i].getSenha() == senhaCadastro){
			return 1;
		}			
	}
	return 0;	
}

void Gerencia::atribuiParametrosUsuario(Usuario *usuario){

	int i=0;

	for(int i=0;i<_usuariosCadastrados.size();i++)
		
		if(usuario->getId() ==_usuariosCadastrados[i].getId()&&usuario->getSenha()==_usuariosCadastrados[i].getSenha()){
			
			usuario->setNome(_usuariosCadastrados[i].getNome());
			_usuariosCadastrados[i].atribuiItens(usuario);

		}

}

void Gerencia::atribuiParametrosFuncionario(Funcionario *funcionario){
		int i=0;

	for(int i=0;i<_funcionariosCadastrados.size();i++)
		
		if(funcionario->getId() ==_funcionariosCadastrados[i].getId()&&funcionario->getSenha()==_funcionariosCadastrados[i].getSenha()){
			
			funcionario->setNome(_funcionariosCadastrados[i].getNome());

		}

}
