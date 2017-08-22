#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Desenhar tabuleiro na tela:
void tabuleiro_em_tela(char tabuleiro[10][10]);
// Desenhar a função na tela
void printar_menu(char tabuleiro[10][10]);
//função para selecionar a peça
void selecao_peca (char tabuleiro[10][10], char *ppeca);
//função para atualizar a tela
void atualizar_tela ( char tabuleiro[10][10], int *rodada);
//função do movimento do bispo pequeno
void validar_movimento_bispob (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido);
//função do movimento do bispo grande
void validar_movimento_bispoB (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido);
//função do movimento do cavalo
void validar_movimento_cavalo (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido);
//função do movimento da torre pequena
void validar_movimento_torret (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido);
//função do movimento da torre grande
void validar_movimento_torreT (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido);
//função do movimento da rainha
void validar_movimento_rainha (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido);
//função do movimento do rei
void validar_movimento_rei (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido);
//função do movimento do peão minusculo
void validar_movimento_peaop (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha, int *movimento_valido);
//função do movimento do peão maisculo
void validar_movimento_peaoP (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha, int *movimento_valido);
//função que move a peca
void mover_peca(char tabuleiro[10][10], char *ppeca, int *rodada, int linhavelha , int colunavelha, int *movimento_valido);
//função que verifica se ocorreu check e mate
void check_mate (char tabuleiro[10][10]);

//Função principal
int main(){
    int menu;
    char tabuleiro[10][10];
    printar_menu(tabuleiro);

    return 0;
}

//função criar tabuleiro
void tabuleiro_em_tela(char tabuleiro[10][10]){
    int linha, coluna;
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

    //colocando os espaços vazios
    for (linha = 3; linha < 7; linha++)
    {
        for (coluna = 1; coluna < 9; coluna++)
        {
            tabuleiro[linha][coluna] = '-';
        }
    }
    //Colocando peças do jogador de cima, branca
    tabuleiro[1][1] = 'T';
    tabuleiro[1][2] = 'C';
    tabuleiro[1][3] = 'B';
    tabuleiro[1][4] = 'R';
    tabuleiro[1][5] = 'A';
    tabuleiro[1][6] = 'B';
    tabuleiro[1][7] = 'C';
    tabuleiro[1][8] = 'T';

    //colocando os peões brancos
    for (coluna = 1; coluna < 9; coluna++)
    {
        tabuleiro[2][coluna] = 'P';
    }
    //Colocando peças do jogador de baixo
    tabuleiro[8][1] = 't';
    tabuleiro[8][2] = 'c';
    tabuleiro[8][3] = 'b';
    tabuleiro[8][4] = 'r';
    tabuleiro[8][5] = 'a';
    tabuleiro[8][6] = 'b';
    tabuleiro[8][7] = 'c';
    tabuleiro[8][8] = 't';

    //colocar os peões pretos
    for (coluna = 1; coluna < 9; coluna++)
    {
        tabuleiro[7][coluna] = 'p';
    }

    //colocando as barras da quina
    for (linha = 0; linha < 10; linha++)
    {
        for (coluna = 0; coluna < 10; coluna++)
        {
            if (linha == 0 && coluna == 0 || linha == 0 && coluna == 9 || linha == 9 && coluna == 0 || linha == 9 && coluna == 9)
            {
                tabuleiro[linha][coluna] = '|';
            }
            printf("%c\t", tabuleiro[linha][coluna]);
        }
        printf("\n\n\n\n");
    }
}

