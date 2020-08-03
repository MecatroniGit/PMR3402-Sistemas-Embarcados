#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definicoes_sistema.h"
#include "teclado.h"

//Char para pegar o valor digitado
char numerodigitado[10];
int qtde;
int preco;
int local;

//É o obter_teclas que recebe o que foi digitado pelo usuário
extern char* tec_digita_usuario(){
    printf("Digite aqui: ");
    scanf("%s", numerodigitado);
    return numerodigitado;
}

//Serve unicamente para a Manutenção, para pegar o local em que deseja inserir o produto
extern int tec_local_produto(){
    printf("Digite o local do produto que vai atualizar: ");
    scanf("%d",&local);
    return local-1;
}

//Serve unicamente para a Manutenção, para pegar a qtde que deseja inserir do produto
extern int tec_qtde_produto(){
    printf("Digite aqui a quantidade adicionada: ");
    scanf("%d",&qtde);
    return qtde;
}

//Serve unicamente para a Manutenção, para pegar o preço que deseja inserir do produto
extern int tec_preco_produto(){
    printf("Digite aqui o preco do produto (em centavos): ");
    scanf("%d",&preco);
    return preco;
}

//Serve unicamente para a Manutenção, para pegar quantas moedas de troco ele inseriu
extern int tec_moeda_inserida(int i){
    int moeda;
    if (i==0){
        moeda=10;
    }
    else if (i==1){
        moeda=25;
    }
    else if (i==2){
        moeda=50;
    }
    else{
        moeda=100;
    }
    printf("Digite aqui quantas de %d centavos deseja inserir: ",moeda);
    scanf("%d",&moeda);
    return moeda;
}
