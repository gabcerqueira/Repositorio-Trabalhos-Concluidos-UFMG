CC=g++
CFLAGS=-std=gnu++0x

all: main


Item.o: Item.hpp Item.cpp
	${CC} ${CFLAGS} -c Item.cpp

Livro.o: Livro.hpp Livro.cpp
	${CC} ${CFLAGS} -c Livro.cpp

Multimidia.o: Multimidia.hpp Multimidia.cpp
	${CC} ${CFLAGS} -c Multimidia.cpp

Acervo.o: Acervo.hpp Acervo.cpp
	${CC} ${CFLAGS} -c Acervo.cpp	

Pessoa.o: Pessoa.hpp Pessoa.cpp
	${CC} ${CFLAGS} -c Pessoa.cpp

Usuario.o: Usuario.hpp Usuario.cpp
	${CC} ${CFLAGS} -c Usuario.cpp

Funcionario.o: Funcionario.hpp Funcionario.cpp
	${CC} ${CFLAGS} -c Funcionario.cpp

Gerencia.o: Gerencia.hpp Gerencia.cpp
	${CC} ${CFLAGS} -c Gerencia.cpp

Biblioteca.o: Biblioteca.hpp Biblioteca.cpp
	${CC} ${CFLAGS} -c Biblioteca.cpp

main.o: Item.hpp Livro.hpp Multimidia.hpp Acervo.hpp Pessoa.hpp Usuario.hpp Funcionario.hpp Gerencia.hpp Biblioteca.hpp main.cpp
	${CC} ${CFLAGS} -c main.cpp

main: main.o  Item.o Livro.o Multimidia.o Acervo.o Pessoa.o Usuario.o Funcionario.o Gerencia.o Biblioteca.o
	${CC} ${CFLAGS} -o main main.o Item.o Livro.o Multimidia.o Acervo.o Pessoa.o Usuario.o Funcionario.o Gerencia.o Biblioteca.o

clean:
	rm -f main *.o