//função criar o menu
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
        printf("\t\t\t```````````````````````````+++@@@@@@@;````````````````````````````````````````\n");
        printf("\t\t\t``````````````````````````++#@'#'#@@@;.```````````````````````````````````````\n");
        printf("\t\t\t`````````````````````````;+#@,#@..:@@@@+;.````````````````````````````````````\n");
        printf("\t\t\t`````````````````````````##+@+'''@@@@@@@@+;::..```````````````````````````````\n");
        printf("\t\t\t````````````````````````'+@@,@'@@@@@@@@@@@@@##+';:.```````````````````````````\n");
        printf("\t\t\t````````````````````````+#@@`@@@@@@@@' @@@@@@@@@,@;.``````````````````````````\n");
        printf("\t\t\t````````````````````````##@, @@@@@@@@` @#@@@@@@@+@@:``````````````````````````\n");
        printf("\t\t\t````````````````````````#@## @@@@@@@@@@@+@@@@@@##@@#,`````````````````````````\n");
        printf("\t\t\t```````````````````````.#@@@`@@@@@@@@@@@++#@@@@@@@@'.`````````````````````````\n");
        printf("\t\t\t```````````````````````.#@#;`@@+'#@@@@@@@@@@@@@;::::.`````````````````````````\n");
        printf("\t\t\t````````````````````````#@#;`@@@@'@@@@@@@@@@@@@@@@@+,`````````````````````````\n");
        printf("\t\t\t````````````````````````+@@@ @@@@'#@@@@@:@@@@#+@@@+,``````````````````````````\n");
        printf("\t\t\t````````````````````````###@`@@@@#'@@@@@@@;:::;@@;,```````````````````````````\n");
        printf("\t\t\t````````````````````````++@;,#@@@@'@@@@#;;;.``.:::````````````````````````````\n");
        printf("\t\t\t````````````````````````,#@@+:@@@@+''';'#@#;.```.,````````````````````````````\n");
        printf("\t\t\t`````````````````````````+#@@ @@@@@@@@@@@@@#:,````````````````````````````````\n");
        printf("\t\t\t`````````````````````````++@@,@@@@@@@@@@@:@@#:.```````````````````````````````\n");
        printf("\t\t\t`````````````````````````,+@+';@@@@@@.,#@@@+@+:.``````````````````````````````\n");
        printf("\t\t\t``````````````````````````+#@# @@@@@@+,@+,#@@@':.`````````````````````````````\n");
        printf("\t\t\t``````````````````````````++@@'@@@@@@@`#@@@@@@@':`````````````````````````````\n");
        printf("\t\t\t``````````````````````````.+@#+:@@@@@##.@@@@@@@@;:````````````````````````````\n");
        printf("\t\t\t`````````````````````````..+#@'`@@@@@@@,'@@@@@@@@:.```````````````````````````\n");
        printf("\t\t\t```````````````````````````++@@;@@@@@@@@`#@@@@@@@@,```````````````````````````\n");
        printf("\t\t\t```````````````````````````;+@@@+@@@@@@@@`@@@@@@@@+,``````````````````````````\n");
        printf("\t\t\t`.``````````````````````.`.:+@@#:@@@@@@@@@ @@@@@@@@,```.``````````````````````\n");
        printf("\t\t\t`..`````````````````````.``'+@#:.@@@@@@@@@@ @@@@@@@+,`.```````````````````````\n");
        printf("\t\t\t`........................`.++@@#:@@@@@@@@@@@;@@@@@@;,........................`\n");
        printf("\t\t\t`.......................`.`++@@@#@@@@@@@@@@@,@@@@@',`........................`\n");
        printf("\t\t\t`.........................:+#@#'@@@@@@@@@@@@@#@@@@,..........................`\n");
        printf("\t\t\t`.........................++@@;'@@@@@@@@@@@@@+@@@@,.`........................`\n");
        printf("\t\t\t`........................,++@+:@@@@@@@@@@@@@@#@@@#:`.........................`\n");
        printf("\t\t\t`.......................`++@@#@@@@@@@@@@@@@@@@@@@#,..........................`\n");
        printf("\t\t\t........................'++#@@@@@@@@@@@@@@@@@@@@@@,...........................\n");
        printf("\t\t\t.........................,#++++##@@@@@@@@@@@@#+;:,:,..........................\n");
        printf("\t\t\t...........................:++#+''''';;;;;;;::;+::............................\n");
        printf("\t\t\t...........................++#@@@@@@@@@@@@@@@@@@;:,...........................\n");
        printf("\t\t\t..........................;++@@+@@@@@@@@@@@@@@#@@+,:..........................\n");
        printf("\t\t\t..........................++@@;@@@@@@@@@@@@@@@@+@@@,,.........................\n");
        printf("\t\t\t.........................++@@.@@@@@@@@@@@@@@@@@@,@@+,,........................\n");
        printf("\t\t\t.........................++@#@@@@@@@@@@@@@@@@@@@@:@@,,........................\n");
        printf("\t\t\t.........................++@;@@@@@@@@@@@@@@@@@@@@;@#,.........................\n");
        printf("\t\t\t.........................#+#@@@@@@@@@@@@@@@@@@@@@@@,,.........................\n");
        printf("\t\t\t.........................'+++++##@@@@@@@@@@@@@#+::,;,.........................\n");
        printf("\t\t\t.........................'+@@##+''''';;;;;;::::;+@@#,.........................\n");
        printf("\t\t\t........................,'#`@#@@@@@@@@@@@@@@@@#@;@ #,.........................\n");
        printf("\t\t\t.,,,,,,,,,,,,,,,,,,,,,,.:+#`@,@,@,@:@#@@'@,@`@`@`@ #,..,,,,,,,,,,,,,,,,,,,,,,.\n");
        printf("\t\t\t.,,,,,,,,,,,,,,,,,,,,,,+#++ @.@`@`@ @'@@.@ @ @ @`@ ;,,,.,,,,,,,,,,,,,,,,,,,,,.\n");
        printf("\t\t\t.,,,,,,,,,,,,,,,,,,,,,,#+#+`+`#`@`@ @;@@`@ @ @ @`:.++,,,,,,,,,,,,,,,,,,,,,,,,,\n");
        printf("\t\t\t.,,,,,,,,,,,,,,,,,,,,.,##@@@@#+.'`'`':''`; ; :.'#@@@@,,,,,,,,,,,,,,,,,,,,,,,,,\n");
        printf("\t\t\t.,,,,,,,,,,,,,,,,,,,,,,:#+#@@@@@@@@@@@@@@@@@@@@@@@+:,,,,,,,,,,,,,,,,,,,,,,,,,,\n");

        printf("\n\n\t\t\t\t\t\t1-Jogar\n\n \t\t\t\t\t\t2-Ajuda\n\n \t\t\t\t\t\t3-Sobre o jogo\n\n \t\t\t\t\t\t4-Sair\n\n");
        printf("######################################################################################################################################\n");
        scanf("%d", &opcoes);
        getchar();
        system("cls");
        char ppeca;


    // opções do menu
    switch(opcoes){
        case 1:
            //printa o menu na tela
            tabuleiro_em_tela(tabuleiro);
            //seleciona a peça. As funções restantes estão dentro desta
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
    //fecha o Do while. Fica no laço enquanto o usuario não selecionar a opção 4(sair) ou 1(jogar)
    } while (opcoes != 4 || opcoes != 1);
//fecha o laço que cria a menu
}

