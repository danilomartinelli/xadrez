//Importar libs que vão ser utilizadas no programa.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

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

//Variaveis para gerenciar o tabuleiro;
const int numberOfRows = 10;
const int numberColumns = 10;

//Define variaveis para player 1 e 2.
char player1[20];
char player2[20];

// Função para limpar tela
void clear_screen()
{
#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif
}

void about()
{
    clear_screen(); //Limpar cmd.

    printf("\t\t\t########## SOBRE ##########\n");
    printf("Jogo de xadrez desenvolvido para a disciplina de introdução a lógica de programação.\n\n");
    printf("\t\t\t########## EQUIPE ########\n");
    printf("Abraão Lima Xavier Evangelista\n");
    printf("Bruno Correia Arvan\n");
    printf("Danilo Leone Di Paolo Martinelli Silva\n");
    printf("Stephanie Oliveira da Rocha\n\n\n");
    printf("Pressione ENTER para voltar.");
    getchar();
}

void help()
{
    clear_screen(); //Limpar cmd.

    printf("\t\t\t########## Ajuda ##########\n\n");
    printf("Player 1 são as peças brancasna linha 8 e 7, Player 2 as peças na linha 1 e 2.\n");
    printf("O Jogue trabalha sempre a partir da LINHA digitada e COLUNA digitada.\n");
    printf("\tExemplo:\n");
    printf("\t\tCavalo se encontra na linha 6, coluna 4. É necessário digitar: 6 4\n");
    printf("O mesmo é necessário para escolher para onde vai ser movimentar.\n");
    printf("\n\nPressione ENTER para voltar.");
    getchar();
}

const char *prettyPiece(char piece)
{
    const char *choosePiece;
    piece = toupper(piece);

    //Deixa o nome da peça mais amigavel para o usuário.
    switch (piece)
    {
    case 'P':
        choosePiece = "Peão";
        break;
    case 'T':
        choosePiece = "Torre";
        break;
    case 'C':
        choosePiece = "Cavalo";
        break;
    case 'B':
        choosePiece = "Bispo";
        break;
    case 'Q':
        choosePiece = "Rainha";
        break;
    case 'K':
        choosePiece = "Rei";
        break;
    default:
        exit(EXIT_FAILURE);
        break;
    }

    return choosePiece;
}

void renderTable()
{
    int row, columns;

    printf("\t\t\t########## PARTIDA ########\n\n\n");

    //Renderizando tabuleiro.
    for (row = 0; row < numberOfRows; row++)
    {
        for (columns = 0; columns < numberColumns; columns++)
        {
            printf("%c\t", table[row][columns]);
        }
        printf("\n\n");
    }
}

//Funções de movimento para cada peça:

