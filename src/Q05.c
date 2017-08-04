#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main () {
    int *pi, *pj, i, j, **ppj;
    setlocale(LC_ALL, "portuguese");

    i=7;
    j=10;
    printf("Os valores de i e j são: %d e %d\n", i, j);
    printf("Os endereços de memória de i e j são: %x e %x\n", &i, &j);

    pi=&i;
    pj=&j;
    printf("Os valores de pi e pj são: %x e %x\n", pi, pj);
    printf("Os endereços de memória de pi e pj são: %x e %x\n", &pi, &pj);

    *pi=20;
    *pj=8;
    printf("Os valores de i e j são: %d e %d\n", i, j);

    *pi=*pj;
    printf("Os valores de i e j são: %d e %d\n", i, j);
    pi=pj;
    printf("Os valores de pi e pj são: %x e %x\n", pi, pj);

    ppj=&pj;
    **ppj=50;
    printf("O valor de j é: %d\n", j);

    return 0;
}
