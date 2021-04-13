#ifndef DEFINICOES_SISTEMA_H_INCLUDED
#define DEFINICOES_SISTEMA_H_INCLUDED

#define true  1
#define false 0

#define NUM_ESTADOS 10
#define NUM_EVENTOS 16

// ESTADOS
#define IDLE_CLIENTE                      0
#define RECEBENDO_DINHEIRO                1
#define VERIFICA_TROCO                    2
#define VERIFICA_DISPONIBILIDADE_PRODUTO  3
#define LIBERA_PRODUTO                    4
#define LIBERA_TROCO                      5
#define DEVOLVE_DINHEIRO                  6
#define IDLE_MANUTENCAO                   7
#define ADICIONANDO_REMOVENDO_DINHEIRO    8
#define ADICIONANDO_REMOVENDO_PRODUTO     9

// EVENTOS
#define NENHUM_EVENTO              -1
#define INSERE_DINHEIRO             0
#define SELECIONA_PRODUTO           1
#define TROCO_DISPONIVEL            2
#define PRODUTO_DISPONIVEL          3
#define PRODUTO_LIBERADO            4
#define TROCO_LIBERADO              5
#define CANCELA                     6
#define TROCO_INDISPONIVEL          7
#define PRODUTO_INDISPONIVEL        8
#define DINHEIRO_LIBERADO           9
#define ACIONA_TRAVA_MANUTENCAO    10
#define DESACIONA_TRAVA_MANUTENCAO 11
#define PRESSIONA_1                12
#define PRESSIONA_2                13
#define PRESSIONA_3                14
#define PRESSIONA_4                15

// ACOES
#define NENHUMA_ACAO -1
#define A01  0 //incrementar buffer de dinheiro
#define A02  1 //verificar se há troco
#define A03  2 //verificar se há produto
#define A04  3 //liberar produto
#define A05  4 //liberar troco
#define A06  5 //devolver dinheiro


#endif // DEFINICOES_SISTEMA_H_INCLUDED
