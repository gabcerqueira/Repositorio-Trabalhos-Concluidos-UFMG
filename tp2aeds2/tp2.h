#ifndef TP2_H_INCLUDED
#define TP2_H_INCLUDED
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>


#define maxtam1 500
#define maxtam2 5000
#define maxtam3 50000
#define maxtam4 300000





//Algoritmos de ordenação




//inserção

void insercao (int v[],int tam);



//seleção

void selecao (int v[],int tam);



//shellsort


void shellsort(int v[], int tam);





//quicksort

void quicksort(int v[], int tam);







//heapsort




void peneira(int *vet, int raiz, int fundo);

void heapsort(int *vet, int n);

void criarvetor(int v[],int tam,int menu);

void calctempo(int v[],int tam,int valor,int numvet);


#endif