#include "Acervo.hpp"

Acervo::Acervo(){}

void Acervo::setAcervoTotal(int totalLivro,int totalMultimidia){
	
	_acervoTotalLivro = totalLivro;
	_acervoTotalMultimidia = totalMultimidia;
}

void Acervo::setAcervoTotalMultimidia(int totalMultimidia){
	
	_acervoTotalMultimidia = totalMultimidia;
}

void Acervo::setAcervoTotalLivro(int totalLivro){
	
	_acervoTotalLivro = totalLivro;
}

int Acervo::getAcervoTotal(){

	return _acervoTotalLivro + _acervoTotalMultimidia;
}

int Acervo::getAcervoTotalLivro(){

	return this->_acervoTotalLivro ;
}

int Acervo::getAcervoTotalMultimidia(){

	return  this->_acervoTotalMultimidia;
}

void Acervo::listarLivros(){

	for(int i=0;i<_acervoLivro.size();i++){

			_acervoLivro[i].imprimeCampos();
	}

}

void Acervo::listarMultimidia(){

	for(int i=0;i<_acervoMultimidia.size();i++){

			_acervoMultimidia[i].imprimeCampos();

	}
}

void Acervo::procuraLivro(string livro,int campo){
	
		int naoExiste=0;
		int i;
		
		if(campo==1){
			
			for(i=0;i <_acervoLivro.size();i++){
			
				if(_acervoLivro[i].getTitulo() == livro){
					_acervoLivro[i].imprimeCampos();
					naoExiste--;
				}
				naoExiste++;
			}
			if(naoExiste==_acervoLivro.size())
				cout<<"Esse livro nao existe na colecao\n"<<endl;
		}
		if(campo==2){
			
			for(i=0;i <_acervoLivro.size();i++){
			
				if(_acervoLivro[i].getAutor()== livro){
					_acervoLivro[i].imprimeCampos();
					naoExiste--;
				}
				
				naoExiste++;
			}
			if(naoExiste==_acervoLivro.size())
				cout<<"Esse livro nao existe na colecao\n"<<endl;
		}
		if(campo==3){
			
			for(i=0;i < _acervoLivro.size();i++){
			
				if(_acervoLivro[i].getEditora() == livro){
					_acervoLivro[i].imprimeCampos();
					naoExiste--;
				}
				
				naoExiste++;
			}
			if(naoExiste==_acervoLivro.size())
				cout<<"Esse livro nao existe na colecao\n"<<endl;
		}			
}

void Acervo::procuraMultimidia(string multimidia, int campo){
	
		int naoExiste=0;
		int i;
		
		if(campo==1){
			
			for(i=0;i < _acervoMultimidia.size();i++){
			
				if(_acervoMultimidia[i].getTitulo() == multimidia){
					_acervoMultimidia[i].imprimeCampos();
					naoExiste--;
				}
				naoExiste++;
			}
			if(naoExiste==_acervoMultimidia.size())
				cout<<"Essa multimidia nao existe na colecao\n"<<endl;
		}
		
		if(campo==2){
			
			for(i=0; i < _acervoMultimidia.size(); i++){
			
				if(_acervoMultimidia[i].getAutor() == multimidia){
					_acervoMultimidia[i].imprimeCampos();
					naoExiste--;
				}
				naoExiste++;
			}
			if(naoExiste==_acervoMultimidia.size())
				cout<<"Essa multimidia nao existe na colecao\n"<<endl;
			
		}	
}

void Acervo::removerLivro(Livro livro){
	int naoExiste=0;
	int i;
	
	for(i=0;i < _acervoLivro.size();i++){
		
		if(_acervoLivro[i].getTitulo() == livro.getTitulo()){
			
			_acervoLivro.erase(_acervoLivro.begin()+i);
			setAcervoTotalLivro(_acervoLivro.size());
			std::cout<<"Livro removido com sucesso\n"<<std::endl;
			naoExiste=-1;
			break;
		}
		naoExiste++;
	}
	if(naoExiste==_acervoLivro.size())
		cout<<"Esse livro nao existe na colecao\n"<<endl;
}	


