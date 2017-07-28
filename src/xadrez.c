//Declarando libs:
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

// Função para limpar tela
void clear_screen()
{
#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif
}

//Função inicial:
int main()
{

    //Declaração de variáveis:
    int menu;

    //Setando UTF-8:
    setlocale(LC_ALL, "portuguese");

    do
    {
        printf("###################################\n");
        printf("\t Jogo de Xadrez\n\n\n");
        printf("\t1-Jogar\n\n \t2-Ajuda\n\n \t3-Sobre o jogo\n\n \t4-Sair\n\n");
        printf("###################################\n");
        scanf("%d", &menu);
        clear_screen();

        //Menu:
        switch (menu)
        {
        case 1:

            printf("jogue");
            break;

        case 2:
            clear_screen();
            printf("Player 1 são as peças brancas, Player 2 as peças Pretas");
            printf("O jogo segue todas as regras oficiais. Exceto que:\n");
            printf("\n      Não é possível fazer movimentos especiais como o roque.\n");
            printf("Para jogar é necessário digitar a letra correspondente a peça que deseja movimentar.\n");
            printf("\nLogo depois digitar a linha e a coluna para qual você deseja se movimentar.\n\n");
            printf("Pressione ENTER para voltar.");
            getchar();
            break;

        case 3:
            clear_screen();
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
            exit(EXIT_SUCCESS);
            break;

        default:
            printf("Opção inválida");
        }
    } while (menu != 4);

    return EXIT_SUCCESS;
}
