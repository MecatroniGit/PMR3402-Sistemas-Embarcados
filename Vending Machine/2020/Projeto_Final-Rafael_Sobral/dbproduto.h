#ifndef DBPRODUTO_H_INCLUDED
#define DBPRODUTO_H_INCLUDED

extern char Produtos_nome[10][25];
extern int Produtos_preco[10];
extern int Produtos_qtde[10];

extern int dbp_checa_produto(int produto_atual);

extern int dbp_retorna_produto(char* desejo);

extern void dbp_atualiza_compra(int produto_atual);

extern void dbp_atualiza_produto(int local, int qtde, int preco);

#endif
