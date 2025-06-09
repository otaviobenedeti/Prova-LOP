#include <stdio.h>

struct pessoa {
    char nome[50];
    int idade;
};

int main(){
    struct pessoa p;
    
    printf("Digite o nome: \n");
    scanf(" %[^\n]", &p.nome);

    printf("Digite a idade: \n");
    scanf("%d", &p.idade);

    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    
    return 0;
}