#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void atd_libera_produto(){
    //Finge que fez algo, pq não tem um atuador em C
    //Não deveria ter uns prints, todo print deveria estar no componente tela, só pus pra simular mais a experiência do comprador
    int trava;
    printf("\nGira gira gira gira... \n");
    trava=rand();
    if (trava<=25){
        printf("Pois é, parece que travou. Uma pena, dá umas batidinhas ai!\n");
    }
}
