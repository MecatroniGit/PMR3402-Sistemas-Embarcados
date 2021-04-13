#include <stdio.h>
#include <stdlib.h>

#include "definicoes_sistema.h"
#include "descarga_produto.h"

int produtos_estoque[4];

int dsp_verifica_produto (int num) {
    if (produtos_estoque[num - 1] > 0) {
        dpl_msg("Produto disponivel\n");
        return true;
    }
    else {
        dpl_msg("Produto em falta\n");
        return false;
    }
}

void dsp_descarregar_produto(int num) {
    produtos_estoque[num - 1] --;
    dpl_msg("Produto descarregado.\n");
}
