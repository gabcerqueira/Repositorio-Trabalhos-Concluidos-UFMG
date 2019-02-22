#include "tp2.h"
#include <stdio.h>
#include <stdbool.h>




//Algoritmos de ordenação
//insercao teste

 void insercao (int v[],int tam){
 int i=0;
 int j=1;
 int aux=0;
  while (j < tam){
 	aux = v[j];
 	i=j-1;
 	while ((i >= 0) && (v[i] > aux)){
 	v[i + 1] = v[i];
	 i=i-1;
 	}
 	v[i + 1]=aux;
 	j = j + 1;
  }
}


//seleção

void selecao (int v[],int tam){
   int i, j, min, x;
   for (i = 0; i < tam-1; ++i) {
      min = i;
      for (j = i+1; j < tam; ++j)
         if (v[j] < v[min])  min = j;
      x = v[i]; v[i] = v[min]; v[min] = x;
   }
}


//shellsort


void shellsort(int v[], int tam) {
    int i , j , value;
    int gap = 1;
    while(gap < tam) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < tam; i++) {
            value = v[i];
            j = i - gap;
            while (j >= 0 && value < v[j]) {
                v[j + gap] = v[j];
                j -= gap;
            }
            v[j + gap] = value;
        }
    }
}




//quicksort

void quicksort(int v[], int tam) {
    int i, j, p, t;
    if (tam < 2)
        return;
    p = v[tam / 2];
    for (i = 0, j = tam - 1;; i++, j--) {
        while (v[i] < p)
            i++;
        while (p < v[j])
            j--;
        if (i >= j)
            break;
        t = v[i];
        v[i] = v[j];
        v[j] = t;
    }
    quicksort(v, i);
    quicksort(v + i, tam - i);
}



//heapsort




void peneira(int *vet, int raiz, int fundo);

void heapsort(int *vet, int n) {
	int i, tmp;

	for (i = (n / 2); i >= 0; i--) {
		peneira(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		tmp = vet[0];
		vet[0] = vet[i];
		vet[i] = tmp;
		peneira(vet, 0, i-1);
	}
}

void peneira(int *vet, int raiz, int fundo) {
	int pronto, filhoMax, tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (vet[raiz * 2] > vet[raiz * 2 + 1]) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (vet[raiz] < vet[filhoMax]) {
		tmp = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = tmp;
		raiz = filhoMax;
    }
	else {
      pronto = 1;
	}
  }
}

void criarvetor(int v[],int tam,int menu){
	int i,j=0;
	if(menu==1){

		for(i=0;i<tam;i++){

			v[i]=rand()%maxtam4;
		
		}

	}

	if(menu==2){

		for(i=0;i<tam;i++){

			v[i]=i;
		
		}

	}


	if(menu==3){

	for(i=tam-1;i>=0;i--){

		v[j]=i;
		j++;

		}
	}
}


void calctempo(int v[],int tam,int valor,int numvet){

	clock_t t;//variável para armazenar tempo
	if(valor==1){

	//vetor 1

	t = clock(); //armazena tempo
	insercao(v,tam);
	t = clock() - t; //tempo final - tempo inicial

	 //imprime o tempo na tela
 	printf("\nTempo de execucao insercao vetor %d: %lf milisegundos\n",numvet, ((double)t)/((CLOCKS_PER_SEC/1000)));
	

	}

	else if(valor==2){

	//vetor 1

	t = clock(); //armazena tempo
	selecao(v,tam);
	t = clock() - t; //tempo final - tempo inicial

	 //imprime o tempo na tela
 	printf("\nTempo de execucao selecao vetor %d: %lf milisegundos\n",numvet, ((double)t)/((CLOCKS_PER_SEC/1000)));
	

	}

	else if(valor==3){

	//vetor 1

	t = clock(); //armazena tempo
	shellsort(v,tam);
	t = clock() - t; //tempo final - tempo inicial

	 //imprime o tempo na tela
 	printf("\nTempo de execucao shellsort vetor %d: %lf milisegundos\n",numvet, ((double)t)/((CLOCKS_PER_SEC/1000)));
	

	}

	else if(valor==4){

	//vetor 1

	t = clock(); //armazena tempo
	quicksort(v,tam);
	t = clock() - t; //tempo final - tempo inicial

	 //imprime o tempo na tela
 	printf("\nTempo de execucao quicksort vetor %d: %lf milisegundos\n",numvet, ((double)t)/((CLOCKS_PER_SEC/1000)));
	

	}

	else if(valor==5){

	//vetor 1

	t = clock(); //armazena tempo
	heapsort(v,tam);
	t = clock() - t; //tempo final - tempo inicial

	 //imprime o tempo na tela
 	printf("\nTempo de execucao heapsort vetor %d: %lf milisegundos\n",numvet, ((double)t)/((CLOCKS_PER_SEC/1000)));
	

	}

}


