#include<stdio.h>
#include<locale.h>

void calculo_area_retangulo(float base, float altura, float *area);

int main(){
    float a, b, ar;
    printf("Digite a base e altura:");
    scanf("%f%f", &b, &a);
    calculo_area_retangulo(b, a, &ar);
    printf("A área calculada foi: %2f", ar);

    return 0;

}

void calculo_area_retangulo(float base, float altura, float *area){
    *area=base*altura;

}

