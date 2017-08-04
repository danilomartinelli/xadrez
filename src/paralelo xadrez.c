#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Desenhar tabuleiro na tela:
void tabuleiro_em_tela(char tabuleiro[10][10]);

int main()
{
    int menu, v;
    char tabuleiro[10][10], c;

    do
    {
        printf("###################################\n");
        printf("\t Jogo de Xadrez\n\n\n");
        printf("\t1-Jogar\n\n \t2-Ajuda\n\n \t3-Sobre o jogo\n\n \t4-Sair\n\n");
        printf("###################################\n");
        scanf("%d", &menu);
        system("cls");

        //menu


    switch(menu){
        case 1:
            tabuleiro_em_tela(tabuleiro);
            break;

        case 2:
            printf("Player 1 controla as pecas brancas e Player 2 as pecas Pretas.");
            printf(" O jogo segue todas as regras oficiais. Exceto que:\n");
            printf("\n    - Nao e possivel fazer movimentos especiais como o roque.\n");
            printf("\nPara jogar, basta digitar a letra correspondente a peca que deseja movimentar.\n");
            printf("\nLogo depois, deve-se digitar a linha e a coluna para qual voce deseja se movimentar.\n\n");
            printf("Pressione qualquer tecla para voltar ao menu");
            getchar();
            break;

        case 3:
            printf("\t\t\t########## SOBRE ##########\n");
            printf("Jogo de xadrez desenvolvido para a disciplina de introducao a logica de programacao");
            printf("\n\t\t\t########## EQUIPE ########\n");
            printf("Abraao Lima Xavier Evangelista\n");
            printf("Bruno Correa Arvan\n");
            printf("Danilo Leone Di Paolo Martinelli Silva\n");
            printf("Stephanie Oliveira da Rocha\n\n\n");
            printf("Pressione qualquer tecla para voltar ao menu");
            getchar();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Opcao invalida!\n");
        }
    } while (menu != 4 || menu != 1);

    return 0;
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
    //Colocando pe�as do jogador de cims
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

    //Colocando pe�as do jogador de baixo
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
