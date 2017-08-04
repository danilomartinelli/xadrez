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
   int linha, coluna, peca_valida;

   do{
        printf("Digite uma peca a ser movida (linha x coluna)");
        scanf("%d %d", &linha, &coluna);
        if((tabuleiro[linha][coluna]!='-') || (tabuleiro[linha][coluna]!='|') || (tabuleiro[linha][coluna]!='1') || (tabuleiro[linha][coluna]!='2') || (tabuleiro[linha][coluna]!='3') || (tabuleiro[linha][coluna]!='4') || (tabuleiro[linha][coluna]!='5') || (tabuleiro[linha][coluna]!='6') || (tabuleiro[linha][coluna]!='7') || (tabuleiro[linha][coluna]!='8')|| (tabuleiro[linha][coluna]!='9')){
            peca_valida=0;
        }
        else{
            peca_valida=1;
        }
        switch(tabuleiro[linha][coluna]){

           case'p':
                printf("Voce selecionou o Peao!\n");
                peca_valida=1;
                break;

            case 'P':
                printf("Voce selecionou o Peao!\n");
                peca_valida=1;
                break;

            case 't':
                printf("Voce selecionou a Torre!\n");
                peca_valida=1;
                break;

            case 'T':
                printf("Voce selecionou a Torre!\n");
                peca_valida=1;
                break;

            case'b':
                printf("Voce selecionou o Bispo!\n");
                peca_valida=1;
                break;

            case'B':
                printf("Voce selecionou o Bispo!\n");
                peca_valida=1;
                break;

            case'c':
                printf("Voce selecionou o Cavalo!\n");
                peca_valida=1;
                break;

            case'C':
                printf("Voce selecionou o Cavalo!\n");
                peca_valida=1;
                break;

            case'R':
                printf("Voce selecionou o Rei!\n");
                peca_valida=1;
                break;

            case'r':
                printf("Voce selecionou o Rei!\n");
                peca_valida=1;
                break;

            case'A':
                printf("Voce selecionou a Rainha!\n");
                peca_valida=1;
                break;

            case'a':
                printf("Voce selecionou a Rainha!\n");
                peca_valida=1;
                break;

            default:
                printf("Peca invalida.");
        }
    } while (peca_valida==0);
}


