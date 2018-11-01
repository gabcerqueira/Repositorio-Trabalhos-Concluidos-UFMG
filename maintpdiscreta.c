#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Ponto
{
	int x;
	int y;
	int dx;
	int dy;


}tPonto;


int main(){

tPonto n1;
int n;
int i;
int contador=1;//contador de operaçoes de movimento
int contmax=1;//contador que poe limite para o movimento
int cont1=1;//quantidade de movimentos em contador
bool cont2=0;//assume valor de 1 para cont1==contmax , para permitir a entrada de contador++


	
	 n1.x=0;
	 n1.y=0;
	 n1.dx=0;
	 n1.dy=0;

	printf("Digite o valor de n\n");
	scanf("%d",&n);

	if(n<0){

		printf("Digite um valor valido para n\n");

		return 0;
	}

	for(i=1;i<=n;i++){


		
			if((contador==1) && (cont1<=contmax) ){
				//cima
				n1.dx=0;
				n1.dy=1;
				n1.x=n1.x + n1.dx;
				n1.y=n1.y + n1.dy;

				/*
				if(n==0){
					
					n1.x=0;
					n1.y=0;
				}
				*/
				if(cont1==contmax){

					cont1=1;
					cont2=1;

				}
				else{

					cont1++;
					cont2=0;
				}
				
			}

			 else if((contador==2) && (cont1<=contmax) ){
				//esquerda
				n1.dx=-1;
				n1.dy=0;
				n1.x=n1.x + n1.dx;
				n1.y=n1.y + n1.dy;
				
				if(cont1==contmax){
					
					contmax++;
					cont1=1;
					cont2=1;
				}
				else{

					cont1++;
					cont2=0;
				}

				
			}

		
		
			 else if((contador==3) && (cont1<=contmax) ){
				//baixo
				n1.dx=0;
				n1.dy=-1;
				n1.x=n1.x + n1.dx;
				n1.y=n1.y + n1.dy;
				
				if(cont1==contmax){

					cont1=1;
					cont2=1;
				}
				else{

					cont1++;
					cont2=0;
				}
				
			}
			else if((contador==4) && (cont1<=contmax) ){
				//direita
				n1.dx=1;
				n1.dy=0;
				n1.x=n1.x + n1.dx;
				n1.y=n1.y + n1.dy;
				
				if(cont1==contmax){
					
					contmax++;
					cont1=1;
					cont2=1;
				
				}
				else{

					cont1++;
					cont2=0;

				}
				
			}
	
		
		if( (cont2==1) && (n!=0) ){

			
			contador++;
			
		}

		// reset do contador de movimento
		if(contador>4){

			contador=1;
			
		}


	}

	printf(" n = %d coordenada x:%d , coordenada y:%d",n,n1.x,n1.y);
	printf("\ncontador = %d\n cont1 = %d\n contmax = %d\n",contador,cont1,contmax);





	return 0;
}