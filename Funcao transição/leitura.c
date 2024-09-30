#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75


void sucessora(int *movimento, int *i, int *j, int matriz[3][3]){
    int aux_valor, aux_i, aux_j;
    aux_i = *i; //guardando a posi��o inicial do vazio
    aux_j = *j;
    if(*movimento == KEY_UP && (*i) > 0){ //fazendo a verifica��o e alterando a posi��o
        (*i)--;
    }
    else if(*movimento == KEY_DOWN && (*i) < 2){
        (*i)++;
    }
    else if(*movimento == KEY_RIGHT && (*j) < 2){
        (*j)++;
    }
    else if(*movimento == KEY_LEFT && (*j) > 0){
        (*j)--;
    }
    else{
        return; // se n�o for v�lido
    }
    aux_valor = matriz[*i][*j]; //guardando o valor que o vazio vai ocupar futuramente
    matriz[*i][*j] = 0; //definindo a nova posi��o como vazio
    matriz[aux_i][aux_j] = aux_valor; //definindo a posi��o antiga do vazio com o novo valor
    return;
}

int tecla = KEY_LEFT, i = 2, j = 1;
int m[3][3] = {{1,2,3},{4,5,6},{7,8,0}};
int main(){
sucessora(&tecla,&i,&j,m);
printf("%d%d",i,j);
}
