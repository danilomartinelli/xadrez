#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void movimento_rei (char tabuleiro[10][10], int linha, int colunam, int linhaNova, int colunaNova){
    int movimento_valido;
    do {
    if(((coluna-colunavelha==1) && (linha-linhavelha==1)) || ((colunavelha-coluna==1) && ((linha-linhavelha)==1)) || ((colunavelha-coluna==1) && (linha-linhavelha==1)) || ((colunavelha-coluna==1) && (linhavelha-linha==1)) || ((linha-linhavelha==1) && ((coluna==colunavelha)) || ((linhavelha-linha==1) && (coluna==colunavelha)) || ((linhavelha==linha) && (colunavelha-coluna=1)) || ((linhavelha==linha) && (coluna-colunavelha=1)){
        movimento_valido=1;
    }
    else {
        movimento_valido=0;
    }
    if (movimento_valido==1){
        printf("Movimento valido");
    }
    else {
        printf("Movimento invalido");
    }
    }
    while (movimento_valido==0);
}
