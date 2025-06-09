#include <stdio.h>
#include <stdlib.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

struct Produto produto;

void cadastrarProduto() {
	printf("\033[32m");
    printf("---Cadastro de Produto---\n");
    printf("\033[0m");
    printf("Nome do produto: ");
    scanf(" %[^\n]", produto.nome); 
    printf("Preco do produto: ");
    scanf("%f", &produto.preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &produto.quantidade);
    printf("Produto cadastrado com sucesso\n");
    
}

void visualizarProduto() {
	printf("\033[33m");
    printf("---Informacoes do Produto---\n");
    printf("\033[0m");
    printf("Nome: %s\n", produto.nome);
    printf("Preco: R$ %.2f\n", produto.preco);
    printf("Quantidade em estoque: %d\n", produto.quantidade);
}      
   
void realizarCompra() {
    int qtdcompra;
    printf("\033[31m");
    printf("---Compra de produto---\n");
    printf("\033[0m");
    printf("Quantidade a comprar: ");
    scanf("%d", &qtdcompra);

    if (qtdcompra <= produto.quantidade) {
        produto.quantidade -= qtdcompra;
        printf("Compra realizada\n");
        printf("estoque restante: %d\n", produto.quantidade);
    } else {
        printf("estoque insuficiente\n");
    }
}

int main() {
    int opcao;

    do {
        printf("---SuperMais---\n");
        printf("[ 1 ] cadastrar Produto\n");
        printf("[ 2 ] visualizar Produto\n");
        printf("[ 3 ] realizar Compra\n");
        printf("[ 0 ] sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                visualizarProduto();
                break;
            case 3:
                realizarCompra();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}