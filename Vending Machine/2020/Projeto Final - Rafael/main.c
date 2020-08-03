#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "atuadores.h"
#include "dbtroco.h"
#include "definicoes_sistema.h"
#include "tela.h"
#include "gerenciador_de_modos.h"
#include "contadordinheiro.h"
#include "dbproduto.h"
#include "teclado.h"

//Vending Machine
//Rafael Sobral Augusto 10337193 05/05/2020

//Variaveis que vão ser usadas no código todo
int acao_transicao[NUM_ESTADOS][NUM_EVENTOS];
int estado_seguinte_transicao[NUM_ESTADOS][NUM_EVENTOS];
int estado_atual;
int evento_atual;
int acao_atual;
char* desejo;
int dinheiro_suficiente;
int produto_disponivel;
int produto_atual;
int troco_retornar;

//Funcao inicioVM
//Como se ligasse a Vending Machine para funcionar
void inicioVM(){
    inicioME();
}

//Funcao inicioME
//Atualiza as matrizes acao_transicao e estado_seguinte_transicao
//Para tal, segue a máquina de estados definida na teoria
//Matrizes indicam para onde ir e qual ação executar para determinado estado e evento realizado
void inicioME(){
    int i;
    int j;

    i=0;
    while (i<NUM_ESTADOS){
        j=0;
        while (j<NUM_EVENTOS){
            acao_transicao[i][j]=SEM_ACAO_NEM_REACAO;
            estado_seguinte_transicao[i][j]=i;
            j+=1;
        }
        i+=1;
    }

    //Eventos no Idle
    estado_seguinte_transicao[IDLE][MOEDA_INSERIDA]=RECEBE_DINHEIRO;
    acao_transicao[IDLE][MOEDA_INSERIDA]=A0;

    estado_seguinte_transicao[IDLE][SELECIONA_PRODUTO]=IDLE;
    acao_transicao[IDLE][SELECIONA_PRODUTO]=A1;

    estado_seguinte_transicao[IDLE][COMPRA_CANCELADA]=IDLE;
    acao_transicao[IDLE][COMPRA_CANCELADA]=A5;

    estado_seguinte_transicao[IDLE][MANUTENCAO_ESCOLHIDA]=AGUARDA_SENHA;
    acao_transicao[IDLE][MANUTENCAO_ESCOLHIDA]=A7;

    //Eventos após recebe dinheiro
    estado_seguinte_transicao[RECEBE_DINHEIRO][MOEDA_INSERIDA]=RECEBE_DINHEIRO;
    acao_transicao[RECEBE_DINHEIRO][MOEDA_INSERIDA]=A0;

    estado_seguinte_transicao[RECEBE_DINHEIRO][SELECIONA_PRODUTO]=PRODUTO_ESCOLHIDO;
    acao_transicao[RECEBE_DINHEIRO][SELECIONA_PRODUTO]=A2;

    estado_seguinte_transicao[RECEBE_DINHEIRO][COMPRA_CANCELADA]=IDLE;
    acao_transicao[RECEBE_DINHEIRO][COMPRA_CANCELADA]=A6;

    //Eventos no Produto Selecionado
    estado_seguinte_transicao[PRODUTO_ESCOLHIDO][SEM_PRODUTO_OU_TROCO]=IDLE;
    acao_transicao[PRODUTO_ESCOLHIDO][SEM_PRODUTO_OU_TROCO]=A3;

    estado_seguinte_transicao[PRODUTO_ESCOLHIDO][FALTA_DINHEIRO]=RECEBE_DINHEIRO;
    acao_transicao[PRODUTO_ESCOLHIDO][FALTA_DINHEIRO]=A1;

    estado_seguinte_transicao[PRODUTO_ESCOLHIDO][COMPRA_APROVADA]=IDLE;
    acao_transicao[PRODUTO_ESCOLHIDO][COMPRA_APROVADA]=A4;

    //Eventos no Aguarda Senha
    estado_seguinte_transicao[AGUARDA_SENHA][SENHA_INCORRETA]=IDLE;
    acao_transicao[AGUARDA_SENHA][SENHA_INCORRETA]=A5;

    estado_seguinte_transicao[AGUARDA_SENHA][SENHA_CORRETA]=MANUTENCAO;
    acao_transicao[AGUARDA_SENHA][SENHA_CORRETA]=A8;

    //Eventos no Idle Manutençao
    estado_seguinte_transicao[MANUTENCAO][RETORNA_PARA_IDLE]=IDLE;
    acao_transicao[MANUTENCAO][RETORNA_PARA_IDLE]=A5;

    estado_seguinte_transicao[MANUTENCAO][SELECIONA_ATUALIZA_PRODUTO]=REPOSICAO_PRODUTO;
    acao_transicao[MANUTENCAO][SELECIONA_ATUALIZA_PRODUTO]=A9;

    estado_seguinte_transicao[MANUTENCAO][SELECIONA_ATUALIZA_TROCO]=REPOSICAO_TROCO;
    acao_transicao[MANUTENCAO][SELECIONA_ATUALIZA_TROCO]=A10;

    //Eventos no Reposição produto
    estado_seguinte_transicao[REPOSICAO_PRODUTO][PRODUTO_ATUALIZADO]=IDLE;
    acao_transicao[REPOSICAO_PRODUTO][PRODUTO_ATUALIZADO]=A11;

    //Eventos no Reposição troco
    estado_seguinte_transicao[REPOSICAO_TROCO][TROCO_ATUALIZADO]=IDLE;
    acao_transicao[REPOSICAO_TROCO][TROCO_ATUALIZADO]=A12;
}

