#include<stdio.h>
#include<locale.h>

void entrada_dados (int tabela[5]);

void mudanca_dados (int tabela[5]);

void printando_tela (int tabela[5]);



int main(){
    int tabela[5];
    entrada_dados(tabela);
    mudanca_dados(tabela);
    printando_tela(tabela);

    return 0;

}

//entrada de dados
void entrada_dados (int vetor[5]){
    int numero, linha;
    for(linha=0; linha<5; linha++){
        printf("Digite um numero\n");
        scanf("%d",&numero);
        vetor[linha]=numero;

    }

}

//mudança de dados
void mudanca_dados (int vetor[5]){
    int linha;
    for( linha=0; linha<5; linha++){
        if(vetor[linha]%2==0){
            vetor[linha]=vetor[linha]/2;
        }
        else{
            vetor[linha]=vetor[linha]*vetor[linha];
        }

    }

}

//printar em tela
void printando_tela (int vetor[]){
    setlocale(LC_ALL,"portuguese");
    int linha;
    for(linha=0; linha<5; linha++){
        printf(" O resultado do %dº é:%d\n\n",linha+1,vetor[linha]);
    }

}


