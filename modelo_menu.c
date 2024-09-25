#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ESC 27
#define KEY_ENTER 13

void menu_draw();

int main (int argc, char ** argv)
{
     menu_draw();
     return 0;
}

void menu_draw ()
{
    int key = 0;
    while(1)
{
    system("cls");
    printf("\n   ******** Menu Principal ********\n");
    printf("   *                              *\n");
    printf("   * %s Opcao 1                    *\n", (key == KEY_UP)? "Û": " ");
    printf("   * %s Opcao 2                    *\n", (key == KEY_DOWN)? "Û": " ");
    printf("   *                              *\n");
    printf("   ********************************\n");
    key = getch();

    if (key == KEY_ESC)
        return;
    }
}
