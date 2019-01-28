#include "Biblioteca.hpp"

//os numeros que representam e diferenciam usuarios e funcionarios no sistema
const int pessoaUsuario = 1;
const int pessoaFuncionario = 2;

Biblioteca::Biblioteca()
{
		
	usuario = nullptr;
	funcionario = nullptr;
	administrador = nullptr;
	acervo = nullptr;
}

void Biblioteca::interfacePrincipal(){
	
    usuario = new Usuario(); 
	funcionario = new Funcionario();
	administrador= new Gerencia();
	acervo= new Acervo();
	
	Usuario padrao("Padrao","1234",4567);
	
	Funcionario base("Base","0000",1234);
	
	administrador->setUsuarioCadastrado(padrao);
	
	administrador->setFuncionarioCadastrado(base);
	
	acervo->inicializarAcervo();
	
	interfaceUsuario();
	
	desalocaDados();
}

//identifica o tipo da pessoa que acessa o sistema para disponibilizar sua respectiva interface
int Biblioteca::determinaInterface(){
	string tipoInt;
	int interface = 0;
	
	while(interface<pessoaUsuario||interface>pessoaFuncionario){
		cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
		cout<<"\n                        BEM VINDO AO SISTEMA DE BIBLIOTECA                         \n"<<endl;
		
		cout<<"Voce deseja acessar o sistema como:\n"<<endl;
		cout<<"Usuario da Biblioteca(1)\n"<<endl;
		cout<<"Funcionario da Biblioteca(2)\n"<<endl;
		getline(cin,tipoInt);
		
		try{
			interface=std::stoi( tipoInt );
		}
		catch(std::invalid_argument &invalid){
			interface=0;
		}

	}
	
	return interface;
}

//interface com login/cadastro e menu para usuario/funcionario
void Biblioteca::interfaceUsuario(){
	
	int execucao =1;
	int acesso=0;
	char decisao=' ';
	int interfaceTipo=0;

	while(execucao){

		interfaceTipo=determinaInterface();

		acesso=telaInicial(interfaceTipo);

		while(acesso){
			
			if(interfaceTipo == pessoaUsuario){
				menuUsuario();
				acesso=0;
				
			}
			
			if(interfaceTipo == pessoaFuncionario){
				menuFuncionario();
				acesso=0;
			}		

		}
			
			while(decisao!= 's'&& decisao!= 'n'){
			cout<<"\n--------------------------------------------------------------------------------\n"<<endl;	
				cout<<"Deseja sair do sistema?(s/n)\n"<<endl;
				cin>>decisao;
				
				cin.ignore();
			}
			
			if(decisao == 's'){
				execucao=0;
			}
			if(decisao== 'n')
				decisao=' ';
			
	}
}

