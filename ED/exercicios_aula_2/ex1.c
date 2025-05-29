// Enunciado: 1) Guarde N números em um vetor alocado dinamicamente. Exiba a média dos números lidos e os múltiplos de 6 digitados.

#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int *ponteiro, n, soma = 0;
    printf("Digite quantos numeros o vetor deve guardar: ");
    scanf("%d", &n);

    ponteiro = (int*) malloc(n*sizeof(int));
    if (ponteiro == NULL) {
        printf("Memoria nao alocada\n");
        return 1;
    }
  
    for (int i = 0; i < n; i++){
        printf("\nDigite o valor: ");
        scanf("%d", &ponteiro[i]);
        soma += ponteiro[i];
    }


    printf("\nMedia: %.2f", (float) soma/n);
    printf("\nMultiplos de 6: ");
    for (int i = 0, m6_num = 0; i < n; i++){
        if ((ponteiro[i] % 6 == 0) && m6_num == 0) {
            printf("%d", ponteiro[i]);
            m6_num++;
        } else if ((ponteiro[i] % 6 == 0) && m6_num != 0) {
            printf(", %d", ponteiro[i]);
            m6_num++;
        } else if ((i == n-1) && m6_num == 0) {
            printf("NENHUM");
        }
    }
    printf("\n\n");

    free(ponteiro);

    return 0;
}