//Importar libs que vão ser utilizadas no programa.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

//Define carácter máximo para username.
#define STRING_PLAYER 20
#define PLAYER_1 1
#define PLAYER_2 2

//Define constantes para o fim de jogo.
#define GAME_ON_GOING 0
#define STALEMATE 1
#define PLAYER1_WINNER 2
#define PLAYER2_WINNER 3
#define CHECK 4

//Define constantes para as peças do jogo.
#define PAWN 'P'
#define ROOK 'T'
#define BISHOP 'B'
#define HORSE 'C'
#define QUEEN 'Q'
#define KING 'K'
#define VOID_SQUARE '-'

//Variaveis para gerenciar o tabuleiro;
const int numberOfRows = 10;
const int numberOfColumns = 10;

//Cria matriz para o tabuleiro.
char table[10][10];

//Define variaveis para player 1 e 2.
char player1[STRING_PLAYER];
char player2[STRING_PLAYER];

//Variavel global
int gameRound = 0;

// Função para limpar tela
void clear_screen()
{
#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif
}

void drawTable()
{
    int row, column;

    //Posições auxiliares:
    table[0][0] = '|';
    table[0][9] = '|';
    table[9][0] = '|';
    table[9][9] = '|';
    for (row = 1; row <= 8; row++)
    {
        // um inteiro de valor 48 equivale a um char de valor 0.
        table[row][0] = row + 48;
        table[row][9] = row + 48;
    }
    for (column = 1; column <= 8; column++)
    {
        // um inteiro de valor 48 equivale a um char de valor 0.
        table[0][column] = column + 48;
        table[9][column] = column + 48;
    }

    //Espaços vazios:
    for (row = 3; row <= 6; row++)
    {
        for (column = 1; column <= 8; column++)
        {
            table[row][column] = '-';
        }
    }

    //Player 1:
    table[8][1] = 'T';
    table[8][2] = 'C';
    table[8][3] = 'B';
    table[8][4] = 'K';
    table[8][5] = 'Q';
    table[8][6] = 'B';
    table[8][7] = 'C';
    table[8][8] = 'T';
    for (column = 1; column <= 8; column++)
    {
        table[7][column] = 'P';
    }

    //Player 2:
    table[1][1] = 't';
    table[1][2] = 'c';
    table[1][3] = 'b';
    table[1][4] = 'k';
    table[1][5] = 'q';
    table[1][6] = 'b';
    table[1][7] = 'c';
    table[1][8] = 't';
    for (column = 1; column <= 8; column++)
    {
        table[2][column] = 'p';
    }
}

