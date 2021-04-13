#include <stdio.h>
#include <stdlib.h>

#include "definicoes_sistema.h"
#include "coletor_dinheiro.h"

int dinheiro_buffer;     //dinheiro no buffer de entrada

void col_add_buffer(int val) {
    dinheiro_buffer += val;
    printf("Dinheiro adicionado. Saldo: %d centavos\n", dinheiro_buffer);
}

void col_zera_buffer() {
    dinheiro_buffer = 0;
    dpl_msg("Retire seu troco.\n");
}

void col_cancelar() {
    dinheiro_buffer = 0;
    dpl_msg("Compra cancelada.\n");
    dpl_msg("Retire seu dinheiro.\n");
}