//função selecao peca
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

        // verificação de peca para player 1
        // player 1 pecas minusculas
        if(rodada%2==0){
                //laço para fazer com que o player 1 selecione uma peca valida
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
                    //opção para voltar ao menu no meio do jogo
                    if(linha==10&&coluna==10){
                    printf("Voce sera redirecionda ao menu\n");
                    system("pause");
                    system("cls");
                    printar_menu(tabuleiro);
                    }

                    //verificando se o player 1 selecionou os espaços internos da matrix
                    if((linha <= 8 && linha >= 1) && (coluna <= 8 && coluna >= 1)){
                         //verificando se o player 1 selecionou os espaços vazios
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
                    //se o player 1 escolheu uma peca valida, colocar o nome da peça
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
              //chama a função que move a peca da posição original para a nova posição

            }while (peca_valida==0);

            mover_peca(tabuleiro, ppeca, &rodada, linhavelha, colunavelha, &peca_valida);

            //fecha o if que verifica se é o player1
            }

        //player 2
        else{
            //laço para fazer com que o player 2 selecione uma peca valida
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
                //opção para voltar ao menu no meio do jogo
                if(linha==10&&coluna==10){
                    printf("Voce será redirecionda ao menu\n");
                    system("pause");
                    system("cls");
                    printar_menu(tabuleiro);
                }

                //verifica se o player 2 selecionou os espaços dentro da matriz
                if((linha <= 8 && linha >= 1) && (coluna <= 8 && coluna >= 1)){
                    //verificando se o player 2 selecionou os espaços vazios
                    if (tabuleiro[linha][coluna]=='-'){
                        peca_valida=0;//peca_valida=o segnifica invalida
                    }
                    else{
                        //verifica se o player 2 selecionou a peca maiscula
                        //isupper()=0 significa que não a variavel não é maiuscula
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

                //se o player 2 escolheu uma peca valida, colocar o nome da peça
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

        //fecha o Do While. Realiza o laço enquanto ele tenha escolhido uma peça invalida
        }while (peca_valida==0);

        // chama a função que move a peça da posição original para uma nova posição
        mover_peca(tabuleiro, ppeca, &rodada, linhavelha, colunavelha, &peca_valida);

    //fecha o else que enquadra o player 2
    }

  //fecha o for do laço infinito
  }

//fecha a função
}