//Tela de inicio comum à interface do usuario e à interface do funcionario
int Biblioteca::telaInicial(int tipoUsuario){
	int telaCadastro=1;
	int telaCadastro2=1;
	int telaInicio = 1;
	int acessoPermitido = 0;
	char cadastroExistente = ' ';
	char cadastrar = ' ';
	char novaTentativa = ' ';
	int idCadastro;
	string idString;
	string nomeCadastro;
	string senhaCadastro;
	
	while(telaInicio){
		cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
		
		try{
			while(cadastroExistente != 'n' && cadastroExistente != 's'){	
			
				cout<<"Voce possui cadastro na biblioteca?(s/n)\n"<<endl;
				cin>> cadastroExistente;
			}
					
				if(cadastroExistente == 's'){
					
					acessoPermitido=login(tipoUsuario);
					return acessoPermitido;
				}
						
				if(cadastroExistente == 'n')
					throw LoginInvalido();
		}
			
			catch(LoginInvalido& invalido){
				
				if(tipoUsuario==pessoaUsuario){
					
					while(telaCadastro){
						
						while(cadastrar != 'n' && cadastrar != 's'){	
						
							cout<<"Voce deseja realizar um cadastro na biblioteca?(s/n)\n"<<endl;
							
							cin>> cadastrar;
						}
						
						if(cadastrar == 's'){
							
							while(telaCadastro2){
								
								cin.ignore();
								cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
								cout<<"\n                                    CADASTRO                                     \n"<<endl;
								cout<<"Digite seu id(inteiro) e sua senha\n"<<endl;
								getline(cin,idString);
								
								try{
									idCadastro=std::stoi(idString);	
								}
								
								catch(std::invalid_argument &e){
									
									cout<<"Id Invalido, falha em realizar cadastro\n"<<endl;
									return 0;									
								}
								

									
								getline(cin,senhaCadastro);
								
								cout<<"Digite seu nome Completo\n"<<endl;
								getline(cin,nomeCadastro);
									
								if(administrador->pesquisaUsuario(idCadastro,senhaCadastro)){
										
									cout<<"Erro ao realizar cadastro\n"<<endl;
																
									cout<<"Tentar novamente?(s/n)\n"<<endl;
										
									while(novaTentativa!='s'||novaTentativa!='n')
										cin>>novaTentativa;
										
									if(novaTentativa == 'n')
										return 0;
								}
						
								else
									cout<<"Usuario cadastrado com sucesso\n"<<endl;
									administrador->setUsuarioCadastrado(funcionario->cadastrarUsuario(nomeCadastro,senhaCadastro,idCadastro));
									return 0;
								
							}
						}	
							
						if(cadastrar == 'n')
							return 0;	
					}
				}
				
				if(tipoUsuario == pessoaFuncionario){
					
					cout<<"Acesso negado: Confira seu id e senha ou realize um cadastro\n"<<endl;
					return 0;
				}
			}
	}
	
		
}	

//login retorna 1 caso o acesso seja valido
int Biblioteca::login(int tipoUsuario){
	
	int idUsuario;
	string idUser;
	string senhaUsuario;
	cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
	cout<<"\n                                ENTRAR NO SISTEMA                                \n"<<endl;
	cout<<"Digite O seu ID e sua senha\n"<<endl;
	
	cin.ignore();
	getline(cin,idUser);
	getline(cin,senhaUsuario);
	
	try{
		idUsuario=std::stoi(idUser);
	}
	
	catch(std::invalid_argument &e){
		cout<<"Acesso negado: Confira seu id\n"<<endl;
		throw LoginInvalido();
	}
	
	if(tipoUsuario == pessoaUsuario){
		
		if(administrador->pesquisaUsuario(idUsuario,senhaUsuario)){
			
			usuario->setId(idUsuario);
			usuario->setSenha(senhaUsuario);
			administrador->atribuiParametrosUsuario(usuario);
			return 1;
		}
	
		else
			cout<<"Acesso negado: Confira seu id e senha ou realize um cadastro\n"<<endl;
			throw LoginInvalido();
	}
		
	if(tipoUsuario == pessoaFuncionario){

		if(administrador->pesquisaFuncionario(idUsuario,senhaUsuario)){
			
			funcionario->setId(idUsuario);
			funcionario->setSenha(senhaUsuario);
			administrador->atribuiParametrosFuncionario(funcionario);			
			return 1;
		}
		
		else
			throw LoginInvalido();
	}	
}

