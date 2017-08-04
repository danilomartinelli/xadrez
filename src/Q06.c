#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void entrada_de_dados (int *numero);
void verificar_paridade (int *numero);
void saida_de_dados (int *numero);

int main () {
    int numero[TAM];
//funções que eu tô usando
    entrada_de_dados(numero);
    verificar_paridade(numero);
    saida_de_dados(numero);

return 0;
}

//numerp[TAM] é um vetor que armazena TAM numeros
//todo vetor é um ponteiro
void entrada_de_dados (int numero[TAM]){
    int i;
    for (i=0; i<TAM; i++) {
        printf("Digite um número: \n");
        scanf("%d", &numero[i]);
    }
}
//Como o vetor numero[] é ponteiro, podemos chamá-lo como ponteiro
void verificar_paridade (int *numero){
    int i;
    for (i=0; i<TAM; i++) {
        if (numero[i]%2 == 0){
            numero[i]=(numero[i]/2);
        }
        else{
            numero[i]=numero[i]*numero[i];
        }
    }
}

void saida_de_dados (int *numero){
    int i;
    for (i=0; i<TAM; i++){
        printf("O resultado é: %d\n", numero[i]);
    }
}
