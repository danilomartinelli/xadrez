#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Título das funções que serão necessárias
void tabuleiro_em_tela(char tabuleiro[10][10]);
void selecao_peca (char tabuleiro[10][10]);

int main(){
    int linha, coluna;
    char tabuleiro[10][10];
    tabuleiro_em_tela(tabuleiro);
    selecao_peca (tabuleiro);
}
//Função para montar e mostrar o tabuleiro.

    void tabuleiro_em_tela(char tabuleiro[10][10]){
    int linha, coluna;


//Criando a coluna auxiliar

    for (linha = 1; linha < 9; linha++)
    {
        coluna = 0;
        tabuleiro[linha][coluna] = linha + 48;
        coluna = 9;
        tabuleiro[linha][coluna] = linha + 48;
    }
//Criando a linha auxiliar

    for (coluna = 1; coluna < 9; coluna++)
    {
        linha = 0;
        tabuleiro[linha][coluna] = coluna + 48;
        linha = 9;
        tabuleiro[linha][coluna] = coluna + 48;
    }

//Adicionando os espaços vazios
    for (linha = 3; linha < 7; linha++)
    {
        for (coluna = 1; coluna < 9; coluna++)
        {
            tabuleiro[linha][coluna] = '-';
        }
    }
//Colocando peças do jogador de cima
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
    for (coluna = 1; coluna < 9; coluna++){
        tabuleiro[7][coluna] = 'p';
    }
//Preenchendo barras laterais
    for (linha = 0; linha < 10; linha++){
        for (coluna = 0; coluna < 10; coluna++){
            if (linha == 0 && coluna == 0 || linha == 0 && coluna == 9 || linha == 9 && coluna == 0 || linha == 9 && coluna == 9){
                tabuleiro[linha][coluna] = '|';
            }
            printf("%3c\t", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
}

void selecao_peca (char tabuleiro[10][10]){
    int linha, coluna;
    printf("Digite uma peça a ser movida (linha x coluna)");
   scanf("%d %d", &linha, &coluna);
    switch(tabuleiro[linha][coluna]){
        case'p':
            printf("Voce selecionou o Peao!\n");
            break;

        case 'P':
            printf("Voce selecionou o Peao!\n");
            break;

        case 't':
            printf("Voce selecionou a Torre!\n");
            break;

        case 'T':
            printf("Voce selecionou a Torre!\n");
            break;

        case'b':
            printf("Voce selecionou o Bispo!\n");
            break;

        case'B':
            printf("Voce selecionou o Bispo!\n");
            break;

        case'c':
            printf("Voce selecionou o Cavalo!\n");
            break;

        case'C':
            printf("Voce selecionou o Cavalo!\n");
            break;

        case'R':
            printf("Voce selecionou o Rei!\n");
            break;

        case'r':
            printf("Voce selecionou o Rei!\n");
            break;

        case'A':
            printf("Voce selecionou a Rainha!\n");
            break;

        case'a':
            printf("Voce selecionou a Rainha!\n");
            break;

        default:
            printf("Peca invalida.");
    }

}


