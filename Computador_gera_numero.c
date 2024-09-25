#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ESC 27
#define KEY_ENTER 13

#define limpa_tela "cls"

int main()
{
    setlocale(LC_ALL,"portuguese");

    void menu_draw ()
    {
        int key = 0;
        while(1)
    {
        system("cls");
        printf("\n   ******** Menu Principal ********\n");
        printf("| O objetivo deste jogo é acertar um número dado o intervalo escolhido |\n");
        printf("   *                              *\n");
        printf("   * %s O jogo gera aleatoriamente um número    *\n", (key == KEY_UP)? "Û": " ");
        printf("   * %s O jogador gera aleatoriamente um número     *\n", (key == KEY_DOWN)? "Û": " ");
        printf("   *                              *\n");
        printf("| Atencao o programa indicara se a tentativa eh |\n");
        printf("| maior ou menor que a resposta! |\n");
        printf("   ********************************\n");
        key = getch();

        if (key == KEY_ESC)
            return;
        system(limpa_tela);
        }
    }

    int sorteia_valor(int *valor){
    srand(time(NULL));
    *valor = 1+(rand()%1000);
    }
}
