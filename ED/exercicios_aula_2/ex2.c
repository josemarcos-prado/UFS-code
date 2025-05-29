// Enunciado: 2) Crie um struct que guarde nome, idade e peso um atletas. Em um vetor, alocado dinamicamente, guarde os dados de N atletas. Exiba uma listagem dos dados dos atletas cadastrados. Ao final exiba a média dos pesos e quantos atletas são menores de idade.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float peso;
} atleta;

int main (void){
    int n = 0;
    printf("Quantos atletas deseja cadastrar? ");
    scanf("%d", &n);
    atleta* atletas = (atleta*) calloc(n, sizeof(atleta));
    if (atletas == NULL) {
        printf("Memoria nao alocada.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {

        printf("\nDigite o nome do atleta %d: ", i + 1);
        while (getchar() != '\n'); 
        fgets(atletas[i].nome, sizeof(atletas[i].nome), stdin);
        atletas[i].nome[strcspn(atletas[i].nome, "\n")] = '\0';

        printf("\nDigite a idade do atleta %d: ", i + 1);
        scanf("%d", &atletas[i].idade);

        printf("\nDigite o peso do atleta em quilogramas %d: ", i + 1);
        scanf("%f", &atletas[i].peso);
    }

    float somaP = 0;
    int menor = 0;
    for (int i = 0; i < n; i++) {
        printf("\nAtleta %d:\n", i+1);
        printf("Nome: %s\n", atletas[i].nome);
        printf("Idade: %i anos\n", atletas[i].idade);
        if (atletas[i].idade < 18) menor++;
        printf("Peso: %.2f kg\n", atletas[i].peso);
        somaP += atletas[i].peso;
    }
    printf("\nMedia dos pesos: %.2f kg\n", (float) somaP/n);
    printf("Numero de atletas menores de idade: %d\n", menor);

    free(atletas);
    
    return 0;
}