// função que move a peca da posição antiga para a nova
// tabuleiro[10][10]=tabuleiro que fica salva as pecas
// *ppeca=ponteiro que indica para a peça escolhida
// rodada=vez de cada jogador
// linhavelha=linha original da peca que irá ser movida
// colunavelha=coluna original da peca que irá ser movida
void mover_peca(char tabuleiro[10][10], char *ppeca, int *rodada, int linhavelha , int colunavelha, int *movimento_valido){
    //linha=linha que a peça será movida
    //coluna=coluna que a peça será movida
    int linha, coluna;
    //peca=peca que será movida
    char peca;
    //peca=a variavel para onde o ponteiro aponta que é justamente a peca escolhida pelo jogador
    peca = *ppeca;
    // laço para fazer com que os jogadores coloquem as peças nos locais certos

    do{
        printf("Digite 0 e 0 para selecionar outra peca ou");
        printf("\nDigite a linha e a coluna para onde voce quer mover a peca '%c' que esta na posicao:%dx%d\n",peca , linhavelha, colunavelha);
        //linha e coluna para aonde a peça será movida
        scanf("%d %d", &linha, &coluna);

        //Se o player digitar 0 e 0 a função retorna para o laço de seleção de peça
        if((linha==0)&&(coluna==0)){
            //para evitar que quando volte para a função de seleção de peca, não vá para o jogador seguinte
            *rodada=*rodada+1;
            *movimento_valido=1;
            atualizar_tela(tabuleiro,rodada);

           }

        else{

        // realizar os movimentos distintos de cada peça
        switch(peca){

            case'p':
                validar_movimento_peaop (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posição escolhida pelo jogador será colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posição de onde a peca escolhida saiu será substituida por um espaço vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a função que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case 't':
                validar_movimento_torret (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posição escolhida pelo jogador será colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posição de onde a peca escolhida saiu será substituida por um espaço vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a função que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case'b':
                validar_movimento_bispob (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posição escolhida pelo jogador será colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posição de onde a peca escolhida saiu será substituida por um espaço vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a função que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case'c':
                validar_movimento_cavalo (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posição escolhida pelo jogador será colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posição de onde a peca escolhida saiu será substituida por um espaço vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a função que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case'r':
                validar_movimento_rei (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posição escolhida pelo jogador será colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posição de onde a peca escolhida saiu será substituida por um espaço vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a função que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case'a':
                validar_movimento_rainha (tabuleiro, linha, coluna,  linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posição escolhida pelo jogador será colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posição de onde a peca escolhida saiu será substituida por um espaço vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a função que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case 'P':
                validar_movimento_peaoP (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posição escolhida pelo jogador será colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posição de onde a peca escolhida saiu será substituida por um espaço vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a função que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case 'T':
                validar_movimento_torreT (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posição escolhida pelo jogador será colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posição de onde a peca escolhida saiu será substituida por um espaço vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a função que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case'B':
                //função que rege o movimento do bispo
                validar_movimento_bispoB (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posição escolhida pelo jogador será colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posição de onde a peca escolhida saiu será substituida por um espaço vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a função que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case'C':
                validar_movimento_cavalo (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posição escolhida pelo jogador será colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posição de onde a peca escolhida saiu será substituida por um espaço vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a função que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case'R':
                validar_movimento_rei (tabuleiro, linha, coluna, linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posição escolhida pelo jogador será colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posição de onde a peca escolhida saiu será substituida por um espaço vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a função que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);
                }
                break;

            case'A':
                validar_movimento_rainha (tabuleiro, linha, coluna,  linhavelha, colunavelha, movimento_valido);
                if(*movimento_valido==1){
                    //atribuindo que na posição escolhida pelo jogador será colocado a peca escolhida pelo jogador
                    tabuleiro[linha][coluna] = peca;
                    //atribuindo que na posição de onde a peca escolhida saiu será substituida por um espaço vazio
                    tabuleiro[linhavelha][colunavelha] = '-';
                    //chama a função que apaga a matrix antiga e desenha a nova matrix
                    atualizar_tela(tabuleiro,rodada);

                }
                break;

            default:
                printf("\nMovimento invalido.\a\n");

            }

            //função que verifica se o jogo acabou
            check_mate (tabuleiro);

        }
        // se o movimento não for valido, printa na tela que não é valido
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
    //linha=linha que irá ser usada para construir a nova matrix(tabuleiro)
    //coluna=coluna que irá ser usada para construir a nova matrix(tabuleiro)
    int linha, coluna;
    //limpar a matrix(tabuleiro) anterior
    system("cls");

    if(*rodada<=0){
        printf("\t\t#################Rodada 0#################\n\n\n");

    }
    else{
        printf("\t\t#################Rodada %d#################\n\n\n", *rodada);

    }
    //printar a matriz na tela
    //varrer as linhas da matrix
    for(linha=0;linha<10;linha++){
        //varrer as colunas da matrix
        for(coluna=0;coluna<10;coluna++){
            printf("%c\t",tabuleiro[linha][coluna]);

        }
        //pular as linhas entre as peças
        printf("\n\n\n\n");
    //fecha  o laço
    }
//fecha a função
}

// função para mover o bispo grande
void validar_movimento_bispoB (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido){
    int contlinha, contcoluna, NaoEntraMais=0;//variavel criada para evitar que a função entre em todos os laços se uma opção inicial for falsa
    *movimento_valido=0;
    // se o bispo se mover na diagonal
    //abs retorna o valor em modulo da operação(absoluto)
    if (abs((coluna-colunavelha)) == abs((linha-linhavelha))){
         // descendo o tabuleiro
         if (linhavelha<linha&&NaoEntraMais==0){
            //da direita para a esquerda
            if(colunavelha>coluna){
                //função que verifica se no intervalo entre a posição original e a final tem alguma peca
                for (contlinha=linhavelha, contcoluna=coluna; contlinha<=linha, contcoluna<=colunavelha; contlinha++, contcoluna++){
                    // se tiver peca
                    if(tabuleiro[contlinha][contcoluna]!='-'){
                        // o bispo não pode andar e comer a peca
                        *movimento_valido=0;
                    }
                    // se não tiverem pecas no intervalo
                    else{
                        // se no local de destino tiver uma peca
                        if(isalpha(tabuleiro[linha][coluna])!=0){
                            // se essa peca for minuscula
                            if(islower(tabuleiro[linha][coluna])!=0){
                                // o bispo pode andar e comer
                                *movimento_valido=1;
                            }
                            else{
                                // o bispo não pode andar e comer
                                *movimento_valido=0;
                            }
                        }
                        // se no local de destino tiver um espaço vazio
                        else{
                            // o bispo pode andar
                            *movimento_valido=1;
                        }
                    }
                }
            }
            //da esquerda para a direita
            if(colunavelha<coluna){
                //função que verifica se no intervalo entre a posição original e a final tem alguma peca
                for (contlinha=linhavelha, contcoluna=colunavelha; contlinha<linha, contcoluna<coluna; contlinha++, contcoluna++){
                    // se tiver peca
                    if(tabuleiro[contlinha][contcoluna]!='-'){
                        // o bispo não pode andar e comer a peca
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
                                // o bispo não pode andar e comer
                                *movimento_valido=0;
                            }
                        }
                        // se no local de destino tiver um espaço vazio
                        else{
                            // o bispo pode andar
                            *movimento_valido=1;
                        }
                    }
                }
            }
            NaoEntraMais=1;
         }
        // subindo o tabuleiro
        if (linha<linhavelha&&NaoEntraMais==0){
            printf("fui chamado 1");
            getchar();
            //da direita para a esquerda
            if(colunavelha>coluna){
                printf("fui chamado 2");
                getchar();
                //função que verifica se no intervalo entre a posição original e a final tem alguma peca
                for (contlinha=linha, contcoluna=coluna; contlinha<linhavelha, contcoluna<colunavelha; contlinha++, contcoluna++){
                    printf("fui chamado 3");
                    getchar();
                    // se tiver peca
                    if(tabuleiro[contlinha][contcoluna]!='-'){
                        // o bispo não pode andar e comer a peca
                        *movimento_valido=0;

                    }
                    else{
                        printf("fui chamado 4");
                        getchar();
                        // se no local de destino tiver uma peca
                        if(isalpha(tabuleiro[linha][coluna])!=0){
                            printf("fui chamado 5");
                            getchar();
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
                        // se no local de destino tiver um espaço vazio
                        else{
                            printf("fui chamado 6");
                            getchar();
                            // o bispo pode andar
                            *movimento_valido=1;
                        }
                    }
                }
            }
            //da esquerda para a direita
            if(colunavelha<coluna){
                //função que verifica se no intervalo entre a posição original e a final tem alguma peca
                for (contlinha=linha, contcoluna=colunavelha; contlinha<linhavelha, contcoluna<coluna; contlinha++, contcoluna++){
                    // se tiver peca
                    if(tabuleiro[contlinha][contcoluna]!='-'){
                        // o bispo não pode andar e comer a peca
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
                        // se no local de destino tiver um espaço vazio
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
}

// função para mover o bispo pequeno
void validar_movimento_bispob (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido){
    int contlinha, contcoluna, NaoEntraMais=0;//variavel criada para evitar que a função entre em todos os laços se uma opção inicial for falsa
    *movimento_valido=0;
    // se o bispo se mover na diagonal
    //abs retorna o valor em modulo da operação(absoluto)
    if (abs((coluna-colunavelha)) == abs((linha-linhavelha))){
         // descendo o tabuleiro
         if (linhavelha<linha&&NaoEntraMais==0){
            //da direita para a esquerda
            if(colunavelha>coluna){
                //função que verifica se no intervalo entre a posição original e a final tem alguma peca
                for (contlinha=linhavelha, contcoluna=coluna; contlinha<=linha, contcoluna<=colunavelha; contlinha++, contcoluna++){
                    // se tiver peca
                    if(tabuleiro[contlinha][contcoluna]!='-'){
                        // o bispo não pode andar e comer a peca
                        *movimento_valido=0;
                    }
                    // se não tiverem pecas no intervalo
                    else{
                        // se no local de destino tiver uma peca
                        if(isalpha(tabuleiro[linha][coluna])!=0){
                            // se essa peca for maiuscula
                            if(isupper(tabuleiro[linha][coluna])!=0){
                                // o bispo pode andar e comer
                                *movimento_valido=1;
                            }
                            else{
                                // o bispo não pode andar e comer
                                *movimento_valido=0;
                            }
                        }
                        // se no local de destino tiver um espaço vazio
                        else{
                            // o bispo pode andar
                            *movimento_valido=1;
                        }
                    }
                }
            }
            //da esquerda para a direita
            if(colunavelha<coluna){
                //função que verifica se no intervalo entre a posição original e a final tem alguma peca
                for (contlinha=linhavelha, contcoluna=colunavelha; contlinha<linha, contcoluna<coluna; contlinha++, contcoluna++){
                    // se tiver peca
                    if(tabuleiro[contlinha][contcoluna]!='-'){
                        // o bispo não pode andar e comer a peca
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
                                // o bispo não pode andar e comer
                                *movimento_valido=0;
                            }
                        }
                        // se no local de destino tiver um espaço vazio
                        else{
                            // o bispo pode andar
                            *movimento_valido=1;
                        }
                    }
                }
            }
            NaoEntraMais=1;
         }
        // subindo o tabuleiro
        if (linha<linhavelha&&NaoEntraMais==0){
            printf("fui chamado 1");
            getchar();
            //da direita para a esquerda
            if(colunavelha>coluna){
                printf("fui chamado 2");
                getchar();
                //função que verifica se no intervalo entre a posição original e a final tem alguma peca
                for (contlinha=linha, contcoluna=coluna; contlinha<linhavelha, contcoluna<colunavelha; contlinha++, contcoluna++){
                    printf("fui chamado 3");
                    getchar();
                    // se tiver peca
                    if(tabuleiro[contlinha][contcoluna]!='-'){
                        // o bispo não pode andar e comer a peca
                        *movimento_valido=0;

                    }
                    else{
                        printf("fui chamado 4");
                        getchar();
                        // se no local de destino tiver uma peca
                        if(isalpha(tabuleiro[linha][coluna])!=0){
                            printf("fui chamado 5");
                            getchar();
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
                        // se no local de destino tiver um espaço vazio
                        else{
                            printf("fui chamado 6");
                            getchar();
                            // o bispo pode andar
                            *movimento_valido=1;
                        }
                    }
                }
            }
            //da esquerda para a direita
            if(colunavelha<coluna){
                //função que verifica se no intervalo entre a posição original e a final tem alguma peca
                for (contlinha=linha, contcoluna=colunavelha; contlinha<linhavelha, contcoluna<coluna; contlinha++, contcoluna++){
                    // se tiver peca
                    if(tabuleiro[contlinha][contcoluna]!='-'){
                        // o bispo não pode andar e comer a peca
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
                        // se no local de destino tiver um espaço vazio
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
}

// função para mover o cavalo
void validar_movimento_cavalo (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido){
        if(((linhavelha-linha==2)&&(colunavelha-coluna==1)) || ((linhavelha-linha==1)&&(colunavelha-coluna==2)) || ((linha-linhavelha==1)&&(colunavelha-coluna==2)) || ((linha-linhavelha==2)&&(colunavelha-coluna==1)) || ((linhavelha-linha==2)&&(coluna-colunavelha==1)) || ((linhavelha-linha==1)&&(coluna-colunavelha==2)) || ((linha-linhavelha==1)&&(coluna-colunavelha==2)) || ((linha-linhavelha==2)&&(coluna-colunavelha==1))){
            printf("\nMovimento valido\n");
            *movimento_valido=1;
        }
        else {
            printf("\nMovimento invalido\n");
            *movimento_valido=0;
        }

}

// função para mover a torre pequena
void validar_movimento_torret (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido){
    int cont, NaoEntraMais=0; //variavel criada para evitar que a função entre em todos os laços se uma opção inicial for falsa
    *movimento_valido=0;
    // Se a torre andar na vertical
    if ((colunavelha==coluna) && (linhavelha!= linha) && (NaoEntraMais==0)){
        //se atorre estiver descendo
        if (linhavelha<linha){
            //verifica se existe alguma peca no intervalo entre a posição partida e a posiçõa de destino da torre
            for (cont=linhavelha; cont<linha; cont++){
                // se encontrar alguma peca o movimento é invalido
                if(tabuleiro[cont][coluna]!='-'){
                    // atorre não pode andar
                    *movimento_valido=0;
                }
                else{
                    // se no local de destino tiver uma peca
                    if(isalpha(tabuleiro[linha][coluna])!=0){
                        // se esta peca for maiuscula
                        if(isupper(tabuleiro[linha][coluna])!=0){
                            // A torre pode comer e andar
                            *movimento_valido=1;
                        }
                        else{
                            // a torre não pode comer e andar
                            *movimento_valido=0;
                        }
                    }
                    // se tiver um espaço vazio
                    else{
                       *movimento_valido=1;
                    }
                }
            }
        }
        // se a torre estiver subindo
        if (linha<linhavelha){
            // verificando se no intervalo entre a posição de destino e a posição de origem tem alguma peca
            for (cont=linha; cont<linhavelha; cont++){
                // setiver alguma peca
                if(tabuleiro[cont][coluna]!='-'){
                    //o movimento é invalido
                    *movimento_valido=0;

                }
                else{
                    // se no local de destino tiver uma peca
                    if(isalpha(tabuleiro[linha][coluna])!=0){
                        // se esta peca for maiuscula
                        if(isupper(tabuleiro[linha][coluna])!=0){
                            // A torre pode comer e andar
                            *movimento_valido=1;
                        }
                        else{
                            // a torre não pode comer e andar
                            *movimento_valido=0;
                        }
                    }
                    // se tiver um espaço vazio
                    else{
                       *movimento_valido=1;
                    }
                }
            }
        }
        // se entrar neste laço a função não entra nos outros
        NaoEntraMais=1;
    }
    // se a torre se mover na horinzontal
    if((linhavelha==linha) && (colunavelha!=coluna) && (NaoEntraMais==0)){
        //da esquerda para a direita
        if(colunavelha<coluna){
            // laço que verifica se intervalo entre a posição final e a inicial tem alguma peca
            for (cont=colunavelha; cont<coluna; cont++){
                //se tiver alguma peca
                if(tabuleiro[linha][cont]!='-'){
                    //a torre não pode andar
                    *movimento_valido=0;
                }
                else{
                    // se no local de destino tiver uma peca
                    if(isalpha(tabuleiro[linha][coluna])!=0){
                        // se esta peca for maiuscula
                        if(isupper(tabuleiro[linha][coluna])!=0){
                            // A torre pode comer e andar
                            *movimento_valido=1;
                        }
                        else{
                            // a torre não pode comer e andar
                            *movimento_valido=0;
                        }
                    }
                    // se tiver um espaço vazio
                    else{
                       *movimento_valido=1;
                    }
                }
            }
        }

        //da direita para a esquerda
        if (coluna<colunavelha){
        // verificando se no intervalo entre a posição de destino e a posição de origem tem alguma peca
            for (cont=coluna; cont<colunavelha; cont++){
                // se tiver alguma letra no intervalo
                if(tabuleiro[linha][cont]!='-'){
                    // a torre não pode andar
                    *movimento_valido=0;

                }
                else{
                    // se no local de destino tiver uma peca
                    if(isalpha(tabuleiro[linha][coluna])!=0){
                        // se esta peca for maiuscula
                        if(isupper(tabuleiro[linha][coluna])!=0){
                            // A torre pode comer e andar
                            *movimento_valido=1;
                        }
                        else{
                            // a torre não pode comer e andar
                            *movimento_valido=0;
                        }
                    }
                    // se tiver um espaço vazio
                    else{
                       *movimento_valido=1;
                    }
                }
            }
        }

    //não entra em mais nenhum laço
    NaoEntraMais=1;
    }
    if (*movimento_valido==1){
        printf("\nMovimento valido\n");
    }
    else{
        printf("\nMovimento invalido\n");
    }
}

// função para mover a torre grande
void validar_movimento_torreT (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido){
    int cont, NaoEntraMais=0; //variavel criada para evitar que a função entre em todos os laços se uma opção inicial for falsa
    *movimento_valido=0;
    // Se a torre andar na vertical
    if ((colunavelha==coluna) && (linhavelha!= linha) && (NaoEntraMais==0)){
        //se atorre estiver descendo
        if (linhavelha<linha){
            //verifica se existe alguma peca no intervalo entre a posição partida e a posiçõa de destino da torre
            for (cont=linhavelha; cont<linha; cont++){
                // se encontrar alguma peca o movimento é invalido
                if(tabuleiro[cont][coluna]!='-'){
                    // atorre não pode andar
                    *movimento_valido=0;
                }
                else{
                    // se no local de destino tiver uma peca
                    if(isalpha(tabuleiro[linha][coluna])!=0){
                        // se esta peca for minuscula
                        if(islower(tabuleiro[linha][coluna])!=0){
                            // A torre pode comer e andar
                            *movimento_valido=1;
                        }
                        else{
                            // a torre não pode comer e andar
                            *movimento_valido=0;
                        }
                    }
                    // se tiver um espaço vazio
                    else{
                       *movimento_valido=1;
                    }
                }
            }
        }
        // se a torre estiver subindo
        if (linha<linhavelha){
            // verificando se no intervalo entre a posição de destino e a posição de origem tem alguma peca
            for (cont=linha; cont<linhavelha; cont++){
                // setiver alguma peca
                if(tabuleiro[cont][coluna]!='-'){
                    //o movimento é invalido
                    *movimento_valido=0;

                }
                else{
                    // se no local de destino tiver uma peca
                    if(isalpha(tabuleiro[linha][coluna])!=0){
                        // se esta peca for minuscula
                        if(islower(tabuleiro[linha][coluna])!=0){
                            // A torre pode comer e andar
                            *movimento_valido=1;
                        }
                        else{
                            // a torre não pode comer e andar
                            *movimento_valido=0;
                        }
                    }
                    // se tiver um espaço vazio
                    else{
                       *movimento_valido=1;
                    }
                }
            }
        }
        // se entrar neste laço a função não entra nos outros
        NaoEntraMais=1;
    }
    // se a torre se mover na horinzontal
    if((linhavelha==linha) && (colunavelha!=coluna) && (NaoEntraMais==0)){
        //da esquerda para a direita
        if(colunavelha<coluna){
            // laço que verifica se intervalo entre a posição final e a inicial tem alguma peca
            for (cont=colunavelha; cont<coluna; cont++){
                //se tiver alguma peca
                if(tabuleiro[linha][cont]!='-'){
                    //a torre não pode andar
                    *movimento_valido=0;
                }
                else{
                    // se no local de destino tiver uma peca
                    if(isalpha(tabuleiro[linha][coluna])!=0){
                        // se esta peca for minuscula
                        if(islower(tabuleiro[linha][coluna])!=0){
                            // A torre pode comer e andar
                            *movimento_valido=1;
                        }
                        else{
                            // a torre não pode comer e andar
                            *movimento_valido=0;
                        }
                    }
                    // se tiver um espaço vazio
                    else{
                       *movimento_valido=1;
                    }
                }
            }
        }

        //da direita para a esquerda
        if (coluna<colunavelha){
        // verificando se no intervalo entre a posição de destino e a posição de origem tem alguma peca
            for (cont=coluna; cont<colunavelha; cont++){
                // se tiver alguma letra no intervalo
                if(tabuleiro[linha][cont]!='-'){
                    // a torre não pode andar
                    *movimento_valido=0;

                }
                else{
                    // se no local de destino tiver uma peca
                    if(isalpha(tabuleiro[linha][coluna])!=0){
                        // se esta peca for minuscula
                        if(islower(tabuleiro[linha][coluna])!=0){
                            // A torre pode comer e andar
                            *movimento_valido=1;
                        }
                        else{
                            // a torre não pode comer e andar
                            *movimento_valido=0;
                        }
                    }
                    // se tiver um espaço vazio
                    else{
                       *movimento_valido=1;
                    }
                }
            }
        }

    //não entra em mais nenhum laço
    NaoEntraMais=1;
    }
    if (*movimento_valido==1){
        printf("\nMovimento valido\n");
    }
    else{
        printf("\nMovimento invalido\n");
    }
}

// função para mover a rainha
void validar_movimento_rainha (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido){
    if((coluna-colunavelha==linha-linhavelha) || (coluna-colunavelha==linhavelha-linha) || ((colunavelha==coluna) && (linha!=linhavelha)) || ((linhavelha==linha) && (colunavelha!=coluna))){
        *movimento_valido=1;
    }
    else {
        *movimento_valido=0;
    }
    if (*movimento_valido==1){
        printf("\nMovimento valido\n");
    }
    else {
        printf("\nMovimento invalido\n");
    }

}

// função para mover o rei
void validar_movimento_rei (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha,int *movimento_valido){
        if(((coluna-colunavelha==1) && (linha-linhavelha==1)) || ((colunavelha-coluna==1) && (linha-linhavelha)==1) || ((colunavelha-coluna==1) && (linha-linhavelha==1)) || ((colunavelha-coluna==1) && (linhavelha-linha==1)) || ((linha-linhavelha==1) && (coluna==colunavelha)) || ((linhavelha-linha==1) && (coluna==colunavelha)) || ((linhavelha==linha) && (colunavelha-coluna==1)) || ((linhavelha==linha) && (coluna-colunavelha==1))){
            *movimento_valido=1;
            printf("\nMovimento valido\n");
        }
        else {
            *movimento_valido=0;
            printf("\nMovimento invalido\n");
        }

}

//função para mover o peao grande
void validar_movimento_peaoP (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha, int *movimento_valido){
    int NaoEntraMais=0; //variavel criada para evitar que a função entre em todos os laços se uma opção inicial for falsa
    *movimento_valido=0;
    //quando o peão se desloca na diagonal esquerda
    if((colunavelha-coluna==1) && (linha-linhavelha==1) && (NaoEntraMais==0)){
        // para um local que tenha uma letra
        if(isalpha(tabuleiro[linha][coluna])!=0){
            // se essa letra for minuscula
            if(islower(tabuleiro[linha][coluna])!=0){
                //significa que ele pode andar e comer a peca do adversario
                *movimento_valido=1;
            }
            else{
                //significa que ele não pode andar e comer a peca do adversario
                *movimento_valido=0;
            }
        }
        // se não for uma letra e sim um espaço vazio, ele não pode andar
        if(tabuleiro[linha][coluna]=='-'){
            *movimento_valido=0;
        }
        // a função não entra nas condiçoes subsequentes
        NaoEntraMais=1;
    }
    //quando o peão se desloca na diagonal direita
    if((coluna-colunavelha==1) && (linha-linhavelha==1) && (NaoEntraMais==0)){
        // para um local que tenha uma letra
        if(isalpha(tabuleiro[linha][coluna])!=0){
             // se essa letra for minuscula
            if(islower(tabuleiro[linha][coluna])!=0){
                //significa que ele pode andar e comer a peca do adversario
                *movimento_valido=1;
            }
            else{
                //significa que ele não pode andar e comer a peca do adversario
                *movimento_valido=0;
            }
        }
        // se não for uma letra e sim um espaço vazio, ele não pode andar
        if(tabuleiro[linha][coluna]=='-'){
            *movimento_valido=0;
        }
        // a função não entra nas condiçoes subsequentes
        NaoEntraMais=1;
    }
     // se o peao andar para frente
    if ((coluna==colunavelha) && (linha-linhavelha==1) && (NaoEntraMais==0)){
        // para um local onde tenha uma letra
        if(isalpha(tabuleiro[linha][coluna])!=0){
            // ele não pode andar e comer. obs peao não come para frente
            *movimento_valido=0;
        }
        //para um local onde tenha um espaço vazio
        if(tabuleiro[linha][coluna]=='-'){
            //ele pode andar
            *movimento_valido=1;
        }
        // a função não entra nas condiçoes subsequentes
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

//função para mover o peao pequeno
void validar_movimento_peaop (char tabuleiro[10][10], int linha, int coluna, int linhavelha, int colunavelha, int *movimento_valido){
   int NaoEntraMais=0; //variavel criada para evitar que a função entre em todos os laços se uma opção inicial for falsa
   *movimento_valido=0;
    //quando o peão se desloca na diagonal esquerda
    if((colunavelha-coluna==1) && (linhavelha-linha==1) && (NaoEntraMais==0)){
        // para um local que tenha uma letra
        if(isalpha(tabuleiro[linha][coluna])!=0){
            // se essa letra for maiuscula
            if((isupper(tabuleiro[linha][coluna])!=0)){
                //significa que ele pode andar e comer a peca do adversario
                *movimento_valido=1;
            }
            else{
                //significa que ele não pode andar e comer a peca do adversario
                *movimento_valido=0;
            }
        }
         // se não for uma letra e sim um espaço vazio, ele não pode andar
        if(tabuleiro[linha][coluna]=='-'){
            *movimento_valido=0;
        }
        // a função não entra nas condiçoes subsequentes
        NaoEntraMais=1;
    }
    //quando o peão se desloca na diagonal direita
    if((coluna-colunavelha==1) && (linhavelha-linha==1) && (NaoEntraMais==0)){
        // para um local que tenha uma letra
        if(isalpha(tabuleiro[linha][coluna])!=0){
            // se essa letra for maiuscula
            if((isupper(tabuleiro[linha][coluna])!=0)){
                //significa que ele pode andar e comer a peca do adversario
                *movimento_valido=1;
            }
            else{
                //significa que ele não pode andar e comer a peca do adversario
                *movimento_valido=0;
            }
        }
         // se não for uma letra e sim um espaço vazio, ele não pode andar
        if(tabuleiro[linha][coluna]=='-'){
            *movimento_valido=0;
        }
        // a função não entra nas condiçoes subsequentes
        NaoEntraMais=1;
    }
    // se o peao andar para frente
    if ((coluna==colunavelha) && (linhavelha-linha==1) && (NaoEntraMais==0)){
        // para um local que tenha uma letra
        if(isalpha(tabuleiro[linha][coluna])!=0){
            // ele não pode andar e comer. obs peao não come para frente
            *movimento_valido=0;
            }
        //para um local onde tenha um espaço vazio
        if(tabuleiro[linha][coluna]=='-'){
            //ele pode andar
            *movimento_valido=1;
        }
        // a função não entra nas condiçoes subsequentes
        NaoEntraMais=1;
    }
    // se for o primeiro movimento do peao ele pode andar duas casas para frente
    if ((linhavelha==7) && (coluna==colunavelha) && (linhavelha-linha==2) && (NaoEntraMais==0)){
        *movimento_valido=1;
        // a função não entra nas condiçoes subsequentes
        NaoEntraMais=1;
    }
    if (*movimento_valido==1){
        printf("\nMovimento valido\n");
    }
    else{
        printf("\nMovimento invalido\n");
    }
}

//função que verifica o fim do jogo
void check_mate (char tabuleiro[10][10]){
    int linha, coluna;
    int rei_vivo=0;// significa que o rei minusculo começa o jogo morto
    int Rei_vivo=0;// significa que o rei maiusculo começa o jogo morto
    char peca;
    //função para rodar a matrix e verificar a presença dos reis
    for (linha=0;linha<10;linha++){
        for(coluna=0;coluna<10;coluna++){
            peca=tabuleiro[linha][coluna];
            // se a função encontrar o rei minusculo siginifica dizer que ele esta vivo
            if(peca=='r'){
                rei_vivo=1;

            }
            // se a função encontrar o rei maisculo siginifica dizer que ele esta vivo
            if(peca=='R'){
                Rei_vivo=1;

            }
        }
    }
    // se não for encontrado o rei minusculo, significa dizer o plater um perdeu
    if(rei_vivo==0){
        //limpa a tela
        system("cls");
        //mostra o perdedor, player 1 (pecas minusculas)
        printf("\nPlayer 1 perdeu. Check Mate\n");
        printf("Parabens Player 2\n");
        printf("Game Over\n");
        system("pause");
        //retorna para o menu
        printar_menu(tabuleiro);

    }
    if(Rei_vivo==0){
        //limpa a tela
        system("cls");
        //mostra o perdedor, player  (pecas maiusculas)
        printf("\nPlayer 2 perdeu. Check Mate\n");
        printf("Parabens player 1\n");
        printf("Game Over\n");
        system("pause");
        //retorna para o menu
        printar_menu(tabuleiro);

    }


}


