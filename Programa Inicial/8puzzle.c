#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



/*

Todo:

enquanto (não completo(puzzle){ //completo(puzzle) deve retornar verdadeiro ou falso, indicando se o puzzle foi resolvido ou não; similar a função somaehpar()
    ler(movimento);  //podem usar scanf() ou fgetc()
    fs(puzzle, puzzle, movimento); //Função similar a altera(); deve modificar o estado puzzle, conforme movimentação que o usuário pediu OK
    imprimir(puzzle); //Imprimir novo estado conforme o movimento do jogador
}

1° Gerar tela
2° Criar random
3° Verificar se é válido de acordo com a lista de inversões
    Como verificar -> Jogar numeros em uma lista, e verificar quantos números maiores que o n[i], caso soma dos numeros maiores que n[i] seja ímpar, não tem solução.
    TODO: Tem forma mais simples de gerar um tabuleiro valido
4° Funcionamento de ponteiro (Verificar quais são os movimentos possíveis)
5° Movimentação (Inverter número com espaço em branco(ponteiro)) - WASD e fget
    Como movimentar -> Limites do i e j da matriz.

6° Verificar constantemente se o jogo acabou

*/

//ASSINATURAS DAS FUNÇÕES

//Imprime a variavel estado, que é uma matriz
void printEstado(int estado[3][3]);
//Copia o conteudo da matriz estado para a matriz copiaEstado
void deepcopy(int estado[3][3], int copiaEstado[3][3]);
//Copia a matriz m1 e faz uma alteracao simples (duplica os valores) alterando a variavel novaMatriz
void fs(int m1[3][3], int novaMatriz[3][3]);
//Soma os valores da matriz e verifica se a soma eh um numero par
int somaehpar(int wololo[3][3]);


int verifica_inversoes(int m[9]);

//MAIN
int main()
{
    int teste[9]={1,2,3,4,5,6,7,8,0};
    setlocale(LC_ALL,"portuguese");
    //Usando printEstado
    printf("Imprimindo Matriz:\n");
    int m[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    printEstado(m); //Notem que passo m diretamente, sem usar o &

    //Usando deepcopy
    printf("\nCopiando e imprimindo versão nova\n");
    int moriginal[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int mnovo[3][3]; //Notem que nao inicializei mnovo
    deepcopy(moriginal, mnovo); //A ordem dos parametros eh essencial; quem inicializa os valores de mnovo eh a propria funcao
    printEstado(mnovo); //imprimindo para ver se está tudo certo

    //Alterando a matriz e gerando novo estado
    printf("\nAlterando e imprimindo versão alterada\n");
    int moriginal2[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int malterada[3][3]; //Notem que nao inicializei malterada
    fs(moriginal2, malterada); //A ordem dos parametros eh essencial; quem inicializa os valores de mnovo eh a propria funcao
    printEstado(malterada); //imprimindo para ver se está tudo certo

    verifica_inversoes(teste);
    return 0;
}

//CORPO DAS FUNCOES

//Imprime a variavel estado, que é uma matriz
void printEstado(int estado[3][3]){
    for(int i=0; i<3; i++)
    {
        printf("\n");
        for(int j=0; j<3; j++)
        {
            printf("%d\t",estado[i][j]);
        }
    }
    return;
}

//Copia o conteudo da matriz estado para a matriz copiaEstado
void deepcopy(int estado[3][3], int copiaEstado[3][3]){
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            copiaEstado[i][j] = estado[i][j];
        }
    }
    return;
}

//TODO2: usar essa funcao como base para criar a funcao sucessora, sera necessario adicionar novos parametros
void fs(int m1[3][3], int novaMatriz[3][3]){
    deepcopy(m1, novaMatriz);
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            novaMatriz[i][j] = novaMatriz[i][j]*2;
        }
    }
    return;
}

//TODO: usar essa funcao como base para a funcao de avaliacao
int somaehpar(int wololo[3][3])
{
    int sum = 0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            sum += wololo[i][j];
        }
    }
    if ((sum % 2) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//TODO: Pensar em como fazer o for percorrer a lista comparando todos os numeros
//int verifica_inversoes(int m[9]0){
//    int soma=0;
//    for(int i=0;i<=2;i++){
//        if(i < i[i+1]){
//            soma++
//        }
//    }
//    return soma;
//}







