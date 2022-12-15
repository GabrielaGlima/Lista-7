/*6. Seja uma estrutura para descrever os carros de uma determinada revendedora,
contendo os seguintes campos:
        typedef struct {
            char marca[15];
            int ano;
            char cor[10];
            float preco;
        } Carro;
a) Declarar o vetor vetcarros do tipo da estrutura definida acima, de tamanho
20.
b) Definir uma função para ler o vetor vetcarros.
c) Definir uma função que receba um preço e imprima os carros (marca, cor e
ano) que tenham preço igual ou menor ao preço recebido.
d) Defina uma função que receba a marca de um carro e imprima as
informações de todos os carros dessa marca (preço, ano e cor).
e) Defina uma função que receba uma marca, ano e cor e informe se existe ou
não um carro com essas características. Se existir, informar o preço.*/
#include <stdlib.h>
#include <stdio.h>
#define TAM 2

typedef struct {
    char marca[15];
    int ano;
    char cor[10];
    float preco;
} Carro;

void ler_carros(Carro *carro){
    printf("Digite as caracteristicas do carro!\n");
    setbuf(stdin, NULL);
    printf("Marca: ");
    setbuf(stdin, NULL);
    gets(carro->marca);
    printf("Ano: ");
    scanf("%d", &carro->ano);
    printf("Cor: ");
    setbuf(stdin, NULL);
    gets(carro->cor);
    setbuf(stdin, NULL);
    printf("Preco: ");
    scanf("%f", &carro->preco);
}

void imprimir_preco(float preco, Carro carro[], int quant){
    int i;
    for(i=0; i<quant; i++){
        if(preco >= carro[i].preco){
            printf("Marca: %s\n", carro[i].marca);
            printf("Ano: %d\n", carro[i].ano);
            printf("Cor: %s\n", carro[i].cor);
        }
    }
}

void imprimir_marca(char marca[], Carro carro[], int quant){
    int i;
    for(i=0; i<quant; i++){
        if(strcmp(marca, carro[i].marca) == 0){
            printf("Preco: %.2f\n", carro[i].preco);
            printf("Ano: %d\n", carro[i].ano);
            printf("Cor: %s\n", carro[i].cor);
        }else
            printf("Nao foi encontrado!\n");
    }
}

void imprimir_marca_cor_ano(char marca[], char cor[], int ano, Carro carro[], int quant){
    int i;
    for(i=0; i<quant; i++){
        if((strcmp(marca, carro[i].marca) == 0) && (strcmp(cor, carro[i].cor) == 0) && (ano == carro[i].ano)){
            printf("Preco: %.2f\n", carro[i].preco);
        }else
            printf("Nao foi encontrado!\n");
    }
}

void menu(int *opcao){
    printf("--------- MENU ---------\n");
    printf("[1] Cadastra um carro\n");
    printf("[2] Preco -> Carros\n");
    printf("[3] Marca -> Carros\n");
    printf("[4] Marca, ano e cor -> Preco\n");
    printf("[0] Sair\n");
    printf("Opcao: ");
    scanf("%d", opcao);
}

int main(){
    Carro carro[TAM];
    int opcao, cont=0, ano;
    float preco;
    char marca[15], cor[10];
    menu(&opcao);

    while(opcao != 0){
        switch (opcao){
        case 1:
            if(cont<TAM){
                ler_carros(&carro[cont]);
                cont++;
                system("cls");
            }else{
                printf("Nao eh possivel mais cadastrar!\n");
                system("pause");
                system("cls");
            }
            break;
        case 2:
            printf("Digite um preco: ");
            scanf("%f", &preco);
            imprimir_preco(preco, carro, cont);
            system("pause");
            system("cls");
            break;
        case 3:
            printf("Digite a marca: ");
            setbuf(stdin, NULL);
            gets(marca);
            setbuf(stdin, NULL);
            imprimir_marca(marca, carro, cont);
            system("pause");
            system("cls");
            break;
        case 4:
            printf("Digite a marca: ");
            setbuf(stdin, NULL);
            gets(marca);
            setbuf(stdin, NULL);
            printf("Digite o ano: ");
            scanf("%d", &ano);
            printf("Digite a cor: ");
            setbuf(stdin, NULL);
            gets(cor);
            setbuf(stdin, NULL);
            imprimir_marca_cor_ano(marca, cor, ano, carro, cont);
            system("pause");
            system("cls");
        }
        menu(&opcao);
    }
    return 0;
}
