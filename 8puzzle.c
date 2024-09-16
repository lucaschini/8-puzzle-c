#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/*

Todo:

enquanto (não completo(puzzle){ //completo(puzzle) deve retornar verdadeiro ou falso, indicando se o puzzle foi resolvido ou não; similar a função somaehpar()
    ler(movimento);  //podem usar scanf() ou fgetc()
    fs(puzzle, puzzle, movimento); //Função similar a altera(); deve modificar o estado puzzle, conforme movimentação que o usuário pediu
    imprimir(puzzle); //Imprimir novo estado conforme o movimento do jogador
}

1° Gerar tela
2° Criar random
3° Verificar se é válido de acordo com a lista de inversões
4° Funcionamento de ponteiro (Verificar quais são os movimentos possíveis)
5° Movimentação (Inverter número com espaço em branco(ponteiro))
6° Verificar constantemente se o jogo acabou

*/

//ASSINATURAS DAS FUNÇÕES

//Imprime a variavel estado, que é uma matriz
void printEstado(int estado[3][3]);
//Copia o conteudo da matriz estado para a matriz copiaEstado
void deepcopy(int estado[3][3], int copiaEstado[3][3]);
//Copia a matriz m1 e faz uma alteracao simples (duplica os valores) alterando a variavel novaMatriz
void altera(int m1[3][3], int novaMatriz[3][3]);
//Soma os valores da matriz e verifica se a soma eh um numero par
int somaehpar(int wololo[3][3]);

//MAIN
int main()
{
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
    altera(moriginal2, malterada); //A ordem dos parametros eh essencial; quem inicializa os valores de mnovo eh a propria funcao
    printEstado(malterada); //imprimindo para ver se está tudo certo

    //Alterando a matriz diversas vezes seguidas
    printf("\nAlterando a matriz 3 vezes seguidas e imprimindo\n");
    printf("Matriz original:");
    printEstado(m);
    printf("\nAlteradas:\n");
    for(int i=0; i<3;i++)
    {
        altera(m, m);
        printf("\t\t");
        printEstado(m);
        printf("\n");
    }

    //verificando se a soma dos valores da matriz eh um numero par
    //Utilizarei as matrizes m (cuja soma eh impar) e malterada (cuja soma eh par)
    printf("\nVerificando se a soma é par\n");
    printf("m: %d\n",somaehpar(m));
    printf("malterada: %d\n",somaehpar(malterada));
    printf("\nVerificando se a soma é par. Usando condições dentro do printf\n");
    printf("m: %d\n",somaehpar(m)==1);
    printf("malterada: %d\n",somaehpar(malterada)==1);
    printf("\nVerificando se a soma é par. Usando a saída da função para processar o if\n");
    if (somaehpar(m))
    {
        printf("a soma de m é par!\n");
    }
    else
    {
        printf("a soma de m é impar!\n");
    }

    if (somaehpar(malterada)) //TODO: algo está errado que faz com que esse eja impresso errado, mas funcionou certo nos outros...
    {
        printf("a soma de malterada é par!\n");
    }
    else
    {
        printf("a soma de malterada é impar!\n");
    }




    return 0;
}

//CORPO DAS FUNCOES

//Imprime a variavel estado, que é uma matriz
//TODO: deixar impressão graficamente mais agradável (pular linhas, etc.)
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
void altera(int m1[3][3], int novaMatriz[3][3]){
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








