#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "definicoes_sistema.h"
#include "dbproduto.h"

//Listas responsáveis por ter o preço, a quantidade e o nome dos produtos
extern int Produtos_preco[10]={350, 300, 250, 200, 300, 300, 350, 400, 0, 0};
extern int Produtos_qtde[10]={7,3,9,2,4,0,12,3,3,8};
extern char Produtos_nome[10][25]={"Alcool em gel","Mascara","Isolamento","Quarentena","Distanciamento","Respirador","Leito","Hospital","Meets","10naVM"};

//Checa se tem produto para suprir o pedido do usuario
extern int dbp_checa_produto(int produto_atual){
    if (Produtos_qtde[produto_atual]>0){
        return 1;
    }
    return 0;
}

//Retorna o produto que o usuario deseja de acordo com o input
//Tive que fazer uma adaptação pois stoi e atoi não funcionam no meu pc
extern int dbp_retorna_produto(char* desejo){
    if (desejo[1]=='1'){
        if (desejo[2]=='0'){
            return 9;
        }
        return 0;
    }
    if (desejo[1]=='2'){
        return 1;
    }
    if (desejo[1]=='3'){
        return 2;
    }
    if (desejo[1]=='4'){
        return 3;
    }
    if (desejo[1]=='5'){
        return 4;
    }
    if (desejo[1]=='6'){
        return 5;
    }
    if (desejo[1]=='7'){
        return 6;
    }
    if (desejo[1]=='8'){
        return 7;
    }
    if (desejo[1]=='9'){
        return 8;
    }
}

//Atualiza a DB do produto após a compra ser confirmada
extern void dbp_atualiza_compra(int produto_atual){
    Produtos_qtde[produto_atual]-=1;
}

//Atualiza a DB do produto após reposição na manutenção
extern void dbp_atualiza_produto(int local, int qtde, int preco){
    Produtos_qtde[local]+=qtde;
    Produtos_preco[local]=preco;
}
