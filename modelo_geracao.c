#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define cor_programa "color 17"
#define limpa_tela "cls"

int valor_sorteado,tentativas[1000],indice=-1,cont=0; //variaveis globais

void boas_vindas(){
printf(" __________________________________________________________\n");
printf("| |\n");
printf("| ->Bem vindo<- |\n");
printf("| |\n");
printf("| O objetivo deste jogo eh acertar um numero entre |\n");
printf("| 1 e 1000 no menor numero de tentativas, |\n");
printf("| |\n");
printf("| Atencao o programa indicara se a tentativa eh |\n");
printf("| maior ou menor que a resposta! |\n");
printf("| |\n");
printf("|__________________________________________________________|\n");
getch();
system(limpa_tela);
}

int sorteia_valor(int *valor){
srand(time(NULL));
*valor = 1+(rand()%1000);
}

void mostra_tentativas(int mostrar){
printf("%d\t",mostrar);
}

int pergunta_usuario(int *numero){

printf("\n\n\n\n Informe uma tentativa: ");
scanf("%d",&*numero);
}

void maior_menor(int ma_me){
printf("\n\n ");

if(ma_me > valor_sorteado){
printf("A sua tentativa eh maior eh o numero sorteado");
sleep(3);
}

if(ma_me < valor_sorteado){
printf("A sua tentativa eh menor eh o numero sorteado");
sleep(3);
}

}

int main()
{
system(cor_programa);

boas_vindas();

sorteia_valor(&valor_sorteado);


do{
system(limpa_tela);

for(cont=0;cont<=indice;cont++)
mostra_tentativas(tentativas[cont]);
indice ++;

pergunta_usuario(&tentativas[indice]);

maior_menor(tentativas[indice]);

}while(tentativas[indice]!=valor_sorteado);

system(limpa_tela);

printf("\n\n\n Parabens vc acertou em %d tentativas!!!",indice+1);

}
