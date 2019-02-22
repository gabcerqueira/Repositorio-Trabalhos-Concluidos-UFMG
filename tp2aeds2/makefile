MINGW_VERSION=4.7.0
FOLDER=C:

all: main.exe

tp2.o:	tp2.c	tp2.h
	gcc -c -Wall tp2.c


main.exe:	tp2.o
	gcc -Wall main.c tp2.o



clean:
	del tp2.o
	del main.exe