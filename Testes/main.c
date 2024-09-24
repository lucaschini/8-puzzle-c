#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void gerar(int *lista); //Crio a função gerar

int main(){
    setlocale(LC_ALL, "PORTUGUESE"); //Defino a linguagem ed revisão como português

    int tela[9]; //Crio a variável do array (pode ser global se quiserem)
    gerar(tela); //Com a função, transformo o array criado em uma tela resolvível

    for(int i = 0; i < 9; i++){ //Printo o array a fim de testes
        printf("%d", tela[i]);
    }
}


void gerar(int *lista){ //Defino a variável gerar

    int valor = 0; //Crio a variável valor já no começo, pois ela será o valor lógico do While
    srand(time(NULL)); // Inicializa o gerador de números aleatórios (Utilizando o fator random do relógio do computador)
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

        int inv = 0; //Defino a variável que contará o número de inversões
        for(int i = 0; i < 8; i++)
        {
            for(int j = i + 1; j < 9; j++ ) //Crio um for dentro de outro para verificar todas as combinações de dois valores do array
            {
                if(lista[i] > lista[j] && lista[i] != 0 && lista[j] != 0) //Se houverem inversões de posição (Um valor maior que o outro na lista) e diferente de 0 (Zero é o vazio):
                {
                    inv++; //Adiciono +1 na contagem de reversões
                }
            }
        }

        //VALIDAR
        for(int i = 0; i < 9; i++){ //Crio um for para ler a lista
            if(lista[i] == 0){ //Acho o vazio
                if((i+1) % 2 == 0 && inv % 2 == 0){ //Verifico se a posição inicial do vazio é par e se o número de inversões também é
                    valor = 1; //Caso seja, a tela gerada é válida
                }
                else{ //Caso contrário:
                    if((i+1) % 2 == 1 && inv % 2 == 1){ //Verifico se a posição atual do vazio é impar e se o número de inversões também
                        valor = 1; //Caso seja, a tela gerada é válida
                    } //Caso o valor gerado não cumpra nenhum dos dois requisitos, a tela gerada não é resolvível, então a função continua gerando até ser
                }
            }

        }

    }
}
