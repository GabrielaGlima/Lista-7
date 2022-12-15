/*4. Escreva rotinas para somar, subtrair e dividir números racionais
(numerador/denominador). Faça um menu com opções.
typedef struct {
    float numerador;
    float denominador;
} Racional;*/
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    float numerador;
    float denominador;
} Racional;

struct Racional {
    float numerador;
    float denominador;
};

float soma(float n1, float n2){
    return n1 + n2;
}

float subtracao(float n1, float n2){
    return n1 - n2;
}

float multiplicacao(float n1, float n2){
    return n1 * n2;
}

float divisao(float n1, float n2){
    return n1 / n2;
}

void menu(char *c){
     printf("----- CALCULADORA BASICA -----\n");

    printf("Digite a operacao que deseja realizar (+, -, *, /): \n");
    setbuf(stdin, NULL);
    scanf("%c", c);
    setbuf(stdin, NULL);
}

void ler(Racional *racional){
    printf("Digite o denominador: ");
    scanf("%f", &racional->denominador);

    printf("Digite o numerador: ");
    scanf("%f", &racional->numerador);
}

int main(){
    Racional racional;
    float resultado = 0;
    char c;

    ler(&racional);
    menu(&c);

    while(c == '+' || c == '-' || c == '*' || c == '/'){

        switch(c){
            case '+':
                resultado = soma(racional.denominador, racional.numerador);
                printf("%.2f + %.2f = %.2f\n", racional.denominador, racional.numerador, resultado);
                system("pause");
                system("cls");
                break;
            case '-':
                resultado = subtracao(racional.denominador, racional.numerador);
                printf("%.2f - %.2f = %.2f\n", racional.denominador, racional.numerador, resultado);
                system("pause");
                system("cls");
                break;
            case '*':
                resultado = multiplicacao(racional.denominador, racional.numerador);
                printf("%.2f * %.2f = %.2f\n", racional.denominador, racional.numerador, resultado);
                system("pause");
                system("cls");
                break;
            case '/':
                if(racional.numerador != 0){
                    resultado = divisao(racional.denominador, racional.numerador);
                    printf("%.2f / %.2f = %.2f\n", racional.denominador, racional.numerador, resultado);
                }else
                    printf("Nao eh possivel dividir por zero!\n");
                system("pause");
                system("cls");
                break;
        }
        menu(&c);
    }
    
    return 0;
}