void Acervo::removerMultimidia(Multimidia multimidia){
	
	int naoExiste=0;
	int i;
	
		for(i=0;i < _acervoMultimidia.size();i++){
		
			if(_acervoMultimidia[i].getTitulo() == multimidia.getTitulo()){
				
				_acervoMultimidia.erase(_acervoMultimidia.begin()+i);
				setAcervoTotalMultimidia(_acervoMultimidia.size());
				std::cout<<"Multimidia removida com sucesso\n"<<std::endl;
				naoExiste=-1;
				break;
			}
			naoExiste++;
			
		}
		if(naoExiste==_acervoMultimidia.size())
			cout<<"Essa multimidia nao existe na colecao\n"<<endl;
			
}	

void Acervo::adicionarMultimidia(Multimidia multimidia){
		
	_acervoMultimidia.push_back(multimidia);
	setAcervoTotalMultimidia(_acervoMultimidia.size());	
}

void Acervo::adicionarLivro(Livro livro){
	
	_acervoLivro.push_back(livro);
	setAcervoTotalLivro(_acervoLivro.size());
}

void Acervo::mudarDisponibilidadeLivro(Livro livro){
	
	int i;
	int naoExiste=0;
	
	for(i=0;i < _acervoLivro.size();i++){
			
			if(_acervoLivro[i].getTitulo() == livro.getTitulo() && _acervoLivro[i].getAutor() == livro.getAutor()){
				_acervoLivro[i].mudarDisponibilidade();
				break;
			}
			naoExiste++;
		}

		if(naoExiste == _acervoLivro.size()){
			cout<<"Impossivel realizar operacao:Este livro nao esta na colecao\n"<<endl;
		}
		
}
void Acervo::mudarDisponibilidadeMultimidia(Multimidia multimidia){
	
	int i;
	int naoExiste=0;
	
	for(i=0;i < _acervoMultimidia.size();i++){
			
			if(_acervoMultimidia[i].getTitulo() == multimidia.getTitulo() && _acervoMultimidia[i].getAutor() == multimidia.getAutor()){
				
				_acervoMultimidia[i].mudarDisponibilidade();
				break;
			}
			naoExiste++;
		}
		
		if(naoExiste == _acervoMultimidia.size()){
			cout<<"Impossivel realizar operacao: Esta multimidia nao esta na colecao\n"<<endl;
		}
}

void Acervo::inicializarAcervo(){
	
	string titulo;
	string autor;
	string prod;
	string tipo;

	string line;

	ifstream inFileLivro; // inFile é o arquivo de leitura dos dados

	inFileLivro.open("Livros.txt", ios::in); // abre o arquivo para leitura

	if (!inFileLivro){
		cout << "Arquivo txt de livros nao pode ser aberto\n" << endl;
		abort();
	} 

	while(getline(inFileLivro, line)){
		stringstream ss(line);
		getline(ss, titulo, '/');
		getline(ss, autor, '/');
		getline(ss, prod, '/');

		Livro novo(titulo, autor, prod,true);    
                                                                           
		 adicionarLivro(novo); 
	}

	inFileLivro.close();
	
	ifstream inFileMultimidia; // inFile é o arquivo de leitura dos dados

	inFileMultimidia.open("Multimidias.txt", ios::in); // abre o arquivo para leitura

	if (!inFileMultimidia){
		
		cout << "Arquivo txt de multimidia nao pode ser aberto\n" << endl;
		abort();
	} 

	while(getline(inFileMultimidia, line)){
		
		stringstream ss(line);
		getline(ss, titulo, '/');
		getline(ss, autor, '/');
		getline(ss, prod, '/');
		getline(ss, tipo, '/');

		Multimidia nova(titulo, autor, prod,tipo,true);    
                                                                           
		 adicionarMultimidia(nova); 
	}
	
	inFileMultimidia.close();
}

int Acervo::pesquisaLivro(Livro livro){
	
	int i;
	
	for(i=0;i < _acervoLivro.size();i++){
			
			if(_acervoLivro[i].getTitulo() == livro.getTitulo() && _acervoLivro[i].getAutor() == livro.getAutor()){
				
				return 1;
			}
		}

		return 0;
}

int Acervo::pesquisaMultimidia(Multimidia multimidia){
	
	int i;
	
	for(i=0;i < _acervoMultimidia.size();i++){
			
			if(_acervoMultimidia[i].getTitulo() == multimidia.getTitulo() && _acervoMultimidia[i].getAutor() == multimidia.getAutor()){
				
				return 1;
			}
		}
		
		return 0;
}
