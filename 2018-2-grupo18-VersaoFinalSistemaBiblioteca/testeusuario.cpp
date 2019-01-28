#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Pessoa.hpp"
#include "Usuario.hpp"
#include "Item.cpp"
#include "Livro.hpp"
#include "Multimidia.hpp"

TEST_CASE("Testa Construtor"){

	Usuario novo;
	novo.setNome("Admin");
	novo.setSenha("0000");
	novo.setId(0000);

	if(novo.getNome() == "Admin" && novo.getSenha() == "0000"){
		REQUIRE(novo.getId() == 0000);
	}

}

TEST_CASE("Testa funcoes com livro"){

	Usuario novo("Admin", "0000", 0000);

	Livro livro("Guerra e Paz", "Liev Tolstoi", "Globo", true);

	novo.reservarLivro(livro);
	novo.alugarLivro(livro);
	livro.mudarDisponibilidade();
	if(livro.isDisponivel() == false){
		novo.devolverLivro("Guerra e Paz");
		livro.mudarDisponibilidade();
		REQUIRE(livro.isDisponivel() == true);
	}

}

TEST_CASE("Testa funcoes com multimidia"){

	Usuario novo("Admin", "0000", 0000);

	Multimidia multi("O Poderoso Chefao", "Francis Ford Coppola", "Paramount", "Filme", true);

	novo.reservarMultimidia(multi);
	novo.alugarMultimidia(multi);
	multi.mudarDisponibilidade();
	if(multi.isDisponivel() == false){
		novo.devolverMultimidia("O Poderoso Chefao");
		multi.mudarDisponibilidade();
		REQUIRE(livro.isDisponivel() == true);
	}

}
