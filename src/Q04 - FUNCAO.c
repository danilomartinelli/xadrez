#include <stdio.h>
#include <stdlib.h>

void calcula_area_retangulo(float base, float altura);

int main (){
    float b, a, area;
    printf("Digite a base a altura");
    scanf("%F %f", &b, &a);
    calcula_area_retangulo(b, a);
    printf("A área calculada foi: %.2f", area);
    return 0;
}

void calcula_area_retangulo(float base, float altura){
    float area;
    area=base*altura;
}