//Funcao execucaoAcao
//É o que propriamente faz a Vending Machine funcionar
//Executa acoes nas transiçoes entre estados
//Input: numero da acao que precisa ser executada
int execucaoAcao(int numAcao){
    int evento_interno_a_fazer=SEM_EVENTOS_FIQUE_EM_CASA;
    int dinheiro_inserido;

    if (numAcao==SEM_ACAO_NEM_REACAO){
        return evento_interno_a_fazer;
    }

    if (numAcao==A0){
        //Estado S0 e Evento S0, executar soma e exibição dinheiro
        if ((desejo[1]=='1')){
            if (desejo[3]=='0'){
                dinheiro_inserido=100;
            }
            else{
                dinheiro_inserido=10;
            }
        }
        if (desejo[1]=='5'){
            dinheiro_inserido=50;
        }
        if (desejo[1]=='2'){
            dinheiro_inserido=25;
        }
        ctd_dinheiro_inserido(dinheiro_inserido);
        tla_visor_inicial();
    }
    if (numAcao==A1){
        tla_falta_dinheiro();
        tla_visor_inicial();
    }
    if (numAcao==A2){
        produto_atual=dbp_retorna_produto(desejo);
        produto_disponivel=dbp_checa_produto(produto_atual);
        if (produto_disponivel==1){
            dinheiro_suficiente=ctd_dinheiro_suficiente(produto_atual);
            if (dinheiro_suficiente==1){
                troco_retornar=dbt_troco_suficiente(dinheiro,produto_atual);
                if (troco_retornar<0){
                    evento_interno_a_fazer=SEM_PRODUTO_OU_TROCO;
                    troco_retornar=0;
                }
                else{
                    evento_interno_a_fazer=COMPRA_APROVADA;
                }
            }
            else{
                evento_interno_a_fazer=FALTA_DINHEIRO;
            }
        }
        else{
            evento_interno_a_fazer=SEM_PRODUTO_OU_TROCO;
        }
    }
    if (numAcao==A3){
        //Devolver dinheiro porque faltou o produto ou troco
        tla_sem_produto_ou_troco(produto_disponivel);
        ctd_devolucao();
        tla_visor_inicial();
    }
    if (numAcao==A4){
        //Tudo certo, compra efetuada
        dbp_atualiza_compra(produto_atual);
        atd_libera_produto();
        tla_compra_efetuada(troco_retornar);
        dbt_diminui_troco();
        dinheiro=0;
        troco_retornar=0;
        tla_visor_inicial();
    }
    if (numAcao==A5){
        tla_visor_inicial();
    }
    if (numAcao==A6){
        tla_cancelamento();
        ctd_devolucao();
        tla_visor_inicial();
    }
    if (numAcao==A7){
        tla_pedido_senha();
    }
    if (numAcao==A8){
        tla_manutencao();
    }
    if (numAcao==A9){
        tla_confirma_manutencao(1);
        evento_interno_a_fazer=PRODUTO_ATUALIZADO;
    }
    if (numAcao==A10){
        tla_confirma_manutencao(2);
        evento_interno_a_fazer=TROCO_ATUALIZADO;
    }
    if (numAcao==A11){
        int qtde;
        int preco;
        int local;
        local=tec_local_produto();
        qtde=tec_qtde_produto();
        preco=tec_preco_produto();
        dbp_atualiza_produto(local,qtde,preco);
        tla_visor_inicial();
    }
    if (numAcao==A12){
        int moedas[4];
        int i=0;
        while (i<=3){
            moedas[i]=tec_moeda_inserida(i);
            i+=1;
        }
        dbt_atualiza_troco(moedas);
        tla_visor_inicial();
    }
    return evento_interno_a_fazer;
}

