#include <stdio_ext.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

//Cria matriz para o tabuleiro.
char table[10][10] =
    {'|', '1', '2', '3', '4', '5', '6', '7', '8', '|',
     '1', 't', 'c', 'b', 'k', 'q', 'b', 'c', 't', '1',
     '2', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', '2',
     '3', '-', '-', '-', '-', '-', '-', '-', '-', '3',
     '4', '-', '-', '-', '-', '-', '-', '-', '-', '4',
     '5', '-', '-', '-', '-', '-', '-', '-', '-', '5',
     '6', '-', '-', '-', '-', '-', '-', '-', '-', '6',
     '7', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', '7',
     '8', 'T', 'C', 'B', 'Q', 'K', 'B', 'C', 'T', '8',
     '|', '1', '2', '3', '4', '5', '6', '7', '8', '|'};

int numberOfLines = 10;
int numberColumns = 10;

//Define variaveis para player 1 e 2.
char player1[20];
char player2[20];

//Variaveis de controle.
int game_over = 0;
int line, column;

void about()
{
    system("cls || clear"); //Limpar cmd.

    //Limpar buffer.
    fflush(stdin);
    __fpurge(stdin);

    printf("\t\t\t########## SOBRE ##########\n");
    printf("Jogo de xadrez desenvolvido para a disciplina de introdução a lógica de programação.\n\n");
    printf("\t\t\t########## EQUIPE ########\n");
    printf("Abraão\n");
    printf("Bruno Correia Arvan\n");
    printf("Danilo Leone Di Paolo Martinelli Silva\n");
    printf("Stephanie Oliveira da Rocha\n\n\n");
    printf("Pressione ENTER para voltar.");
    getchar();
}

void help()
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

void renderTable()
{
    int row, columns;

    //Renderizando tabuleiro.
    for (row = 0; row < numberOfLines; row++)
    {
        for (columns = 0; columns < numberColumns; columns++)
        {
            printf("%c\t", table[row][columns]);
        }
        printf("\n\n");
    }
}

const char *choosePiece(int player)
{
    char piece;
    char *name;
    if(player == 1) {
        name = player1;
    }
    if(player == 1) {
        name = player2;
    }

    do {
        renderTable();
        printf("%s,\n", player1);
        printf("Digite a posição da peça a ser movida (LINHA, COLUNA): ");
        scanf("%d %d", &line, &column);
        piece = table[line][column];
        printf("%c", piece);
        system("cls || clear");
    } while (!((player == 1 && isupper(piece)) || (player == 2 && islower(piece)) && piece != '-' && piece != '|' && isalpha(piece)));

    const char *choosePiece;
    int row, columns;

    for (row = 0; row < numberOfLines; row++)
    {
        for (columns = 0; columns < numberColumns; columns++)
        {
            if (table[row][columns] == piece)
            {
                printf("OK");
            }
        }
    }

    return choosePiece;
}

int main()
{
    system("cls || clear"); //Limpar cmd.

    //Configurando UTF-8 para caracteres.
    setlocale(LC_ALL, "Portuguese");

    //Declarar variaveis:
    int optionsMenu;
    int trueOption = 0;

    const char *piece;

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
        if (trueOption == 1)
        {
            printf("Digite uma opção válida. \n");
        }
        printf("Selecione o número correspondente a opção do menu: ");
        scanf("%d", &optionsMenu);

        switch (optionsMenu)
        {
        case 1:
            trueOption = 0;
            break;
        case 2:
            trueOption = 0;
            help();
            break;
        case 3:
            trueOption = 0;
            about();
            break;
        case 4:
            exit(0);
            break;
        default:
            trueOption = 1;
            break;
        }
    } while (optionsMenu != 1);

    system("cls || clear"); //Limpar cmd.

    //Limpar buffer.
    fflush(stdin);
    __fpurge(stdin);

    printf("Digite o nome do Player 1: ");
    scanf("%s", player1);

    printf("Digite o nome do Player 2: ");
    scanf(" %s", player2);

    do
    {
        system("cls || clear");

        printf("\t\t\t########## PARTIDA ########\n\n\n");

        piece = choosePiece(1);

        fflush(stdin);
        __fpurge(stdin);
        system("cls || clear");

        piece = choosePiece(2);

    } while (game_over = 0);

    return EXIT_SUCCESS;
}