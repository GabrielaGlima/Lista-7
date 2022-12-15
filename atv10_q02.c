/*2. Considere um cadastro de produtos de um estoque, com as seguintes
informações para cada produto:
• Código de identificação do produto: representado por um valor inteiro
• Nome do produto: com até 50 caracteres
• Quantidade disponível no estoque: representado por um número inteiro
• Preço de venda: representado por um valor real (float)

a) Defina uma estrutura em C, denominada Produto, que tenha os campos
apropriados para guardar as informações de um produto, conforme descrito
acima. Essa estrutura pode armazenar 15 produtos.
b) Escreva uma função que leia um inteiro codigo, uma string nome de 50
caracteres e um float preço e atribua esses valores lidos aos componentes de
uma variável produto que é do tipo struct Produto.
c) Imprima os valores de p.
Obs. O programa deve ser capaz de armazenar dados de até 15 produtos.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 15

typedef struct{
    int codigo;
    char nome[50];
    int estoque;
    float valor_venda;
}Produto;

void printProduto(Produto p){
    printf("\n* * PRODUTO * *");
    printf("\ID: %d", p.codigo);
    printf("\nNome: %s", p.nome);
    printf("\nEstoque: %d", p.estoque);
    printf("\nValor Venda: %.2f", p.valor_venda);
}

void leiaProduto(Produto *p){
    printf("\nInforme o codigo: ");
    scanf("%d", &p->codigo);
    printf("\nInforme o nome: ");
    scanf("%s", &p->nome);
    printf("\nInforme o estoque: ");
    scanf("%d", &p->estoque);
    printf("\nInforme o valor venda: ");
    scanf("%f", &p->valor_venda);
}

int main(){
    Produto p[15];
    int i = 0;

    for (i =0; i < MAX; i++){
        printf("\n===> Informe o produto %d", i+1);
        leiaProduto(&p[i]);
        printf("\n===>");
    }
    for (i =0; i < MAX; i++){
        printProduto(p[i]);
    }
    return 0;
}
