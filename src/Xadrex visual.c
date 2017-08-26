#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Desenhar tabuleiro na tela
void tabuleiro_em_tela(char tabuleiro[10][10]);
// Desenhar a fun��o na tela
void printar_menu(char tabuleiro[10][10]);
//fun��o para selecionar a pe�a
void selecao_peca (char tabuleiro[10][10], char *ppeca);
//fun��o para atualizar a tela
void atualizar_tela ( char tabuleiro[10][10], int *rodada);
//fun��o do movimento do bispo pequeno
void validar_movimento_bispob (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido);
//fun��o do movimento do bispo grande
void validar_movimento_bispoB (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido);
//fun��o do movimento do cavalo grande
void validar_movimento_cavaloc (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido);
//fun��o do movimento do cavalo pequeno
void validar_movimento_cavaloC (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido);
//fun��o do movimento da torre pequena
void validar_movimento_torret (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido);
//fun��o do movimento da torre grande
void validar_movimento_torreT (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido);
//fun��o do movimento da rainha pequena
void validar_movimento_rainhar (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido);
//fun��o do movimento da rainha grande
void validar_movimento_rainhaR (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido);
//fun��o do movimento do rei pequeno
void validar_movimento_reir (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido);
//fun��o do movimento do rei grande
void validar_movimento_reiR (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido);
//fun��o do movimento do pe�o minusculo
void validar_movimento_peaop (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha, int *movimento_valido);
//fun��o do movimento do pe�o maisculo
void validar_movimento_peaoP (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha, int *movimento_valido);
//fun��o que move a peca
void mover_peca(char tabuleiro[10][10], char *ppeca, int *rodada, int linhavelha , int colunavelha, int *movimento_valido);
//fun��o que verifica se ocorreu check e mate
void check_mate (char tabuleiro[10][10]);

//Fun��o principal
int main(){
    char tabuleiro[10][10];
    printar_menu(tabuleiro);

    return 0;
}

//fun��o criar tabuleiro
void tabuleiro_em_tela(char tabuleiro[10][10]){
    int linha, coluna, aux;
    //criar as coordenadas nas laterais
    for (linha = 1; linha < 9; linha++)
    {
        coluna = 0;
        tabuleiro[linha][coluna] = linha + 48;
        coluna = 9;
        tabuleiro[linha][coluna] = linha + 48;
    }
    //criar as coordenadas superior e inferior
    for (coluna = 1; coluna < 9; coluna++)
    {
        linha = 0;
        tabuleiro[linha][coluna] = coluna + 48;
        linha = 9;
        tabuleiro[linha][coluna] = coluna + 48;
    }

    //colocando os espa�os vazios
    for (linha = 3; linha < 7; linha++)
    {
        for (coluna = 1; coluna < 9; coluna++)
        {
            tabuleiro[linha][coluna] = '-';
        }
    }
    //Colocando pe�as do jogador de cima, branca
    tabuleiro[1][1] = 'T';
    tabuleiro[1][2] = 'C';
    tabuleiro[1][3] = 'B';
    tabuleiro[1][4] = 'R';
    tabuleiro[1][5] = 'A';
    tabuleiro[1][6] = 'B';
    tabuleiro[1][7] = 'C';
    tabuleiro[1][8] = 'T';

    //colocando os pe�es brancos
    for (coluna = 1; coluna < 9; coluna++)
    {
        tabuleiro[2][coluna] = 'P';
    }
    //Colocando pe�as do jogador de baixo
    tabuleiro[8][1] = 't';
    tabuleiro[8][2] = 'c';
    tabuleiro[8][3] = 'b';
    tabuleiro[8][4] = 'r';
    tabuleiro[8][5] = 'a';
    tabuleiro[8][6] = 'b';
    tabuleiro[8][7] = 'c';
    tabuleiro[8][8] = 't';

    //colocar os pe�es pretos
    for (coluna = 1; coluna < 9; coluna++)
    {
        tabuleiro[7][coluna] = 'p';
    }

   //colocando as barras da quina
    for (linha = 0; linha < 10; linha++){
        for (coluna = 0; coluna < 10; coluna++){
            if (linha == 0 && coluna == 0 || linha == 0 && coluna == 9 || linha == 9 && coluna == 0 || linha == 9 && coluna == 9){
                tabuleiro[linha][coluna] = '|';
            }
        }
    }
    // varrendo as linhas para colocar o backgroud e as pecas
    for (linha = 0; linha < 10; linha++){
        // /////// aux=0
        // ///x/// aux=1
        // /////// aux=2
        for(aux=0; aux<3; aux++){
            // varrendo as colunas para colocar o backgroud e as pecas
            for (coluna = 0; coluna < 10; coluna++){
                // verificando se � os espa�os internos da matrix
                if((linha <= 8 && linha >= 1) && (coluna <= 8 && coluna >= 1)){
                    // se o valor de aux for par, � para colocar os backgrounds
                    if(aux%2==0){
                            // se o valor de coluna+linha for par colocar o backgroud branco
                            if((coluna+linha)%2!=0){
                                // colocando o background branco
                                printf("\xDb\xDb\xDb\xDb\xDb");
                            }
                            // se o valor de coluna+linha for impar colocar o backgroud branco
                            else{
                                // colocando o background preto. como o fundo do DOS � preto, basta colocar espa�os vazios
                                printf("     ");
                            }
                    }
                    // printar a peca no meio do background
                    else{
                            // se o valor de coluna+linha for par colocar uma peca entre o backgroud branco
                            if((coluna+linha)%2!=0){
                                // colocando a peca entre o background branco
                                printf("\xDb\xDb%c\xDb\xDb", tabuleiro[linha][coluna]);
                            }
                            // se o valor de coluna+linha for par colocar uma peca entre o backgroud branco
                            else{
                                // colocando a peca entre o background preto
                                printf("  %c  ", tabuleiro[linha][coluna]);
                            }
                    }
                }
                //se n�o forem os espa�os internos e sim as coordenadas auxiliares
                else{
                        //se for a primeira linha ou a ultima
                        if((linha==0)||(linha==9)){
                            // para colocar o espacameto nas coordenadas. entre o primeiro e o segundo termo, e entre o oitavo e o nono
                            if((coluna==0)||(coluna==8)){
                                // printar s� uma vez
                                if(aux%2!=0){
                                    printf("%c  ", tabuleiro[linha][coluna]);
                                }
                            }
                            // para colocar o espacameto nas coordenadas
                            else{
                                // printar s� uma vez
                                if(aux%2!=0){
                                    // para colocar o espacameto nas coordenadas
                                    printf("%c    ", tabuleiro[linha][coluna]);
                                }
                            }

                        }
                        // nas outras laterais
                        else{
                            // printar s� uma vez
                            if(aux%2!=0){
                                printf("%c", tabuleiro[linha][coluna]);
                            }
                            // centralizar a coordenada auxiliar
                            else{
                                printf(" ");
                            }
                        }
                }
            }
            // pular uma linha
            printf("\n");
        }
    }
}

