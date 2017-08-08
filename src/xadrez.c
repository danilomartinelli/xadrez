#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Desenhar tabuleiro na tela:
void tabuleiro_em_tela(char tabuleiro[10][10]);
// Desenhar a funçãso na tela
void printar_menu(char tabuleiro[10][10]);
//Selecionar a peça
void selecao_peca (char tabuleiro[10][10]);

//Função principal
int main()
{
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
        printf("\n");
    }
}

//função criar o menu
void printar_menu(char tabuleiro[10][10]){
    int opcoes;

    do
    {
        //printar o menu
        printf("###################################\n");
        printf("\t Jogo de Xadrez\n\n\n");
        printf("{##################+;:,,,,,,,,,,,,,,,,,,,,,,,,,,:'##########################+;:,,,,,,,,,,,,,,,,,,,,,,,,,,\n");
printf("{##################+;:,,,,,,,,,,,,,,,,,,,,,,,,,,:'+#########################+;:,,,,,,,,,,,,,,,,,,,,,,,,,:\n");
printf("{##################+;:,,,,,,,,,.,,,,,,,,,,,,,,,::'##########################+':::,,,,,,,,,,,,,,,,,,,,,,::\n");
printf("{+++++++++++++++++++';::::::::```:::::::::::::::;'++++++++++#+#+#++++###'+#++';:::::::::::::::::::::::::;\n");
printf("{;'''''''''''''''''''';;;;;;'.``.;;;;;;;;;;;;;;;;'''''''''''''''''''''###.'''';;;;;;;;;;;;;;;;;;;''';'';'\n");
printf("{::::::;;:::::::::;;''++++'':```#'++++++++++''++';;:::::::::::::::::;;;@#'.;;''++++++++++++++++++++++++++\n");
printf("{::::::::::::::::,:;'+###;'',```.###############';:,,,,,,,,,,,,,,,,,::,##+;`:''##########################\n");
printf("{,,,,,,,,,,,,,,,,,,:'+#+'''';:.```+#############':,,,,,,,,,,,,,,,,,,,:+##+;:..:'########################+\n");
printf("{,,,,,,,,,,,,,,,,,,:'+'+''''';:,. `'############':,,,,,,,,,,,,,,,,,,###+;:;;,`.:;#######################+\n");
printf("{,,,,,,,,,,,,,::,,,:'''+'''''';:. `.############':,,,,,,,,,,,,,,,,,;##+';'+;'.`,.:######################+\n");
printf("{,,,,,,,,,,,,,,,,,::;''+'''''';;,````@##########':,,,,,,,,,,,,,,,,,+#@+';;''+;.,..;#####################+\n");
printf("{,,,,,,,,,,,,,,,,,:;'''+'''''';;:,.```;#########':,,,,,,,,,,,,,,,,'##++'+''''';..`,+####################+\n");
printf("{,,,,,,,,,,,,,,,,,,''''+''''''';;::,.```@#######':,,,,,,,,,,,,,,,+##''';'''''++..`.,####################+\n");
printf("{,,,,,,,,,,,,,,,,,;'+'+''''''''';;;;:,`` ######+':,,,,,,,,,,,,,;##+'++++'';;''+':`,.:####################\n");
printf("{,,,,,,,,,,,,,,,,,''+'+'''''''''';;;;;,` .#####+':,,,,,,,,,,,,;@#'+++++'';;;''#+..,.:####################\n");
printf("{,,,,,,,,,,,,,:,:;'''+'''+''''''''';;;:.` #####+':,,,,,,,,,,,.+@'++++++''';'+'++;:`,`:##################+\n");
printf("{,,,,,,,,,,,,,:,,''+''';;++''''';;';;::.``#####+':,,,,,,,,,,,;##+++++++++'++'+##'..,.;##################+\n");
printf("{,,,,,,,,,,,,,:,:+''+';;;'+''''';;;';,:..;#####+':,,,,,,,,,,,:#@#++++++++++;####+;;.;`##################+\n");
printf("{,,,,,,,,,,,,,,:;'+'+';;;;''''';;:;';,,::######+':,,,,,,,,,,,,@###+++++++++#####+;.;.,;#################+\n");
printf("{,,,,,,,,,,,,,:,'''++;;;::;'';;;;;'#;:..@######+':,,,,,,,,,,,,,@@@++###@#++@@####'',.::#################+\n");
printf("{,,,,,,,,,,,,,::'+'+';;;::::#########+;@#######+':,,,,,,,,,,,,,,@#+:,,;':,,@####+',,';,#################+\n");
printf("{,,,,,,,,,,,,,,,'+++';:;:::::##################+':,,,,,,,,,,,,,,:;,,,,,,,,+@###++':':,:#################+\n");
printf("{,,,,,,,,,,,,,,,''++';::::::,:#################+':,,,,,,,,,,,,,,,,,,,,,,,:@####++';,:';##################\n");
printf("{,,,,,,,,,,,,,,:''++';:,,,::,,'################+;:,,,,,,,,,,,,,,,,,,,,,,:######+';;''+,##################\n");
printf("{,,,,,,,,,,,,,,,''+++;:::,,,.``;###############+;:,,,,,,,,,,,,,,,,,,,,,,###+++++'''+;,'##################\n");
printf("{,,,,,,,,,,,,,,,'''++';::,,,,..``##############+;:,,,,,,,,,,,,,,,,,,,,;@#++++++'''';'''##################\n");
printf("{,,,,,,,,,,,,,,,'+++''';::,,,...``;############+;:,,,,,,,,,,,,,,,,,,,@#+++++++'';''++::##################\n");
printf("{,,,,,,,,,,,,,,,''''''';;::,,,,,.```###########+;:,,,,,,,,,,,,,,,,,'#++++'''''';'''';';##################\n");
printf("{,,,,,,,,,,,,,,,'++++''';;:::,,,,..` ##########+;:,,,,,,,,,,,,,,,,+#++;:''''';+';'+';''##################\n");
printf("{,,,,,,,,,,,,,,,:'+++'''';;::::,,,.`  #########+;:,,,,,,,,,,,,,,,;##+:::;+++'';''++';:###################\n");
printf("{:::,,,,,,,,,,,:,'''++'''';;::::::,.  @########+;:,,,,,,,,,,,,,,,#@+;:::;+++':+;'+''''##################+\n");
printf("{::::::::,,,::::,++++++'''';::::::,.``#########+;:,,,,,,,,,,,,,,,##+'::;+++;:':++''+''##################+\n");
printf("{::::::::::::::::;+++++''''';;;:;:,```#++++++++';:::,,,::::::::::###+;:;;::;+:'''''''+++++++++++++++++++'\n");
printf("{:::::::::::::::::++++'+''''';;;::,``.''';;;;;;;;::::::::::::::::+@@#';:::'':;;'''':';';;''';;;;;;;;;;;;;\n");
printf("{:::;;;:::::::::::;+''''''''''';;,.``,::::::::::::::::::::::::::::@@@#+;'':,,::::''';:::;;;;;;:::::::::::\n");
printf("{::;;;;:::::::::::,++'''''''''';:....:::,,,,,,,,,,,,,,,,,,,::::::,:@@@#+++''';;:::'',,::::;;::,,,,,,,,,,,\n");
printf("{::;;;;::,,,,,,,,,,:+++'''''''';:...:,,,,,,,,,,,,,,,,,,,,,,,::;::,,,@@@@@@########+.,,:::;;;::,,,,,,,,,,,\n");
printf("{:;;;;;;:,,,,,,,,,,,'######+++##':::,,,,,,,,,,,,,,,,,,,,,,,:::;::#+'++####+;:+'';:,,,,:::;;;;:,,,,,,,,,,,\n");
printf("{:;;;;;;:,,,,,,,,,:++'';;,,,...`.````,,,,,,,,,,,,,,,,,,,,,,,:::;#@@@@##@@@######+',,,,:::;;;;:,,,,,,,,,,,\n");
printf("{:;;;;;;:,,,,,,:,,+'+'';;:,,,...`.....,,,,,,,,,,,,,,,,,,,,,,::;@@@@@@@@@@@#######+',,:::;;;;;::,,,,,,,,,,\n");
printf("{:;;;';;::::::::,+''+''';::,,.......``.,,,,,,,,,,,,,,,,,,,,:::###@@@@@@@@@@######'+:::::;;;;;::,,,:::::::\n");
printf("{:;;''';::::::::;''+++';:,,..````     `:::::::::::::::::::::::###@@@@@@@@@@##+;:;;';::::;;;;;::::::::::::\n");
printf("{:;;;;;;;:::::::;''++''';:,,..`````````:::::::::::::::::::::::##+@@@@@@@@###++'''+++::::;;;;;::::::::::::\n");
printf("{;;;;;;;::::::::'''+++'';:,,..`````````:::::::::::::::::::::::##+@@@@@@@@####++'++++::::;;;;;::::::::::::\n");
printf("{;;;;;;;::::::::;'++++'';;:,.``````````:::::::::::::::::::::::##+@@@@@@@@@##+++;++++::::;;;;;::::::::::::\n");
printf("{:;;;;;:::::::::;''+++'''::,..`````````:::::::::::::::::::::::###@@@@@@@@####++;++++::;;;;;;;;:::::::::::\n");
printf("{::;;;;;::::::::;'++++''';:,..`````````::::::::::::::::::::::;###@@@@@@@@####++;++++::;;;;;;;;;::::;;;;::\n");
printf("{:;;;;;:::::::::;''+++''';:,..`````````;;;;;;;;::::::::::::::;###@@@@@@@@####++;++++::;;;;;;;;;;;;;;;;;;:\n");
printf("{:;;;;;:::::::::;''+++'''::,...````````;;;;;;;;::::::::::::::'###@@@@@@@@####++;+++';;;;;;;;;;;;;;;;;;;;:\n");
printf("{:;;;;;;::::::::'''++++'';:,,..````````;;;;;;;;;:::::::::::::+##+@@@@@@@@###+++''++';;;;;;;;;;;;;;;;;;;;;\n");
printf("{;;;;;;;;;;;;;;;+++++++'';;,,...```````';;;;;;;;;;:::::::::::+@@#@@@@@@@@@##++#;'++';;;;'';;;;';;'';;;;;;\n");
printf("{;;;;;;;;;;;;;;;;+####+++';:::.:,,,,,:'''''''''';;;;;;;;;;;;;;;+#@@@@@@@@@@###+####';;;;;;';''';';;;;;;';\n");
printf("{;;;;;;;;:;;;;;;;'+#####++++++'';';;:,,;';;;;;;;;::::::::::::;'+''++++++++#+++''''';''';;;'''''''''''''';\n");
printf("{;;;;;;:::::::::;'''''''';;::,,....``..:;;;;;;;;;::::::::::::;''+++'+'''''''';;;;;;;;;;;;';'';;;;;;''';;;\n\n\n");

        printf("\t1-Jogar\n\n \t2-Ajuda\n\n \t3-Sobre o jogo\n\n \t4-Sair\n\n");
        printf("###################################\n");
        scanf("%d", &opcoes);
        system("cls");


    // opções do menu
    switch(opcoes){
        case 1:
            tabuleiro_em_tela(tabuleiro);
            selecao_peca(tabuleiro);
            break;

        case 2:
            printf("Player 1 controla as pecas brancas e Player 2 as pecas Pretas.");
            printf(" O jogo segue todas as regras oficiais. Exceto que:\n");
            printf("\n    - Nao e possivel fazer movimentos especiais como o roque.\n");
            printf("\nPara jogar, basta digitar a letra correspondente a peca que deseja movimentar.\n");
            printf("\nLogo depois, deve-se digitar a linha e a coluna para qual voce deseja se movimentar.\n\n");
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
    } while (opcoes != 4 || opcoes != 1);

}


//função selecao peca
void selecao_peca (char tabuleiro[10][10]){
   int linha, coluna, peca_valida;

   do{
        printf("Digite uma peca a ser movida (linha x coluna)");
        scanf("%d %d", &linha, &coluna);
        getchar();
        //verificando se o player selecionou os espaços vazios
        if((linha <= 8 && linha >= 1) && (coluna <= 8 && coluna >= 1)){
            if (tabuleiro[linha][coluna]=='-'){
                peca_valida=0;//peca_valida=o segnifica invalida
            }
            else{
                peca_valida=1;//peca valida=1 significa valida
            }
        }
        //verifica se o player selecionou as coordenadas ou estrapolou a matriz
        else{
            peca_valida=0;
        }
        //se o player escolheu uma peca valida, colocar o nome da peça
        if (peca_valida==1){
            switch(tabuleiro[linha][coluna]){

               case'p':
                    printf("Voce selecionou o Peao!\n");
                    peca_valida=1;
                    break;

                case 'P':
                    printf("Voce selecionou o Peao!\n");
                    peca_valida=1;
                    break;

                case 't':
                    printf("Voce selecionou a Torre!\n");
                    peca_valida=1;
                    break;

                case 'T':
                    printf("Voce selecionou a Torre!\n");
                    peca_valida=1;
                    break;

                case'b':
                    printf("Voce selecionou o Bispo!\n");
                    peca_valida=1;
                    break;

                case'B':
                    printf("Voce selecionou o Bispo!\n");
                    peca_valida=1;
                    break;

                case'c':
                    printf("Voce selecionou o Cavalo!\n");
                    peca_valida=1;
                    break;

                case'C':
                    printf("Voce selecionou o Cavalo!\n");
                    peca_valida=1;
                    break;

                case'R':
                    printf("Voce selecionou o Rei!\n");
                    peca_valida=1;
                    break;

                case'r':
                    printf("Voce selecionou o Rei!\n");
                    peca_valida=1;
                    break;

                case'A':
                    printf("Voce selecionou a Rainha!\n");
                    peca_valida=1;
                    break;

                case'a':
                    printf("Voce selecionou a Rainha!\n");
                    peca_valida=1;
                    break;

                default:
                    printf("Peca invalida.\n");
            }
        }
        else{
            printf("Peca invalida.\n");
        }
    } while (peca_valida==0);
}
