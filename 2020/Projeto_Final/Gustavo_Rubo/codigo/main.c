#include <stdio.h>
#include <stdlib.h>

/*
    VENDING MACHINE
*/

#include "definicoes_sistema.h"
#include "display.h"
#include "coletor_dinheiro.h"
#include "teclado_produtos.h"
#include "cofre.h"
#include "descarga_produto.h"

/***********************************************************************
 Estaticos
 ***********************************************************************/
  int codigoEvento;
  int codigoAcao;
  int estado;
  int acao_matrizTransicaoEstados[NUM_ESTADOS][NUM_EVENTOS];
  int proximo_estado_matrizTransicaoEstados[NUM_ESTADOS][NUM_EVENTOS];

  dinheiro_armazenado = 5000; //comeca com 50 reais para troco
  dinheiro_buffer = 0;
  int produtos_estoque[] = {2, 5, 3, 4}; //temos 4 produtos
  int produtos_valor[] = {200, 350, 300, 40000};
  char* teclas;

/************************************************************************
 executarAcao
 Executa uma acao
 Parametros de entrada:
    (int) codigo da acao a ser executada
 Retorno: (int) codigo do evento interno ou NENHUM_EVENTO
*************************************************************************/
int executarAcao(int codigoAcao)
{
    int retval;
    char *ptr;
    int num = strtol(teclas + 1, &ptr, 10);

    retval = NENHUM_EVENTO;
    if (codigoAcao == NENHUMA_ACAO)
        return retval;

    switch(codigoAcao)
    {
    case A01:
        //incrementa buffer de dinheiro
        col_add_buffer(num);
        break;
    case A02:
        //verifica se o dinheiro é suficiente e se há troco
        if (dinheiro_buffer < produtos_valor[num - 1]) {
            dpl_msg("Dinheiro insuficiente.\n");
            break;
        }
        if (cof_verifica_troco(dinheiro_buffer - produtos_valor[num - 1]))
            retval = TROCO_DISPONIVEL;
        break;
    case A03:
        //verifica se ha produto
        if (dsp_verifica_produto(num))
            retval = PRODUTO_DISPONIVEL;
        break;
    case A04:
        //liberar produto
        dsp_descarregar_produto(num);
        retval = PRODUTO_LIBERADO;
        break;
    case A05:
        //liberar troco, adicionar buffer ao armazenamento
        cof_armazena_valor(dinheiro_buffer);
        col_zera_buffer();
        retval = TROCO_LIBERADO;
        break;
    case A06:
        //devolver dinheiro
        col_cancelar();
        retval = CANCELA;
        break;
    } // switch

    return retval;
} // executarAcao

/************************************************************************
 iniciaMaquina de Estados
 Carrega a maquina de estados
 Parametros de entrada: nenhum
 Retorno: nenhum
*************************************************************************/
void iniciaMaquinaEstados()
{
  int i;
  int j;

  for (i=0; i < NUM_ESTADOS; i++) {
    for (j=0; j < NUM_EVENTOS; j++) {
       acao_matrizTransicaoEstados[i][j] = NENHUMA_ACAO;
       proximo_estado_matrizTransicaoEstados[i][j] = i;
    }
  }
  proximo_estado_matrizTransicaoEstados[IDLE_CLIENTE][INSERE_DINHEIRO] = RECEBENDO_DINHEIRO;
  acao_matrizTransicaoEstados[IDLE_CLIENTE][INSERE_DINHEIRO] = A01;

  proximo_estado_matrizTransicaoEstados[RECEBENDO_DINHEIRO][INSERE_DINHEIRO] = RECEBENDO_DINHEIRO;
  acao_matrizTransicaoEstados[RECEBENDO_DINHEIRO][INSERE_DINHEIRO] = A01;

  proximo_estado_matrizTransicaoEstados[RECEBENDO_DINHEIRO][SELECIONA_PRODUTO] = VERIFICA_TROCO;
  acao_matrizTransicaoEstados[RECEBENDO_DINHEIRO][SELECIONA_PRODUTO] = A02;

  proximo_estado_matrizTransicaoEstados[VERIFICA_TROCO][TROCO_DISPONIVEL] = VERIFICA_DISPONIBILIDADE_PRODUTO;
  acao_matrizTransicaoEstados[VERIFICA_TROCO][TROCO_DISPONIVEL] = A03;

  proximo_estado_matrizTransicaoEstados[VERIFICA_DISPONIBILIDADE_PRODUTO][PRODUTO_DISPONIVEL] = LIBERA_PRODUTO;
  acao_matrizTransicaoEstados[VERIFICA_DISPONIBILIDADE_PRODUTO][PRODUTO_DISPONIVEL] = A04;

  proximo_estado_matrizTransicaoEstados[LIBERA_PRODUTO][PRODUTO_LIBERADO] = LIBERA_TROCO;
  acao_matrizTransicaoEstados[LIBERA_PRODUTO][PRODUTO_LIBERADO] = A05;

  proximo_estado_matrizTransicaoEstados[LIBERA_TROCO][TROCO_LIBERADO] = IDLE_CLIENTE;
  acao_matrizTransicaoEstados[LIBERA_TROCO][TROCO_LIBERADO] = NENHUMA_ACAO;

  proximo_estado_matrizTransicaoEstados[RECEBENDO_DINHEIRO][CANCELA] = DEVOLVE_DINHEIRO;
  acao_matrizTransicaoEstados[RECEBENDO_DINHEIRO][CANCELA] = A06;

  proximo_estado_matrizTransicaoEstados[VERIFICA_TROCO][TROCO_INDISPONIVEL] = DEVOLVE_DINHEIRO;
  acao_matrizTransicaoEstados[VERIFICA_TROCO][TROCO_INDISPONIVEL] = NENHUMA_ACAO;

  proximo_estado_matrizTransicaoEstados[VERIFICA_DISPONIBILIDADE_PRODUTO][PRODUTO_INDISPONIVEL] = DEVOLVE_DINHEIRO;
  acao_matrizTransicaoEstados[VERIFICA_DISPONIBILIDADE_PRODUTO][PRODUTO_INDISPONIVEL] = NENHUMA_ACAO;

  proximo_estado_matrizTransicaoEstados[IDLE_CLIENTE][ACIONA_TRAVA_MANUTENCAO] = IDLE_MANUTENCAO;
  acao_matrizTransicaoEstados[IDLE_CLIENTE][ACIONA_TRAVA_MANUTENCAO] = NENHUMA_ACAO;

  proximo_estado_matrizTransicaoEstados[IDLE_MANUTENCAO][DESACIONA_TRAVA_MANUTENCAO] = IDLE_CLIENTE;
  acao_matrizTransicaoEstados[IDLE_MANUTENCAO][DESACIONA_TRAVA_MANUTENCAO] = NENHUMA_ACAO;

  proximo_estado_matrizTransicaoEstados[IDLE_MANUTENCAO][PRESSIONA_1] = ADICIONANDO_REMOVENDO_DINHEIRO;
  acao_matrizTransicaoEstados[IDLE_MANUTENCAO][PRESSIONA_1] = NENHUMA_ACAO;

  proximo_estado_matrizTransicaoEstados[ADICIONANDO_REMOVENDO_DINHEIRO][PRESSIONA_2] = IDLE_MANUTENCAO;
  acao_matrizTransicaoEstados[ADICIONANDO_REMOVENDO_DINHEIRO][PRESSIONA_2] = NENHUMA_ACAO;

  proximo_estado_matrizTransicaoEstados[IDLE_MANUTENCAO][PRESSIONA_3] = ADICIONANDO_REMOVENDO_PRODUTO;
  acao_matrizTransicaoEstados[IDLE_MANUTENCAO][PRESSIONA_3] = NENHUMA_ACAO;

  proximo_estado_matrizTransicaoEstados[ADICIONANDO_REMOVENDO_PRODUTO][PRESSIONA_4] = IDLE_MANUTENCAO;
  acao_matrizTransicaoEstados[IDLE_MANUTENCAO][PRESSIONA_4] = NENHUMA_ACAO;

} // initStateMachine