void Biblioteca::menuUsuario(){
	string stringOperacao;
	string nomeLivro;
	string autorLivro;
	string editoraLivro;
	string nomeMultimidia;
	string autorMultimidia;
	string tipoMultimidia;
	string stringPesquisa;
	int menu=1;
	int operacao=0;
	int tipoPesquisa=0;
	
	while(menu){
		
		cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
		cout<<"\n                                      MENU                                       \n"<<endl;
		while(operacao<1||operacao>11){
			
			cout<<"Qual operacao voce deseja realizar?(1/2/3/4/5/6/7/8/9/10/11)\n"<<endl;
			
			cout<<"(1)Reservar Livro\n"<<endl;
			cout<<"(2)Alugar Livro\n"<<endl;
			cout<<"(3)Devolver Livro\n"<<endl;
			cout<<"(4)Reservar Multimidia\n"<<endl;
			cout<<"(5)Alugar Multimidia\n"<<endl;
			cout<<"(6)Devolver Multimidia\n"<<endl;
			cout<<"(7)Imprimir livros alugados\n"<<endl;
			cout<<"(8)Imprimir livros reservados\n"<<endl;
			cout<<"(9)Pesquisar por livro\n"<<endl;
			cout<<"(10)Pesquisar por multimidia\n"<<endl;
			cout<<"(11)Fazer logoff\n"<<endl;
			
			getline(cin,stringOperacao);
			try{
				operacao=std::stoi(stringOperacao);
			}
			catch(std::invalid_argument &arg){
				operacao=0;
			}
		}
		
		if(operacao==1){
			cout<<"\n--------------------------------------------------------------------------------\n"<<endl;

			
			cout<<"Digite o titulo, o autor e a editora do livro que voce quer reservar\n"<<endl;
			
			getline(cin,nomeLivro);
			getline(cin,autorLivro);
			getline(cin,editoraLivro); 
						
			Livro livroReservado;
			
			livroReservado.setTitulo(nomeLivro);
			livroReservado.setAutor(autorLivro);
			livroReservado.setEditora(editoraLivro);
			
			if(acervo->pesquisaLivro(livroReservado)){
				
				acervo->mudarDisponibilidadeLivro(livroReservado);
				usuario->reservarLivro(livroReservado);
				cout<<"Livro reservado com sucesso\n"<<endl;
			}
			if(!acervo->pesquisaLivro(livroReservado))
				cout<<"Livro nao esta disponivel para reserva\n"<<endl;
			operacao=0;
		}
			
		if(operacao==2){	
			cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
			cout<<"Digite o titulo, o autor e a editora do livro que voce quer alugar\n"<<endl;
			
			getline(cin,nomeLivro);
			getline(cin,autorLivro);
			getline(cin,editoraLivro); 
			
			Livro livroAlugado;
			
			livroAlugado.setTitulo(nomeLivro);
			livroAlugado.setAutor(autorLivro);
			livroAlugado.setEditora(editoraLivro);
			
			if(acervo->pesquisaLivro(livroAlugado)){
				
				acervo->mudarDisponibilidadeLivro(livroAlugado);
				usuario->alugarLivro(livroAlugado);
				cout<<"Livro alugado com sucesso\n"<<endl;
			}
			if(!acervo->pesquisaLivro(livroAlugado))
				cout<<"Livro nao esta disponivel para aluguel\n"<<endl;
			operacao=0;
						
		}
		
		if(operacao==3){
			cout<<"\n--------------------------------------------------------------------------------\n"<<endl;		
			cout<<"Digite o titulo e o autor do livro que voce quer devolver\n"<<endl;
			
			getline(cin,nomeLivro);
			getline(cin,autorLivro);			
			
			usuario->devolverLivro(nomeLivro);
			
			Livro livroDevolvido;
			
			livroDevolvido.setTitulo(nomeLivro);
			livroDevolvido.setAutor(autorLivro);
			
			
			acervo->mudarDisponibilidadeLivro(livroDevolvido);
			operacao=0;
		}
		
		if(operacao==4){	
			cout<<"\n--------------------------------------------------------------------------------\n"<<endl;

			cout<<"Digite o titulo, o autor e o tipo da multimidia que voce quer reservar\n"<<endl;
			
			getline(cin,nomeMultimidia);
			getline(cin,autorMultimidia);
			getline(cin,tipoMultimidia);

			
			Multimidia multimidiaReservado;
			
			multimidiaReservado.setTitulo(nomeMultimidia);
			multimidiaReservado.setAutor(autorMultimidia);
			multimidiaReservado.setTipo(tipoMultimidia);
			
			if(acervo->pesquisaMultimidia(multimidiaReservado)){			
				acervo->mudarDisponibilidadeMultimidia(multimidiaReservado);
				usuario->reservarMultimidia(multimidiaReservado);
				cout<<"Multimidia reservada com sucesso\n"<<endl;
			}
			if(!acervo->pesquisaMultimidia(multimidiaReservado))
				cout<<"Multimidia nao esta disponivel para reserva\n"<<endl;
			operacao=0;
		}
		
		if(operacao==5){
			cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
			
			cout<<"Digite o titulo, o autor e o tipo da multimidia que voce quer alugar:\n"<<endl;
			
			getline(cin,nomeMultimidia);
			getline(cin,autorMultimidia);
			getline(cin,tipoMultimidia);
			
			Multimidia multimidiaAlugado;
			
			multimidiaAlugado.setTitulo(nomeMultimidia);
			multimidiaAlugado.setAutor(autorMultimidia);
			multimidiaAlugado.setTipo(tipoMultimidia);
				
			if(acervo->pesquisaMultimidia(multimidiaAlugado)){			
				acervo->mudarDisponibilidadeMultimidia(multimidiaAlugado);
				usuario->alugarMultimidia(multimidiaAlugado);
				cout<<"Multimidia alugada com sucesso\n"<<endl;
			}
			
			if(!acervo->pesquisaMultimidia(multimidiaAlugado))
				cout<<"Multimidia nao esta disponivel para aluguel\n"<<endl;
			
			operacao=0;
		}
		
		if(operacao==6){
			cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
			
			cout<<"Digite o titulo e o autor da multimidia que voce quer devolver:\n"<<endl;
			
			getline(cin,nomeMultimidia);
			getline(cin,autorMultimidia);				
			
			usuario->devolverMultimidia(nomeMultimidia);
			
			Multimidia multimidiaDevolvido;
			
			multimidiaDevolvido.setTitulo(nomeMultimidia);
			multimidiaDevolvido.setAutor(autorMultimidia);
			
			acervo->mudarDisponibilidadeMultimidia(multimidiaDevolvido);
			operacao=0;
		}
		
		if(operacao==7){	
			usuario->imprimeLivrosAlugados();
			operacao=0;
		}
		
		if(operacao==8){	
			usuario->imprimeLivrosReservados();
			operacao=0;
		}
		
		if(operacao==9){
			cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
			while(tipoPesquisa<1||tipoPesquisa>3){
				
				cout<<"Voce deseja pesquisar por :\n"<<endl;
				cout<<"(1)Titulo do livro\n"<<endl;
				cout<<"(2)Nome do autor\n"<<endl;
				cout<<"(3)Nome da editora\n"<<endl;
				
				getline(cin,stringPesquisa);
				try{
					tipoPesquisa=std::stoi(stringPesquisa);
				}
				catch(std::invalid_argument &argu){
					tipoPesquisa=0;
				}
			}
			if(tipoPesquisa==1){
				cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
				
				cout<<"Digite o titulo do livro que voce deseja pesquisar:\n";
				
				getline(cin,nomeLivro);
				
				acervo->procuraLivro(nomeLivro,tipoPesquisa);
				tipoPesquisa=0;
				operacao=0;
			}
				
			if(tipoPesquisa==2){
				cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
				
				cout<<"Digite o autor do livro que voce deseja pesquisar:\n"<<endl;
				
				getline(cin,autorLivro);
				
				acervo->procuraLivro(autorLivro,tipoPesquisa);
				tipoPesquisa=0;
				operacao=0;
			}
				
			if(tipoPesquisa==3){
				cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
				cout<<"Digite a editora do livro que voce deseja pesquisar:\n"<<endl;
				getline(cin,editoraLivro);
				
				acervo->procuraLivro(editoraLivro,tipoPesquisa);
				tipoPesquisa=0;
				operacao=0;
			}
			
		}
		
		if(operacao==10){	
		
			while(tipoPesquisa<1||tipoPesquisa>2){
				cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
				cout<<"Voce deseja pesquisar por :\n"<<endl;
				cout<<"(1)Titulo da multimidia\n"<<endl;
				cout<<"(2)Nome do autor\n"<<endl;
				
				getline(cin,stringPesquisa);
				try{
					tipoPesquisa=std::stoi(stringPesquisa);
				}
				catch(std::invalid_argument &argume){
					tipoPesquisa=0;
				}
			}
			
			if(tipoPesquisa==1){
				cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
				cin.ignore();
				
				cout<<"Digite o titulo da multimidia que voce deseja pesquisar:\n"<<endl;
				
				getline(cin,nomeMultimidia);
				
				acervo->procuraMultimidia(nomeMultimidia,tipoPesquisa);
				tipoPesquisa=0;
				operacao=0;
			}
				
			if(tipoPesquisa==2){
				cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
				cin.ignore();
				
				cout<<"Digite o autor da multimidia que voce deseja pesquisar:\n"<<endl;
				
				getline(cin,autorMultimidia);
				
				acervo->procuraLivro(autorMultimidia,tipoPesquisa);
				tipoPesquisa=0;
				operacao=0;
			}
		}
		
		if(operacao==11){
			menu=0;
		}
	}	
}

