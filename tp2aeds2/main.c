/*Você deve implementar os algoritmos de ordenação e
realizar uma série de estudos teóricos sobre eles. Especificamente, implemente os algoritmos
Inserção, Seleção, Shellsort, Quicksort, Heapsort, e compare-os experimentalmente usando
vetores gerados aleatoriamente e vetores já ordenados (ordem crescente e decrescente).
Considere vetores com diferentes tamanhos em cada experimento. Relate os resultados
utilizando gráficos de tempo de execução em função do tamanho do vetor.*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include "tp2.h"



int main(){

	//clock_t t;//variável para armazenar tempo

	int valor=0,menu=0;
	int numvet=0;

	int v1[maxtam1];

	int v2[maxtam2];

	int v3[maxtam3];

	int v4[maxtam4];

	srand(time(NULL));

	printf(" Digite 1 para vetores aleatorios \n Digite 2 para vetores crescentes \n Digite 3 para vetores decrescentes \n");
	scanf("%d",&menu);


	if(menu==1){

	//geração dos vetores com numeros aleatorios

	criarvetor(v1,maxtam1,menu);
	criarvetor(v2,maxtam2,menu);
	criarvetor(v3,maxtam3,menu);
	criarvetor(v4,maxtam4,menu);



	//menu para ordenar os vetores aleatorios pelos diferentes métodos


	printf("\n Digite 1 para insercao \n Digite 2 para selecao \n Digite 3 para shellsort \n Digite 4 para quicksort \n Digite 5 para heapsort \n");
	scanf("%d",&valor);


 switch ( valor ){
    case 1 :

   	//ordenando por inserção

    numvet=1;
   	calctempo(v1,maxtam1,valor,numvet);
   	numvet=2;
   	calctempo(v2,maxtam2,valor,numvet);
   	numvet=3;
   	calctempo(v3,maxtam3,valor,numvet);
   	numvet=4;
   	calctempo(v4,maxtam4,valor,numvet);

    break;

    case 2 :

   	//ordenando por seleção

    numvet=1;
   	calctempo(v1,maxtam1,valor,numvet);
   	numvet=2;
   	calctempo(v2,maxtam2,valor,numvet);
   	numvet=3;
   	calctempo(v3,maxtam3,valor,numvet);
   	numvet=4;
   	calctempo(v4,maxtam4,valor,numvet);

    break;


 
    case 3 :
        
	//ordenando por shellsort


	numvet=1;
   	calctempo(v1,maxtam1,valor,numvet);
   	numvet=2;
   	calctempo(v2,maxtam2,valor,numvet);
   	numvet=3;
   	calctempo(v3,maxtam3,valor,numvet);
   	numvet=4;
   	calctempo(v4,maxtam4,valor,numvet);


    break;

 
    case 4 :

    //ordenando por Quicksort

    numvet=1;
   	calctempo(v1,maxtam1,valor,numvet);
   	numvet=2;
   	calctempo(v2,maxtam2,valor,numvet);
   	numvet=3;
   	calctempo(v3,maxtam3,valor,numvet);
   	numvet=4;
   	calctempo(v4,maxtam4,valor,numvet);


    break;


    case 5 :

    
    //ordenando por heapsort

    numvet=1;
   	calctempo(v1,maxtam1,valor,numvet);
   	numvet=2;
   	calctempo(v2,maxtam2,valor,numvet);
   	numvet=3;
   	calctempo(v3,maxtam3,valor,numvet);
   	numvet=4;
   	calctempo(v4,maxtam4,valor,numvet);

    break;


	}


	}


	if(menu==2){

	//geração dos vetores com numeros em ordem crescente

	criarvetor(v1,maxtam1,menu);
	criarvetor(v2,maxtam2,menu);
	criarvetor(v3,maxtam3,menu);
	criarvetor(v4,maxtam4,menu);


	//menu para ordenar os vetores aleatorios pelos diferentes métodos


	printf("\n Digite 1 para insercao \n Digite 2 para selecao \n Digite 3 para shellsort \n Digite 4 para quicksort \n Digite 5 para heapsort \n");
	scanf("%d",&valor);


 switch ( valor ){
    case 1 :

   	//ordenando por inserção
    numvet=1;
   	calctempo(v1,maxtam1,valor,numvet);
   	numvet=2;
   	calctempo(v2,maxtam2,valor,numvet);
   	numvet=3;
   	calctempo(v3,maxtam3,valor,numvet);
   	numvet=4;
   	calctempo(v4,maxtam4,valor,numvet);

    break;
 
    case 2 :

   	//ordenando por seleção

    numvet=1;
   	calctempo(v1,maxtam1,valor,numvet);
   	numvet=2;
   	calctempo(v2,maxtam2,valor,numvet);
   	numvet=3;
   	calctempo(v3,maxtam3,valor,numvet);
   	numvet=4;
   	calctempo(v4,maxtam4,valor,numvet);

    break;


 
    case 3 :
        
	//ordenando por shellsort

    numvet=1;
   	calctempo(v1,maxtam1,valor,numvet);
   	numvet=2;
   	calctempo(v2,maxtam2,valor,numvet);
   	numvet=3;
   	calctempo(v3,maxtam3,valor,numvet);
   	numvet=4;
   	calctempo(v4,maxtam4,valor,numvet);

    break;

 
    case 4 :

    //ordenando por Quicksort

    numvet=1;
   	calctempo(v1,maxtam1,valor,numvet);
   	numvet=2;
   	calctempo(v2,maxtam2,valor,numvet);
   	numvet=3;
   	calctempo(v3,maxtam3,valor,numvet);
   	numvet=4;
   	calctempo(v4,maxtam4,valor,numvet);

    break;


    case 5 :

    
    //ordenando por heapsort

    numvet=1;
   	calctempo(v1,maxtam1,valor,numvet);
   	numvet=2;
   	calctempo(v2,maxtam2,valor,numvet);
   	numvet=3;
   	calctempo(v3,maxtam3,valor,numvet);
   	numvet=4;
   	calctempo(v4,maxtam4,valor,numvet);

    break;


	}


	}



	if(menu==3){


	//geração dos vetores com numeros em ordem decrescente

	criarvetor(v1,maxtam1,menu);
	criarvetor(v2,maxtam2,menu);
	criarvetor(v3,maxtam3,menu);
	criarvetor(v4,maxtam4,menu);



	//menu para ordenar os vetores aleatorios pelos diferentes métodos


	printf("\n Digite 1 para insercao \n Digite 2 para selecao \n Digite 3 para shellsort \n Digite 4 para quicksort \n Digite 5 para heapsort \n");
	scanf("%d",&valor);


 switch ( valor ){
    case 1 :

   	//ordenando por inserção

    numvet=1;
   	calctempo(v1,maxtam1,valor,numvet);
   	numvet=2;
   	calctempo(v2,maxtam2,valor,numvet);
   	numvet=3;
   	calctempo(v3,maxtam3,valor,numvet);
   	numvet=4;
   	calctempo(v4,maxtam4,valor,numvet);

    break;
 
    case 2 :

   	//ordenando por seleção

    numvet=1;
   	calctempo(v1,maxtam1,valor,numvet);
   	numvet=2;
   	calctempo(v2,maxtam2,valor,numvet);
   	numvet=3;
   	calctempo(v3,maxtam3,valor,numvet);
   	numvet=4;
   	calctempo(v4,maxtam4,valor,numvet);

    break;


 
    case 3 :
        
	//ordenando por shellsort

    numvet=1;
   	calctempo(v1,maxtam1,valor,numvet);
   	numvet=2;
   	calctempo(v2,maxtam2,valor,numvet);
   	numvet=3;
   	calctempo(v3,maxtam3,valor,numvet);
   	numvet=4;
   	calctempo(v4,maxtam4,valor,numvet);

    break;

 
    case 4 :

    //ordenando por Quicksort

    numvet=1;
   	calctempo(v1,maxtam1,valor,numvet);
   	numvet=2;
   	calctempo(v2,maxtam2,valor,numvet);
   	numvet=3;
   	calctempo(v3,maxtam3,valor,numvet);
   	numvet=4;
   	calctempo(v4,maxtam4,valor,numvet);

    break;


    case 5 :

    
    //ordenando por heapsort

    numvet=1;
   	calctempo(v1,maxtam1,valor,numvet);
   	numvet=2;
   	calctempo(v2,maxtam2,valor,numvet);
   	numvet=3;
   	calctempo(v3,maxtam3,valor,numvet);
   	numvet=4;
   	calctempo(v4,maxtam4,valor,numvet);

    break;


	}

	}
	system("pause");
	return 0;
}




