#include <stdio.h>


typedef struct {
    char banda[10];
    char genero[10];
    int ano;
	int qtds;
    float preco;
} CD;

int cpcdestoque = 10;
CD estoque[10];
int totalcd = 0;

void cadastrar();
void vender();
void pesquisar(); 
void consultar();

int main() {
    int opcao;
    do {
    printf("---Som & Arte---\n");
    printf("[1] Cadastrar Cds\n");
    printf("[2] Vender Cds\n");
    printf("[3] Pesquisar Cds por genero\n");
    printf("[4] Proucurar Cds\n");
    printf("[0] Sair\n");
    printf("Escolha uma opcao:\n");
    scanf("%d", &opcao);
    
	switch (opcao) {
    case 1: 
		cadastrar(); 
	break;
	
    case 2: 
		vender(); 
	break;
	
	case 3: 
		pesquisar(); 
	break;
	
    case 4: 
		consultar(); 
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

void cadastrar() {
    if (totalcd >= cpcdestoque) {
    printf("Estoque cheio!\n");
    return;
    }
    printf("---Cadastrar Cds---\n");
    printf("Nome da banda:\n");
    scanf(" %[^\n]", estoque[totalcd].banda);
    printf("Ano:\n");
    scanf("%d", &estoque[totalcd].ano);
    printf("Genero:\n");
    scanf(" %[^\n]", estoque[totalcd].genero);
    printf("Quantidade em estoque:\n");
    scanf("%d", &estoque[totalcd].qtds);
    printf("Preco do CD:\n");
    scanf("%f", &estoque[totalcd].preco);

    totalcd++;
    printf("CD cadastrado com sucesso!\n");
}

void vender() {
	
    char banda[10];
    int qtds; 
    
    printf("---Vender Cds---\n");
    printf("Banda do Cd a ser vendido:\n");
    scanf(" %[^\n]", banda);
    printf("Quantidade:\n");
    scanf("%d", &qtds);

    for (int i = 0; i < totalcd; i++) {
    if (estoque[i].banda, banda) {
    if (estoque[i].qtds >= qtds) {
    estoque[i].qtds -= qtds;
    
    printf("---Carrinho---\n");
    
    printf("Venda realizada, total a pagar: R$ %.2f\n", estoque[i].preco * qtds);
    } else {
    printf("estoque insuficiente\n");
    }
    return;
    }
    }
    printf("CD nao encontrado!\n");
}

void pesquisar() {
	
    char genero[10];
    
    printf("---Procurar genero do CDs---\n");
    
    printf("Digite o genero para pesquisar:\n");
    scanf(" %[^\n]", genero);

    int encontrados = 0;
    
    for (int i = 0; i < totalcd; i++) {
    if (estoque[i].genero, genero) {
    printf("Banda: %s\nAno: %d\nQuantidade: %d\nPreco: %.2f\n\n",estoque[i].banda, estoque[i].ano, estoque[i].qtds, estoque[i].preco);
    
    encontrados++;
    }
    }

    if (encontrados == 0) {
    printf("Nenhum CD encontrado para o genero.\n");
    }
}

void consultar() {
	
    char banda[10];
    
    printf("---Proucurar Cds---\n");
    printf("Digite a banda para consultar:\n");
    scanf(" %[^\n]", banda);
    for (int i = 0; i < totalcd; i++) {
    if (estoque[i].banda, banda) {
    printf("CD encontrado quantidade disponivel: %d\n", estoque[i].qtds);
    return;
    }
    }

    printf("CD nao encontrado.\n");
}