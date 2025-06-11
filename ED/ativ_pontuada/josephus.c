#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct no {
    char nome[128];
    char cpf[16];
    struct no* proxNo;
} tipoNo;

typedef struct {
    tipoNo *fim;
    int quant;
} tipoLista;

//Função que inicializa os campos do struct lista
int inicializa(tipoLista *lista) {
    lista->quant = 0;
    lista->fim = NULL;
    return 0;
}

//Função que preenche os dados de um nó
void preencheNo(tipoNo *no) {    
    printf("\nDigite o CPF do participante: ");
    fgets(no->cpf, sizeof(no->cpf), stdin);
    no->cpf[strcspn(no->cpf, "\n")] = '\0';

    printf("\nDigite o nome do participante: ");
    fgets(no->nome, sizeof(no->nome), stdin);
    no->nome[strcspn(no->nome, "\n")] = '\0';
}

//Função que adiciona o primeiro elemento à lista
int adicionaListaVazia(tipoLista *lista){
    if (lista->fim != NULL)
        return 0;
    else {
        tipoNo* novoNo = (tipoNo*) malloc(sizeof(tipoNo));
        if (!novoNo)
            return 0;
        else {
            preencheNo(novoNo);
            novoNo->proxNo = novoNo;
            lista->fim = novoNo;
            lista->quant++;
            return 1;
        }
    }
}

//Função que adiciona um novo elemento na lista (no "fim")
int adicionaNo(tipoLista *lista) {
    if (lista->fim == NULL)
        return adicionaListaVazia(lista);
    else{
        tipoNo *novoNo = (tipoNo*) malloc (sizeof(tipoNo));
        if (!novoNo) 
            return 0;
        else {
            preencheNo(novoNo);
            novoNo->proxNo = lista->fim->proxNo;
            lista->fim->proxNo = novoNo;
            lista->fim = novoNo;
            lista->quant++;
            return 1;
        }
    }
}

//Função responsável por exibir a lista
int exibeLista (tipoLista *lista){
    if (lista->quant == 0){
        printf("\nLista Vazia\n");
        return 0;
    } else {
        tipoNo *aux = lista->fim->proxNo;
        printf("\nParticipantes: ");
        for (int i = 0; i < lista->quant; i++){
            printf("\n%s | CPF: %s", aux->nome, aux->cpf);
            aux = aux->proxNo;
        }
        printf("\n");
        return 0;
    }
    
}

void sorteia(tipoLista *lista, int *temVencedor) {
    if (lista->quant == 1){
        printf("\nApenas 1 participante!");
        return;
    }

    srand(time(NULL));
    int sorteado = 1 + (rand() % lista->quant);
    printf("\nNumero sorteado: %d\n", sorteado);

    tipoNo *antecessor = lista->fim;
    for (int i = 1; i < sorteado; i++){
        antecessor = antecessor->proxNo;
    }
    tipoNo *removido = antecessor->proxNo;
    printf("\n%s foi removido(a)\n", removido->nome);
    antecessor->proxNo = removido->proxNo;
    if (removido == lista->fim)
        lista->fim = antecessor;
    free(removido);
    lista->quant--;

    if (lista->quant == 1) {
        printf("\n%s ganhou o sorteio!", lista->fim->nome);
        *temVencedor = 1;
        return;
    } else {
        exibeLista(lista);
        return;
    }

}

//Função responsável por desalocar a memória alocada a cada nó
int destroiLista (tipoLista *lista) {
    if (lista->quant == 0) {
        return 0;
    }
    else {
        tipoNo *aux = lista->fim;
        tipoNo *prox;
        while(lista->quant > 0) {
            prox = aux->proxNo;
            free(aux);
            aux = prox;
            lista->quant--;
        }
        lista->fim = NULL;
        return 1;
    }
}

int main (void) {
    tipoLista lista;
    int temVencedor = 0;
    inicializa(&lista);
    char op;
    do {
        printf("\n    Sorteio do Cruzeiro");
        printf("\n1 - Adicionar participante a lista");
        printf("\n2 - Exibir a Lista");
        printf("\n3 - Sortear");
        printf("\n4 - Sortear ate o final");
        printf("\n0 - Sair do programa");
        printf("\nSelecione a opcao desejada: ");

        scanf("%c", &op);
        while(getchar() != '\n');
        switch(op) {
            case '1': adicionaNo(&lista);
                    break;
            case '2': exibeLista(&lista);
                    break;
            case '3': sorteia(&lista, &temVencedor);
                    break;
            case '4': do{
                        sorteia(&lista, &temVencedor);
                    } while(!temVencedor);
                    break;
            case '0': break;
            default: printf("\n\nOpcao nao reconhecida\n\n");
        }

    } while(op != '0' && !temVencedor);
    destroiLista(&lista);
    return 0;
}