#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char nome[128];
    struct no* proxNo;
} tipoNo;

typedef struct {
    int quant;
    tipoNo *inicio;
    tipoNo *fim;
} tipoLista;

int main (void) {
    

    return 0;
}