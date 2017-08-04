#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void tabuleiro_em_tela(char tabuleiro[10][10]);
void selecao_peca (int linha, int coluna);

int main(){
    int linha, coluna;
    char tabuleiro[10][10];
    tabuleiro_em_tela(tabuleiro);
    selecao_peca (linha, coluna);
}

    void tabuleiro_em_tela(char tabuleiro[10][10]){
    int linha, coluna;

    for (linha = 1; linha < 9; linha++)
    {
        coluna = 0;
        tabuleiro[linha][coluna] = linha + 48;
        coluna = 9;
        tabuleiro[linha][coluna] = linha + 48;
    }

    for (coluna = 1; coluna < 9; coluna++)
    {
        linha = 0;
        tabuleiro[linha][coluna] = coluna + 48;
        linha = 9;
        tabuleiro[linha][coluna] = coluna + 48;
    }


    for (linha = 3; linha < 7; linha++)
    {
        for (coluna = 1; coluna < 9; coluna++)
        {
            tabuleiro[linha][coluna] = '-';
        }
    }
    //Colocando peças do jogador de cims
    tabuleiro[1][1] = 'T';
    tabuleiro[1][2] = 'C';
    tabuleiro[1][3] = 'B';
    tabuleiro[1][4] = 'R';
    tabuleiro[1][5] = 'A';
    tabuleiro[1][6] = 'B';
    tabuleiro[1][7] = 'C';
    tabuleiro[1][8] = 'T';
    for (coluna = 1; coluna < 9; coluna++)
    {
        tabuleiro[2][coluna] = 'P';
    }

    //Colocando peças do jogador de baixo
    tabuleiro[8][1] = 't';
    tabuleiro[8][2] = 'c';
    tabuleiro[8][3] = 'b';
    tabuleiro[8][4] = 'r';
    tabuleiro[8][5] = 'a';
    tabuleiro[8][6] = 'b';
    tabuleiro[8][7] = 'c';
    tabuleiro[8][8] = 't';
    for (coluna = 1; coluna < 9; coluna++)
    {
        tabuleiro[7][coluna] = 'p';
    }

    for (linha = 0; linha < 10; linha++)
    {
        for (coluna = 0; coluna < 10; coluna++)
        {
            if (linha == 0 && coluna == 0 || linha == 0 && coluna == 9 || linha == 9 && coluna == 0 || linha == 9 && coluna == 9)
            {
                tabuleiro[linha][coluna] = '|';
            }
            printf("%3c\t", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
}

void selecao_peca (int linha, int coluna){
    char tabuleiro[10][10];
    printf("Digite uma peça a ser movida (linha x coluna)");
    scanf("%d %d", &linha, &coluna);
    printf("%c", tabuleiro[linha][coluna]);
    }


