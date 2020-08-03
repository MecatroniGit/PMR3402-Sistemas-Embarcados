#ifndef GERENCIADOR_DE_MODOS_H_INCLUDED
#define GERENCIADOR_DE_MODOS_H_INCLUDED

/************************
 senha
 Variável que representa a senha do sistema a ser validada.
*************************/
extern char* senha;

/************************
 gdm_validar_senha
 Verifica se a senha condiz com a senha cadastrada
 entradas
   senha: senha digitada pelo usuário
 saidas
   TRUE: senha correta
   FALSE: senha incorreta
*************************/
extern bool gdm_validar_senha(char* senha);


#endif