//Exibe SOBRE no DOS.
void about()
{
    clear_screen();

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

//Exibe AJUDA no DOS.
void help()
{
    clear_screen();

    printf("\t\t\t########## Ajuda ##########\n\n");
    printf("Player 1 são as peças brancasna linha 8 e 7, Player 2 as peças na linha 1 e 2.\n");
    printf("O Jogue trabalha sempre a partir da LINHA digitada e COLUNA digitada.\n");
    printf("\tExemplo:\n");
    printf("\t\tCavalo se encontra na linha 6, coluna 4. É necessário digitar: 6 4\n");
    printf("O mesmo é necessário para escolher para onde vai ser movimentar.\n");
    printf("\n\nPressione ENTER para voltar.");
    getchar();
}

//Deixa o nome da peça mais amigavel para o usuário.
const char *prettyPiece(char piece)
{
    const char *choosePiece;
    piece = toupper(piece);

    switch (piece)
    {
    case PAWN:
        choosePiece = "Peão";
        break;
    case ROOK:
        choosePiece = "Torre";
        break;
    case HORSE:
        choosePiece = "Cavalo";
        break;
    case BISHOP:
        choosePiece = "Bispo";
        break;
    case QUEEN:
        choosePiece = "Rainha";
        break;
    case KING:
        choosePiece = "Rei";
        break;
    default:
        exit(EXIT_FAILURE);
        break;
    }

    return choosePiece;
}

//Função para renderizar o tabuleiro na tela.
void renderTable()
{
    int row, columns;

    printf("\t\t\t########## PARTIDA ########\n\n\n");

    //Renderizando tabuleiro.
    for (row = 0; row < numberOfRows; row++)
    {
        for (columns = 0; columns < numberOfColumns; columns++)
        {
            printf("%c\t", table[row][columns]);
        }
        printf("\n\n");
    }
    printf("Rodada n°: %d\n\n", gameRound);
}

//Veficar se peça é do time verificado
int boolPlayerPiece(int row, int column, int player)
{
    char piece = table[row][column];
    if (isalpha(piece))
    {
        if ((isupper(piece) && player == PLAYER_1) || (islower(piece) && player == PLAYER_2))
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
        return 0;
    }
}

//Função para verificar se é check:
int checkVerify(int newRow, int newColumn, int player)
{
    //Variáveis auxiliares
    int count, count2;

    //Verifica se torre ou rainha estão em posição de dar check ao rei inimigo:
    if (newRow != 8)
    {
        for (count = newRow + 1; count <= 8; count++)
        {
            if (table[count][newColumn] != VOID_SQUARE)
            {
                if (!(boolPlayerPiece(count, newColumn, player)) && (toupper(table[count][newColumn]) == ROOK || toupper(table[count][newColumn]) == QUEEN))
                {
                    return 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    if (newRow != 1)
    {
        for (count = newRow - 1; count >= 1; count--)
        {
            if (table[count][newColumn] != VOID_SQUARE)
            {
                if (!(boolPlayerPiece(count, newColumn, player)) && (toupper(table[count][newColumn]) == ROOK || toupper(table[count][newColumn]) == QUEEN))
                {
                    return 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    if (newColumn != 8)
    {
        for (count = newColumn + 1; count <= 8; count++)
        {
            if (table[newRow][count] != VOID_SQUARE)
            {
                if (!(boolPlayerPiece(newRow, count, player)) && (toupper(table[newRow][count]) == ROOK || toupper(table[newRow][count]) == QUEEN))
                {
                    return 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    if (newColumn != 1)
    {
        for (count = newColumn - 1; count >= 1; count--)
        {
            if (table[newRow][count] != VOID_SQUARE)
            {
                if (!(boolPlayerPiece(newRow, count, player)) && (toupper(table[newRow][count]) == ROOK || toupper(table[newRow][count]) == QUEEN))
                {
                    return 1;
                }
                else
                {
                    break;
                }
            }
        }
    }

    //Verifica se bispo ou rainha estão em posição de dar check ao rei inimigo:
    if (newColumn != 8 && newRow != 8)
    {
        for (count = newRow + 1, count2 = newColumn + 1; count <= 8, count2 <= 8; count++, count2++)
        {
            if (table[count][count2] != VOID_SQUARE)
            {
                if (!(boolPlayerPiece(count, count2, player)) && (toupper(table[count][count2]) == BISHOP || toupper(table[count][count2]) == QUEEN))
                {
                    return 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    if (newColumn != 1 && newRow != 8)
    {
        for (count = newRow + 1, count2 = newColumn - 1; count <= 8, count2 >= 1; count++, count2--)
        {
            if (table[count][count2] != VOID_SQUARE)
            {
                if (!(boolPlayerPiece(count, count2, player)) && (toupper(table[count][count2]) == BISHOP || toupper(table[count][count2]) == QUEEN))
                {
                    return 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    if (newColumn != 8 && newRow != 1)
    {
        for (count = newRow - 1, count2 = newColumn + 1; count >= 1, count2 <= 8; count--, count2++)
        {
            if (table[count][count2] != VOID_SQUARE)
            {
                if (!(boolPlayerPiece(count, count2, player)) && (toupper(table[count][count2]) == BISHOP || toupper(table[count][count2]) == QUEEN))
                {
                    return 1;
                }
                else
                {
                    break;
                }
            }
        }
    }
    if (newColumn != 1 && newRow != 1)
    {
        for (count = newRow - 1, count2 = newColumn - 1; count >= 1, count2 >= 1; count--, count2--)
        {
            if (table[count][count2] != VOID_SQUARE)
            {
                if (!(boolPlayerPiece(count, count2, player)) && (toupper(table[count][count2]) == BISHOP || toupper(table[count][count2]) == QUEEN))
                {
                    return 1;
                }
                else
                {
                    break;
                }
            }
        }
    }

    //Verifica se cavalo está em posição de dar check ao rei inimigo:

    count = newRow + 1;
    count2 = newColumn + 2;
    if (table[count][count2] != VOID_SQUARE)
    {
        if (!(boolPlayerPiece(count, count2, player)) && (toupper(table[count][count2]) == HORSE))
            return 1;
    }

    count = newRow + 1;
    count2 = newColumn - 2;
    if (table[count][count2] != VOID_SQUARE)
    {
        if (!(boolPlayerPiece(count, count2, player)) && (toupper(table[count][count2]) == HORSE))
            return 1;
    }

    count = newRow - 1;
    count2 = newColumn + 2;
    if (table[count][count2] != VOID_SQUARE)
    {
        if (!(boolPlayerPiece(count, count2, player)) && (toupper(table[count][count2]) == HORSE))
            return 1;
    }

    count = newRow - 1;
    count2 = newColumn - 2;
    if (table[count][count2] != VOID_SQUARE)
    {
        if (!(boolPlayerPiece(count, count2, player)) && (toupper(table[count][count2]) == HORSE))
            return 1;
    }

    count = newRow + 2;
    count2 = newColumn + 1;
    if (table[count][count2] != VOID_SQUARE)
    {
        if (!(boolPlayerPiece(count, count2, player)) && (toupper(table[count][count2]) == HORSE))
            return 1;
    }

    count = newRow + 2;
    count2 = newColumn - 1;
    if (table[count][count2] != VOID_SQUARE)
    {
        if (!(boolPlayerPiece(count, count2, player)) && (toupper(table[count][count2]) == HORSE))
            return 1;
    }

    count = newRow - 2;
    count2 = newColumn + 1;
    if (table[count][count2] != VOID_SQUARE)
    {
        if (!(boolPlayerPiece(count, count2, player)) && (toupper(table[count][count2]) == HORSE))
            return 1;
    }

    count = newRow - 2;
    count2 = newColumn - 1;
    if (table[count][count2] != VOID_SQUARE)
    {
        if (!(boolPlayerPiece(count, count2, player)) && (toupper(table[count][count2]) == HORSE))
            return 1;
    }

    //Verifica se o peão está em posição de dar check ao rei inimigo:
    if (player = PLAYER_1)
    {
        count = newRow - 1;
        count2 = newColumn + 1;
        if (table[count][count2] != VOID_SQUARE)
        {
            if (!(boolPlayerPiece(count, count2, player)) && (toupper(table[count][count2]) == PAWN))
                return 1;
        }

        count = newRow - 1;
        count2 = newColumn - 1;
        if (table[count][count2] != VOID_SQUARE)
        {
            if (!(boolPlayerPiece(count, count2, player)) && (toupper(table[count][count2]) == PAWN))
                return 1;
        }
    }
    if (player = PLAYER_2)
    {
        count = newRow + 1;
        count2 = newColumn + 1;
        if (table[count][count2] != VOID_SQUARE)
        {
            if (!(boolPlayerPiece(count, count2, player)) && (toupper(table[count][count2]) == PAWN))
                return 1;
        }

        count = newRow + 1;
        count2 = newColumn - 1;
        if (table[count][count2] != VOID_SQUARE)
        {
            if (!(boolPlayerPiece(count, count2, player)) && (toupper(table[count][count2]) == PAWN))
                return 1;
        }
    }

    //Caso não entre em nenhuma das condições acima, é suposto que não é check e o retorno é 0.
    return 0;
}

//Funções de movimento para cada peça:

//Peão
int pawnPiece(int oldRow, int oldColumn, int newRow, int newColumn, int player)
{
    if (player == PLAYER_1)
    {
        if (newRow == (oldRow - 1) && (newColumn == (oldColumn + 1) || newColumn == (oldColumn - 1)))
        {
            if (!boolPlayerPiece(newRow, newColumn, player) && table[newRow][newColumn] != VOID_SQUARE)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if (oldRow == 7)
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
    if (player == PLAYER_2)
    {
        if (newRow == (oldRow + 1) && (newColumn == (oldColumn + 1) || newColumn == (oldColumn - 1)))
        {
            if (!boolPlayerPiece(newRow, newColumn, player) && table[newRow][newColumn] != VOID_SQUARE)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if (oldRow == 2)
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
    if (bishopPiece(oldRow, oldColumn, newRow, newColumn) || rookPiece(oldRow, oldColumn, newRow, newColumn))
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
    case PAWN: //Peão
        if (pawnPiece(oldRow, oldColumn, newRow, newColumn, player))
        {
            return 1;
        }
        return 0;
    case ROOK: //Torre
        if (rookPiece(oldRow, oldColumn, newRow, newColumn))
        {
            return 1;
        }
        return 0;
    case HORSE: //Cavalo
        if (horsePiece(oldRow, oldColumn, newRow, newColumn))
        {
            return 1;
        }
        return 0;
    case BISHOP: //Bispo
        if (bishopPiece(oldRow, oldColumn, newRow, newColumn))
        {
            return 1;
        }
        return 0;
    case QUEEN: //Rainha
        if (queenPiece(oldRow, oldColumn, newRow, newColumn))
        {
            return 1;
        }
        return 0;
    case KING: //Rei
        if (kingPiece(oldRow, oldColumn, newRow, newColumn))
        {
            return 1;
        }
        return 0;
    default:
        return 0;
    }
}

//Verificar possíveis locais para o peão.
int pawnVerify(int oldRow, int oldColumn, int newRow, int newColumn, int player)
{
    if (table[newRow][newColumn] == VOID_SQUARE && newColumn == oldColumn)
    {
        if (player == PLAYER_1 && oldRow == 7 && newRow == 5 && table[6][newColumn] != VOID_SQUARE)
        {
            return 0;
        }
        if (player == PLAYER_2 && oldRow == 2 && newRow == 4 && table[3][newColumn] != VOID_SQUARE)
        {
            return 0;
        }
        return 1;
    }
    else
    {
        return 1;
    }
}

//Verificar possíveis locais para a torre.
int rookVerify(int oldRow, int oldColumn, int newRow, int newColumn, int player)
{
    //Declarar variáveis auxiliares.
    int aux;
    char tempPiece;

    //Torre percorrendo verticalmente para baixo.
    if (newColumn == oldColumn && newRow > oldRow)
    {
        for (aux = (oldRow + 1); aux <= newRow; aux++)
        {
            tempPiece = table[aux][newColumn];

            if (tempPiece != VOID_SQUARE)
            {
                if (boolPlayerPiece(aux, newColumn, player))
                {
                    return 0;
                }
                else
                {
                    if (!boolPlayerPiece(aux, newColumn, player) && aux == newRow)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }

    //Torre percorrendo verticalmente para cima.
    if (newColumn == oldColumn && newRow < oldRow)
    {
        for (aux = (oldRow - 1); aux >= newRow; aux--)
        {
            tempPiece = table[aux][newColumn];

            if (tempPiece != VOID_SQUARE)
            {
                if (boolPlayerPiece(aux, newColumn, player))
                {
                    return 0;
                }
                else
                {
                    if (!boolPlayerPiece(aux, newColumn, player) && aux == newRow)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }

    //Torre percorrendo horizontalmente para a direita.
    if (newRow == oldRow && newColumn > oldColumn)
    {
        for (aux = (oldColumn + 1); aux <= newColumn; aux++)
        {
            tempPiece = table[aux][newColumn];

            if (tempPiece != VOID_SQUARE)
            {
                if (boolPlayerPiece(newRow, aux, player))
                {
                    return 0;
                }
                else
                {
                    if (!boolPlayerPiece(newRow, aux, player) && aux == newColumn)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }

    //Torre percorrendo horizontalmente para a esquerda.
    if (newRow == oldRow && newColumn < oldColumn)
    {
        for (aux = (oldColumn - 1); aux >= newColumn; aux--)
        {
            tempPiece = table[aux][newColumn];

            if (tempPiece != VOID_SQUARE)
            {
                if (boolPlayerPiece(newRow, aux, player))
                {
                    return 0;
                }
                else
                {
                    if (!boolPlayerPiece(newRow, aux, player) && aux == newColumn)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
    return 0;
}

//Verificar possíveis locais para o bispo.
int bishopVerify(int oldRow, int oldColumn, int newRow, int newColumn, int player)
{
    //Declarar variáveis auxiliares.
    int auxRow, auxColumn;
    char tempPiece;

    //Bispo percorrendo para o inferior direito.
    if (newColumn > oldColumn && newRow > oldRow)
    {
        for (auxRow = (oldRow + 1), auxColumn = (oldColumn + 1); auxRow <= newRow, auxColumn <= newColumn; auxRow++, auxColumn++)
        {
            tempPiece = table[auxRow][auxColumn];

            if (tempPiece != VOID_SQUARE)
            {
                if (boolPlayerPiece(auxRow, auxColumn, player))
                {
                    return 0;
                }
                else
                {
                    if (!boolPlayerPiece(auxRow, auxColumn, player) && auxRow == newRow)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }

    //Bispo percorrendo para o superior direito.
    if (newColumn > oldColumn && newRow < oldRow)
    {
        for (auxRow = (oldRow - 1), auxColumn = (oldColumn + 1); auxRow >= newRow, auxColumn <= newColumn; auxRow--, auxColumn++)
        {
            tempPiece = table[auxRow][auxColumn];

            if (tempPiece != VOID_SQUARE)
            {
                if (boolPlayerPiece(auxRow, auxColumn, player))
                {
                    return 0;
                }
                else
                {
                    if (!boolPlayerPiece(auxRow, auxColumn, player) && auxRow == newRow)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }

    //Bispo percorrendo para o inferior esquerdo.
    if (newRow > oldRow && newColumn < oldColumn)
    {
        for (auxColumn = (oldColumn - 1), auxRow = (oldRow + 1); auxColumn >= newColumn, auxRow <= newRow; auxRow++, auxColumn--)
        {
            tempPiece = table[auxRow][auxColumn];

            if (tempPiece != VOID_SQUARE)
            {
                if (boolPlayerPiece(auxRow, auxColumn, player))
                {
                    return 0;
                }
                else
                {
                    if (!boolPlayerPiece(auxRow, auxColumn, player) && auxRow == newRow)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }

    //Bispo percorrendo para o inferior superior.
    if (newRow < oldRow && newColumn < oldColumn)
    {
        for (auxColumn = (oldColumn - 1), auxRow = (oldRow - 1); auxColumn >= newColumn, auxRow >= newRow; auxColumn--, auxRow--)
        {
            tempPiece = table[auxRow][auxColumn];

            if (tempPiece != VOID_SQUARE)
            {
                if (boolPlayerPiece(auxRow, auxColumn, player))
                {
                    return 0;
                }
                else
                {
                    if (!boolPlayerPiece(auxRow, auxColumn, player) && auxRow == newRow)
                    {
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
    return 0;
}

//Verificar possíveis locais para o cavalo.
int horseVerify(int newRow, int newColumn, int player)
{
    //Declarar variáveis auxiliares.
    char tempPiece = table[newRow][newColumn];

    if (tempPiece != VOID_SQUARE)
    {
        if (boolPlayerPiece(newRow, newColumn, player))
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}

//Verificar possíveis locais para a rainha.
int queenVerify(int oldRow, int oldColumn, int newRow, int newColumn, int player)
{
    if (bishopVerify(oldRow, oldColumn, newRow, newColumn, player) || rookVerify(oldRow, oldColumn, newRow, newColumn, player))
    {
        return 1;
    }
    return 0;
}

//Verificar possíveis locais para o rei.
int kingVerify(int newRow, int newColumn, int player)
{
    //Declarar variáveis auxiliares.
    char tempPiece = table[newRow][newColumn];

    if (tempPiece != VOID_SQUARE)
    {
        if (boolPlayerPiece(newRow, newColumn, player))
        {
            return 0;
        }
        else
        {
            if (!(checkVerify(newRow, newColumn, player)))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    else
    {
        if (!(checkVerify(newRow, newColumn, player)))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

//Verifica se posição atribuida pelo player pode ser ocupada.
int positionVerify(char piece, int oldRow, int oldColumn, int newRow, int newColumn, int player)
{
    if ((newRow >= 1 && newRow <= 8) && (newColumn >= 1 && newColumn <= 8))
    {
        switch (toupper(piece))
        {
        case PAWN: //Peão
            if (pawnVerify(oldRow, oldColumn, newRow, newColumn, player))
            {
                return 1;
            }
            return 0;
        case ROOK: //Torre
            if (rookVerify(oldRow, oldColumn, newRow, newColumn, player))
            {
                return 1;
            }
            return 0;
        case BISHOP: //Bispo
            if (bishopVerify(oldRow, oldColumn, newRow, newColumn, player))
            {
                return 1;
            }
            return 0;
        case HORSE: //Cavalo
            if (horseVerify(newRow, newColumn, player))
            {
                return 1;
            }
            return 0;
        case QUEEN: //Rainha
            if (queenVerify(oldRow, oldColumn, newRow, newColumn, player))
            {
                return 1;
            }
            return 0;
        case KING: //Rei
            if (kingVerify(newRow, newColumn, player))
            {
                return 1;
            }
            return 0;
        default:
            return 0;
        }
    }
    return 0;
}

//Função que movimenta as peças no tabuleiro.
void movePiece(char piece, int oldRow, int oldColumn, int newRow, int newColumn)
{
    table[newRow][newColumn] = piece;
    table[oldRow][oldColumn] = VOID_SQUARE;
}

//FUnção que gerencia todas as ações da peça do player.
void actionPiece(int player)
{
    char piece;
    char name[20];
    int newRow, newColumn, oldRow, oldColumn;
    const char *prettyPieceStr;

    if (player == PLAYER_1)
    {
        strcpy(name, player1);
    }
    if (player == PLAYER_2)
    {
        strcpy(name, player2);
    }

    //Variáveis auxiliares:
    int countErro = 0, movePieceOk = 1;

    //Loop para escolher peça e escolher a movimentação.
    do
    {   
        //Seleção de peça:
        do
        {
            renderTable();
            printf("Player: %s", name);
            if (countErro >= 1)
            {
                printf("Você digitou uma posição inválida.\n");
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
        } while (!((player == PLAYER_1 && isupper(piece)) || (player == PLAYER_2 && islower(piece)) && piece != VOID_SQUARE && piece != '|' && isalpha(piece) && (oldRow >= 1 && oldRow <= 8) && (oldColumn >= 1 && oldColumn <= 8)));

        // Movimentação de peça:
        int countAuxPieceMove = 0;
        do
        {
            //Atribui nome da peça ao char.
            prettyPieceStr = prettyPiece(piece);

            clear_screen();
            renderTable();
            printf("Player: %s\n", name);
            printf("Você selecionou: %s (%d, %d)\n", prettyPieceStr, oldRow, oldColumn);
            if (countAuxPieceMove >= 1)
            {
                printf("Movimento inválido.\n");
                printf("Digite 0 0 para selecionar outra peça.\n");
            }
            else
            {
                printf("Digite 0 0 para selecionar outra peça.\n");
            }
            printf("Digite para qual posição você deseja movimentar a peça: ");
            scanf("%d %d", &newRow, &newColumn);
            getchar(); //Consumir Enter.

            //Caso o player digite 0 0.
            if (newRow == 0 && newColumn == 0)
            {
                countErro = 0;
                countAuxPieceMove = 0;
                clear_screen();
                break;
            }
            else //Caso player digite 0 0, não é contado como erro.
            {
                countAuxPieceMove++;
            }

            movePieceOk = 0;

        } while (!(pieceMove(piece, oldRow, oldColumn, newRow, newColumn, player) && positionVerify(piece, oldRow, oldColumn, newRow, newColumn, player)));
    } while (movePieceOk);

    movePiece(piece, oldRow, oldColumn, newRow, newColumn);
}

int checkGameOver(int player)
{
    int kingRowPosition, kingColumnPosition, row, column;
    //Procura a posição do rei no jogo:
    for (row = 0; row < numberOfRows; row++)
    {
        for (column = 0; column < numberOfColumns; column++)
        {
            if (player == PLAYER_1 && table[row][column] == 'K')
            {
            }
            if (player == PLAYER_2 && table[row][column] == 'k')
            {
            }
        }
    }

    return GAME_ON_GOING;
}

int main()
{
    do
    {
        //Coloca as peças no tabuleiro.
        drawTable();

        clear_screen();

        //Configurando UTF-8 para caracteres.
        setlocale(LC_ALL, "Portuguese");

        //Declarar variaveis:
        int optionsMenu;
        int trueOption = 0;
        const char *piece;

        //Variaveis de controle.
        int game_over = GAME_ON_GOING;

        do
        {
            clear_screen();

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

        clear_screen();

        printf("Digite o nome do Player 1 (Máx. 20 caractéres): ");
        fgets(player1, 20, stdin);

        printf("Digite o nome do Player 2 (Máx. 20 caractéres): ");
        fgets(player2, 20, stdin);

        do
        {
            //Incrementa em 1 round.
            gameRound++;

            clear_screen();

            //PLAYER 1 MOVER PEÇA.
            actionPiece(PLAYER_1);
            //CHECAR SE PLAYER 1 VENCEU/EMPATOU.
            game_over = checkGameOver(PLAYER_1);

            //Caso o jogo acabe na rodada do player 1.
            if (game_over != GAME_ON_GOING)
                break;

            clear_screen();

            //PLAYER 2 MOVER PEÇA.
            actionPiece(PLAYER_2);
            //CHECAR SE PLAYER 2 VENCEU/EMPATOU.
            game_over = checkGameOver(PLAYER_2);

        } while (game_over == GAME_ON_GOING);

        clear_screen();
        switch (game_over)
        {

        case STALEMATE:
            renderTable();
            printf("\n\t\tEMPATE!\n");
            printf("O jogo terminou em empate.\n");
            printf("Presione ENTER para voltar a tela inicial...");
            getchar();
            break;

        case PLAYER1_WINNER:
            renderTable();
            printf("\n\t\tVITÓRIA DE %s!\n", player1);
            printf("O player 1 deu Xeque-mate.\n");
            printf("Presione ENTER para voltar a tela inicial...");
            getchar();
            break;

        case PLAYER2_WINNER:
            renderTable();
            printf("\n\t\tVITÓRIA DE %s!\n", player2);
            printf("O player 2 deu Xeque-mate.\n");
            printf("Presione ENTER para voltar a tela inicial...");
            getchar();
            break;

        default:
            return EXIT_FAILURE;
        }
    } while (1); //Ao terminar uma partida, volta a tela inicial.

    return EXIT_SUCCESS;
}