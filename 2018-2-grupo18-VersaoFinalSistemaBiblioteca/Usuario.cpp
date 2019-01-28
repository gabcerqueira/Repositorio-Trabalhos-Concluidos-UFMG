#include "Usuario.hpp"

Usuario::Usuario(){}

Usuario::Usuario(string nome, string senha, int id) : Pessoa(nome,senha,id){}

void Usuario::alugarLivro(Livro item){
	 
	//fazer as excecoes pro teste: nao pode ser item nulo, nem indisponivel
	_livrosAlugados.push_back(item);
}

void Usuario::reservarLivro(Livro item){
   
  //fazer as excecoes pro teste: nao pode ser item nulo, nem indisponivel
  _livrosReservados.push_back(item);
}

void Usuario::devolverLivro(string item){
	for(int i=0;i <_livrosAlugados.size() ;i++){
		
		if(_livrosAlugados[i].getTitulo() == item){
				_livrosAlugados.erase(_livrosAlugados.begin()+i);
		}
	}
}

void Usuario::alugarMultimidia(Multimidia item){
	 
	_multimidiaAlugados.push_back(item);
}

void Usuario::reservarMultimidia(Multimidia item){
  
  _multimidiaReservados.push_back(item);
}

void Usuario::devolverMultimidia(string item){
	
	int naoExiste=0;
	
	for(int i=0;i <_multimidiaAlugados.size() ;i++){
		
		if(_multimidiaAlugados[i].getTitulo() == item){
				_multimidiaAlugados.erase(_multimidiaAlugados.begin()+i);
				cout<<"Multimidia devolvida com sucesso"<<endl;
		}
		else
			naoExiste++;
	}
	if(naoExiste==_multimidiaAlugados.size())
		cout<<"esta multimidia nao estava alugada"<<endl;
}

void Usuario::imprimeLivrosAlugados(){

  if(_livrosAlugados.empty()){
    cout<<"Voce nao possui nenhum livro alugado"<<endl;    
  }
	else	
		for(int i=0; i<_livrosAlugados.size(); i++){
			_livrosAlugados[i].imprimeCampos();
		}
}

void Usuario::imprimeMultimidiaAlugados(){

  if(_multimidiaAlugados.empty()){
    cout<<"Voce nao possui nenhuma multimidia alugada\n"<<endl; 
  }
	else	
		for(int i=0; i<_multimidiaAlugados.size(); i++){
			_multimidiaAlugados[i].imprimeCampos();
		}
}

void Usuario::imprimeLivrosReservados(){

  if(_livrosReservados.empty()){
    cout<<"Voce nao possui nenhum livro reservado\n"<<endl;   
  }

  else
	  for(int i=0; i<_livrosReservados.size(); i++){
		_livrosReservados[i].imprimeCampos();
		}
}

void Usuario::imprimeMultimidiaReservados(){

  if(_livrosReservados.empty()){
    cout<<"Voce nao possui nenhuma multimidia reservada\n"<<endl;    
  }

  else 
	  for(int i=0; i<_multimidiaReservados.size(); i++){
		_multimidiaReservados[i].imprimeCampos();
	  }
}

void Usuario::atribuiItens(Usuario *usuario){
	int i;

	if(!_livrosAlugados.empty()){

		for(i=0;i<_livrosAlugados.size();i++){
			usuario->_livrosAlugados.push_back(_livrosAlugados[i]);
		}

	}
	if(!_livrosReservados.empty()){

		for(i=0;i<_livrosReservados.size();i++){
			usuario->_livrosReservados.push_back(_livrosReservados[i]);
		}

	}
	if(!_multimidiaAlugados.empty()){

		for(i=0;i<_multimidiaAlugados.size();i++){
			usuario->_multimidiaAlugados.push_back(_multimidiaAlugados[i]);
		}

	}
	if(!_multimidiaReservados.empty()){
		
		for(i=0;i<_multimidiaReservados.size();i++){
			usuario->_multimidiaReservados.push_back(_multimidiaReservados[i]);
		}

	}
}