#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Acervo.hpp"
#include "Item.cpp"
#include "Livro.hpp"
#include "Multimidia.hpp"

TEST_CASE("Teste adicionar, remover e pesquisar livro"){

	Acervo atual;

	atual.setAcervoTotalLivro(0);

	Livro novo("Guerra e Paz", "Liev Tolstoi", "Globo", true);

	atual.adicionarLivro(novo);

	if(atual.pesquisaLivro(novo) == 1 && atual.getAcervoTotalLivro() == 1){
 		atual.removerLivro(novo);
 		REQUIRE(atual.pesquisaLivro(novo) == 0);
	}

}

TEST_CASE("Teste adicionar, remover e pesquisar multimidia"){

	Acervo atual;

	atual.setAcervoTotalMultimidia(0);

	Multimidia novo("O Poderoso Chefao", "Francis Ford Coppola", "Paramount", "Filme", true);

	atual.adicionarMultimidia(novo);

	if(atual.pesquisaMultimidia(novo) == 1 && atual.getAcervoTotalMultimidia() == 1){
 		atual.removerMultimidia(novo);
 		REQUIRE(atual.pesquisaMultimidia(novo) == 0);
	}

}

TEST_CASE("Sets e get acervo total e mudança de disponibilidade"){

	Acervo atual;

	atual.setAcervoTotal(0,0);

	Livro livro("Guerra e Paz", "Liev Tolstoi", "Globo", true);
	Multimidia multi("O Poderoso Chefao", "Francis Ford Coppola", "Paramount", "Filme", true);

	atual.adicionarLivro(livro);
	atual.adicionarMultimidia(multi);

	atual.mudarDisponibilidadeLivro(livro);
	atual.mudarDisponibilidadeMultimidia(multi);

	if(livro.isDisponivel() == false && multi.isDisponivel() == false){
		REQUIRE(atual.getAcervoTotal() == (atual.getAcervoTotalLivro() + atual.getAcervoTotalMultimidia()));
	}

}
