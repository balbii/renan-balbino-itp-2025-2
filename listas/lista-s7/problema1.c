#include <stdio.h>
#include <string.h>

int main() {
    char palavra[21];
    int indice;

    scanf("%s %d", palavra, &indice);

    int tam = strlen(palavra);

    if (palavra[indice] == 'x') {
        printf("bum!\n");
    } else {
        int bombas = 0;
        if (indice > 0 && palavra[indice - 1] == 'x') bombas++;
        if (indice < tam - 1 && palavra[indice + 1] == 'x') bombas++;
        printf("%d\n", bombas);
    }

    return 0;
}