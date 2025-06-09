#include <stdio.h>
#include <stdlib.h>

struct aluno {
    char nome[50];
    int idade;
    float nota;
};

struct aluno alunos[3];

void listaralunos() {
    for (int i = 0; i < 3; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Nota: %.2f\n", alunos[i].nota);
        system("cls");
    }
}

int main() {
    for (int i = 0; i < 3; i++) {
        printf("\nDigite os dados do aluno %d:\n", i + 1);
        printf("Nome:\n");
        scanf("%s", alunos[i].nome); 
        printf("Idade:\n");
        scanf("%d", &alunos[i].idade);
        printf("Nota:\n");
        scanf("%f", &alunos[i].nota);
    }

    listaralunos();

    return 0;
}