/************************************************************************
 iniciaSistema
 Inicia o sistema ...
 Parametros de entrada: nenhum
 Retorno: nenhum
*************************************************************************/
void iniciaSistema()
{
   iniciaMaquinaEstados();
} // initSystem

/************************************************************************
 obterEvento
 Obtem um evento, que pode ser da IHM ou do alarme
 Parametros de entrada: nenhum
 Retorno: codigo do evento
*************************************************************************/

int obterEvento(int estado)
{
  int retval = NENHUM_EVENTO;

  teclas = tcp_obterTeclas();

  if (teclas[0] == 'i' && (estado == 0 || estado == 1))
    return INSERE_DINHEIRO;
  if (teclas[0] == 's' && (estado == 1))
    return SELECIONA_PRODUTO;
  if (teclas[0] == 'c' && (estado == 1))
    return CANCELA;
  if (teclas[0] == 'm' && (estado == 0))
    return ACIONA_TRAVA_MANUTENCAO;
  if (teclas[0] == 'n' && (estado == 7))
    return DESACIONA_TRAVA_MANUTENCAO;

  return retval;

} // obterEvento

/************************************************************************
 obterAcao
 Obtem uma acao da Matriz de transicao de estados
 Parametros de entrada: estado (int)
                        evento (int)
 Retorno: codigo da acao
*************************************************************************/
int obterAcao(int estado, int codigoEvento) {
  return acao_matrizTransicaoEstados[estado][codigoEvento];
} // obterAcao


/************************************************************************
 obterProximoEstado
 Obtem o proximo estado da Matriz de transicao de estados
 Parametros de entrada: estado (int)
                        evento (int)
 Retorno: codigo do estado
*************************************************************************/
int obterProximoEstado(int estado, int codigoEvento) {
  return proximo_estado_matrizTransicaoEstados[estado][codigoEvento];
} // obterAcao


/************************************************************************
 Main
 Loop principal de controle que executa a maquina de estados
 Parametros de entrada: nenhum
 Retorno: nenhum
*************************************************************************/
int main() {

  int codigoEvento;
  int codigoAcao;
  int estado;
  int eventoInterno;

  estado = IDLE_CLIENTE;
  eventoInterno = NENHUM_EVENTO;

  iniciaSistema();
  printf ("Vending Machine iniciada\n");
  printf ("Para inserir dinheiro, tecle i e valor a inserir em moedas\n");
  printf ("Para cancelar, tecle c\n");
  printf ("Para selecionar o produto, tecle s e numero do produto\n");
  printf("Produtos:\n1 - Agua  R$2,00\n2 - Refri R$3,50\n3 - Suco  R$3,00\n4 - Lala  R$40,00\n");

  while (true) {
    if (eventoInterno == NENHUM_EVENTO) {
        codigoEvento = obterEvento(estado);
    } else {
        codigoEvento = eventoInterno;
    }
    if (codigoEvento != NENHUM_EVENTO)
    {
       codigoAcao = obterAcao(estado, codigoEvento);
       estado = obterProximoEstado(estado, codigoEvento);
       eventoInterno = executarAcao(codigoAcao);
       //printf("Estado: %d  Evento: %d  Acao: %d  Dinheiro inserido: %d centavos\n", estado, codigoEvento, codigoAcao, dinheiro_buffer);
    }
  } // while true
} // main
