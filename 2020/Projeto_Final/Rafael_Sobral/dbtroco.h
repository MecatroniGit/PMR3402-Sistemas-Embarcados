#ifndef DBTROCO_H_INCLUDED
#define DBTROCO_H_INCLUDED

extern int troco[4];

extern int dbt_troco_suficiente(int dinheiro, int produto_atual);

extern void dbt_diminui_troco();

extern void dbt_atualiza_troco(int moedas[4]);

#endif