//fun��o criar o menu
void printar_menu(char tabuleiro[10][10]){
    int opcoes;

    do
    {
    //printar o menu

        //PRINTAR UM BELO DE UM NOME
        printf("######################################################################################################################################\n");
        printf("\n\n\n");
        printf("XXXXXXX       XXXXXXX               AAA               DDDDDDDDDDDDD      RRRRRRRRRRRRRRRRR   EEEEEEEEEEEEEEEEEEEEEEZZZZZZZZZZZZZZZZZZZ\n");
        printf("X:::::X       X:::::X              A:::A              D::::::::::::DDD   R::::::::::::::::R  E::::::::::::::::::::EZ:::::::::::::::::Z\n");
        printf("X:::::X       X:::::X             A:::::A             D:::::::::::::::DD R::::::RRRRRR:::::R E::::::::::::::::::::EZ:::::::::::::::::Z\n");
        printf("X::::::X     X::::::X            A:::::::A            DDD:::::DDDDD:::::DRR:::::R     R:::::REE::::::EEEEEEEEE::::EZ:::ZZZZZZZZ:::::Z\n");
        printf("XXX:::::X   X:::::XXX           A:::::::::A             D:::::D    D:::::D R::::R     R:::::R  E:::::E       EEEEEEZZZZZ     Z:::::Z\n");
        printf("   X:::::X X:::::X             A:::::A:::::A            D:::::D     D:::::DR::::R     R:::::R  E:::::E                     Z:::::Z\n");
        printf("    X:::::X:::::X             A:::::A A:::::A           D:::::D     D:::::DR::::RRRRRR:::::R   E::::::EEEEEEEEEE          Z:::::Z\n");
        printf("     X:::::::::X             A:::::A   A:::::A          D:::::D     D:::::DR:::::::::::::RR    E:::::::::::::::E         Z:::::Z\n");
        printf("     X:::::::::X            A:::::A     A:::::A         D:::::D     D:::::DR::::RRRRRR:::::R   E:::::::::::::::E        Z:::::Z\n");
        printf("    X:::::X:::::X          A:::::AAAAAAAAA:::::A        D:::::D     D:::::DR::::R     R:::::R  E::::::EEEEEEEEEE       Z:::::Z\n");
        printf("   X:::::X X:::::X        A:::::::::::::::::::::A       D:::::D     D:::::DR::::R     R:::::R  E:::::E                Z:::::Z\n");
        printf("XXX:::::X   X:::::XXX    A:::::AAAAAAAAAAAAA:::::A      D:::::D    D:::::D R::::R     R:::::R  E:::::E       EEEEEEZZZ:::::Z     ZZZZZ\n");
        printf("X::::::X     X::::::X   A:::::A             A:::::A   DDD:::::DDDDD:::::DRR:::::R     R:::::REE::::::EEEEEEEE:::::EZ::::::ZZZZZZZZ:::Z\n");
        printf("X:::::X       X:::::X  A:::::A               A:::::A  D:::::::::::::::DD R::::::R     R:::::RE::::::::::::::::::::EZ:::::::::::::::::Z\n");
        printf("X:::::X       X:::::X A:::::A                 A:::::A D::::::::::::DDD   R::::::R     R:::::RE::::::::::::::::::::EZ:::::::::::::::::Z\n");
        printf("XXXXXXX       XXXXXXXAAAAAAA                   AAAAAAADDDDDDDDDDDDD      RRRRRRRR     RRRRRRREEEEEEEEEEEEEEEEEEEEEEZZZZZZZZZZZZZZZZZZZ\n");

        //printa um BELO DE UM CAVALO. MUITO BELO. ROBUSTO. COMO O PROFESSOR QUERIA
        printf("```````````````````````````````````````````````````+++@@@@@@@;````````````````````````````````````````````````````````````````````````\n");
        printf("``````````````````````````````````````````````````++#@'#'#@@@;.```````````````````````````````````````````````````````````````````````\n");
        printf("`````````````````````````````````````````````````;+#@,#@..:@@@@+;.````````````````````````````````````````````````````````````````````\n");
        printf("`````````````````````````````````````````````````##+@+'''@@@@@@@@+;::..```````````````````````````````````````````````````````````````\n");
        printf("````````````````````````````````````````````````'+@@,@'@@@@@@@@@@@@@##+';:.```````````````````````````````````````````````````````````\n");
        printf("````````````````````````````````````````````````+#@@`@@@@@@@@' @@@@@@@@@,@;.``````````````````````````````````````````````````````````\n");
        printf("````````````````````````````````````````````````##@, @@@@@@@@` @#@@@@@@@+@@:``````````````````````````````````````````````````````````\n");
        printf("````````````````````````````````````````````````#@## @@@@@@@@@@@+@@@@@@##@@#,`````````````````````````````````````````````````````````\n");
        printf("```````````````````````````````````````````````.#@@@`@@@@@@@@@@@++#@@@@@@@@'.`````````````````````````````````````````````````````````\n");
        printf("```````````````````````````````````````````````.#@#;`@@+'#@@@@@@@@@@@@@;::::.`````````````````````````````````````````````````````````\n");
        printf("````````````````````````````````````````````````#@#;`@@@@'@@@@@@@@@@@@@@@@@+,`````````````````````````````````````````````````````````\n");
        printf("````````````````````````````````````````````````+@@@ @@@@'#@@@@@:@@@@#+@@@+,``````````````````````````````````````````````````````````\n");
        printf("````````````````````````````````````````````````###@`@@@@#'@@@@@@@;:::;@@;,```````````````````````````````````````````````````````````\n");
        printf("````````````````````````````````````````````````++@;,#@@@@'@@@@#;;;.``.:::````````````````````````````````````````````````````````````\n");
        printf("````````````````````````````````````````````````,#@@+:@@@@+''';'#@#;.```.,````````````````````````````````````````````````````````````\n");
        printf("`````````````````````````````````````````````````+#@@ @@@@@@@@@@@@@#:,````````````````````````````````````````````````````````````````\n");
        printf("`````````````````````````````````````````````````++@@,@@@@@@@@@@@:@@#:.```````````````````````````````````````````````````````````````\n");
        printf("`````````````````````````````````````````````````,+@+';@@@@@@.,#@@@+@+:.``````````````````````````````````````````````````````````````\n");
        printf("``````````````````````````````````````````````````+#@# @@@@@@+,@+,#@@@':.`````````````````````````````````````````````````````````````\n");
        printf("``````````````````````````````````````````````````++@@'@@@@@@@`#@@@@@@@':`````````````````````````````````````````````````````````````\n");
        printf("``````````````````````````````````````````````````.+@#+:@@@@@##.@@@@@@@@;:````````````````````````````````````````````````````````````\n");
        printf("`````````````````````````````````````````````````..+#@'`@@@@@@@,'@@@@@@@@:.```````````````````````````````````````````````````````````\n");
        printf("```````````````````````````````````````````````````++@@;@@@@@@@@`#@@@@@@@@,```````````````````````````````````````````````````````````\n");
        printf("```````````````````````````````````````````````````;+@@@+@@@@@@@@`@@@@@@@@+,``````````````````````````````````````````````````````````\n");
        printf("````````````````````````````````````````````````.`.:+@@#:@@@@@@@@@ @@@@@@@@,```.``````````````````````````````````````````````````````\n");
        printf("````````````````````````````````````````````````.``'+@#:.@@@@@@@@@@ @@@@@@@+,`.```````````````````````````````````````````````````````\n");
        printf(".................................................`.++@@#:@@@@@@@@@@@;@@@@@@;,.........................................................\n");
        printf("................................................`.`++@@@#@@@@@@@@@@@,@@@@@',`.........................................................\n");
        printf("..................................................:+#@#'@@@@@@@@@@@@@#@@@@,...........................................................\n");
        printf("..................................................++@@;'@@@@@@@@@@@@@+@@@@,.`.........................................................\n");
        printf(".................................................,++@+:@@@@@@@@@@@@@@#@@@#:`..........................................................\n");
        printf("................................................`++@@#@@@@@@@@@@@@@@@@@@@#,...........................................................\n");
        printf("................................................'++#@@@@@@@@@@@@@@@@@@@@@@,...........................................................\n");
        printf(".................................................,#++++##@@@@@@@@@@@@#+;:,:,..........................................................\n");
        printf("...................................................:++#+''''';;;;;;;::;+::............................................................\n");
        printf("...................................................++#@@@@@@@@@@@@@@@@@@;:,...........................................................\n");
        printf("..................................................;++@@+@@@@@@@@@@@@@@#@@+,:..........................................................\n");
        printf("..................................................++@@;@@@@@@@@@@@@@@@@+@@@,,.........................................................\n");
        printf(".................................................++@@.@@@@@@@@@@@@@@@@@@,@@+,,........................................................\n");
        printf(".................................................++@#@@@@@@@@@@@@@@@@@@@@:@@,,........................................................\n");
        printf(".................................................++@;@@@@@@@@@@@@@@@@@@@@;@#,.........................................................\n");
        printf(".................................................#+#@@@@@@@@@@@@@@@@@@@@@@@,,.........................................................\n");
        printf(".................................................'+++++##@@@@@@@@@@@@@#+::,;,.........................................................\n");
        printf(".................................................'+@@##+''''';;;;;;::::;+@@#,.........................................................\n");
        printf("................................................,'#`@#@@@@@@@@@@@@@@@@#@;@ #,.........................................................\n");
        printf(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,.:+#`@,@,@,@:@#@@'@,@`@`@`@ #,..,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n");
        printf(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,+#++ @.@`@`@ @'@@.@ @ @ @`@ ;,,,.,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n");
        printf(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,#+#+`+`#`@`@ @;@@`@ @ @ @`:.++,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n");
        printf(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,.,##@@@@#+.'`'`':''`; ; :.'#@@@@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n");
        printf(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,:#+#@@@@@@@@@@@@@@@@@@@@@@@+:,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n");

        printf("\n\n\t\t\t\t\t\t1-Jogar\n\n \t\t\t\t\t\t2-Ajuda\n\n \t\t\t\t\t\t3-Sobre o jogo\n\n \t\t\t\t\t\t4-Sair\n\n");
        printf("######################################################################################################################################\n");
        scanf("%d", &opcoes);
        getchar();
        system("cls");
        char ppeca;


    // op��es do menu
    switch(opcoes){
        case 1:
            //printa o menu na tela
            tabuleiro_em_tela(tabuleiro);
            //seleciona a pe�a. As fun��es restantes est�o dentro desta
            selecao_peca(tabuleiro, &ppeca);

            break;

        case 2:
            printf("Player 1 controla as pecas minusculas e Player 2 as pecas maiusculas.");
            printf(" O jogo segue todas as regras oficiais. Exceto que:\n");
            printf("\n    - Nao e possivel fazer movimentos especiais como o roque.\n");
            printf("\nPara jogar, basta digitar a linha e a coluna correspondentes a peca que deseja movimentar.\n");
            printf("\nLogo depois, deve-se digitar a linha e a coluna para qual voce deseja se movimentar.\n\n");
            printf(" o 'p' representa o peao Branco\n");
            printf(" o 'P' representa o peao Preto\n");
            printf(" o 'c' representa o cavalo Branco\n");
            printf(" o 'C' representa o cavalo Preto\n");
            printf(" o 't' representa a torre Branco\n");
            printf(" o 'T' representa a torre Preto\n");
            printf(" o 'b' representa o bispo Branco\n");
            printf(" o 'B' representa o bispo Preto\n");
            printf(" o 'a' representa a rainha Branco\n");
            printf(" o 'A' representa a rainha Preto\n");
            printf(" o 'r' representa o rei Branco\n");
            printf(" o 'R' representa o rei Preto\n");
            system("pause");
            system("cls");
            break;


        case 3:
            printf("\t\t\t########## SOBRE ##########\n");
            printf("Jogo de xadrez desenvolvido para a disciplina de introducao a logica de programacao");
            printf("\n\t\t\t########## EQUIPE ########\n");
            printf("Abraao Lima Xavier Evangelista\n");
            printf("Bruno Correa Arvan\n");
            printf("Danilo Leone Di Paolo Martinelli Silva\n");
            printf("Stephanie Oliveira da Rocha\n\n\n");
            system("pause");
            system("cls");
            break;


        case 4:
            exit(0);
            break;

        default:
            printf("Opcao invalida!\n");
        }
    //fecha o Do while. Fica no la�o enquanto o usuario n�o selecionar a op��o 4(sair) ou 1(jogar)
    } while (opcoes != 4 || opcoes != 1);
//fecha o la�o que cria a menu
}

//fun��o selecao peca
void selecao_peca (char tabuleiro[10][10], char *ppeca){
   int linha, coluna, peca_valida, rodada, linhavelha, colunavelha;
   char peca, nomeJogador1[20], nomeJogador2[20];
   printf("Digite o nome do jogador 1\n");
   gets(nomeJogador1);
   printf("Digite o nome do jogador 2\n");
   gets(nomeJogador2);

   //loop infinito
   //rodada=vez de cada player
   for(rodada=0;;rodada++){

        // verifica��o de peca para player 1
        // player 1 pecas minusculas
        if(rodada%2==0){
                //la�o para fazer com que o player 1 selecione uma peca valida
                 do{

                    printf("%s (Player 1) digite uma peca a ser movida (minusculas) (linha x coluna) ou\n",&nomeJogador1);
                    printf("Digite 10 e 10 para voltar ao menu\n");
                    scanf("%d %d", &linha, &coluna);
                    //guardar a linha de onde a peca saiu
                    linhavelha=linha;
                    //guardar a coluna de onde a peca saiu
                    colunavelha=coluna;
                    //guardar peca
                    peca=tabuleiro[linha][coluna];
                    //guardar o local da peca
                    ppeca=&peca;
                    //op��o para voltar ao menu no meio do jogo
                    if(linha==10&&coluna==10){
                    printf("Voce sera redirecionda ao menu\n");
                    system("pause");
                    system("cls");
                    printar_menu(tabuleiro);
                    }

                    //verificando se o player 1 selecionou os espa�os internos da matrix
                    if((linha <= 8 && linha >= 1) && (coluna <= 8 && coluna >= 1)){
                         //verificando se o player 1 selecionou os espa�os vazios
                        if (tabuleiro[linha][coluna]=='-'){
                            peca_valida=0;//peca_valida=o segnifica invalida
                        }
                        else{
                            //verifica se o player 1 selecinou a peca minuscula
                            if (isupper(peca)!=1) {
                                peca_valida=1;//peca valida=1 significa valida

                            } else {
                                peca_valida=0;//peca_valida=o segnifica invalida
                            }
                        }
                    }
                    //verifica se o player 1 selecionou as coordenadas auxiliares ou estrapolou a matriz
                    else{
                        peca_valida=0;
                    }
                    //se o player 1 escolheu uma peca valida, colocar o nome da pe�a
                    if (peca_valida==1){
                        atualizar_tela(tabuleiro,&rodada);
                        switch(tabuleiro[linha][coluna]){

                           case'p':
                                printf("Voce selecionou o Peao! (%dx%d)\n",linha,coluna);

                                break;

                            case 't':
                                printf("Voce selecionou a Torre! (%dx%d)\n",linha,coluna);
                                break;

                            case'b':
                                printf("Voce selecionou o Bispo! (%dx%d)\n",linha,coluna);
                                break;

                            case'c':
                                printf("Voce selecionou o Cavalo! (%dx%d)\n",linha,coluna);
                                break;

                            case'r':
                                printf("Voce selecionou o Rei! (%dx%d)\n",linha,coluna);
                                break;

                            case'a':
                                printf("Voce selecionou a Rainha! (%dx%d)\n",linha,coluna);
                                break;

                            default:
                                printf("Peca invalida. (%dx%d)\n",linha,coluna);
                        }
                    }
                    else{
                        atualizar_tela(tabuleiro,&rodada);
                        printf("Peca invalida.\n\a");
                    }
                    //fecha o Do While
              //chama a fun��o que move a peca da posi��o original para a nova posi��o

            }while (peca_valida==0);

            mover_peca(tabuleiro, ppeca, &rodada, linhavelha, colunavelha, &peca_valida);

            //fecha o if que verifica se � o player1
            }

        //player 2
        else{
            //la�o para fazer com que o player 2 selecione uma peca valida
             do{
                printf("%s (Player 2) digite uma peca a ser movida (minusculas) (linha x coluna) ou\n",&nomeJogador2);
                printf("Digite 10 e 10 para voltar ao menu\n");
                scanf("%d %d", &linha, &coluna);
                //guardar a linha de onde a peca saiu
                linhavelha=linha;
                //guardar a coluna de onde a peca saiu
                colunavelha=coluna;
                //guardar a peca
                peca=tabuleiro[linha][coluna];
                //guardar o local desta peca
                ppeca=&peca;
                //op��o para voltar ao menu no meio do jogo
                if(linha==10&&coluna==10){
                    printf("Voce ser� redirecionda ao menu\n");
                    system("pause");
                    system("cls");
                    printar_menu(tabuleiro);
                }

                //verifica se o player 2 selecionou os espa�os dentro da matriz
                if((linha <= 8 && linha >= 1) && (coluna <= 8 && coluna >= 1)){
                    //verificando se o player 2 selecionou os espa�os vazios
                    if (tabuleiro[linha][coluna]=='-'){
                        peca_valida=0;//peca_valida=o segnifica invalida
                    }
                    else{
                        //verifica se o player 2 selecionou a peca maiscula
                        //isupper()=0 significa que n�o a variavel n�o � maiuscula
                         if (isupper(peca)!=0 ) {
                            peca_valida=1;//peca valida=1 significa valida
                        } else {
                            peca_valida=0;//peca_valida=o segnifica invalida
                        }
                    }

                //fim do se que verifica se a peca escolhida esta dentro da matrix
                }

                //verifica se o player 2 selecionou as coordenadas ou estrapolou a matriz
                else{
                    peca_valida=0;
                }

                //se o player 2 escolheu uma peca valida, colocar o nome da pe�a
                if (peca_valida==1){
                    atualizar_tela(tabuleiro,&rodada);
                    switch(tabuleiro[linha][coluna]){

                        case 'P':
                            printf("Voce selecionou o Peao! (%dx%d)\n",linha,coluna);
                            break;

                        case 'T':
                            printf("Voce selecionou a Torre! (%dx%d)\n",linha,coluna);
                            break;

                        case'B':
                            printf("Voce selecionou o Bispo! (%dx%d)\n",linha,coluna);
                            break;

                        case'C':
                            printf("Voce selecionou o Cavalo! (%dx%d)\n",linha,coluna);
                            break;

                        case'R':
                            printf("Voce selecionou o Rei! (%dx%d)\n",linha,coluna);
                            break;

                        case'A':
                            printf("Voce selecionou a Rainha! (%dx%d)\n",linha,coluna);
                            break;

                        default:
                            printf("Peca invalida.\n\a");
                    }
                }
                else{
                     atualizar_tela(tabuleiro,&rodada);
                     printf("Peca invalida.\n");
                }

        //fecha o Do While. Realiza o la�o enquanto ele tenha escolhido uma pe�a invalida
        }while (peca_valida==0);

        // chama a fun��o que move a pe�a da posi��o original para uma nova posi��o
        mover_peca(tabuleiro, ppeca, &rodada, linhavelha, colunavelha, &peca_valida);

    //fecha o else que enquadra o player 2
    }

  //fecha o for do la�o infinito
  }

//fecha a fun��o
}

// fun��o que move a peca da posi��o antiga para a nova
// tabuleiro[10][10]=tabuleiro que fica salva as pecas
// *ppeca=ponteiro que indica para a pe�a escolhida
// rodada=vez de cada jogador
// linhavelha=linha original da peca que ir� ser movida
// colunavelha=coluna original da peca que ir� ser movida
void mover_peca(char tabuleiro[10][10], char *ppeca, int *rodada, int linhavelha , int colunavelha, int *movimento_valido){
    //linha=linha que a pe�a ser� movida
    //coluna=coluna que a pe�a ser� movida
    int linha, coluna;
    //peca=peca que ser� movida
    char peca;
    //peca=a variavel para onde o ponteiro aponta que � justamente a peca escolhida pelo jogador
    peca = *ppeca;
    // la�o para fazer com que os jogadores coloquem as pe�as nos locais certos

    do{
        printf("Digite 0 e 0 para selecionar outra peca ou");
        printf("\nDigite a linha e a coluna para onde voce quer mover a peca '%c' que esta na posicao:%dx%d\n",peca , linhavelha, colunavelha);
        //linha e coluna para aonde a pe�a ser� movida
        scanf("%d %d", &linha, &coluna);

        //Se o player digitar 0 e 0 a fun��o retorna para o la�o de sele��o de pe�a
        if((linha==0)&&(coluna==0)){
            //para evitar que quando volte para a fun��o de sele��o de peca, n�o v� para o jogador seguinte
            *rodada=*rodada+1;
            *movimento_valido=1;
            atualizar_tela(tabuleiro,rodada);

           }

        else{

        // realizar os movimentos distintos de cada pe�a
        switch(peca){

            case'p':
                validar_movimento_peaop (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posi��o escolhida pelo jogador ser� colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posi��o de onde a peca escolhida saiu ser� substituida por um espa�o vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a fun��o que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case 't':
                validar_movimento_torret (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posi��o escolhida pelo jogador ser� colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posi��o de onde a peca escolhida saiu ser� substituida por um espa�o vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a fun��o que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case'b':
                validar_movimento_bispob (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posi��o escolhida pelo jogador ser� colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posi��o de onde a peca escolhida saiu ser� substituida por um espa�o vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a fun��o que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case'c':
                validar_movimento_cavaloc (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posi��o escolhida pelo jogador ser� colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posi��o de onde a peca escolhida saiu ser� substituida por um espa�o vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a fun��o que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case'r':
                validar_movimento_reir (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posi��o escolhida pelo jogador ser� colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posi��o de onde a peca escolhida saiu ser� substituida por um espa�o vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a fun��o que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case'a':
                validar_movimento_rainhar (tabuleiro, linha, coluna,  linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posi��o escolhida pelo jogador ser� colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posi��o de onde a peca escolhida saiu ser� substituida por um espa�o vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a fun��o que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case 'P':
                validar_movimento_peaoP (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posi��o escolhida pelo jogador ser� colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posi��o de onde a peca escolhida saiu ser� substituida por um espa�o vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a fun��o que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case 'T':
                validar_movimento_torreT (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posi��o escolhida pelo jogador ser� colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posi��o de onde a peca escolhida saiu ser� substituida por um espa�o vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a fun��o que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case'B':
                //fun��o que rege o movimento do bispo
                validar_movimento_bispoB (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posi��o escolhida pelo jogador ser� colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posi��o de onde a peca escolhida saiu ser� substituida por um espa�o vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a fun��o que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case'C':
                validar_movimento_cavaloC (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posi��o escolhida pelo jogador ser� colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posi��o de onde a peca escolhida saiu ser� substituida por um espa�o vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a fun��o que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case'R':
                validar_movimento_reiR (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posi��o escolhida pelo jogador ser� colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posi��o de onde a peca escolhida saiu ser� substituida por um espa�o vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a fun��o que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case'A':
                validar_movimento_rainhaR (tabuleiro, linha, coluna,  linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posi��o escolhida pelo jogador ser� colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posi��o de onde a peca escolhida saiu ser� substituida por um espa�o vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a fun��o que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);

                }
                break;

            default:
                printf("\nMovimento invalido.\a\n");

            }

            //fun��o que verifica se o jogo acabou
            check_mate (tabuleiro);

        }
        // se o movimento n�o for valido, printa na tela que n�o � valido
        if(*movimento_valido==0){
            // limpa a tela
            atualizar_tela(tabuleiro,rodada);
            printf("\nMovimento invalido.\a\n");
        }
        }while(*movimento_valido==0);

}

// tabuleiro[10][10]=tabuleiro do jogo
// rodada=vez de cada jogador
void atualizar_tela ( char tabuleiro[10][10], int *rodada){
    //linha=linha que ir� ser usada para construir a nova matrix(tabuleiro)
    //coluna=coluna que ir� ser usada para construir a nova matrix(tabuleiro)
    int linha, coluna, aux;
    //limpar a matrix(tabuleiro) anterior
    system("cls");

    if(*rodada<=0){
        printf("#################Rodada 0#################\n\n");

    }
    else{
        printf("#################Rodada %d#################\n\n", *rodada);

    }
    //printar a matriz na tela
    //varrer as linhas da matrix
    // varrendo as linhas para colocar o backgroud e as pecas
    for (linha = 0; linha < 10; linha++){
        // /////// aux=0
        // ///x/// aux=1
        // /////// aux=2
        for(aux=0; aux<3; aux++){
            // varrendo as colunas para colocar o backgroud e as pecas
            for (coluna = 0; coluna < 10; coluna++){
                // verificando se � os espa�os internos da matrix
                if((linha <= 8 && linha >= 1) && (coluna <= 8 && coluna >= 1)){
                    // se o valor de aux for par, � para colocar os backgrounds
                    if(aux%2==0){
                            // se o valor de coluna+linha for par colocar o backgroud branco
                            if((coluna+linha)%2!=0){
                                // colocando o background branco
                                printf("\xDb\xDb\xDb\xDb\xDb");
                            }
                            // se o valor de coluna+linha for impar colocar o backgroud branco
                            else{
                                // colocando o background preto. como o fundo do DOS � preto, basta colocar espa�os vazios
                                printf("     ");
                            }
                    }
                    // printar a peca no meio do background
                    else{
                            // se o valor de coluna+linha for par colocar uma peca entre o backgroud branco
                            if((coluna+linha)%2!=0){
                                // colocando a peca entre o background branco
                                printf("\xDb\xDb%c\xDb\xDb", tabuleiro[linha][coluna]);
                            }
                            // se o valor de coluna+linha for par colocar uma peca entre o backgroud branco
                            else{
                                // colocando a peca entre o background preto
                                printf("  %c  ", tabuleiro[linha][coluna]);
                            }
                    }
                }
                //se n�o forem os espa�os internos e sim as coordenadas auxiliares
                else{
                        //se for a primeira linha ou a ultima
                        if((linha==0)||(linha==9)){
                            // para colocar o espacameto nas coordenadas. entre o primeiro e o segundo termo, e entre o oitavo e o nono
                            if((coluna==0)||(coluna==8)){
                                // printar s� uma vez
                                if(aux%2!=0){
                                    printf("%c  ", tabuleiro[linha][coluna]);
                                }
                            }
                            // para colocar o espacameto nas coordenadas
                            else{
                                // printar s� uma vez
                                if(aux%2!=0){
                                    // para colocar o espacameto nas coordenadas
                                    printf("%c    ", tabuleiro[linha][coluna]);
                                }
                            }

                        }
                        // nas outras laterais
                        else{
                            // printar s� uma vez
                            if(aux%2!=0){
                                printf("%c", tabuleiro[linha][coluna]);
                            }
                            // centralizar a coordenada auxiliar
                            else{
                                printf(" ");
                            }
                        }
                }
            }
            // pular uma linha
            printf("\n");
        }
    }
//fecha a fun��o
}

// fun��o para mover o bispo minusculo
void validar_movimento_bispob (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido){
    int contlinha, contcoluna, NaoEntraMais=0;//variavel criada para evitar que a fun��o entre em todos os la�os se uma op��o inicial for falsa
    *movimento_valido=0;
    // se o bispo se mover na diagonal
    //abs retorna o valor em modulo da opera��o(absoluto)
    if (abs((coluna-colunavelha)) == abs((linha-linhavelha))){
         // descendo o tabuleiro
         if (linhavelha<linha&&NaoEntraMais==0){
            //da direita para a esquerda
            if(colunavelha>coluna){
                // se ele se locomover uma posi��o
                if(abs(linhavelha-linha)==1){
                    // se no local de destino tiver uma peca
                            if(isalpha(tabuleiro[linha][coluna])!=0){
                                // se essa peca for maiuscula
                                if(isupper(tabuleiro[linha][coluna])!=0){
                                    // o bispo pode andar e comer
                                    *movimento_valido=1;
                                }
                                else{
                                    // o bispo n�o pode andar e comer
                                    *movimento_valido=0;
                                }
                            }
                            // se no local de destino tiver um espa�o vazio
                            else{
                                // o bispo pode andar
                                *movimento_valido=1;
                            }

                }
                else{
                    //fun��o que verifica se no intervalo entre a posi��o original e a final tem alguma peca
                    for (contlinha=linhavelha, contcoluna=coluna; contlinha<linha, contcoluna<colunavelha; contlinha++, contcoluna++){
                        // se tiver peca
                        if(tabuleiro[contlinha][contcoluna]!='-'){
                            // o bispo n�o pode andar e comer a peca
                            *movimento_valido=0;
                        }
                        // se n�o tiverem pecas no intervalo
                        else{
                            // se no local de destino tiver uma peca
                            if(isalpha(tabuleiro[linha][coluna])!=0){
                                // se essa peca for maiuscula
                                if(isupper(tabuleiro[linha][coluna])!=0){
                                    // o bispo pode andar e comer
                                    *movimento_valido=1;
                                }
                                else{
                                    // o bispo n�o pode andar e comer
                                    *movimento_valido=0;
                                }
                            }
                            // se no local de destino tiver um espa�o vazio
                            else{
                                // o bispo pode andar
                                *movimento_valido=1;
                            }
                        }
                    }
                }
            }
            //da esquerda para a direita
            if(colunavelha<coluna){
                // se ele se locomover uma posi��o
                if(abs(linhavelha-linha)==1){
                    // se no local de destino tiver uma peca
                            if(isalpha(tabuleiro[linha][coluna])!=0){
                                // se essa peca for maiuscula
                                if(isupper(tabuleiro[linha][coluna])!=0){
                                    // o bispo pode andar e comer
                                    *movimento_valido=1;
                                }
                                else{
                                    // o bispo n�o pode andar e comer
                                    *movimento_valido=0;
                                }
                            }
                            // se no local de destino tiver um espa�o vazio
                            else{
                                // o bispo pode andar
                                *movimento_valido=1;
                            }

                    }
                else{
                    //fun��o que verifica se no intervalo entre a posi��o original e a final tem alguma peca
                    for (contlinha=linhavelha, contcoluna=colunavelha; contlinha<linha, contcoluna<coluna; contlinha++, contcoluna++){
                        // se tiver peca
                        if(tabuleiro[contlinha][contcoluna]!='-'){
                            // o bispo n�o pode andar e comer a peca
                            *movimento_valido=0;
                        }
                        else{
                            // se no local de destino tiver uma peca
                            if(isalpha(tabuleiro[linha][coluna])!=0){
                                // se essa peca for maiuscula
                                if(isupper(tabuleiro[linha][coluna])!=0){
                                    // o bispo pode andar e comer
                                    *movimento_valido=1;
                                }
                                else{
                                    // o bispo n�o pode andar e comer
                                    *movimento_valido=0;
                                }
                            }
                            // se no local de destino tiver um espa�o vazio
                            else{
                                // o bispo pode andar
                                *movimento_valido=1;
                            }
                        }
                    }
                }
            }
            NaoEntraMais=1;
         }
        // subindo o tabuleiro
        if (linha<linhavelha&&NaoEntraMais==0){
            //da direita para a esquerda
            if(colunavelha>coluna){
                // se ele se locomover uma posi��o
                if(abs(linhavelha-linha)==1){
                    // se no local de destino tiver uma peca
                            if(isalpha(tabuleiro[linha][coluna])!=0){
                                // se essa peca for maiuscula
                                if(isupper(tabuleiro[linha][coluna])!=0){
                                    // o bispo pode andar e comer
                                    *movimento_valido=1;
                                }
                                else{
                                    // o bispo n�o pode andar e comer
                                    *movimento_valido=0;
                                }
                            }
                            // se no local de destino tiver um espa�o vazio
                            else{
                                // o bispo pode andar
                                *movimento_valido=1;
                            }

                }
                // se ele se locomover varias posi�oes
                else{
                    //fun��o que verifica se no intervalo entre a posi��o original e a final tem alguma peca
                    for (contlinha=linha, contcoluna=coluna; contlinha<linhavelha, contcoluna<colunavelha; contlinha++, contcoluna++){
                        // se tiver peca
                        if(tabuleiro[contlinha][contcoluna]!='-'){
                            // o bispo n�o pode andar e comer a peca
                            *movimento_valido=0;
                        }
                        else{
                            // se no local de destino tiver uma peca
                            if(isalpha(tabuleiro[linha][coluna])!=0){
                                // se essa peca for maiuscula
                                if(isupper(tabuleiro[linha][coluna])!=0){
                                    // o bispo pode andar e comer
                                    *movimento_valido=1;
                                }
                                else{
                                    // o bispo pode andar e comer
                                    *movimento_valido=0;
                                }
                            }
                            // se no local de destino tiver um espa�o vazio
                            else{
                                // o bispo pode andar
                                *movimento_valido=1;
                            }
                        }
                    }
                }
            }
            //da esquerda para a direita
            if(colunavelha<coluna){
                // se ele se locomover uma posi��o
                if(abs(linhavelha-linha)==1){
                    // se no local de destino tiver uma peca
                            if(isalpha(tabuleiro[linha][coluna])!=0){
                                // se essa peca for maiuscula
                                if(isupper(tabuleiro[linha][coluna])!=0){
                                    // o bispo pode andar e comer
                                    *movimento_valido=1;
                                }
                                else{
                                    // o bispo n�o pode andar e comer
                                    *movimento_valido=0;
                                }
                            }
                            // se no local de destino tiver um espa�o vazio
                            else{
                                // o bispo pode andar
                                *movimento_valido=1;
                            }

                }
                else{
                    //fun��o que verifica se no intervalo entre a posi��o original e a final tem alguma peca
                    for (contlinha=linha, contcoluna=colunavelha; contlinha<linhavelha, contcoluna<coluna; contlinha++, contcoluna++){
                        // se tiver peca
                        if(tabuleiro[contlinha][contcoluna]!='-'){
                            // o bispo n�o pode andar e comer a peca
                            *movimento_valido=0;

                        }
                        else{
                            // se no local de destino tiver uma peca
                            if(isalpha(tabuleiro[linha][coluna])!=0){
                                // se essa peca for maiuscula
                                if(isupper(tabuleiro[linha][coluna])!=0){
                                    // o bispo pode andar e comer
                                    *movimento_valido=1;
                                }
                                else{
                                    // o bispo pode andar e comer
                                    *movimento_valido=0;
                                }
                            }
                            // se no local de destino tiver um espa�o vazio
                            else{
                                // o bispo pode andar
                                *movimento_valido=1;
                            }
                        }
                    }
                }
            }
        }
        NaoEntraMais=1;
    }
}

// fun��o para mover o bispo minusculo
void validar_movimento_bispoB (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido){
    int contlinha, contcoluna, NaoEntraMais=0;//variavel criada para evitar que a fun��o entre em todos os la�os se uma op��o inicial for falsa
    *movimento_valido=0;
    // se o bispo se mover na diagonal
    //abs retorna o valor em modulo da opera��o(absoluto)
    if (abs((coluna-colunavelha)) == abs((linha-linhavelha))){
         // descendo o tabuleiro
         if (linhavelha<linha&&NaoEntraMais==0){
            //da direita para a esquerda
            if(colunavelha>coluna){
                // se ele se locomover uma posi��o
                if(abs(linhavelha-linha)==1){
                    // se no local de destino tiver uma peca
                            if(isalpha(tabuleiro[linha][coluna])!=0){
                                // se essa peca for minuscula
                                if(islower(tabuleiro[linha][coluna])!=0){
                                    // o bispo pode andar e comer
                                    *movimento_valido=1;
                                }
                                else{
                                    // o bispo n�o pode andar e comer
                                    *movimento_valido=0;
                                }
                            }
                            // se no local de destino tiver um espa�o vazio
                            else{
                                // o bispo pode andar
                                *movimento_valido=1;
                            }

                }
                else{
                    //fun��o que verifica se no intervalo entre a posi��o original e a final tem alguma peca
                    for (contlinha=linhavelha, contcoluna=coluna; contlinha<linha, contcoluna<colunavelha; contlinha++, contcoluna++){
                        // se tiver peca
                        if(tabuleiro[contlinha][contcoluna]!='-'){
                            // o bispo n�o pode andar e comer a peca
                            *movimento_valido=0;
                        }
                        // se n�o tiverem pecas no intervalo
                        else{
                            // se no local de destino tiver uma peca
                            if(isalpha(tabuleiro[linha][coluna])!=0){
                                // se essa peca for minuscula
                                if(islower(tabuleiro[linha][coluna])!=0){
                                    // o bispo pode andar e comer
                                    *movimento_valido=1;
                                }
                                else{
                                    // o bispo n�o pode andar e comer
                                    *movimento_valido=0;
                                }
                            }
                            // se no local de destino tiver um espa�o vazio
                            else{
                                // o bispo pode andar
                                *movimento_valido=1;
                            }
                        }
                    }
                }
            }
            //da esquerda para a direita
            if(colunavelha<coluna){
                // se ele se locomover uma posi��o
                if(abs(linhavelha-linha)==1){
                    // se no local de destino tiver uma peca
                            if(isalpha(tabuleiro[linha][coluna])!=0){
                                // se essa peca for minuscula
                                if(islower(tabuleiro[linha][coluna])!=0){
                                    // o bispo pode andar e comer
                                    *movimento_valido=1;
                                }
                                else{
                                    // o bispo n�o pode andar e comer
                                    *movimento_valido=0;
                                }
                            }
                            // se no local de destino tiver um espa�o vazio
                            else{
                                // o bispo pode andar
                                *movimento_valido=1;
                            }

                    }
                else{
                    //fun��o que verifica se no intervalo entre a posi��o original e a final tem alguma peca
                    for (contlinha=linhavelha, contcoluna=colunavelha; contlinha<linha, contcoluna<coluna; contlinha++, contcoluna++){
                        // se tiver peca
                        if(tabuleiro[contlinha][contcoluna]!='-'){
                            // o bispo n�o pode andar e comer a peca
                            *movimento_valido=0;
                        }
                        else{
                            // se no local de destino tiver uma peca
                            if(isalpha(tabuleiro[linha][coluna])!=0){
                                // se essa peca for minuscula
                                if(islower(tabuleiro[linha][coluna])!=0){
                                    // o bispo pode andar e comer
                                    *movimento_valido=1;
                                }
                                else{
                                    // o bispo n�o pode andar e comer
                                    *movimento_valido=0;
                                }
                            }
                            // se no local de destino tiver um espa�o vazio
                            else{
                                // o bispo pode andar
                                *movimento_valido=1;
                            }
                        }
                    }
                }
            }
            NaoEntraMais=1;
         }
        // subindo o tabuleiro
        if (linha<linhavelha&&NaoEntraMais==0){
            //da direita para a esquerda
            if(colunavelha>coluna){
                // se ele se locomover uma posi��o
                if(abs(linhavelha-linha)==1){
                    // se no local de destino tiver uma peca
                            if(isalpha(tabuleiro[linha][coluna])!=0){
                               // se essa peca for minuscula
                                if(islower(tabuleiro[linha][coluna])!=0){
                                    // o bispo pode andar e comer
                                    *movimento_valido=1;
                                }
                                else{
                                    // o bispo n�o pode andar e comer
                                    *movimento_valido=0;
                                }
                            }
                            // se no local de destino tiver um espa�o vazio
                            else{
                                // o bispo pode andar
                                *movimento_valido=1;
                            }

                }
                // se ele se locomover varias posi�oes
                else{
                    //fun��o que verifica se no intervalo entre a posi��o original e a final tem alguma peca
                    for (contlinha=linha, contcoluna=coluna; contlinha<linhavelha, contcoluna<colunavelha; contlinha++, contcoluna++){
                        // se tiver peca
                        if(tabuleiro[contlinha][contcoluna]!='-'){
                            // o bispo n�o pode andar e comer a peca
                            *movimento_valido=0;
                        }
                        else{
                            // se no local de destino tiver uma peca
                            if(isalpha(tabuleiro[linha][coluna])!=0){
                               // se essa peca for minuscula
                                if(islower(tabuleiro[linha][coluna])!=0){
                                    // o bispo pode andar e comer
                                    *movimento_valido=1;
                                }
                                else{
                                    // o bispo pode andar e comer
                                    *movimento_valido=0;
                                }
                            }
                            // se no local de destino tiver um espa�o vazio
                            else{
                                // o bispo pode andar
                                *movimento_valido=1;
                            }
                        }
                    }
                }
            }
            //da esquerda para a direita
            if(colunavelha<coluna){
                // se ele se locomover uma posi��o
                if(abs(linhavelha-linha)==1){
                    // se no local de destino tiver uma peca
                            if(isalpha(tabuleiro[linha][coluna])!=0){
                                // se essa peca for minuscula
                                if(islower(tabuleiro[linha][coluna])!=0){
                                    // o bispo pode andar e comer
                                    *movimento_valido=1;
                                }
                                else{
                                    // o bispo n�o pode andar e comer
                                    *movimento_valido=0;
                                }
                            }
                            // se no local de destino tiver um espa�o vazio
                            else{
                                // o bispo pode andar
                                *movimento_valido=1;
                            }

                }
                else{
                    //fun��o que verifica se no intervalo entre a posi��o original e a final tem alguma peca
                    for (contlinha=linha, contcoluna=colunavelha; contlinha<linhavelha, contcoluna<coluna; contlinha++, contcoluna++){
                        // se tiver peca
                        if(tabuleiro[contlinha][contcoluna]!='-'){
                            // o bispo n�o pode andar e comer a peca
                            *movimento_valido=0;

                        }
                        else{
                            // se no local de destino tiver uma peca
                            if(isalpha(tabuleiro[linha][coluna])!=0){
                               // se essa peca for minuscula
                                if(islower(tabuleiro[linha][coluna])!=0){
                                    // o bispo pode andar e comer
                                    *movimento_valido=1;
                                }
                                else{
                                    // o bispo pode andar e comer
                                    *movimento_valido=0;
                                }
                            }
                            // se no local de destino tiver um espa�o vazio
                            else{
                                // o bispo pode andar
                                *movimento_valido=1;
                            }
                        }
                    }
                }
            }
        }
        NaoEntraMais=1;
    }
}

// fun��o para mover o cavalo minusculo
void validar_movimento_cavaloc (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido){
    *movimento_valido=0;
        if(((linhavelha-linha==2)&&(colunavelha-coluna==1)) || ((linhavelha-linha==1)&&(colunavelha-coluna==2)) || ((linha-linhavelha==1)&&(colunavelha-coluna==2)) || ((linha-linhavelha==2)&&(colunavelha-coluna==1)) || ((linhavelha-linha==2)&&(coluna-colunavelha==1)) || ((linhavelha-linha==1)&&(coluna-colunavelha==2)) || ((linha-linhavelha==1)&&(coluna-colunavelha==2)) || ((linha-linhavelha==2)&&(coluna-colunavelha==1))){
            // se no local de destino tiver uma peca
                if(isalpha(tabuleiro[linha][coluna])!=0){
                    // se esta peca for maiuscula
                    if(isupper(tabuleiro[linha][coluna])!=0){
                        // O cavalo pode comer e andar
                        *movimento_valido=1;
                        }
                        else{
                            // O cavalo n�o pode comer e andar
                            *movimento_valido=0;
                        }
                    }
                    // Se o local do destino estiver vazio
                    if(tabuleiro[linha][coluna]=='-'){
                        //O cavalo pode andar
                        *movimento_valido=1;
                    }
    }
    if(*movimento_valido==1){
        printf("Movimento valido\n");
    }
    else{
        printf("Movimento invalido\n");
    }
}

// fun��o para mover o cavalo maiusculo
void validar_movimento_cavaloC (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido){
    *movimento_valido=0;
        if(((linhavelha-linha==2)&&(colunavelha-coluna==1)) || ((linhavelha-linha==1)&&(colunavelha-coluna==2)) || ((linha-linhavelha==1)&&(colunavelha-coluna==2)) || ((linha-linhavelha==2)&&(colunavelha-coluna==1)) || ((linhavelha-linha==2)&&(coluna-colunavelha==1)) || ((linhavelha-linha==1)&&(coluna-colunavelha==2)) || ((linha-linhavelha==1)&&(coluna-colunavelha==2)) || ((linha-linhavelha==2)&&(coluna-colunavelha==1))){
            // se no local de destino tiver uma peca
                if(isalpha(tabuleiro[linha][coluna])!=0){
                    // se esta peca for minuscula
                    if(islower(tabuleiro[linha][coluna])!=0){
                        // O cavalo pode comer e andar
                        *movimento_valido=1;
                        }
                    else{
                        // O cavalo n�o pode comer e andar
                        *movimento_valido=0;
                    }
                }
                // Se o local do destino estiver vazio
                if(tabuleiro[linha][coluna]=='-'){
                    //O cavalo pode andar
                    *movimento_valido=1;
                }
    }
    if(*movimento_valido==1){
        printf("Movimento valido\n");
    }
    else{
        printf("Movimento invalido\n");
    }
}

// fun��o para mover a torre pequena
void validar_movimento_torret (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido){
int cont, NaoEntraMais=0; //variavel criada para evitar que a fun��o entre em todos os la�os se uma op��o inicial for falsa
    *movimento_valido=0;
    // Se a torre andar na vertical
    if ((colunavelha==coluna) && (linhavelha!= linha) && (NaoEntraMais==0)){
        //se atorre estiver descendo
        if (linhavelha<linha){
            //verifica se existe alguma peca no intervalo entre a posi��o partida e a posi��a de destino da torre
            for (cont=linhavelha; cont<linha; cont++){
                // se encontrar alguma peca o movimento � invalido
                if(tabuleiro[cont][coluna]!='-'){
                    // a torre n�o pode andar
                    *movimento_valido=0;
                }
            }
            // se no local de destino tiver uma peca
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se esta peca for minuscula
                if(isupper(tabuleiro[linha][coluna])!=0){
                    // A torre pode comer e andar
                    *movimento_valido=1;
                }
                else{
                    // a torre n�o pode comer e andar
                    *movimento_valido=0;
                }
            }
            // se tiver um espa�o vazio
            if(tabuleiro[linha][coluna]=='-'){
                *movimento_valido=1;
            }
        }
        // se a torre estiver subindo
        if (linha<linhavelha){
            // verificando se no intervalo entre a posi��o de destino e a posi��o de origem tem alguma peca
            for (cont=linha; cont<linhavelha; cont++){
                // setiver alguma peca
                if(tabuleiro[cont][coluna]!='-'){
                    //o movimento � invalido
                    *movimento_valido=0;
                }
            }
            // se no local de destino tiver uma peca
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se esta peca for minuscula
                if(isupper(tabuleiro[linha][coluna])!=0){
                    // A torre pode comer e andar
                    *movimento_valido=1;
                }
                else{
                    // a torre n�o pode comer e andar
                    *movimento_valido=0;
                }
            }
            // se tiver um espa�o vazio
            else{
                *movimento_valido=1;
            }
        }
        // se entrar neste la�o a fun��o n�o entra nos outros
        NaoEntraMais=1;
    }
    // se a torre se mover na horinzontal
    if((linhavelha==linha) && (colunavelha!=coluna) && (NaoEntraMais==0)){
        //da esquerda para a direita
        if(colunavelha<coluna){
            // la�o que verifica se intervalo entre a posi��o final e a inicial tem alguma peca
            for (cont=colunavelha; cont<coluna; cont++){
                //se tiver alguma peca
                if(tabuleiro[linha][cont]!='-'){
                    //a torre n�o pode andar
                    *movimento_valido=0;
                }
            }
            // se no local de destino tiver uma peca
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se esta peca for minuscula
                if(isupper(tabuleiro[linha][coluna])!=0){
                    // A torre pode comer e andar
                    *movimento_valido=1;
                }
                else{
                    // a torre n�o pode comer e andar
                    *movimento_valido=0;
                }
            }
            // se tiver um espa�o vazio
            else{
                *movimento_valido=1;
            }
        }

        //da direita para a esquerda
        if (coluna<colunavelha){
        // verificando se no intervalo entre a posi��o de destino e a posi��o de origem tem alguma peca
            for (cont=coluna; cont<colunavelha; cont++){
                // se tiver alguma letra no intervalo
                if(tabuleiro[linha][cont]!='-'){
                    // a torre n�o pode andar
                    *movimento_valido=0;
                }
            }
            //se no local de destino tiver uma peca
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se esta peca for minuscula
                if(isupper(tabuleiro[linha][coluna])!=0){
                    // A torre pode comer e andar
                    *movimento_valido=1;
                }
                else{
                    // a torre n�o pode comer e andar
                    *movimento_valido=0;
                }
            }
            // se tiver um espa�o vazio
            else{
                *movimento_valido=1;
            }
        }
    //n�o entra em mais nenhum la�o
    NaoEntraMais=1;
    }
    if (*movimento_valido==1){
        printf("\nMovimento valido\n");
    }
    else{
        printf("\nMovimento invalido\n");
    }
}

// fun��o para mover a torre grande
void validar_movimento_torreT (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido){
    int cont, NaoEntraMais=0; //variavel criada para evitar que a fun��o entre em todos os la�os se uma op��o inicial for falsa
    *movimento_valido=0;
    // Se a torre andar na vertical
    if ((colunavelha==coluna) && (linhavelha!= linha) && (NaoEntraMais==0)){
        //se atorre estiver descendo
        if (linhavelha<linha){
            //verifica se existe alguma peca no intervalo entre a posi��o partida e a posi��a de destino da torre
            for (cont=linhavelha; cont<linha; cont++){
                // se encontrar alguma peca o movimento � invalido
                if(tabuleiro[cont][coluna]!='-'){
                    // a torre n�o pode andar
                    *movimento_valido=0;
                }
            }
                    // se no local de destino tiver uma peca
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se esta peca for minuscula
                if(islower(tabuleiro[linha][coluna])!=0){
                    // A torre pode comer e andar
                    *movimento_valido=1;
                }
                else{
                    // a torre n�o pode comer e andar
                    *movimento_valido=0;
                }
            }
            // se tiver um espa�o vazio
            if(tabuleiro[linha][coluna]=='-'){
                *movimento_valido=1;
            }
        }
        // se a torre estiver subindo
        if (linha<linhavelha){
            // verificando se no intervalo entre a posi��o de destino e a posi��o de origem tem alguma peca
            for (cont=linha; cont<linhavelha; cont++){
                // setiver alguma peca
                if(tabuleiro[cont][coluna]!='-'){
                    //o movimento � invalido
                    *movimento_valido=0;

                }
            }
            // se no local de destino tiver uma peca
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se esta peca for minuscula
                if(islower(tabuleiro[linha][coluna])!=0){
                    // A torre pode comer e andar
                    *movimento_valido=1;
                }
                else{
                    // a torre n�o pode comer e andar
                    *movimento_valido=0;
                }
            }
            // se tiver um espa�o vazio
            else{
                *movimento_valido=1;
            }
        }
        // se entrar neste la�o a fun��o n�o entra nos outros
        NaoEntraMais=1;
    }
    // se a torre se mover na horinzontal
    if((linhavelha==linha) && (colunavelha!=coluna) && (NaoEntraMais==0)){
        //da esquerda para a direita
        if(colunavelha<coluna){
            // la�o que verifica se intervalo entre a posi��o final e a inicial tem alguma peca
            for (cont=colunavelha; cont<coluna; cont++){
                //se tiver alguma peca
                if(tabuleiro[linha][cont]!='-'){
                    //a torre n�o pode andar
                    *movimento_valido=0;
                }
            }
            // se no local de destino tiver uma peca
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se esta peca for minuscula
                if(islower(tabuleiro[linha][coluna])!=0){
                    // A torre pode comer e andar
                    *movimento_valido=1;
                }
                else{
                    // a torre n�o pode comer e andar
                    *movimento_valido=0;
                }
            }
            // se tiver um espa�o vazio
            else{
                *movimento_valido=1;
            }
        }

        //da direita para a esquerda
        if (coluna<colunavelha){
        // verificando se no intervalo entre a posi��o de destino e a posi��o de origem tem alguma peca
            for (cont=coluna; cont<colunavelha; cont++){
                // se tiver alguma letra no intervalo
                if(tabuleiro[linha][cont]!='-'){
                    // a torre n�o pode andar
                    *movimento_valido=0;
                }
            }
            //se no local de destino tiver uma peca
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se esta peca for minuscula
                if(islower(tabuleiro[linha][coluna])!=0){
                    // A torre pode comer e andar
                    *movimento_valido=1;
                }
                else{
                    // a torre n�o pode comer e andar
                    *movimento_valido=0;
                }
            }
            // se tiver um espa�o vazio
            else{
                *movimento_valido=1;
            }
        }
    //n�o entra em mais nenhum la�o
    NaoEntraMais=1;
    }
    if (*movimento_valido==1){
        printf("\nMovimento valido\n");
    }
    else{
        printf("\nMovimento invalido\n");
    }
}

// fun��o para mover a rainha pequena
void validar_movimento_rainhar (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido){
    // a rainha tem a mesma liberdade do bispo
    validar_movimento_bispob(tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
    // se o movimento da rainha n�o corresponder com o movimento do bispo
    if(*movimento_valido==0){
        // a rainha tem a mesma liberdade da torre
        validar_movimento_torret(tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
    }

}

// fun��o para mover a rainha grande
void validar_movimento_rainhaR (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido){
   // a rainha tem a mesma liberdade do bispo
    validar_movimento_bispoB(tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
    // se o movimento da rainha n�o corresponder com o movimento do bispo
    if(*movimento_valido==0){
        // a rainha tem a mesma liberdade da torre
        validar_movimento_torret(tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
    }

}

// fun��o para mover o rei pequeno
void validar_movimento_reir (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido){
    *movimento_valido = 0;

        if (linhavelha == linha && colunavelha == coluna - 1) {
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se essa letra for minuscula
                if(isupper(tabuleiro[linha][coluna])!=0){
                    //significa que ele pode andar e comer a peca do adversario
                    *movimento_valido=1;
                }
                else{
                    //significa que ele n�o pode andar e comer a peca do adversario
                    *movimento_valido=0;
                }
            } else {
                if (tabuleiro[linha][coluna]=='-') {
                    *movimento_valido=1;
                }
            }
        }
        if (linhavelha == linha && colunavelha == coluna + 1) {
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se essa letra for minuscula
                if(isupper(tabuleiro[linha][coluna])!=0){
                    //significa que ele pode andar e comer a peca do adversario
                    *movimento_valido=1;
                }
                else{
                    //significa que ele n�o pode andar e comer a peca do adversario
                    *movimento_valido=0;
                }
            } else {
                if (tabuleiro[linha][coluna]=='-') {
                    *movimento_valido=1;
                }
            }
        }
        if (colunavelha == coluna && linhavelha == linha - 1) {
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se essa letra for minuscula
                if(isupper(tabuleiro[linha][coluna])!=0){
                    //significa que ele pode andar e comer a peca do adversario
                    *movimento_valido=1;
                }
                else{
                    //significa que ele n�o pode andar e comer a peca do adversario
                    *movimento_valido=0;
                }
            } else {
                if (tabuleiro[linha][coluna]=='-') {
                    *movimento_valido=1;
                }
            }
        }
        if (colunavelha == coluna && linhavelha == linha + 1) {
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se essa letra for minuscula
                if(isupper(tabuleiro[linha][coluna])!=0){
                    //significa que ele pode andar e comer a peca do adversario
                    *movimento_valido=1;
                }
                else{
                    //significa que ele n�o pode andar e comer a peca do adversario
                    *movimento_valido=0;
                }
            } else {
                if (tabuleiro[linha][coluna]=='-') {
                    *movimento_valido=1;
                }
            }
        }
        if (colunavelha == coluna + 1 && linhavelha == linha + 1) {
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se essa letra for minuscula
                if(isupper(tabuleiro[linha][coluna])!=0){
                    //significa que ele pode andar e comer a peca do adversario
                    *movimento_valido=1;
                }
                else{
                    //significa que ele n�o pode andar e comer a peca do adversario
                    *movimento_valido=0;
                }
            } else {
                if (tabuleiro[linha][coluna]=='-') {
                    *movimento_valido=1;
                }
            }
        }
        if (colunavelha == coluna + 1 && linhavelha == linha - 1) {
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se essa letra for minuscula
                if(isupper(tabuleiro[linha][coluna])!=0){
                    //significa que ele pode andar e comer a peca do adversario
                    *movimento_valido=1;
                }
                else{
                    //significa que ele n�o pode andar e comer a peca do adversario
                    *movimento_valido=0;
                }
            } else {
                if (tabuleiro[linha][coluna]=='-') {
                    *movimento_valido=1;
                }
            }
        }
        if (colunavelha == coluna - 1 && linhavelha == linha - 1) {
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se essa letra for minuscula
                if(isupper(tabuleiro[linha][coluna])!=0){
                    //significa que ele pode andar e comer a peca do adversario
                    *movimento_valido=1;
                }
                else{
                    //significa que ele n�o pode andar e comer a peca do adversario
                    *movimento_valido=0;
                }
            } else {
                if (tabuleiro[linha][coluna]=='-') {
                    *movimento_valido=1;
                }
            }
        }
        if (colunavelha == coluna - 1 && linhavelha == linha + 1) {
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se essa letra for minuscula
                if(isupper(tabuleiro[linha][coluna])!=0){
                    //significa que ele pode andar e comer a peca do adversario
                    *movimento_valido=1;
                }
                else{
                    //significa que ele n�o pode andar e comer a peca do adversario
                    *movimento_valido=0;
                }
            } else {
                if (tabuleiro[linha][coluna]=='-') {
                    *movimento_valido=1;
                }
            }
        }

}

// fun��o para mover o rei grande
void validar_movimento_reiR (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido){
    *movimento_valido = 0;

        if (linhavelha == linha && colunavelha == coluna - 1) {
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se essa letra for minuscula
                if(islower(tabuleiro[linha][coluna])!=0){
                    //significa que ele pode andar e comer a peca do adversario
                    *movimento_valido=1;
                }
                else{
                    //significa que ele n�o pode andar e comer a peca do adversario
                    *movimento_valido=0;
                }
            } else {
                if (tabuleiro[linha][coluna]=='-') {
                    *movimento_valido=1;
                }
            }
        }
        if (linhavelha == linha && colunavelha == coluna + 1) {
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se essa letra for minuscula
                if(islower(tabuleiro[linha][coluna])!=0){
                    //significa que ele pode andar e comer a peca do adversario
                    *movimento_valido=1;
                }
                else{
                    //significa que ele n�o pode andar e comer a peca do adversario
                    *movimento_valido=0;
                }
            } else {
                if (tabuleiro[linha][coluna]=='-') {
                    *movimento_valido=1;
                }
            }
        }
        if (colunavelha == coluna && linhavelha == linha - 1) {
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se essa letra for minuscula
                if(islower(tabuleiro[linha][coluna])!=0){
                    //significa que ele pode andar e comer a peca do adversario
                    *movimento_valido=1;
                }
                else{
                    //significa que ele n�o pode andar e comer a peca do adversario
                    *movimento_valido=0;
                }
            } else {
                if (tabuleiro[linha][coluna]=='-') {
                    *movimento_valido=1;
                }
            }
        }
        if (colunavelha == coluna && linhavelha == linha + 1) {
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se essa letra for minuscula
                if(islower(tabuleiro[linha][coluna])!=0){
                    //significa que ele pode andar e comer a peca do adversario
                    *movimento_valido=1;
                }
                else{
                    //significa que ele n�o pode andar e comer a peca do adversario
                    *movimento_valido=0;
                }
            } else {
                if (tabuleiro[linha][coluna]=='-') {
                    *movimento_valido=1;
                }
            }
        }
        if (colunavelha == coluna + 1 && linhavelha == linha + 1) {
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se essa letra for minuscula
                if(islower(tabuleiro[linha][coluna])!=0){
                    //significa que ele pode andar e comer a peca do adversario
                    *movimento_valido=1;
                }
                else{
                    //significa que ele n�o pode andar e comer a peca do adversario
                    *movimento_valido=0;
                }
            } else {
                if (tabuleiro[linha][coluna]=='-') {
                    *movimento_valido=1;
                }
            }
        }
        if (colunavelha == coluna + 1 && linhavelha == linha - 1) {
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se essa letra for minuscula
                if(islower(tabuleiro[linha][coluna])!=0){
                    //significa que ele pode andar e comer a peca do adversario
                    *movimento_valido=1;
                }
                else{
                    //significa que ele n�o pode andar e comer a peca do adversario
                    *movimento_valido=0;
                }
            } else {
                if (tabuleiro[linha][coluna]=='-') {
                    *movimento_valido=1;
                }
            }
        }
        if (colunavelha == coluna - 1 && linhavelha == linha - 1) {
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se essa letra for minuscula
                if(islower(tabuleiro[linha][coluna])!=0){
                    //significa que ele pode andar e comer a peca do adversario
                    *movimento_valido=1;
                }
                else{
                    //significa que ele n�o pode andar e comer a peca do adversario
                    *movimento_valido=0;
                }
            } else {
                if (tabuleiro[linha][coluna]=='-') {
                    *movimento_valido=1;
                }
            }
        }
        if (colunavelha == coluna - 1 && linhavelha == linha + 1) {
            if(isalpha(tabuleiro[linha][coluna])!=0){
                // se essa letra for minuscula
                if(islower(tabuleiro[linha][coluna])!=0){
                    //significa que ele pode andar e comer a peca do adversario
                    *movimento_valido=1;
                }
                else{
                    //significa que ele n�o pode andar e comer a peca do adversario
                    *movimento_valido=0;
                }
            } else {
                if (tabuleiro[linha][coluna]=='-') {
                    *movimento_valido=1;
                }
            }
        }

}

