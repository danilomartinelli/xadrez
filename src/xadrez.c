#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>


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
             printf("Player 1 são as peças brancas, Player 2 as peças Pretas.\n");
             printf("O jogo segue todas as regras oficiais. Exceto que:\n");
             printf("\nNão é possível fazer movimentos especiais como o roque.\n\n");
             printf("Para jogar é necessário digitar a letra correspondente a peça que deseja movimentar.\n");
             printf("\nLogo depois digitar a linha e a coluna para qual você deseja se movimentar.\n\n");
             printf("Pressione ENTER para voltar.");
             getchar();
             break;

        case 3:
             printf("\t\t\t########## SOBRE ##########\n");
             printf("Jogo de xadrez desenvolvido para a disciplina de introdução a lógica de programação.\n\n");
             printf("\t\t\t########## EQUIPE ########\n");
             printf("Abraão Lima Xavier Evangelista\n");
             printf("Bruno Corrêa Arvan\n");
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
