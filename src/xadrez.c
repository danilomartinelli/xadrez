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
#define PLAYER1_CHECK 4
#define PLAYER2_CHECK 5

//Define constantes para as peças do jogo.
#define PAWN 'P'
#define ROOK 'T'
#define BISHOP 'B'
#define HORSE 'C'
#define QUEEN 'Q'
#define KING 'K'
#define VOID_SQUARE '-'

//Variáveis para gerenciar o tabuleiro:
#define NUMBER_OF_ROWS 10
#define NUMBER_OF_COLUMNS 10

//Variáveis para os erros:
#define WRONG_PIECE_POSITION 95
#define WRONG_PIECE_MOVIMENT 96
#define ERROR_MENU_CHOOSE 97
#define KING_CHECK 98

// Função para limpar tela
void clear_screen()
{
#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif
}

//Controla as mensagens de erro do jogo:
void errorMsg(int err)
{
    switch (err)
    {
    case WRONG_PIECE_POSITION:
        printf("Você digitou uma posição inválida.\n");
        break;
    case WRONG_PIECE_MOVIMENT:
        printf("Movimento inválido.\n");
        break;
    case ERROR_MENU_CHOOSE:
        printf("Digite uma opção válida.\n");
        break;
    case KING_CHECK:
        printf("O rei está em cheque!\n");
        break;
    default:
        printf("Comando inválido. \n");
        break;
    }
}

void drawTable(char table[][10])
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
            table[row][column] = VOID_SQUARE;
        }
    }

    //Player 1:
    table[8][1] = 'T';
    table[8][2] = 'C';
    table[8][3] = 'B';
    table[8][4] = 'Q';
    table[8][5] = 'K';
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
    table[1][4] = 'q';
    table[1][5] = 'k';
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
    FILE *file; //Declara Struct do tipo FILE.
    char row[100];

    clear_screen();

    //Verifica se existe arquivo:
    file = fopen("assets/about.txt", "rt");
    if (file == NULL)
        exit(EXIT_FAILURE);

    //Printa as linhas do arquivo no DOS.
    while (!feof(file))
    {
        fgets(row, 100, file);
        printf("%s", row);
    }

    printf("\n\nPressione ENTER para voltar.");
    getchar();
}

//Exibe AJUDA no DOS.
void help()
{
    FILE *file; //Declara Struct do tipo FILE.
    char row[100];

    clear_screen();

    //Verifica se existe arquivo:
    file = fopen("assets/help.txt", "rt");
    if (file == NULL)
        exit(EXIT_FAILURE);

    //Printa as linhas do arquivo no DOS.
    while (!feof(file))
    {
        fgets(row, 100, file);
        printf("%s", row);
    }

    printf("\n\nPressione ENTER para voltar.");
    getchar();
}