//fun��o para mover o peao grande
void validar_movimento_peaoP (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha, int *movimento_valido){
    int NaoEntraMais=0; //variavel criada para evitar que a fun��o entre em todos os la�os se uma op��o inicial for falsa
    *movimento_valido=0;
    //quando o pe�o se desloca na diagonal esquerda
    if((colunavelha-coluna==1) && (linha-linhavelha==1) && (NaoEntraMais==0)){
        // para um local que tenha uma letra
        if(isalpha(tabuleiro[linha][coluna])!=0){
            // se essa letra for minuscula
            if(islower(tabuleiro[linha][coluna])!=0){
                //significa que ele pode andar e comer a peca do adversario
                *movimento_valido=1;
            }
            else{
                //significa que ele n�o pode andar e comer a peca do adversario
                *movimento_valido=0;
            }
        }
        // se n�o for uma letra e sim um espa�o vazio, ele n�o pode andar
        if(tabuleiro[linha][coluna]=='-'){
            *movimento_valido=0;
        }
        // a fun��o n�o entra nas condi�oes subsequentes
        NaoEntraMais=1;
    }
    //quando o pe�o se desloca na diagonal direita
    if((coluna-colunavelha==1) && (linha-linhavelha==1) && (NaoEntraMais==0)){
        // para um local que tenha uma letra
        if(isalpha(tabuleiro[linha][coluna])!=0){
             // se essa letra for minuscula
            if(islower(tabuleiro[linha][coluna])!=0){
                //significa que ele pode andar e comer a peca do adversario
                *movimento_valido=1;
            }
            else{
                //significa que ele n�o pode andar e comer a peca do adversario
                *movimento_valido=0;
            }
        }
        // se n�o for uma letra e sim um espa�o vazio, ele n�o pode andar
        if(tabuleiro[linha][coluna]=='-'){
            *movimento_valido=0;
        }
        // a fun��o n�o entra nas condi�oes subsequentes
        NaoEntraMais=1;
    }
     // se o peao andar para frente
    if ((coluna==colunavelha) && (linha-linhavelha==1) && (NaoEntraMais==0)){
        // para um local onde tenha uma letra
        if(isalpha(tabuleiro[linha][coluna])!=0){
            // ele n�o pode andar e comer. obs peao n�o come para frente
            *movimento_valido=0;
        }
        //para um local onde tenha um espa�o vazio
        if(tabuleiro[linha][coluna]=='-'){
            //ele pode andar
            *movimento_valido=1;
        }
        // a fun��o n�o entra nas condi�oes subsequentes
        NaoEntraMais=1;
    }
    // se for o primeiro movimento do peao ele pode andar duas casas para frente
    if ((linhavelha==2) && (coluna==colunavelha) && (linha-linhavelha==2) && (NaoEntraMais==0)){
        *movimento_valido=1;
        NaoEntraMais=1;
    }
    if (*movimento_valido==1){
        printf("\nMovimento valido\n");
    }
    else{
        printf("\nMovimento invalido\n");
    }
}

