#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    //Configurando UTF-8 para caracteres.
    setlocale(LC_ALL, "Portuguese");

    //Tela inicial.
    printf("\t\t\t########## XADREZ ##########\n\n");
    printf("Equipe: Abraao, Danilo, Daniel e Stephanie");

    return 0;
}