void imgIntro()
{
    FILE *file; //Declara Struct do tipo FILE.
    char row[100];

    clear_screen();

    //Verifica se existe arquivo:
    file = fopen("assets/imgIntro.txt", "rt");
    if (file == NULL)
        exit(EXIT_FAILURE);

    //Printa as linhas do arquivo no DOS.
    while (!feof(file))
    {
        fgets(row, 100, file);
        printf("%s", row);
    }
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
void renderTable(int gameRound, char table[][10])
{
    int row, columns;

    printf("\t\t\t########## PARTIDA ########\n\n\n");

    //Renderizando tabuleiro.
    for (row = 0; row < NUMBER_OF_ROWS; row++)
    {
        for (columns = 0; columns < NUMBER_OF_COLUMNS; columns++)
        {
            printf("%c\t", table[row][columns]);
        }
        printf("\n\n");
    }
    printf("Rodada n°: %d\n\n", gameRound);
}

//Veficar se peça é do time verificado
int boolPlayerPiece(int row, int column, int player, char table[][10])
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
int checkVerify(int newRow, int newColumn, int player, char table[][10])
{
    //Variáveis auxiliares
    int count, count2;

    //Verifica se torre ou rainha estão em posição de dar check ao rei inimigo:
    if (newRow != 8)
    {
        //Vertical para baixo.
        for (count = newRow + 1; count <= 8; count++)
        {
            if (table[count][newColumn] != VOID_SQUARE)
            {
                if (!(boolPlayerPiece(count, newColumn, player, table)) && (toupper(table[count][newColumn]) == ROOK || toupper(table[count][newColumn]) == QUEEN))
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
        //Vertical para cima.
        for (count = newRow - 1; count >= 1; count--)
        {
            if (table[count][newColumn] != VOID_SQUARE)
            {
                if (!(boolPlayerPiece(count, newColumn, player, table)) && (toupper(table[count][newColumn]) == ROOK || toupper(table[count][newColumn]) == QUEEN))
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
        //Horizontal para direita.
        for (count = newColumn + 1; count <= 8; count++)
        {
            if (table[newRow][count] != VOID_SQUARE)
            {
                if (!(boolPlayerPiece(newRow, count, player, table)) && (toupper(table[newRow][count]) == ROOK || toupper(table[newRow][count]) == QUEEN))
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
        //Horizontal para esquerda.
        for (count = newColumn - 1; count >= 1; count--)
        {
            if (table[newRow][count] != VOID_SQUARE)
            {
                if (!(boolPlayerPiece(newRow, count, player, table)) && (toupper(table[newRow][count]) == ROOK || toupper(table[newRow][count]) == QUEEN))
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
                if (!(boolPlayerPiece(count, count2, player, table)) && (toupper(table[count][count2]) == BISHOP || toupper(table[count][count2]) == QUEEN))
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
                if (!(boolPlayerPiece(count, count2, player, table)) && (toupper(table[count][count2]) == BISHOP || toupper(table[count][count2]) == QUEEN))
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
                if (!(boolPlayerPiece(count, count2, player, table)) && (toupper(table[count][count2]) == BISHOP || toupper(table[count][count2]) == QUEEN))
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
                if (!(boolPlayerPiece(count, count2, player, table)) && (toupper(table[count][count2]) == BISHOP || toupper(table[count][count2]) == QUEEN))
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
        if (!(boolPlayerPiece(count, count2, player, table)) && (toupper(table[count][count2]) == HORSE))
        {
            return 1;
        }
    }

    count = newRow + 1;
    count2 = newColumn - 2;
    if (table[count][count2] != VOID_SQUARE)
    {
        if (!(boolPlayerPiece(count, count2, player, table)) && (toupper(table[count][count2]) == HORSE))
        {
            return 1;
        }
    }

    count = newRow - 1;
    count2 = newColumn + 2;
    if (table[count][count2] != VOID_SQUARE)
    {
        if (!(boolPlayerPiece(count, count2, player, table)) && (toupper(table[count][count2]) == HORSE))
        {
            return 1;
        }
    }

    count = newRow - 1;
    count2 = newColumn - 2;
    if (table[count][count2] != VOID_SQUARE)
    {
        if (!(boolPlayerPiece(count, count2, player, table)) && (toupper(table[count][count2]) == HORSE))
        {
            return 1;
        }
    }

    count = newRow + 2;
    count2 = newColumn + 1;
    if (table[count][count2] != VOID_SQUARE)
    {
        if (!(boolPlayerPiece(count, count2, player, table)) && (toupper(table[count][count2]) == HORSE))
        {
            return 1;
        }
    }

    count = newRow + 2;
    count2 = newColumn - 1;
    if (table[count][count2] != VOID_SQUARE)
    {
        if (!(boolPlayerPiece(count, count2, player, table)) && (toupper(table[count][count2]) == HORSE))
        {
            return 1;
        }
    }

    count = newRow - 2;
    count2 = newColumn + 1;
    if (table[count][count2] != VOID_SQUARE)
    {
        if (!(boolPlayerPiece(count, count2, player, table)) && (toupper(table[count][count2]) == HORSE))
        {
            return 1;
        }
    }

    count = newRow - 2;
    count2 = newColumn - 1;
    if (table[count][count2] != VOID_SQUARE)
    {
        if (!(boolPlayerPiece(count, count2, player, table)) && (toupper(table[count][count2]) == HORSE))
        {
            return 1;
        }
    }

    //Verifica se o peão está em posição de dar check ao rei inimigo:
    if (player == PLAYER_1)
    {
        count = newRow - 1;
        count2 = newColumn + 1;
        if (table[count][count2] != VOID_SQUARE)
        {
            if (!(boolPlayerPiece(count, count2, player, table)) && (toupper(table[count][count2]) == PAWN))
            {
                return 1;
            }
        }

        count = newRow - 1;
        count2 = newColumn - 1;
        if (table[count][count2] != VOID_SQUARE)
        {
            if (!(boolPlayerPiece(count, count2, player, table)) && (toupper(table[count][count2]) == PAWN))
            {
                return 1;
            }
        }
    }
    if (player == PLAYER_2)
    {
        count = newRow + 1;
        count2 = newColumn + 1;
        if (table[count][count2] != VOID_SQUARE)
        {
            if (!(boolPlayerPiece(count, count2, player, table)) && (toupper(table[count][count2]) == PAWN))
            {
                return 1;
            }
        }

        count = newRow + 1;
        count2 = newColumn - 1;
        if (table[count][count2] != VOID_SQUARE)
        {
            if (!(boolPlayerPiece(count, count2, player, table)) && (toupper(table[count][count2]) == PAWN))
            {
                return 1;
            }
        }
    }

    //Caso não entre em nenhuma das condições acima, é suposto que não é check e o retorno é 0.
    return 0;
}

//Funções de movimento para cada peça:

//Peão
int pawnPiece(int oldRow, int oldColumn, int newRow, int newColumn, int player, char table[][10])
{
    if (player == PLAYER_1)
    {
        if (newRow == (oldRow - 1) && (newColumn == (oldColumn + 1) || newColumn == (oldColumn - 1)))
        {
            if (!boolPlayerPiece(newRow, newColumn, player, table) && table[newRow][newColumn] != VOID_SQUARE)
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
            if (!boolPlayerPiece(newRow, newColumn, player, table) && table[newRow][newColumn] != VOID_SQUARE)
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
int pieceMove(char piece, int oldRow, int oldColumn, int newRow, int newColumn, int player, char table[][10])
{
    const char *prettyPieceStr;
    prettyPieceStr = prettyPiece(piece);

    switch (toupper(piece))
    {
    case PAWN: //Peão
        if (pawnPiece(oldRow, oldColumn, newRow, newColumn, player, table))
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
int pawnVerify(int oldRow, int oldColumn, int newRow, int newColumn, int player, char table[][10])
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
        if (newColumn == oldColumn && table[newRow][newColumn] != VOID_SQUARE)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

//Verificar possíveis locais para a torre.
int rookVerify(int oldRow, int oldColumn, int newRow, int newColumn, int player, char table[][10])
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
                if (boolPlayerPiece(aux, newColumn, player, table))
                {
                    return 0;
                }
                else
                {
                    if (!boolPlayerPiece(aux, newColumn, player, table) && aux == newRow)
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
                if (boolPlayerPiece(aux, newColumn, player, table))
                {
                    return 0;
                }
                else
                {
                    if (!boolPlayerPiece(aux, newColumn, player, table) && aux == newRow)
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
            tempPiece = table[newRow][aux];

            if (tempPiece != VOID_SQUARE)
            {
                if (boolPlayerPiece(newRow, aux, player, table))
                {
                    return 0;
                }
                else
                {
                    if (!boolPlayerPiece(newRow, aux, player, table) && aux == newColumn)
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
            tempPiece = table[newRow][aux];

            if (tempPiece != VOID_SQUARE)
            {
                if (boolPlayerPiece(newRow, aux, player, table))
                {
                    return 0;
                }
                else
                {
                    if (!boolPlayerPiece(newRow, aux, player, table) && aux == newColumn)
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
int bishopVerify(int oldRow, int oldColumn, int newRow, int newColumn, int player, char table[][10])
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
                if (boolPlayerPiece(auxRow, auxColumn, player, table))
                {
                    return 0;
                }
                else
                {
                    if (!boolPlayerPiece(auxRow, auxColumn, player, table) && auxRow == newRow)
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
                if (boolPlayerPiece(auxRow, auxColumn, player, table))
                {
                    return 0;
                }
                else
                {
                    if (!boolPlayerPiece(auxRow, auxColumn, player, table) && auxRow == newRow)
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
                if (boolPlayerPiece(auxRow, auxColumn, player, table))
                {
                    return 0;
                }
                else
                {
                    if (!boolPlayerPiece(auxRow, auxColumn, player, table) && auxRow == newRow)
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
                if (boolPlayerPiece(auxRow, auxColumn, player, table))
                {
                    return 0;
                }
                else
                {
                    if (!boolPlayerPiece(auxRow, auxColumn, player, table) && auxRow == newRow)
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
int horseVerify(int newRow, int newColumn, int player, char table[][10])
{
    //Declarar variáveis auxiliares.
    char tempPiece = table[newRow][newColumn];

    if (tempPiece != VOID_SQUARE)
    {
        if (boolPlayerPiece(newRow, newColumn, player, table))
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
int queenVerify(int oldRow, int oldColumn, int newRow, int newColumn, int player, char table[][10])
{
    if (bishopVerify(oldRow, oldColumn, newRow, newColumn, player, table) || rookVerify(oldRow, oldColumn, newRow, newColumn, player, table))
    {
        return 1;
    }
    return 0;
}

//Verificar possíveis locais para o rei.
int kingVerify(int newRow, int newColumn, int player, char table[][10])
{
    //Declarar variáveis auxiliares.
    char tempPiece = table[newRow][newColumn];

    if (tempPiece != VOID_SQUARE)
    {
        if (boolPlayerPiece(newRow, newColumn, player, table))
        {
            return 0;
        }
        else
        {
            if (!(checkVerify(newRow, newColumn, player, table)))
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
        if (!(checkVerify(newRow, newColumn, player, table)))
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
int positionVerify(char piece, int oldRow, int oldColumn, int newRow, int newColumn, int player, char table[][10], int game_over)
{
    if ((player == PLAYER_1 && game_over != PLAYER1_CHECK) || (player == PLAYER_2 && game_over != PLAYER2_CHECK))
    {
        if ((newRow >= 1 && newRow <= 8) && (newColumn >= 1 && newColumn <= 8))
        {
            switch (toupper(piece))
            {
            case PAWN: //Peão
                if (pawnVerify(oldRow, oldColumn, newRow, newColumn, player, table))
                {
                    return 1;
                }
                return 0;
            case ROOK: //Torre
                if (rookVerify(oldRow, oldColumn, newRow, newColumn, player, table))
                {
                    return 1;
                }
                return 0;
            case BISHOP: //Bispo
                if (bishopVerify(oldRow, oldColumn, newRow, newColumn, player, table))
                {
                    return 1;
                }
                return 0;
            case HORSE: //Cavalo
                if (horseVerify(newRow, newColumn, player, table))
                {
                    return 1;
                }
                return 0;
            case QUEEN: //Rainha
                if (queenVerify(oldRow, oldColumn, newRow, newColumn, player, table))
                {
                    return 1;
                }
                return 0;
            case KING: //Rei
                if (kingVerify(newRow, newColumn, player, table))
                {
                    return 1;
                }
                return 0;
            default:
                return 0;
            }
        }
    }
    else
    {
        if (toupper(piece) == KING)
        {
            if (kingVerify(newRow, newColumn, player, table))
            {
                return 1;
            }
            return 0;
        }
        else
        {
            return 0;
        }
    }
}

//Função que movimenta as peças no tabuleiro.
void movePiece(char piece, int oldRow, int oldColumn, int newRow, int newColumn, char table[][10])
{
    table[newRow][newColumn] = piece;
    table[oldRow][oldColumn] = VOID_SQUARE;
}

//FUnção que gerencia todas as ações da peça do player.
void actionPiece(int player, int gameRound, char *playerName, char table[][10], int game_over)
{
    char piece;
    int newRow, newColumn, oldRow, oldColumn;
    const char *prettyPieceStr;

    //Variáveis auxiliares:
    int countErro = 0, movePieceOk = 1;

    //Loop para escolher peça e escolher a movimentação.
    do
    {
        //Seleção de peça:
        do
        {
            renderTable(gameRound, table);
            printf("Player: %s", playerName);
            if (countErro >= 1)
                errorMsg(WRONG_PIECE_POSITION);
            printf("Digite a posição da peça a ser movida (LINHA COLUNA): ");
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
            renderTable(gameRound, table);
            printf("Player: %s\n", playerName);
            printf("Você selecionou: %s (%d, %d)\n", prettyPieceStr, oldRow, oldColumn);

            if (countAuxPieceMove >= 1)
            {
                if (game_over != PLAYER1_CHECK && game_over != PLAYER2_CHECK)
                {
                    errorMsg(WRONG_PIECE_MOVIMENT);
                }
                else
                {
                    errorMsg(KING_CHECK);
                }
            }

            printf("Digite 0 0 para selecionar outra peça.\n");
            printf("Digite para qual posição você deseja movimentar a peça: ");
            scanf("%d %d", &newRow, &newColumn);
            getchar(); //Consumir Enter.

            //Caso o player digite 0 0.
            if (newRow == 0 && newColumn == 0)
            {
                countErro = 0;
                countAuxPieceMove = 0;
                clear_screen();
                movePieceOk = 1;
                break;
            }
            else //Caso player digite 0 0, não é contado como erro.
            {
                countAuxPieceMove++;
            }

            movePieceOk = 0;

        } while (!(pieceMove(piece, oldRow, oldColumn, newRow, newColumn, player, table) && positionVerify(piece, oldRow, oldColumn, newRow, newColumn, player, table, game_over)));
    } while (movePieceOk);

    movePiece(piece, oldRow, oldColumn, newRow, newColumn, table);
}

//Verifica se é xeque, xeque-mate ou empate:
int checkGameOver(int player, char table[][10])
{
    //Declarar variáveis auxiliares:
    int kingRow, kingColumn, row, column, boolCheck = 0, boolCheckMate = 0, stalemateVerify = 0;

    //Procura a posição do rei no jogo:
    for (row = 0; row < NUMBER_OF_ROWS; row++)
    {
        for (column = 0; column < NUMBER_OF_COLUMNS; column++)
        {
            if (player == PLAYER_1 && table[row][column] == 'K')
            {
                kingRow = row;
                kingColumn = column;
            }
            if (player == PLAYER_2 && table[row][column] == 'k')
            {
                kingRow = row;
                kingColumn = column;
            }
        }
    }

    // Verifica se rei se encontra em cheque na posição atual.
    if (checkVerify(kingRow, kingColumn, player, table))
    {
        boolCheck = 1;
        boolCheckMate++;
    }

    // Verifica se é possível andar para todas as posições:

    //CIMA
    row = kingRow - 1;
    column = kingColumn;
    if (kingRow == 1 || boolPlayerPiece(row, column, player, table))
    {
        if (kingRow == 1)
        {
            stalemateVerify++;
        }
        boolCheckMate++;
    }
    else
    {
        if (checkVerify(row, column, player, table))
        {
            boolCheckMate++;
            stalemateVerify++;
        }
    }

    //CIMA-ESQUERDA
    row = kingRow - 1;
    column = kingColumn - 1;
    if (kingRow == 1 || boolPlayerPiece(row, column, player, table))
    {
        if (kingRow == 1)
        {
            stalemateVerify++;
        }
        boolCheckMate++;
    }
    else
    {
        if (checkVerify(row, column, player, table))
        {
            boolCheckMate++;
            stalemateVerify++;
        }
    }

    //CIMA-DIREITA
    row = kingRow - 1;
    column = kingColumn + 1;
    if (kingRow == 1 || boolPlayerPiece(row, column, player, table))
    {
        if (kingRow == 1)
        {
            stalemateVerify++;
        }
        boolCheckMate++;
    }
    else
    {
        if (checkVerify(row, column, player, table))
        {
            boolCheckMate++;
            stalemateVerify++;
        }
    }

    //ESQUERDA
    row = kingRow;
    column = kingColumn - 1;
    if (kingColumn == 1 || boolPlayerPiece(row, column, player, table))
    {
        if (kingColumn == 1)
        {
            stalemateVerify++;
        }
        boolCheckMate++;
    }
    else
    {
        if (checkVerify(row, column, player, table))
        {
            boolCheckMate++;
            stalemateVerify++;
        }
    }

    //DIREITA
    row = kingRow;
    column = kingColumn + 1;
    if (kingColumn == 8 || boolPlayerPiece(row, column, player, table))
    {
        if (kingColumn == 8)
        {
            stalemateVerify++;
        }
        boolCheckMate++;
    }
    else
    {
        if (checkVerify(row, column, player, table))
        {
            boolCheckMate++;
            stalemateVerify++;
        }
    }

    //BAIXO
    row = kingRow + 1;
    column = kingColumn;
    if (kingRow == 8 || boolPlayerPiece(row, column, player, table))
    {
        if (kingRow == 8)
        {
            stalemateVerify++;
        }
        boolCheckMate++;
    }
    else
    {
        if (checkVerify(row, column, player, table))
        {
            boolCheckMate++;
            stalemateVerify++;
        }
    }

    //BAIXO-ESQUERDA
    row = kingRow + 1;
    column = kingColumn - 1;
    if (kingRow == 8 || boolPlayerPiece(row, column, player, table))
    {
        if (kingRow == 8)
        {
            stalemateVerify++;
        }
        boolCheckMate++;
    }
    else
    {
        if (checkVerify(row, column, player, table))
        {
            boolCheckMate++;
            stalemateVerify++;
        }
    }

    //BAIXO-DIREITA
    row = kingRow + 1;
    column = kingColumn + 1;
    if (kingRow == 8 || boolPlayerPiece(row, column, player, table))
    {
        if (kingRow == 8)
        {
            stalemateVerify++;
        }
        boolCheckMate++;
    }
    else
    {
        if (checkVerify(row, column, player, table))
        {
            boolCheckMate++;
            stalemateVerify++;
        }
    }

    //Retorna valores que significam XEQUE, XEQUE-MATE, EMPATE e JOGO EM ANDAMENTO:
    if (boolCheckMate == 9)
    {
        if (player == PLAYER_1)
            return PLAYER2_WINNER;
        if (player == PLAYER_2)
            return PLAYER1_WINNER;
    }
    if (stalemateVerify == 8 && boolCheck == 0)
    {
        return STALEMATE;
    }
    if (boolCheck == 1 && boolCheckMate < 9)
    {
        if (player == PLAYER_1)
            return PLAYER1_CHECK;
        if (player == PLAYER_2)
            return PLAYER2_CHECK;
    }
    return GAME_ON_GOING;
}

int main()
{
    do
    {
        clear_screen();

        //Configurando UTF-8 para caracteres.
        setlocale(LC_ALL, "Portuguese");

        //Declarar variaveis:
        int optionsMenu;
        int trueOption = 0;
        const char *piece;

        //Variaveis de controle.
        int game_over = GAME_ON_GOING;
        int gameRound = 0;

        //Cria matriz para o tabuleiro.
        char table[10][10];

        //Define variaveis para player 1 e 2.
        char player1[STRING_PLAYER];
        char player2[STRING_PLAYER];

        //Coloca as peças no tabuleiro.
        drawTable(table);

        do
        {
            clear_screen();
            imgIntro();
            printf("\n\n\n");
            printf("1. Novo Jogo\n");
            printf("2. Ajuda\n");
            printf("3. Sobre\n");
            printf("4. Sair\n\n");

            if (trueOption == 1)
                errorMsg(ERROR_MENU_CHOOSE);

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
            actionPiece(PLAYER_1, gameRound, player1, table, game_over);
            //CHECAR SE PLAYER 1 VENCEU/EMPATOU/DEIXOU PLAYER INIMIGO EM CHECK.
            game_over = checkGameOver(PLAYER_2, table);

            //Caso o jogo acabe na rodada do player 1.
            if (game_over != GAME_ON_GOING && game_over != PLAYER1_CHECK && game_over != PLAYER2_CHECK)
            {
                break;
            }

            clear_screen();

            //PLAYER 2 MOVER PEÇA.
            actionPiece(PLAYER_2, gameRound, player2, table, game_over);
            //CHECAR SE PLAYER 2 VENCEU/EMPATOU/DEIXOU PLAYER INIMIGO EM CHECK.
            game_over = checkGameOver(PLAYER_1, table);

        } while (game_over == GAME_ON_GOING || game_over == PLAYER1_CHECK || game_over == PLAYER2_CHECK);

        clear_screen();
        switch (game_over)
        {

        case STALEMATE:
            renderTable(gameRound, table);
            printf("\n\t\tEMPATE!\n");
            printf("O jogo terminou em empate.\n");
            printf("Presione ENTER para voltar a tela inicial...");
            getchar();
            break;

        case PLAYER1_WINNER:
            renderTable(gameRound, table);
            printf("\n\t\tVITÓRIA DE %s\n", player1);
            printf("O player 1 deu Xeque-mate.\n");
            printf("Presione ENTER para voltar a tela inicial...");
            getchar();
            break;

        case PLAYER2_WINNER:
            renderTable(gameRound, table);
            printf("\n\t\tVITÓRIA DE %s\n", player2);
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