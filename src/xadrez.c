#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>


int main () {

    int menu;
    setlocale(LC_ALL,"portuguese");
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

            printf("jogue");
            break;


        case 2:
             system("cls");
             printf("Player 1 são as peças brancas, Player 2 as peças Pretas");
             printf("O jogo segue todas as regras oficiais. Exceto que:\n");
             printf("\n      Não é possível fazer movimentos especiais como o roque.\n");
             printf("Para jogar é necessário digitar a letra correspondente a peça que deseja movimentar.\n");
             printf("\nLogo depois digitar a linha e a coluna para qual você deseja se movimentar.\n\n");
             printf("Pressione ENTER para voltar.");
             getchar();
             break;

        case 3:
             system("cls");
             printf("\t\t\t########## SOBRE ##########\n");
             printf("Jogo de xadrez desenvolvido para a disciplina de introdução a lógica de programação");
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

        default:
             printf("Opção inválida");
       }
    }while(menu!=4);


return 0;
}
