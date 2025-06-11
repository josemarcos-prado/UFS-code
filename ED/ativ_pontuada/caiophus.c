#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

typedef struct no{
	char name[127];
	char CPF[13];
	struct no *proxNo;
	}tipoNo;
typedef struct listaCirc{
	tipoNo *fim;
	int quant;
}cabeca;


void criaLista(cabeca *lista){
	lista->fim = NULL;
	lista->quant =0;
}

void iniciaNome(cabeca *lista){
		tipoNo *novoNo;
		novoNo= (tipoNo*)malloc(sizeof(tipoNo));
		printf("Digite o nome do participante 1:");
		getchar();
		fgets(novoNo->name,sizeof(novoNo->name),stdin);
		printf("Digite o CPF do participante 1:");
		fgets(novoNo->CPF,sizeof(novoNo->CPF),stdin);
		novoNo->proxNo=novoNo; 
		lista->fim=novoNo;
		lista->quant++;
}

void proxPessoas(cabeca *lista,int total){
		for(int i=1;i<total;i++){
				tipoNo *novoNo;
				novoNo= (tipoNo*)malloc(sizeof(tipoNo));
				printf("Digite o nome do participante %d:",i+1);
				fgets(novoNo->name,sizeof(novoNo->name),stdin);
				printf("Digite o CPF do participante %d:",i+1);
				fgets(novoNo->CPF,sizeof(novoNo->CPF),stdin);
				novoNo->proxNo=lista->fim->proxNo;
				lista->fim->proxNo=novoNo;
				lista->fim=novoNo;
				lista->quant++;
			}
}


void imprime(cabeca *lista){
	tipoNo *atual;
	atual=lista->fim->proxNo;
	printf("\n   PRESENTES:   \n");
	do{
		printf("\n%s",atual->name);
		atual=atual->proxNo;
	}while(atual!=lista->fim->proxNo);
}

int sorteia(cabeca *lista){
		int random;
		srand(time(0));
		random=1+rand()%(lista->quant *2);
		printf("O numero sorteado foi:%d\n",random);
		return random;
}

void roletaR(cabeca *lista,int alea){
	int i=1;
	tipoNo *atual, *aux;
	atual=lista->fim->proxNo;
	aux=lista->fim;
	while(i<alea){
			aux=aux->proxNo;
			atual=atual->proxNo;
			i++;
		}
	if(lista->fim==atual){
			lista->fim=aux;
		}
	aux->proxNo=atual->proxNo;
	printf("O Eliminado foi:%s\n",atual->name);
	free(atual);
	lista->quant--;
	imprime(lista);
}

void vitoria(cabeca *lista,int total){
		while(lista->quant!=1){
			int ran;
			ran= sorteia(lista);
			roletaR(lista,ran);
		}
		printf("O vencedor foi:%sCPF:%s\n",lista->fim->name,lista->fim->CPF);
}


int main(){
	int total;
	printf("Digite quantas pessoas irao participar:");
	scanf("%d",&total);
	cabeca pessoas;
	criaLista(&pessoas);
	while(total<=0){
			printf("Numero Invalido\n");
			printf("Digite quantas pessoas irao participar:");
			scanf("%d",&total);
		}
	if(total==1){
			iniciaNome(&pessoas);
		}
	if(total>1){
			iniciaNome(&pessoas);
			proxPessoas(&pessoas,total);
		}
	imprime(&pessoas);
	vitoria(&pessoas,total);
	printf("Acabou");
}
