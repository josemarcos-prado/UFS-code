#include <stdio.h>
#include <stdlib.h>

int quantElem = 0;
int maximo = 0;

/* Fun��o que cria uma lista vazia com N elementos e retorna um ponteiro para a lista criada*/
int* criaLista(){
    int *vetor;
    vetor = malloc(maximo*sizeof(int));
    if(!vetor){
        printf("\nOcorreu um erro! A memoria n�o foi alocada.");
        exit(1);
    }
    return vetor;
}

/* Fun��o que faz inser��o n�o ordenada no vetor*/
int insereNaoOrd(int *vetor){
if(quantElem < maximo){
   printf("\nDigite um numero inteiro:");
   scanf("%d",&vetor[quantElem++]);
   return 1;
}
else
   return 0;
}

//Função que faz inserção ordenada no vetor
int insereOrd(int *vetor){
    if (quantElem < maximo){
        int temp;
        int i = quantElem;
        printf("Digite um numero inteiro: ");
        scanf("%d", &temp);
        while (temp < vetor[i-1] && i > 0) {
            vetor[i] = vetor[i-1];
            i--;
        }
        vetor[i] = temp;
        quantElem++;
        return 1;
    }
    else 
        return 0;
}

/*Fun��o que faz pesquisa sequencial*/
int pesqSeq(int *vetor, int elemento){
for(int x = 0; x < quantElem; x++)
    if(elemento == vetor[x])
       return x;
return -1;
}

//Função que faz pesquisa binária
int pesqBin (int *vetor, int elemento) {
    int inicio = 0;
    int fim = quantElem-1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == elemento) 
            return meio;
        else if (elemento > vetor[meio])
            inicio = meio + 1;
        else 
            fim = meio - 1;
    }
    return -1;
}

/*Fun��o que exibe os elementos do vetor*/
void mostraVetor(int *vetor){
printf("\nConteudo do vetor:");
for(int x = 0; x<quantElem; x++)
    printf("%5d",vetor[x]);
}


/*Fun��o que faz a remo��o de vetor n�o ordenado*/
int remocaoNaoOrd(int *vetor,int elemento){
int resp = pesqSeq(vetor, elemento);
if(resp != -1){
    vetor[resp] = vetor[quantElem - 1];
    quantElem--;
    return 1;
    }
return 0;
}

//Função que remove o i-ésimo no de uma lista ordenada
int removeIOrd(int *vetor, int i) {
    if (i >= 0 && i < quantElem) {
        if(i < quantElem - 1) {
            for (int j = i; j < quantElem - 1; j++) {
                vetor[j] = vetor[j+1];
            }
            quantElem--;
        }
        else 
            quantElem--;
        
        return 1;
    }
    else 
        return 0;
}

//Função que faz a remoção de vetor ordenado
int remocaoOrd(int *vetor, int elemento) {
    int resp = pesqBin(vetor, elemento);
    return removeIOrd(vetor, resp);
}

//Função que remove o i-esimo no de uma lista não ordenada
int removeINaoOrd (int *vetor, int i) {
    if (i >= 0 && i < quantElem){
        vetor[i] = vetor[quantElem-1];
        quantElem--;
        return 1;
    }
    else
        return 0;
}

int main(void){

int *lista, aux, resp;
char op;
printf("\nDigite quantos elementos deseja ter na lista:");
scanf("%d",&maximo);
lista = criaLista();

do{
        printf("\n\n\nEscolha uma opcao\n1 - Insercao nao ordenada\n2 - Pesquisa sequencial");
        printf("\n3 - Remocao nao ordenada\n4 - Insercao ordenada\n5 - Pesquisa binaria\n6 - Remocao ordenada\n7 - Remover no na i-esima posicao (nao ordenado)\n8 - Remover no na i-esima posicao (ordenado)\n9 - Exibir lista \n0 - Sair do programa");
        printf("\nDigite sua opcao: ");
        while(getchar() != '\n');
        scanf("%c",&op);
        switch(op){
        case '1': if(!insereNaoOrd(lista))
                    printf("\nLista cheia. Insercao nao realizada.");
                else
                    printf("\nElemento inserido com sucesso");
                break;
        case '2': printf("\nDigite o elemento que deseja procurar:");
                scanf("%d",&aux);
                resp = pesqSeq(lista, aux);
                if(resp == -1)
                    printf("\nElemento nao encontrado");
                else
                    printf("\nElemento encontrado na posicao %d do vetor.",resp);
                break;
        case '3': printf("\nDigite o elemento que deseja remover:");
                scanf("%d",&aux);
                if(remocaoNaoOrd(lista,aux))
                    printf("\nElemento removido com sucesso.");
                else
                    printf("\nFalha na remocao do elemento.");
                break;
        case '4': if (!insereOrd(lista)) 
                    printf("\nLista Cheia. Insercao nao realizada");
                else 
                    printf("\nElemento inserido com sucesso");
                break;
        case '5': printf("\nDigite o elemento que deseja procurar: ");
                scanf("%d", &aux);
                resp = pesqBin(lista, aux);
                if (resp == -1)
                    printf("\nElemento nao encontrado.");
                else
                    printf("\nElemento encontrado na posicao %d do vetor.", resp);
                break;
        case '6': printf("\nDigite o elemento que deseja remover: ");
                scanf("%d", &aux);
                if (remocaoOrd(lista, aux))
                    printf("\nElemento removido com sucesso");
                else
                    printf("\nFalha na remocao do elemento.");
                break;
        case '7': printf("\nDigite o indice do elemento a ser removido: ");
                scanf("%d", &aux);
                if (removeINaoOrd(lista, aux))
                    printf("\nElemento removido com sucesso.");
                else
                    printf("\nFalha ao remover o elemento no indice %d.", aux);
                break;
        case '8': printf("\nDigite o indice do elemento a ser removido: ");
                scanf("%d", &aux);
                if (removeIOrd(lista,aux))
                    printf("\nElemento removido com sucesso.");
                else 
                    printf("\nFalha ao remover o elemento no indice %d", aux);
                break;
        case '9': mostraVetor(lista);
                break;
        case '0': printf("\nEncerrando programa.");
                break;
        default: printf("\n\nOpcao indisponivel. Selecione uma nova opcao.");
        }
}while(op != '0');


free(lista); /*Libera mem�ria alocada para a lista*/
return 0;
}
