/*3. Crie um programa que apresente, na tela de abertura, um menu com opções
para:
a) Inserir uma nova pessoa: nome, altura e ano de nascimento.
b) Listar todos os nomes e respectivas alturas.
c) Listar os nomes das pessoas que nasceram depois de um certo ano.
Obs. Cada uma destas opções deve ser implementada em uma função separada.
O programa deve ser capaz de armazenar dados de até 100 pessoas.*/
#include<stdio.h>
#include<stdlib.h>
#define TAM 1

typedef struct {
    char nome[30];
    float altura;
    int ano_nascimento;
} Pessoa;

void cadastrar_pessoa(Pessoa *pessoa){
    printf("Nome: ");
    setbuf(stdin, NULL);
    gets(pessoa->nome);
    setbuf(stdin, NULL);
    printf("Altura: ");
    scanf("%f", &pessoa->altura);
    printf("Ano de nascimento: ");
    scanf("%d", &pessoa->ano_nascimento);
}

void imprimir_pessoa(Pessoa *pessoa){
    printf("Nome: %s\n", pessoa->nome);
    printf("Altura: %.2f\n", pessoa->altura);
}

void imprimir_nome(Pessoa *pessoa){
    printf("Nome: %s\n", pessoa->nome);
}

void menu(int *opcao){
    printf(" -------------- MENU --------------\n");
    printf("[1] Cadastrar uma pessoa\n[2] Listar pessoas cadastradas\n[3] Listar nomes das pessoas que nasceram depois de um certo ano\n[0] Sair\n");
    printf("Opcao: ");
    scanf("%d", opcao);
}

int main(){
    Pessoa pessoa[TAM];
    int cont = 0, opcao, i, ano_nascimento;
    menu(&opcao);

    while(opcao != 0){
        switch (opcao){
            case 1:
                if(cont<TAM){
                    cadastrar_pessoa(&pessoa[cont]);
                    cont++;
                    system("cls");
                }
                else{
                    printf("Nao eh permitido mais cadastros!\n");
                    system("pause");
                    system("cls");
                }          
                break;
            case 2: 
                for(i=0; i<cont; i++){
                    imprimir_pessoa(&pessoa[i]);
                }
                system("pause");
                system("cls"); 
                break;
            case 3: 
                printf("Digite um ano de nascimento: ");
                scanf("%d", &ano_nascimento);
                for(i=0; i<cont; i++){
                    if(pessoa[i].ano_nascimento>=ano_nascimento){
                        imprimir_pessoa(&pessoa[i]);
                    }else
                        printf("Não existe pessoas cadastradas que nasceram depois de %d\n", ano_nascimento);
                }
                system("pause");
                system("cls"); 
                break;
        }
        menu(&opcao);
    }

    return 0;
}