//Peão
int pawnPiece(int oldRow, int oldColumn, int newRow, int newColumn, int player)
{
    if (player == 1)
    {
        if (oldColumn == 7)
        {
            if (newColumn == oldColumn && (newRow == (oldRow - 1) || newRow == (oldRow - 2)))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (newColumn == oldColumn && newRow == (oldRow - 1))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return 0;
    }
    if (player == 2)
    {
        if (oldColumn == 2)
        {
            if (newColumn == oldColumn && (newRow == (oldRow + 1) || newRow == (oldRow + 2)))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (newColumn == oldColumn && newRow == (oldRow + 1))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return 0;
    }
    return 0;
}

//Torre
int rookPiece(int oldRow, int oldColumn, int newRow, int newColumn)
{
    if ((newColumn == oldColumn && (newRow >= 1 && newRow <= 8)) || (newRow == oldRow && (newColumn >= 1 && newColumn <= 8)))
    {
        return 1;
    }
    return 0;
}

//Cavalo
int horsePiece(int oldRow, int oldColumn, int newRow, int newColumn)
{
    if (((newColumn == oldColumn - 1) || (newColumn == oldColumn + 1)) && ((newRow == oldRow - 2) || (newRow == oldRow + 2)))
    {
        return 1;
    }
    if (((newColumn == oldColumn - 2) || (newColumn == oldColumn + 2)) && ((newRow == oldRow - 1) || (newRow == oldRow + 1)))
    {
        return 1;
    }
    return 0;
}

//Bispo
int bishopPiece(int oldRow, int oldColumn, int newRow, int newColumn)
{
    int rowAux = oldRow - newRow;
    int columnAux = oldColumn - newColumn;

    //Valor absoluto da diferença.
    rowAux = abs(rowAux);
    columnAux = abs(columnAux);

    if (rowAux == columnAux)
    {
        return 1;
    }
    return 0;
}

//Rainha
int queenPiece(int oldRow, int oldColumn, int newRow, int newColumn)
{
    if (bishopPiece(oldRow, oldColumn, newRow, newColumn) ^ rookPiece(oldRow, oldColumn, newRow, newColumn))
    {
        return 1;
    }
    return 0;
}

//Rei
int kingPiece(int oldRow, int oldColumn, int newRow, int newColumn)
{
    if ((newRow == oldRow + 1 || newRow == oldRow || newRow == oldRow - 1) && (newColumn == oldColumn + 1 || newColumn == oldColumn || newColumn == oldColumn - 1))
    {
        return 1;
    }
    return 0;
}

//Gerencia as função de movimento de peças
int pieceMove(char piece, int oldRow, int oldColumn, int newRow, int newColumn, int player)
{
    const char *prettyPieceStr;
    prettyPieceStr = prettyPiece(piece);

    char name[20];
    if (player == 1)
    {
        strcpy(name, player1);
    }
    if (player == 2)
    {
        strcpy(name, player2);
    }

    switch (toupper(piece))
    {
    case 'P':
        if (pawnPiece(oldRow, oldColumn, newRow, newColumn, player))
        {
            return 1;
        }
        return 0;
    case 'T':
        if (rookPiece(oldRow, oldColumn, newRow, newColumn))
        {
            return 1;
        }
        return 0;
    case 'C':
        if (horsePiece(oldRow, oldColumn, newRow, newColumn))
        {
            return 1;
        }
        return 0;
    case 'B':
        if (bishopPiece(oldRow, oldColumn, newRow, newColumn))
        {
            return 1;
        }
        return 0;
    case 'Q':
        if (queenPiece(oldRow, oldColumn, newRow, newColumn))
        {
            return 1;
        }
        return 0;
    case 'K':
        if (kingPiece(oldRow, oldColumn, newRow, newColumn))
        {
            return 1;
        }
        return 0;
    default:
        return 0;
    }
}

//Verifica se posição atribuida pelo player pode ser ocupada.
int positionVerify(char piece, int oldRow, int oldColumn, int newRow, int newColumn, int player)
{
    if ((newRow >= 1 && newRow <= 8) && (newColumn >= 1 && newColumn <= 8))
    {
        switch (toupper(piece))
        {
        case 'P': //Peão
            if (table[newRow][newColumn] == '-')
            {
                if (player == 1 && oldRow == 7 && newRow == 5 && table[6][newColumn] != '-') {
                    return 0;
                } 
                if (player == 2 && oldRow == 2 && newRow == 4 && table[3][newColumn] != '-') {
                    return 0;
                }
                return 1;
            }
            else
            {
                return 0;
            }
        default:
            return 1;
            break;
        }
    }
    return 0;
}

void movePiece(char piece, int oldRow, int oldColumn, int newRow, int newColumn)
{
    table[newRow][newColumn] = piece;
    table[oldRow][oldColumn] = '-';
}

//FUnção que gerencia todas as ações da peça do player.
void actionPiece(int player)
{
    char piece;
    char name[20];
    int newRow, newColumn, oldRow, oldColumn;
    const char *prettyPieceStr;

    if (player == 1)
    {
        strcpy(name, player1);
    }
    if (player == 2)
    {
        strcpy(name, player2);
    }

    //Verifica se é possível escolher a peça.
    int countErro = 0;
    do
    {
        renderTable();
        printf("Player: %s", name);
        if (countErro >= 1)
        {
            printf("Você digitou um valor inválido.\n");
            printf("Digite a posição da peça a ser movida (LINHA COLUNA): ");
        }
        else
        {
            printf("Digite a posição da peça a ser movida (LINHA COLUNA): ");
        }
        scanf("%d %d", &oldRow, &oldColumn);
        getchar(); //Consumir Enter.
        piece = table[oldRow][oldColumn];
        clear_screen();
        countErro++;
    } while (!((player == 1 && isupper(piece)) || (player == 2 && islower(piece)) && piece != '-' && piece != '|' && isalpha(piece) && (oldRow >= 1 && oldRow <= 8) && (oldColumn >= 1 && oldColumn <= 8)));

    prettyPieceStr = prettyPiece(piece);

    int countAuxPieceMove = 0;
    do
    {
        clear_screen();
        renderTable();
        printf("Player: %s\n", name);
        printf("Você selecionou: %s (%d, %d)\n", prettyPieceStr, oldRow, oldColumn);
        if (countAuxPieceMove > 0)
            printf("Movimento inválido.\n");
        printf("Digite para qual posição você deseja movimentar a peça: ");
        scanf("%d %d", &newRow, &newColumn);
        getchar(); //Consumir Enter.
        countAuxPieceMove++;
    } while (!pieceMove(piece, oldRow, oldColumn, newRow, newColumn, player));

    movePiece(piece, oldRow, oldColumn, newRow, newColumn);
}

int main()
{
    clear_screen(); //Limpar cmd.

    //Configurando UTF-8 para caracteres.
    setlocale(LC_ALL, "Portuguese");

    //Declarar variaveis:
    int optionsMenu;
    int trueOption = 0;
    const char *piece;

    //Variaveis de controle.
    int game_over = 0;

    do
    {
        clear_screen(); //Limpar cmd.

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
        getchar(); //Consumir Enter.

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
            exit(EXIT_SUCCESS);
            break;
        default:
            trueOption = 1;
            break;
        }
    } while (optionsMenu != 1);

    clear_screen(); //Limpar cmd.

    printf("Digite o nome do Player 1: ");
    fgets(player1, 20, stdin);

    printf("Digite o nome do Player 2: ");
    fgets(player2, 20, stdin);

    do
    {
        clear_screen();

        //SEÇÃO - PLAYER 1 MOVER PEÇA.
        actionPiece(1);

        clear_screen(); //Limpar cmd.

        //SEÇÃO - PLAYER 2 MOVER PEÇA.
        actionPiece(2);

    } while (game_over = 1);

    return EXIT_SUCCESS;
}