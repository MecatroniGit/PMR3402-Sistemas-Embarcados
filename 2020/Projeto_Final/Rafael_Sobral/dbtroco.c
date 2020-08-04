#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "definicoes_sistema.h"
#include "contadordinheiro.h"
#include "dbproduto.h"
#include "dbtroco.h"

//Variaveis para conter quanto troco tem e calcular quanto troco precisa sem alterar a DB do troco
extern int troco[4]={10,8,15,7};
extern int usados[4]={0,0,0,0};
int trocoretornar;

//Calcula qual o troco necessario e se tem esse valor
extern int dbt_troco_suficiente(int dinheiro,int produto_atual){
    int trocoadar=dinheiro-Produtos_preco[produto_atual];
    trocoretornar=trocoadar;

    while (trocoadar>0){
        if (trocoadar>=10){
            if (trocoadar%10!=0){
                if (troco[1]-usados[1]>0){
                    trocoadar-=25;
                    usados[1]+=1;
                    }
            }
            else if (trocoadar>=100){
                if (troco[3]-usados[3]>0){
                    trocoadar-=100;
                    usados[3]+=1;
                }
                else if (troco[2]-usados[2]>1){
                    trocoadar-=100;
                    usados[2]+=1;
                }
                else if (troco[1]-usados[1]>3){
                    trocoadar-=100;
                    usados[1]+=4;
                }
                else if (troco[0]-usados[0]>9){
                    trocoadar-=100;
                    troco[0]-=10;
                    usados[0]+=10;
                }
                else{
                    usados[0]=0;
                    usados[1]=0;
                    usados[2]=0;
                    usados[3]=0;
                    return -1;
                }
            }
            else if (trocoadar>=50){
                if (troco[2]-usados[2]>0){
                    trocoadar-=50;
                    usados[2]+=1;
                }
                else if (troco[1]-usados[1]>1){
                    trocoadar-=50;
                    usados[1]+=1;
                }
                else if (troco[0]-usados[0]>4){
                    trocoadar-=50;
                    usados[0]+=5;
                }
                else{
                    usados[0]=0;
                    usados[1]=0;
                    usados[2]=0;
                    usados[3]=0;
                    return -1;
                }
            }
            else{
                if (troco[0]-usados[0]>0){
                    usados[0]+=1;
                    trocoadar-=10;
                }
                else{
                    usados[0]=0;
                    usados[1]=0;
                    usados[2]=0;
                    usados[3]=0;
                    return -1;
                }
            }
        }
        else{
            usados[0]=0;
            usados[1]=0;
            usados[2]=0;
            usados[3]=0;
            return -1;
        }
    }
    return trocoretornar;
}

//Atualiza a DB do troco após compra confirmada
extern void dbt_diminui_troco(){
    troco[0]-=usados[0];
    troco[1]-=usados[1];
    troco[2]-=usados[2];
    troco[3]-=usados[3];
    usados[0]=0;
    usados[1]=0;
    usados[2]=0;
    usados[3]=0;
}

//Atualiza o troco após Manutenção
extern void dbt_atualiza_troco(int moedas[4]){
    int i=0;
    while (i<=3){
        troco[i]+=moedas[i];
        i+=1;
    }
}
