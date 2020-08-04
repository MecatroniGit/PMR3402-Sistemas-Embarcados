#ifndef DEFINICOES_SISTEMA_H_INCLUDED
#define DEFINICOES_SISTEMA_H_INCLUDED

#define NUM_ESTADOS 7
#define NUM_EVENTOS 13

// ESTADOS
#define IDLE 0
#define RECEBE_DINHEIRO 1
#define PRODUTO_ESCOLHIDO 2
#define AGUARDA_SENHA 3
#define MANUTENCAO 4
#define REPOSICAO_PRODUTO 5
#define REPOSICAO_TROCO 6

// EVENTOS
#define SEM_EVENTOS_FIQUE_EM_CASA -1
#define MOEDA_INSERIDA 0
#define SELECIONA_PRODUTO 1
#define SEM_PRODUTO_OU_TROCO 2
#define FALTA_DINHEIRO 3
#define COMPRA_APROVADA 4
#define COMPRA_CANCELADA 5
#define MANUTENCAO_ESCOLHIDA 6
#define SENHA_INCORRETA 7
#define SENHA_CORRETA 8
#define RETORNA_PARA_IDLE 9
#define SELECIONA_ATUALIZA_PRODUTO 10
#define SELECIONA_ATUALIZA_TROCO 11
#define PRODUTO_ATUALIZADO 12
#define TROCO_ATUALIZADO 13

// ACOES
#define SEM_ACAO_NEM_REACAO -1
#define A0  0 //Soma dinheiro e exibe
#define A1  1 //Exibe mensagem pedindo dinheiro
#define A2  2 //Verifica produto dinheiro e troco
#define A3  3 //Devolve dinheiro e exibe problema (produto ou troco)
#define A4  4 //Atualiza DB de troco/produto e os libera
#define A5  5 //Printa o início no Idle
#define A6  6 //Devolve dinheiro e printa início do Idle
#define A7  7 //Pede a senha para o usuario
#define A8  8 //Pergunta o que deseja fazer
#define A9  9 //Confirma que selecionou repor produto
#define A10  10 //Confirma que selecionou repor troco
#define A11  11 //Pede preço, qtde e local e atualiza DB de produtos e printa valores atuais
#define A12  12 //Pede valores das moedas, atualiza DB de troco e printa valores atuais

#endif
