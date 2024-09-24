#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int validar(int lista[]);

int main(){
    setlocale(LC_ALL, "PORTUGUESE");

    /*
    int lista[9];
    for (int i = 0; i < 9; i++){
        lista[i] = i;
    }

    int inv = inversoes(lista);
    */
}


int validar(int lista[]){

    int inv = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = i + 1; j < 9; j++ )
        {
            if(lista[i] > lista[j])
            {
                inv++
            }
        }
    }

    int valor = 0;
    for(int i = 0; i < 9; i++){
        if(lista[i] == 0){
            if(i+1 % 2 == 0 && inv % 2 == 0){
                valor = 1;
            }
            else{
                if(i+1 % 2 == 1 && inv % 2 == 1){
                    valor = 1;
                }
            }
        }
    }


}
