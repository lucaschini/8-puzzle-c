#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75


void leitura(int *posicao_vazio_i, int *posicao_vazio_j){
    int movimento;
    printf("Faça um movimento:\n\n");
    movimento = getch();
    printf("%c",movimento);
    printf("%d%d",*posicao_vazio_i,*posicao_vazio_j);
    if(movimento == KEY_UP){
        (*posicao_vazio_i)--;
        printf("UP");
    }
    else if(movimento == KEY_DOWN){
        (*posicao_vazio_i)++;
        printf("DO");
    }
    else if(movimento == KEY_RIGHT){
        (*posicao_vazio_j)++;
        printf("RI");
    }
    else if(movimento == KEY_LEFT){
        (*posicao_vazio_j)--;
        printf("LE");
    }
    if((*posicao_vazio_i)>2 || (*posicao_vazio_i)<0 || (*posicao_vazio_j)>2 || (*posicao_vazio_j)<0){
        printf("O movimento não é válido");
    }
    else{
        return *posicao_vazio_i, *posicao_vazio_j;
    }
}
int i, j;
i = 2;
j = 1;
int main(){
leitura(&i,&j);
printf("%d%d",i,j);
}
