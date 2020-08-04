#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definicoes_sistema.h"
#include "contadordinheiro.h"
#include "dbproduto.h"
#include "tela.h"

//Visor padrão da VM, aparecerá sempre que voltar para o IDLE
extern void tla_visor_inicial(){
    printf("\nVending Machine da Quarentena! \n");
    printf("Escolha dentre os seguintes produtos: \n");

    int i;
    i=0;
    float precofloat;
    while (i<10){
        precofloat=Produtos_preco[i]/100.0;
        printf("%d - %s : R$ %0.2f \n", i+1, Produtos_nome[i],precofloat);
        i+=1;
    }
    float dinheirofloat;
    dinheirofloat=dinheiro/100.0;
    printf("\nPara inserir dinheiro, digite x+o valor da sua moeda em centavos! \n");
    printf("Por exemplo, se inserir 100 centavos, digitar x100 \n");
    printf("Para selecionar um produto, digite p+o local do produto \n");
    printf("Por exemplo, se quiser o produto 5, digitar p5 \n");
    printf("Para entrar na Manutenção, digite M \n");
    printf("Você já inseriu: R$%0.2f \n",dinheirofloat);
    printf("Para cancelar a operacao, digite C \n");
}

//Mensagem avisando que não tem dinheiro suficiente para certo produto
extern void tla_falta_dinheiro(){
    printf("\nINSIRA DINHEIRO SUFICIENTE PARA ESSE PRODUTO!! \n \n");
}

//Mensagem avisando erro em alguma das etapas da compra
extern void tla_sem_produto_ou_troco(int produto_disponivel){
    if (produto_disponivel==0){
        printf("\nInfelizmente, esse produto está em falta! Pegue seu dinheiro de volta ao lado e volte para casa em segurança! \n");
    }
    else{
        printf("\nInfelizmente, não temos troco suficiente para o valor inserido! Pegue seu dinheiro de volta ao lado! \n");
    }
}

//Mensagem avisando que a compra foi efetuada direitnho
extern void tla_compra_efetuada(int troco_retornar){
    printf("\nSua compra foi efetuada com sucesso! \n");
    printf("Retire seu produto e seu troco de R$%0.2f! \n \n",troco_retornar/100.0);
}

//Mensagem confirmando o cancelamento
extern void tla_cancelamento(){
    printf("\nInfelizmente, sua compra foi CANCELADAH! Pegue seu dinheiro de volta ao lado! \n");
}

//Mensagem pedindo a senha na manutenção
extern void tla_pedido_senha(){
    printf("\nPor favor, digite a senha correta abaixo para entrar no modo de Manutencao! \n");
}

//Mensagem para quando entrou na manutenção
extern void tla_manutencao(){
    printf("\nBem-vindo ao modo de Manutencao! \n");
    printf("O que você deseja fazer? \n");
    printf("Digite T se quiser atualizar o troco \n");
    printf("Digite P se quiser atualizar os produtos \n");
    printf("Digite qualquer outra coisa para determinar o fim e voltar para a tela inicial \n");
}

//Mensagem confirmando o que foi selecionado
extern void tla_confirma_manutencao(int decisao){
    if (decisao==1){
        printf("Voce selecionou atualizar as informacoes dos produtos! \n");
    }
    else{
        printf("Voce selecionou atualizar as informacoes do troco! \n");
    }
}
