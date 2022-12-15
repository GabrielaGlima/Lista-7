/*5. Seja a seguinte estrutura:
        typedef struct {
            int hora;
            int min;
            int seg;
        } Time;
a) Receber uma quantidade de tempo em segundos e transformar a mesma em
horas, minutos e segundo, preenchendo as informações da variável tempo
do tipo struct Time.
b) Faça uma função que recebe o campo hora e devolve a quantidade de horas
em segundos.
c) Faça uma função para imprimir os campos da estrutura Time.*/
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int hora;
    int min;
    int seg;
} Time;

void cadastrar_usando_segundos(int *hora, int *min, int *seg){
    int resto;
    *hora = *seg/3600;
    resto = *seg % 3600;
    *min = *hora/60;
    *seg = resto % 60;
}

int horas_seg(int horas){
    return horas * 3600;
}

void imprimir(Time *time){
    printf("%d:%d:%d\n", time->hora, time->min, time->seg);
}

int main(){
    Time time;
    int seg, horas;

    printf("Digite a quantidade de segundos: ");
    scanf("%d", &seg);
    time.seg = seg;
    cadastrar_usando_segundos(&time.hora, &time.min, &time.seg);
    imprimir(&time);
    printf("Digite a quantidade de horas: ");
    scanf("%d", &horas);
    seg = horas_seg(horas);
    printf("%d horas eh igual a %d\n", horas, seg);
    
    return 0;
}