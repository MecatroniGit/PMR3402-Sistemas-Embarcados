#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dbproduto.h"
#include "definicoes_sistema.h"
#include "contadordinheiro.h"

//Váriavel que armazena dinheiro inserido pelo comprador
extern int dinheiro=0;

//Incrementa o dinheiro inserido conforme a moeda selecionada
extern void ctd_dinheiro_inserido(int dinheiro_inserido){
    dinheiro+=dinheiro_inserido;
}

//Checa se o dinheiro inserido é suficiente para o produto selecionado
extern int ctd_dinheiro_suficiente(int produto_atual){
    if (Produtos_preco[produto_atual]<=dinheiro){
        return 1;
    }
    return 0;
}

//"Devolve" o dinheiro do comprador caso cancele a compra ou não tenha troco/produto
extern void ctd_devolucao(){
    dinheiro=0;
}