void Biblioteca::menuFuncionario(){
	
	int menu=1;
	int operacao=0;
	string nomeLivro,autorLivro,editoraLivro,nomeMultimidia,autorMultimidia,produtoraMultimidia,tipoMultimidia;
	string nomeUsuario,senhaUsuario,nomeFuncionario,senhaFuncionario;
	int userFuncionario,userUsuario;
	string idUser,idServer,stringOperacao;
	int idValido=1;
	
	
	while(menu){

		while(operacao<1||operacao>9){
			cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
			cout<<"\n                                      MENU                                       \n"<<endl;
			cout<<"Qual operacao voce deseja realizar?(1/2/3/4/5/6/7/8/9)\n"<<endl;
			
			cout<<"(1)Adicionar livro ao acervo da bibliteca\n"<<endl;
			cout<<"(2)Remover livro do acervo da biblioteca\n"<<endl;
			cout<<"(3)Adicionar multimidia ao acervo da bibliteca\n"<<endl;
			cout<<"(4)Remover multimidia do acervo da biblioteca\n"<<endl;
			cout<<"(5)Cadastrar novo usuario da biblioteca\n"<<endl;
			cout<<"(6)Cadastrar novo funcionario da biblioteca\n"<<endl;
			cout<<"(7)Imprimir colecao de livros\n"<<endl;
			cout<<"(8)Imprimir colecao de multimidia\n"<<endl;
			cout<<"(9)Fazer logoff\n"<<endl;
			
			getline(cin,stringOperacao);
			try{
				operacao=std::stoi(stringOperacao);
			}
			catch(std::invalid_argument &arg){
				operacao=0;
			}
		}
		
		if(operacao == 1){
			cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
			
			cout<<"Digite o titulo, o autor e a editora do livro que voce quer adicionar:\n"<<endl;
			
			getline(cin,nomeLivro);
			getline(cin,autorLivro);		
			getline(cin,editoraLivro);
					
			funcionario->adicionarLivros(acervo,nomeLivro,autorLivro,editoraLivro);
			std::cout<<"Livro adicionado com sucesso\n"<<std::endl;
			operacao=0;
		}
			
		
		if(operacao == 2){
			cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
			
			cout<<"Digite o titulo, o autor e a editora do livro que voce quer remover:\n"<<endl;
			
			getline(cin,nomeLivro);
			getline(cin,autorLivro);			
			getline(cin,editoraLivro);
			
			funcionario->removerLivros(acervo,nomeLivro,autorLivro,editoraLivro);
			operacao=0;
		}	
		
		
		if(operacao == 3){
			cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
		
			cout<<"Digite o titulo, o autor,a produtora e o tipo da multimidia que voce quer adicionar:\n"<<endl;
			
			getline(cin,nomeMultimidia);
			getline(cin,autorMultimidia);
			getline(cin,produtoraMultimidia);
			
			cin>>tipoMultimidia;
			
			funcionario->adicionarMultimidias(acervo,nomeMultimidia,autorMultimidia,produtoraMultimidia,tipoMultimidia);
			std::cout<<"Multimidia adicionada com sucesso\n"<<std::endl;	
			operacao=0;
		}	

		if(operacao == 4){
			cout<<"\n--------------------------------------------------------------------------\n"<<endl;
				
			cout<<"Digite o titulo, o autor,a produtora e o tipo da multimidia que voce quer remover:\n"<<endl;
			
			getline(cin,nomeMultimidia);
			getline(cin,autorMultimidia);
			getline(cin,produtoraMultimidia);
			getline(cin,tipoMultimidia);
			
			funcionario->removerMultimidias(acervo,nomeMultimidia,autorMultimidia,produtoraMultimidia,tipoMultimidia);
			operacao=0;
		}			
		
		if(operacao==5){
			cout<<"\n--------------------------------------------------------------------------------\n"<<endl;

			
			cout<<"Digite o nome completo:\n"<<endl;
			
			getline(cin,nomeUsuario);
			
			cout<<"Digite o login(numero inteiro) e uma nova senha para o usuario:\n"<<endl;
			
			getline(cin,idUser);
			
			try{
				userUsuario=std::stoi(idUser);
			}
			catch(std::invalid_argument & inva){
				idValido=0;
				operacao=0;
			}
			getline(cin,senhaUsuario);
			
			if(administrador->pesquisaUsuario(userUsuario,senhaUsuario)){
				cout<<"Erro: esse usuario ja esta cadastrado\n"<<endl;
				operacao=0;
			}
			else
				if(idValido){
					
					cout<<"Usuario cadastrado com sucesso\n"<<endl;
					administrador->setUsuarioCadastrado(funcionario->cadastrarUsuario(nomeUsuario,senhaUsuario,userUsuario));
					operacao=0;
				}
				else
					cout<<"Falha em cadastrar Usuario: Id invalido\n"<<endl;
					idValido=1;
		}
		
		if(operacao==6){
			cout<<"\n--------------------------------------------------------------------------------\n"<<endl;
			
			cout<<"Digite o nome completo:\n"<<endl;
			getline(cin,nomeFuncionario);
			
			cout<<"Digite o login(numero inteiro) e uma nova senha para o funcionario:\n"<<endl;
			getline(cin,idServer);
			
			try{
				userFuncionario=std::stoi(idServer);
			}
			catch(std::invalid_argument &inv){

				operacao=0;
				idValido=0;
			}
			getline(cin,senhaFuncionario);
			
			if(administrador->pesquisaFuncionario(userFuncionario,senhaFuncionario)){
				cout<<"Erro: esse funcionario ja esta cadastrado\n"<<endl;
				operacao=0;
			}
			
			else
				if(idValido){
					cout<<"Funcionario cadastrado com sucesso\n"<<endl;
					administrador->setFuncionarioCadastrado(funcionario->cadastrarFuncionario(nomeFuncionario,senhaFuncionario,userFuncionario));	
					operacao=0;
				}
				else
					cout<<"Falha em cadastrar Funcionario: Id invalido\n"<<endl;
					idValido=1;
		}
		
		if(operacao == 7){
			cout<<"\n--------------------------------------------------------------------------------\n"<<endl;	
			acervo->listarLivros();
			operacao=0;
		}
			
		if(operacao == 8){
			cout<<"\n--------------------------------------------------------------------------------\n"<<endl;	
			acervo->listarMultimidia();
			operacao=0;
		}
		
		if(operacao == 9){
			menu=0;
		}
	}	
}

void Biblioteca::desalocaDados(){
	delete usuario;
	delete funcionario;
	delete administrador;
	delete acervo;
}
	
Biblioteca::~Biblioteca(){

}