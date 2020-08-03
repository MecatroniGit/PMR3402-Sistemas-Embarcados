#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "definicoes_sistema.h"

//Variáveis
char* senha = "admin";

//Funções
extern bool gdm_validar_senha(char* senhaDigitada){
    if(strcmp(senhaDigitada,"admin")==0){
        return true;
    }else{
        return false;
    }
}
