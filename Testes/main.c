#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void gerar(int *lista); //Crio a fun��o gerar

int main(){
    setlocale(LC_ALL, "PORTUGUESE"); //Defino a linguagem ed revis�o como portugu�s

    int tela[9]; //Crio a vari�vel do array (pode ser global se quiserem)
    gerar(tela); //Com a fun��o, transformo o array criado em uma tela resolv�vel

    for(int i = 0; i < 9; i++){ //Printo o array a fim de testes
        printf("%d", tela[i]);
    }
}


void gerar(int *lista){ //Defino a vari�vel gerar

    int valor = 0; //Crio a vari�vel valor j� no come�o, pois ela ser� o valor l�gico do While
    srand(time(NULL)); // Inicializa o gerador de n�meros aleat�rios (Utilizando o fator random do rel�gio do computador)
    while (valor != 1){

        // GERAR LISTA:
        int i, j, temp; // Defini��o de vari�veis
        // Inicializa a lista com valores aleat�rios:
        for (i = 0; i < 9; i++) {
            lista[i] = i; // inicializa a lista com valores de 0 a 9
        }
        // Embaralha a lista utilizando um algoritmo de Fisher-Yates
        for (i = 8; i > 0; i--) {
            j = rand() % (i + 1); // gera um �ndice aleat�rio
            temp = lista[i];
            lista[i] = lista[j];
            lista[j] = temp; // troca os valores
        }


        //CALCULAR INVERS�ES:

        int inv = 0; //Defino a vari�vel que contar� o n�mero de invers�es
        for(int i = 0; i < 8; i++)
        {
            for(int j = i + 1; j < 9; j++ ) //Crio um for dentro de outro para verificar todas as combina��es de dois valores do array
            {
                if(lista[i] > lista[j] && lista[i] != 0 && lista[j] != 0) //Se houverem invers�es de posi��o (Um valor maior que o outro na lista) e diferente de 0 (Zero � o vazio):
                {
                    inv++; //Adiciono +1 na contagem de revers�es
                }
            }
        }

        //VALIDAR
        for(int i = 0; i < 9; i++){ //Crio um for para ler a lista
            if(lista[i] == 0){ //Acho o vazio
                if((i+1) % 2 == 0 && inv % 2 == 0){ //Verifico se a posi��o inicial do vazio � par e se o n�mero de invers�es tamb�m �
                    valor = 1; //Caso seja, a tela gerada � v�lida
                }
                else{ //Caso contr�rio:
                    if((i+1) % 2 == 1 && inv % 2 == 1){ //Verifico se a posi��o atual do vazio � impar e se o n�mero de invers�es tamb�m
                        valor = 1; //Caso seja, a tela gerada � v�lida
                    } //Caso o valor gerado n�o cumpra nenhum dos dois requisitos, a tela gerada n�o � resolv�vel, ent�o a fun��o continua gerando at� ser
                }
            }

        }

    }
}
