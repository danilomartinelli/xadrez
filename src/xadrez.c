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

        case 3:
             system("cls");
             printf("\t\t\t########## SOBRE ##########\n");
             printf("Jogo de xadrez desenvolvido para a disciplina de introducao a logica de programacao");
             printf("\n\t\t\t########## EQUIPE ########\n");
             printf("Abraao Lima Xavier Evangelista\n");
             printf("Bruno Correa Arvan\n");
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
