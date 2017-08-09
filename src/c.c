#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void nome_jogadores (char *nomeJogador1, char *nomeJogador2);

int main () {
    char nomeJogador1[20], nomeJogador2[20];
    nome_jogadores(nomeJogador1, nomeJogador2);
    printf("%s, %s", nomeJogador1, nomeJogador2);

    return 0;
}
void nome_jogadores (char nomeJogador1[20], char nomeJogador2[20]) {
    printf("Digite o nome do jogador 1\n");
    gets(nomeJogador1);
    printf("Digite o nome do jogador2\n");
    gets(nomeJogador2);
    }
