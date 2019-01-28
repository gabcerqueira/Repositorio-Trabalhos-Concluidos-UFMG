#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Pessoa.hpp"
#include "Funcionario.hpp"
#include "Usuario.hpp"
#include "Item.cpp"
#include "Livro.hpp"
#include "Multimidia.hpp"
#include "Acervo.hpp"

TEST_CASE("Testa funcoes para adicionar ou remover livros"){

	Funcionario novo("Admin", "0000", 0000);

	Acervo atual;

	Livro livro("Guerra e Paz", "Liev Tolstoi", "Globo", true);

	novo.adicionarLivros(atual, "Guerra e Paz", "Liev Tolstoi", "Globo");

	if(atual.pesquisaLivro(livro) == 1){
		novo.removerLivros(atual, "Guerra e Paz", "Liev Tolstoi", "Globo");
		REQUIRE(atual.pesquisaLivro(livro) == 0);
	}

}

TEST_CASE("Testa funcoes para adiconar ou remover multimidias"){

	Funcionario novo("Admin", "0000", 0000);

	Acervo atual;

	Multimidia multi("O Poderoso Chefao", "Francis Ford Coppola", "Paramount", "Filme", true);

	novo.adicionarMultimidia(atual, "O Poderoso Chefao", "Francis Ford Coppola", "Paramount", "Filme");

	if(atual.pesquisaMultimidia(multi)  == 1){
		novo.removerMultimidias(atual, "O Poderoso Chefao", "Francis Ford Coppola", "Paramount", "Filme");
		REQUIRE(atual.pesquisaMultimidia(multi)  == 0);
	}

}

TEST_CASE("Testa cadastro de usuarios e funcionarios"){

	Funcionario novo;
	novo.setNome("Admin");
	novo.setSenha("0000");
	novo.setId(0000);

	Usuario adm01 = novo.cadastrarUsuario("Admin01", "0001", 0001);
	Funcionario adm02 = novo.cadastrarUsuario("Admin02", "0002", 0002);

	if(adm01.getNome() == "Admin01" && adm01.getSenha == "0001"){
		REQUIRE(adm01.getId() == 0001);
	}

	if(adm02.getNome() == "Admin02" && adm01.getSenha == "0002"){
		REQUIRE(adm01.getId() == 0002);
	}

}
