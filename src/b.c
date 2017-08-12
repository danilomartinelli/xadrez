#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//Início das funções de movimento
void movimento_bispo (tabuleiro, linha, coluna, linhaNova, colunaNova);

int main () {
    movimento_bispo (tabuleiro, linha, coluna, linhaNova, colunaNova);
return 0;
}

void movimento_bispo (char tabuleiro[10][10], int linha, int coluna, int linhaNova, int colunaNova){
    int movimento_valido;
    do {
        if((colunaNova-coluna == linhaNova-linha) || (colunaNova-coluna==linha-linhaNova)){
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

void movimento_rainha (char tabuleiro[10][10], int linha, int colunam, int linhaNova, int colunaNova){
    int movimento_valido;
    do {
    if((colunaNova-coluna==linhaNova-linha) || (colunaNova-coluna==linha-linhaNova) || ((coluna==colunaNova) && (linhanova!=linha)) || ((linha==linhaNova) && (colunaNova!=coluna))){
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

void movimento_torre (char tauleiro[10][10], int linha, int coluna, int linhaNova, int colunaNova){
    int movimento_valido;
    do {
        if((coluna==colunaNova) && (linhanova!= linha)) || ((linha==linhaNova) && (colunaNova!=coluna))){
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

void movimento_cavalo (char tabuleiro[10][10], int linhavelha, int colunavelha, int linha, int coluna){
    int *movimento_valido;
    do {
        if(((linhavelha-linha==2)&&(colunavelha-coluna==1)) || ((linhavelha-linha==1)&&(colunavelha-coluna==2)) || ((linha-linhavelha==1)&&(colunavelha-coluna==2)) || ((linha-linhavelha==2)&&(colunavelha-coluna==1)) || ((linhavelha-linha==2)&&(coluna-colunavelha==1)) || ((linhavelha-linha==1)&&(coluna-colunavelha==2)) || ((linha-linhavelha==1)&&(coluna-colunavelha==2)) || ((linha-linhavelha==2)&&(coluna-colunavelha==1))){
            printf("Movimento valido");
            *movimento_valido=1;
        }
        else {
            printf("Movimento invalido");
            *movimento_valido=0;
        }
    }
    while (*movimento_valido==0);
}
