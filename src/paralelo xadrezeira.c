#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void validar_movimento_peaoP (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha){
    int movimento_valido, cont;

    if(((colunavelha-coluna==1) && (linhavelha-linha==1))){
        if(isalpha(tabuleiro[linha][coluna])==1){
            if((islower(tabuleiro[linha][coluna])==1)){
                movimento_valido=1;
            }
            else{
                movimento_valido=0;
            }
        }
        if(tabuleiro[linha][coluna]=='-'){
            movimento_valido=1;
        }
    }
    if(((coluna-colunavelha==1) && (linha-linhavelha==1))){
        if(isalpha(tabuleiro[linha][coluna])==1){
            if((islower(tabuleiro[linha][coluna])==1)){
                movimento_valido=1;
            }
            else{
                movimento_valido=0;
            }
        }
        if(tabuleiro[linha][coluna]=='-'){
            movimento_valido=1;
        }
    }
    if (((coluna==colunavelha) && (linha-linhavelha==1))){
        if(isalpha(tabuleiro[linha][coluna])==1){
                movimento_valido=0;
            }
        if(tabuleiro[linha][coluna]=='-'){
            movimento_valido=1;
        }
    }
}

void validar_movimento_peaop (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha){
    int movimento_valido, cont;

    if(((colunavelha-coluna==1) && (linha-linhavelha==1))){
        if(isalpha(tabuleiro[linha][coluna])==1){
            if((isupper(tabuleiro[linha][coluna])==1)){
                movimento_valido=1;
            }
            else{
                movimento_valido=0;
            }
        }
        if(tabuleiro[linha][coluna]=='-'){
            movimento_valido=1;
        }
    }
    if(((coluna-colunavelha==1) && (linhavelha-linha==1))){
        if(isalpha(tabuleiro[linha][coluna])==1){
            if((isupper(tabuleiro[linha][coluna])==1)){
                movimento_valido=1;
            }
            else{
                movimento_valido=0;
            }
        }
        if(tabuleiro[linha][coluna]=='-'){
            movimento_valido=1;
        }
    }
    if (((coluna==colunavelha) && (linhavelha-linha==1))){
        if(isalpha(tabuleiro[linha][coluna])==1){
                movimento_valido=0;
            }
        if(tabuleiro[linha][coluna]=='-'){
            movimento_valido=1;
        }
    }
}
