#ifndef TELA_H_INCLUDED
#define TELA_H_INCLUDED

extern void tla_visor_inicial();

extern void tla_falta_dinheiro();

extern void tla_sem_produto_ou_troco(int produto_disponivel);

extern void tla_compra_efetuada(int troco_retornar);

extern void tla_cancelamento();

extern void tla_pedido_senha();

extern void tla_manutencao();

extern void tla_confirma_manutencao(int decisao);

#endif