//Funcao obtemEvento
//Interpreta qual deve ser o proximo evento de acordo com o estado e o que aconteceu
//Depende exclusivamente da ação do usuário
//Output: numero do evento que tem que ser realizado
int obtemEvento(){
    int evento_obtido=SEM_EVENTOS_FIQUE_EM_CASA;
    desejo=tec_digita_usuario();
    if ((estado_atual==IDLE || estado_atual==RECEBE_DINHEIRO)&& (desejo[0]=='x')){
        //Estado S0 e Evento E0
        return MOEDA_INSERIDA;
    }
    else if ((estado_atual==IDLE || estado_atual==RECEBE_DINHEIRO) && desejo[0]=='p'){
        return SELECIONA_PRODUTO;
    }
    else if ((estado_atual==IDLE || estado_atual==RECEBE_DINHEIRO) && desejo[0]=='C'){
        return COMPRA_CANCELADA;
    }
    else if (estado_atual==IDLE && desejo[0]=='M'){
        return MANUTENCAO_ESCOLHIDA;
    }
    else if (estado_atual==AGUARDA_SENHA){
        if (strcmp(desejo,"covid19")==0){
            return SENHA_CORRETA;
        }
        return SENHA_INCORRETA;
    }
    else if (estado_atual==MANUTENCAO){
        if (desejo[0]=='P'){
            return SELECIONA_ATUALIZA_PRODUTO;
        }
        else if (desejo[0]=='T'){
            return SELECIONA_ATUALIZA_TROCO;
        }
        else{
            return RETORNA_PARA_IDLE;
        }
    }
    else if (estado_atual==REPOSICAO_PRODUTO){
        return PRODUTO_ATUALIZADO;
    }
    return evento_obtido;
    //Bral tem que fazer kkkk otario esse mlk ai
}

//Funcao obtemAcao
//Basicamente, pega todo o trabalho ja feito pela obtemEvento e com isso, decide a açao a realizar
//Baseia-se na matriz inicial montada em inicioME
//Inputs: Estado e eventos atuais
//Output: Acao a ser realizada agora
int obtemAcao(int estado_atual, int evento_atual){
    return acao_transicao[estado_atual][evento_atual];
}

//Funcao obtemProximoEstado
//Basicamente,tambem pega o trabalho realizado pela obtemEvento e fala qual é o estado pra onde vai
//Baseia-se puramente na matriz montada em inicioME
//Inputs: Estado e eventos atuais
//Output: Proximo estado
int obtemProximoEstado(int estado_atual, int evento_atual){
    return estado_seguinte_transicao[estado_atual][evento_atual];
}

//Funcao Main
//Responsavel por inicializar a máquina e o loop infinito da VM
int main(){
    int evento_interno;

    evento_interno=SEM_EVENTOS_FIQUE_EM_CASA;
    inicioVM();
    printf("IT'S ALIVEEEE!! By: Sobral. \n");


    int i=0;
    int num=0;
    char s[5];
    char buf[4];
    while (i<3){
        scanf("%s",buf);
        s[i]=buf;
        i+=1;
    }
    printf("jagunca %s",s);


    estado_atual=IDLE;

    //Realiza o print do display inicial
    tla_visor_inicial();

    while (1){
        if (evento_interno==SEM_EVENTOS_FIQUE_EM_CASA){
            //Caso não tenham eventos internos pra realizar, pede input do usuário
            evento_atual=obtemEvento();
        }
        else {
            evento_atual=evento_interno;
        }
        if (evento_atual!=SEM_EVENTOS_FIQUE_EM_CASA) {
            acao_atual=obtemAcao(estado_atual, evento_atual);
            estado_atual=obtemProximoEstado(estado_atual,evento_atual);
            evento_interno=execucaoAcao(acao_atual);
        }
        else if (evento_atual==SEM_EVENTOS_FIQUE_EM_CASA && estado_atual !=IDLE){
            estado_atual=IDLE;

        }
    }
}
