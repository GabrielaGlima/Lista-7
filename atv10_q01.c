/*1. Armazene os dados de um aluno que tenha as seguintes informações:
• Número de matrícula: representado por um valor inteiro.
• Um vetor de notas: vetor de float para armazenar três notas.
• Média aritmética das notas: representado por um valor real.
a) Defina uma estrutura em C, denominada Aluno, que tenha os campos
apropriados para aguardar as informações de um aluno, conforme descrito
acima.
b) Escreva uma função que leia os dados do aluno atribuindo os valores lidos
aos componentes de uma variável aluno que é do tipo struct Aluno. Dentro
dessa função chame outras funções para ajudar na leitura:
• Crie uma função para ler as três notas dos alunos. Protótipo:
        void ler_notas(float v[], int quant);
• Crie uma função para calcular a média das notas do aluno e atribua o
resultado a média do aluno. Protótipo:
        void calcular_media(float notas[], float *media, int quant);
c) Imprima os valores de aluno.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 3

typedef struct{
    int matricula;
    float notas[3];
    float media;
}Aluno;

void ler_notas(float v[], int quant);
void ler_notas2(Aluno *aluno);
void calcular_media(float notas[], float *media, int quant);
void calcular_media2(Aluno *aluno);

void ler_notas2(Aluno *aluno){
    for(int i = 0; i < MAX; i++){
        printf("Digite a %da nota: \n", i+1);
        scanf("%f", &aluno->notas[i]);
    }
}

void calcular_media2(Aluno *aluno){
    float media = 0;
    for(int i = 0; i < MAX; i++){
        media += aluno->notas[i];
    }
    media = media / MAX;
    aluno->media = media;
}

void ler_notas(float v[], int quant){
    for(int i = 0; i < quant; i++){
        printf("Digite a %da nota: \n", i+1);
        scanf("%f", &v[i]);
    }
}

void calcular_media(float notas[], float *media, int quant){
    float res_media = 0;
    for(int i = 0; i < quant; i++){
        res_media += notas[i];
    }
    res_media /= quant;
    *media = res_media;
}

void leia_aluno(Aluno *aluno){
    printf("Digite a matricula do aluno: ");
    scanf("%d", &aluno->matricula);
    ler_notas(aluno->notas, MAX);
    calcular_media(aluno->notas, &aluno->media, MAX);
}

void imprime_aluno(Aluno *aluno){
    printf("Matricula: %d\n", aluno->matricula);
    printf("Primeira nota: %.2f\nSegunda nota: %.2f\nTerceira nota: %.2f\n", aluno->notas[0], aluno->notas[1], aluno->notas[2]);
    printf("Media das notas: %.2f\n", aluno->media);
}

int main(){
    // int *p, x = 10;
    // p = &x;
    // scanf("%d", p);
    // printf("%d", *p);

    Aluno aluno;

    leia_aluno(&aluno);
    imprime_aluno(&aluno);

    return 0;
}