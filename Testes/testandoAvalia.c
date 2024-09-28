#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void avalia();

int main()
{
    setlocale(LC_ALL,"portuguese");

    int teste[3][3] = {{1,2,3},{4,5,6},{7,8,0}}, resultado = 2, v_procurado[3][3] = {{1,2,3},{4,5,6},{7,8,0}};


    avalia();
//    printf("Resultado da avaliação %d",resultado);

    return 0;
}

void avalia()
{
    int v_procurado[3][3] = {{1,2,3},{4,5,6},{7,8,0}}, sum = 0, teste[3][3] = {{1,2,3},{4,5,6},{7,0,8}}; // usar soma pra verificar quantos numeros estão em uma posição correta

    for(int i=0; i<3; i++){
            printf("\n");
        for(int j=0; j<3; j++){
            if(v_procurado[i][j] == teste[i][j]){
                printf("%d \n", v_procurado[i][j]);
                printf("%d \n", teste[i][j]);
                sum++;
            }
        }
    }
    printf("Resultado da soma: %d",sum);
//    if (sum > 0){
//        return 1; // caso a soma seja 9, todos os valores estão na posição correta, a solução foi encontrada
//    } else {
//          return 0; // caso o vetor atual nao seja igual ao objetivo, ele retorna 0, ou seja, a solução não foi encontrada
//    }
}