//fun��o para mover o peao pequeno
void validar_movimento_peaop (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha, int *movimento_valido){
   int NaoEntraMais=0; //variavel criada para evitar que a fun��o entre em todos os la�os se uma op��o inicial for falsa
   *movimento_valido=0;
    //quando o pe�o se desloca na diagonal esquerda
    if((colunavelha-coluna==1) && (linhavelha-linha==1) && (NaoEntraMais==0)){
        // para um local que tenha uma letra
        if(isalpha(tabuleiro[linha][coluna])!=0){
            // se essa letra for maiuscula
            if((isupper(tabuleiro[linha][coluna])!=0)){
                //significa que ele pode andar e comer a peca do adversario
                *movimento_valido=1;
            }
            else{
                //significa que ele n�o pode andar e comer a peca do adversario
                *movimento_valido=0;
            }
        }
         // se n�o for uma letra e sim um espa�o vazio, ele n�o pode andar
        if(tabuleiro[linha][coluna]=='-'){
            *movimento_valido=0;
        }
        // a fun��o n�o entra nas condi�oes subsequentes
        NaoEntraMais=1;
    }
    //quando o pe�o se desloca na diagonal direita
    if((coluna-colunavelha==1) && (linhavelha-linha==1) && (NaoEntraMais==0)){
        // para um local que tenha uma letra
        if(isalpha(tabuleiro[linha][coluna])!=0){
            // se essa letra for maiuscula
            if((isupper(tabuleiro[linha][coluna])!=0)){
                //significa que ele pode andar e comer a peca do adversario
                *movimento_valido=1;
            }
            else{
                //significa que ele n�o pode andar e comer a peca do adversario
                *movimento_valido=0;
            }
        }
         // se n�o for uma letra e sim um espa�o vazio, ele n�o pode andar
        if(tabuleiro[linha][coluna]=='-'){
            *movimento_valido=0;
        }
        // a fun��o n�o entra nas condi�oes subsequentes
        NaoEntraMais=1;
    }
    // se o peao andar para frente
    if ((coluna==colunavelha) && (linhavelha-linha==1) && (NaoEntraMais==0)){
        // para um local que tenha uma letra
        if(isalpha(tabuleiro[linha][coluna])!=0){
            // ele n�o pode andar e comer. obs peao n�o come para frente
            *movimento_valido=0;
            }
        //para um local onde tenha um espa�o vazio
        if(tabuleiro[linha][coluna]=='-'){
            //ele pode andar
            *movimento_valido=1;
        }
        // a fun��o n�o entra nas condi�oes subsequentes
        NaoEntraMais=1;
    }
    // se for o primeiro movimento do peao ele pode andar duas casas para frente
    if ((linhavelha==7) && (coluna==colunavelha) && (linhavelha-linha==2) && (NaoEntraMais==0)){
        *movimento_valido=1;
        // a fun��o n�o entra nas condi�oes subsequentes
        NaoEntraMais=1;
    }
    if (*movimento_valido==1){
        printf("\nMovimento valido\n");
    }
    else{
        printf("\nMovimento invalido\n");
    }
}

