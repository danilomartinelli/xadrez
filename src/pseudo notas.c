#include<stdio.h>

int entrada_dados (int tabela[5]);


int main(){
    int tabela[5];
    entrada_dados(tabela);

    return 0;

}

int entrada_dados (int vetor[5]){
    int numero, linha;
    for(linha=0; linha<5; linha++){
        printf("Digite um numero\n");
        scanf("%d",&numero);
        vetor[linha]=numero;

    }

}
