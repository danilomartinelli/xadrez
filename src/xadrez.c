#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main () {
    int menu,v;
    do{
    printf("###################################\n");
    printf("\t Jogo de Xadrez\n\n\n");
    printf("\t1-Jogar\n\n \t2-Ajuda\n\n \t3-Sobre o jogo\n\n \t4-Sair\n\n");
    printf("###################################\n");
    scanf("%d", &menu);
    system("cls");

    //menu

    switch(menu){
        case 1:
            system("cls");
            break;


        case 2:
<<<<<<< HEAD
             printf("Player 1 são as peças brancas, Player 2 as peças Pretas.\n");
             printf("O jogo segue todas as regras oficiais. Exceto que:\n");
             printf("\nNão é possível fazer movimentos especiais como o roque.\n\n");
             printf("Para jogar é necessário digitar a letra correspondente a peça que deseja movimentar.\n");
             printf("\nLogo depois digitar a linha e a coluna para qual você deseja se movimentar.\n\n");
             printf("Pressione ENTER para voltar.");
             getchar();
             break;
=======
             system("cls");
             printf("Player 1 controla as pecas brancas e Player 2 as pecas Pretas.");
             printf(" O jogo segue todas as regras oficiais. Exceto que:\n");
             printf("\n    - Nao e possivel fazer movimentos especiais como o roque.\n");
             printf("\nPara jogar, basta digitar a letra correspondente a peca que deseja movimentar.\n");
             printf("\nLogo depois, deve-se digitar a linha e a coluna para qual voce deseja se movimentar.\n\n");
             printf("Pressione 5 para voltar.\n");
             scanf("%d",&v);
             if(v==5){
                    system("cls");
                    break;}
>>>>>>> master

        case 3:
             system("cls");
             printf("\t\t\t########## SOBRE ##########\n");
<<<<<<< HEAD
             printf("Jogo de xadrez desenvolvido para a disciplina de introdução a lógica de programação.\n\n");
             printf("\t\t\t########## EQUIPE ########\n");
             printf("Abraão Lima Xavier Evangelista\n");
             printf("Bruno Corrêa Arvan\n");
=======
             printf("Jogo de xadrez desenvolvido para a disciplina de introducao a logica de programacao");
             printf("\n\t\t\t########## EQUIPE ########\n");
             printf("Abraao Lima Xavier Evangelista\n");
             printf("Bruno Correa Arvan\n");
>>>>>>> master
             printf("Danilo Leone Di Paolo Martinelli Silva\n");
             printf("Stephanie Oliveira da Rocha\n\n\n");
             printf("Pressione 5 para voltar.\n");
             scanf("%d",&v);
             if(v==5){
                    system("cls");
                    break;}
        case 4:

             exit(0);
             break;

        default:
             printf("Opcao invalida!\n");
       }
    }while(menu!=4);


    return 0;

}


PARTE DO TABULEIRO

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#define espacos_vazios "-"

int main () {
    int linha, coluna;

char tabuleiro[10][10];

    for (linha=1; linha<9; linha++){
        coluna=0;
        tabuleiro[linha][coluna] = linha+48;
    }
    for (linha=1; linha<9; linha++){
        coluna=9;
        tabuleiro[linha][coluna] = linha+48;
    }
    for (coluna=1; coluna<9; coluna++){
        linha=0;
        tabuleiro[linha][coluna] = coluna+48;
    }
    for (coluna=1; coluna<9; coluna++){
        linha=9;
        tabuleiro[linha][coluna] = coluna+48;
    }
    for (linha=1; linha<9; linha++){
        for (coluna=1; coluna<9; coluna++){
            tabuleiro[linha][coluna] = '-';
        }
    }

    for (linha=0; linha<10; linha++){
        for (coluna=0; coluna<10; coluna++){
            if (linha==0 && coluna==0 || linha==0 && coluna==9 || linha==9 && coluna==0 || linha==9 && coluna==9){
               tabuleiro[linha][coluna] = '|';
            }
        printf("%3c\t",tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