//fun��o que verifica o fim do jogo
void check_mate (char tabuleiro[10][10]){
    int linha, coluna;
    int rei_vivo=0;// significa que o rei minusculo come�a o jogo morto
    int Rei_vivo=0;// significa que o rei maiusculo come�a o jogo morto
    char peca;
    //fun��o para rodar a matrix e verificar a presen�a dos reis
    for (linha=0;linha<10;linha++){
        for(coluna=0;coluna<10;coluna++){
            peca=tabuleiro[linha][coluna];
            // se a fun��o encontrar o rei minusculo siginifica dizer que ele esta vivo
            if(peca=='r'){
                rei_vivo=1;

            }
            // se a fun��o encontrar o rei maisculo siginifica dizer que ele esta vivo
            if(peca=='R'){
                Rei_vivo=1;

            }
        }
    }
    // se n�o for encontrado o rei minusculo, significa dizer o plater um perdeu
    if(rei_vivo==0){
        //limpa a tela
        system("cls");
        //mostra o perdedor, player 1 (pecas minusculas)
        printf("\n\aPlayer 1 perdeu. Check Mate\a\n");
        printf("\aParabens Player 2\a\n");
        printf("\aGame Over\a\n");
        system("pause");
        //limpa a tela
        system("cls");
        //retorna para o menu
        printar_menu(tabuleiro);

    }
    if(Rei_vivo==0){
        //limpa a tela
        system("cls");
        //mostra o perdedor, player  (pecas maiusculas)
        printf("\n\aPlayer 2 perdeu. Check Mate\a\n");
        printf("aParabens player 1\a\n");
        printf("\aGame Over\a\n");
        system("pause");
        //limpa a tela
        system("cls");
        //retorna para o menu
        printar_menu(tabuleiro);

    }


}



