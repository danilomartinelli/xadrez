#include <stdio.h>
#include <stdlib.h>

void calcula_area_retangulo(float base, float altura, float *area);

int main (){
    float b, a, area;
    printf("Digite a base a altura");
    scanf("%f %f", &b, &a);
    calcula_area_retangulo(b, a, &area);
    printf("A área calculada foi: %.2f", area);
    return 0;
}

void calcula_area_retangulo(float base, float altura, float *area){
    *area=base*altura;
}
