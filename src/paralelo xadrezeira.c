#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void movimento_peao (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha){
    int movimento_valido;
    do {
    if((coluna==colunavelha) && (linha-linhavelha==1)){
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
