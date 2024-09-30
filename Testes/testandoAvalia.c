#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void avalia(int m_comparar[3][3], int *retorno);

int main()
{
    setlocale(LC_ALL,"portuguese");

    int teste[3][3] = {{1,2,3},{4,5,6},{7,8,0}}, resultado = 2, *retorno;


    avalia(teste, &retorno);
    printf("Resultado da avaliação %d",retorno);

    return 0;
}

void avalia(int m_comparar[3][3], int *retorno){
    int v_procurado[3][3] = {{1,2,3},{4,5,6},{7,8,0}}, sum = 0; // usar soma pra verificar quantos numeros estão em uma posição correta

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(v_procurado[i][j] == m_comparar[i][j]){
                sum++;
            }
        }
    }
    if (sum == 9){
            *retorno = 1; // caso a soma seja 9, todos os valores estão na posição correta, a solução foi encontrada
    } else {
        *retorno = 0; // caso o vetor atual nao seja igual ao objetivo, ele retorna 0, ou seja, a solução não foi encontrada
    }
}
