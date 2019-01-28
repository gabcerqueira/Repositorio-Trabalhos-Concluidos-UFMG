#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Item.hpp"
#include "Multimidia.hpp"

TEST_CASE("Testa Construtor e disponibilidade"){

	Multimidia novo("O Poderoso Chefao", "Francis Ford Coppola", "Paramount", "Filme", true);
	novo.setTipo("Filme");
	novo.setDisponibilidade(true);

	if(novo.isDisponivel() == true){
		REQUIRE(novo.getTipo() == "Filme");
		novo.mudarDisponibilidade();
		REQUIRE(novo.isDisponivel() == false);
	}

}
