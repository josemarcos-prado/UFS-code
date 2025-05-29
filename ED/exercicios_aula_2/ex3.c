// Enunciado: 3) Construa um programa que armazene nome, matrícula e média de até N alunos e dê ao usuário a possibilidade de ver a listagem dos alunos em ordem alfabética ou em ordem de classificação. Obs: uma vez que os dados sejam digitados, o usuário deve poder ver as listagens quantas vezes ele desejar. 

//Organização do código: Includes -> Definições de tipos e funções usadas -> main().

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tipo usado para armazenar um aluno.
typedef struct {
    char nome[80]; //Número grande para um nome.
    char matricula[13]; //Número fixo de dígitos.
    float media;
} aluno;

//Bubble sort com strings (usando strcmp).
void ordemalfa (aluno* listalunos, int n) {
    //Percorre a lista de par em par no máximo n-1 vezes.
    for (int i = 0, trocou = 0; i < n - 1; i++) {
        //Após percorrer toda a lista pelo menos uma vez, checa se houve alguma troca. Se não houve, a lista está ordenada, então sai do loop.
        if (trocou == 0 && i != 0) break;
        //Percorre a lista de par em par, checando se cada par está em ordem.
        for (int j = 0; j < n - i - 1; j++) {
            //Compara os dois nomes.
            int comp = strcmp(listalunos[j].nome, listalunos[j + 1].nome); 
            //Caso sejam iguais, avança pra próxima iteração.
            if (comp == 0) continue;
            //Caso o segundo nome venha antes na ordem alfabética, troca as posições dos alunos na lista e altera o valor de "trocou" para 1.
            else if (comp > 0) {
                aluno temp = listalunos[j];
                listalunos[j] = listalunos[j + 1];
                listalunos[j + 1] = temp;
                trocou = 1;
            }
        }
    }
    return;
}

//Bubble sort com números (usando o operador "<")
void ordemnota (aluno* listalunos, int n) {
    //Percorre a lista de par em par no máximo n-1 vezes.
    for (int i = 0, trocou = 0; i < n - 1; i++) {
        //Checa se houve trocas na iteração anterior (exclui a primeira iteração da checagem). Se não houve, a lista está ordenada, então sai do loop.
        if (trocou == 0 && i != 0) break;
        //Percorre a lista de par em par, checando se as médias estão em ordem.
        for (int j = 0; j < n - i - 1; j++) {
            //Se algum par estiver desordenado, troca e muda o valor de "trocou" para 1.
            if (listalunos[j].media < listalunos[j + 1].media) {
                aluno temp = listalunos[j];
                listalunos[j] = listalunos[j + 1];
                listalunos[j + 1] = temp;
                trocou = 1;
            }
        }
    }
    return;
}

//Função para imprimir uma lista de alunos com n alunos na mesma formatação
void imprimealunosf (aluno* listalunos, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNome: %s", listalunos[i].nome);
        printf("\nMatricula: %s", listalunos[i].matricula);
        printf("\nMedia: %.1f", listalunos[i].media);
        printf("\n");
    }
    return;
}

int main (void) {
    //Pede e armazena o número de alunos a serem registrados.
    int n; 
    printf("Quantos alunos deseja registrar? ");
    scanf("%d", &n);

    //Aloca dinamicamente a memória para armazenar n alunos.
    aluno* alunos = (aluno*) malloc(n * sizeof(aluno));
    //Checa se a memória foi alocada corretamente.
    if (alunos == NULL) {
        printf("Memoria nao alocada\n");
        return 1;
    }

    //Preenche o vetor com os dados inseridos pelo usuário através do teclado.
    for (int i = 0; i < n; i++) {
        printf("\nDigite o nome do aluno(a) %d: ", i + 1);
        while(getchar() != '\n');
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("\nDigite a matricula do aluno(a) %d: ", i + 1);
        scanf("%s", alunos[i].matricula);

        printf("\nDigite a media do aluno(a) %d: ", i + 1);
        scanf("%f", &alunos[i].media);
    }

    //Exibe um menu que espera um input do usuário e aparece novamente até que o input seja o equivalente para a saída do programa.
    int sair = 0;
    while (sair != 1){
        char comando;
        printf("\nO que deseja fazer a seguir? (Digite o numero correspondente)");
        printf("\n1. Visualizar listagem dos alunos em ordem alfabetica");
        printf("\n2. Visualizar listagem dos alunos em ordem de classificacao (media)");
        printf("\n3. Sair");
        printf("\n\n");        
        while(getchar() != '\n');
        scanf("%c", &comando);
        switch (comando)
        {
            case '1':
                ordemalfa(alunos, n);
                imprimealunosf(alunos, n);
                break;

            case '2':
                ordemnota(alunos, n);
                imprimealunosf(alunos, n);
                break;
            
            case '3':
                sair = 1;
                break;

            default:
                printf("\nComando não reconhecido");
                break;
        }
    }
    
    //Libera a memória que havia sido alocada.
    free(alunos);

    return 0;
}