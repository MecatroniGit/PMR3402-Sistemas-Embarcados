#include <stdio.h>
#include <stdlib.h>

#include "definicoes_sistema.h"
#include "sirene.h"

/************************
 sne_bip
 Aciona momentaneamente a sirene
 entradas
   nenhuma
 saidas
   nenhuma
*************************/
void sne_bip()
{
    printf("Bip da sirene\n");
}


/************************
 sne_acionar
 Aciona ou desaciona a sirene
 entradas
   controle: TRUE:ligar FALSE:desligar
 saidas
   nenhuma
*************************/
void sne_acionar(int controle)
{
    printf("Acionamento da sirene: %d\n", controle);
}
