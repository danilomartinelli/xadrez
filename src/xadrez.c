#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#define jogar 1
#define ajuda 2
#define sobre 3
#define sair 4


int main () {
    setlocale(LC_ALL, "portuguese");
    printf("###################################\n");
    printf("\t Jogo de Xadrez\n\n\n");
    printf("\t1-Jogar\n\n \t2-Ajuda\n\n \t3-Sobre o jogo\n\n \t4-Sair\n");
    printf("###################################\n");
    int menu;
    scanf("%d", &menu);
    system("cls");

    //menu
    switch(menu){
        case 1:
            printf("jogue");
            break;


        case 2:
             printf("Player 1 s�o as pe�as brancas, Player 2 as pe�as Pretas.\n");
             printf("O jogo segue todas as regras oficiais. Exceto que:\n");
             printf("\nN�o � poss�vel fazer movimentos especiais como o roque.\n\n");
             printf("Para jogar � necess�rio digitar a letra correspondente a pe�a que deseja movimentar.\n");
             printf("\nLogo depois digitar a linha e a coluna para qual voc� deseja se movimentar.\n\n");
             printf("Pressione ENTER para voltar.");
             getchar();
             break;

        case 3:
             printf("\t\t\t########## SOBRE ##########\n");
             printf("Jogo de xadrez desenvolvido para a disciplina de introdu��o a l�gica de programa��o.\n\n");
             printf("\t\t\t########## EQUIPE ########\n");
             printf("Abra�o Lima Xavier Evangelista\n");
             printf("Bruno Corr�a Arvan\n");
             printf("Danilo Leone Di Paolo Martinelli Silva\n");
             printf("Stephanie Oliveira da Rocha\n\n\n");
             printf("Pressione ENTER para voltar.");
             getchar();
              break;


        case 4:
             exit(0);
             break;
    }

return 0;
}
