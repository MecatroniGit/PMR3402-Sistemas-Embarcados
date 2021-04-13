#include <stdio.h>
#include <stdlib.h>

#include "definicoes_sistema.h"
#include "teclado_produtos.h"

char buf[10];
char* tcp_obterTeclas()
{
    //Produtos aceitos: 1, 2, 3, 4
    printf("obter teclas: ");
    scanf("%s", buf);
    return buf;
}
