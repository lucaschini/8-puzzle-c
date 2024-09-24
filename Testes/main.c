#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void gerar(int *lista);

int main(){
    setlocale(LC_ALL, "PORTUGUESE");

    int tela[9];
    gerar(tela);

    for(int i = 0; i < 9; i++){
        printf("%d", tela[i]);
    }
}


void gerar(int *lista){

    int valor = 0;
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    while (valor != 1){

        // GERAR LISTA:
        int i, j, temp; // Definição de variáveis
        // Inicializa a lista com valores aleatórios:
        for (i = 0; i < 9; i++) {
            lista[i] = i; // inicializa a lista com valores de 0 a 9
        }
        // Embaralha a lista utilizando um algoritmo de Fisher-Yates
        for (i = 8; i > 0; i--) {
            j = rand() % (i + 1); // gera um índice aleatório
            temp = lista[i];
            lista[i] = lista[j];
            lista[j] = temp; // troca os valores
        }


        //CALCULAR INVERSÕES:

        int inv = 0;
        for(int i = 0; i < 8; i++)
        {
            for(int j = i + 1; j < 9; j++ )
            {
                if(lista[i] > lista[j])
                {
                    inv++;
                }
            }
        }

        //VALIDAR
        for(int i = 0; i < 9; i++){
            if(lista[i] == 0){
                if((i+1) % 2 == 0 && inv % 2 == 0){
                    valor = 1;
                }
                else{
                    if((i+1) % 2 == 1 && inv % 2 == 1){
                        valor = 1;
                    }
                }
            }

        }

    }
}
