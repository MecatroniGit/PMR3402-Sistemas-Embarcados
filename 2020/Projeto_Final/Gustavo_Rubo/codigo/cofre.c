#include <stdio.h>
#include <stdlib.h>

#include "definicoes_sistema.h"
#include "cofre.h"
#include "display.h"

int dinheiro_armazenado;

void cof_armazena_valor (int val) {
    dinheiro_armazenado += val;
    dpl_msg("Compra confirmada.\n");
}

int cof_verifica_troco (int troco) {
    if (dinheiro_armazenado >= troco) return true;
    else {
      dpl_msg("Não temos troco no momento.\n");
      return false;
    }
}

void cof_remove_troco (int troco) {
    dinheiro_armazenado -= troco;
}
