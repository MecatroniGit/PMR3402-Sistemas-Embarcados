#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void atd_libera_produto(){
    //Finge que fez algo, pq n�o tem um atuador em C
    //N�o deveria ter uns prints, todo print deveria estar no componente tela, s� pus pra simular mais a experi�ncia do comprador
    int trava;
    printf("\nGira gira gira gira... \n");
    trava=rand();
    if (trava<=25){
        printf("Pois �, parece que travou. Uma pena, d� umas batidinhas ai!\n");
    }
}
