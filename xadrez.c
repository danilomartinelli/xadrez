#include <stdio_ext.h>
#include <stdlib.h>
#include <locale.h>

//Cria matriz para o tabuleiro.
char tabuleiro[10][10] =
    {'-', '1', '2', '3', '4', '5', '6', '7', '8', '|',
     '1', 't', 'c', 'b', 'k', 'q', 'b', 'c', 't', '1',
     '2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', '2',
     '3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '3',
     '4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '4',
     '5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '5',
     '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '6',
     '7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', '7',
     '8', 'T', 'C', 'B', 'Q', 'K', 'B', 'C', 'T', '8',
     '-', '1', '2', '3', '4', '5', '6', '7', '8', '-'};

//Define variaveis para player 1 e 2.
char player1[20];
char player2[20];

void sobre()
{
    system("cls || clear"); //Limpar cmd.

    //Limpar buffer.
    fflush(stdin);
    __fpurge(stdin);

    printf("\t\t\t########## SOBRE ##########\n");
    printf("Jogo de xadrez desenvolvido para a disciplina de introdução a lógica de programação.\n\n");
    printf("\t\t\t########## EQUIPE ########\n");
    printf("Abraão\n");
    printf("Danilo Leone Di Paolo Martinelli Silva\n");
    printf("Daniel\n");
    printf("Stephanie Oliveira da Rocha\n\n\n");
    printf("Pressione ENTER para voltar.");
    getchar();
}

void ajuda()
{
    system("cls || clear"); //Limpar cmd.

    //Limpar buffer.
    fflush(stdin);
    __fpurge(stdin);

    printf("\t\t\t########## Ajuda ##########\n\n");
    printf("Player 1 são as peças brancas, Player 2 as peças Pretas.\n");
    printf("O jogo segue todas as regras oficiais. Exceto que:\n");
    printf("\t\tNão é possível fazer movimentos especiais como o roque.\n\n");
    printf("Para jogar é necessário digitar a letra correspondente a peça que deseja movimentar.\n");
    printf("Logo depois digitar a linha e a coluna para qual você deseja se movimentar.\n\n");
    printf("Pressione ENTER para voltar.");
    getchar();
}

int main()
{
    system("cls || clear"); //Limpar cmd.

    //Configurando UTF-8 para caracteres.
    setlocale(LC_ALL, "Portuguese");

    //Inicia o menu.
    //Declarar variaveis:
    int opcaoMenu;
    int opcaoValida = 0;

    do
    {
        system("cls || clear"); //Limpar cmd.

        //Limpar buffer.
        fflush(stdin);
        __fpurge(stdin);

        printf("\t\t\t########## XADREZ ########\n\n\n");
        printf("\t\t\t########## MENU ##########\n");
        printf("1. Novo Jogo\n");
        printf("2. Ajuda\n");
        printf("3. Sobre\n");
        printf("4. Sair\n\n");
        if (opcaoValida == 1) {
            printf("Digite uma opção válida. \n");
        }
        printf("Selecione o número correspondente a opção do menu: ");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu)
        {
        case 1:
            opcaoValida = 0;
            break;
        case 2:
            opcaoValida = 0;
            ajuda();
            break;
        case 3:
            opcaoValida = 0;
            sobre();
            break;
        case 4:
            exit(0);
            break;
        default:
            opcaoValida = 1;
            break;
        }
    } while (opcaoMenu != 4);

    return 0;
}