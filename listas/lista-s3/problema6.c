#include <math.h>
#include <stdio.h>

int main() {

    char febre, dorCabeca, dorCorpo, tosse;
    printf("Você está com febre? (s/n): ");
    scanf(" %c", &febre);
    printf("Você está com dor de cabeça? (s/n): ");
    scanf(" %c", &dorCabeca);
    printf("Você está com dor no corpo? (s/n): ");
    scanf(" %c", &dorCorpo);
    printf("Você está com tosse? (s/n): ");
    scanf(" %c", &tosse);

    if (febre == 's' && dorCabeca == 's' && dorCorpo == 's' && tosse == 'n') {
        printf("Possível gripe\n");
    } else if (febre == 's' && dorCabeca == 'n' && dorCorpo == 'n' && tosse == 's') {
        printf("Possível resfriado\n");
    } else if (febre == 'n' && dorCabeca == 's' && dorCorpo == 'n' && tosse == 'n') {
        printf("Possível enxaqueca\n");
    } else if (febre == 'n' && dorCabeca == 'n' && dorCorpo == 'n' && tosse == 'n') {
        printf("Você parece estar bem\n");
    } else if (febre == 's' && dorCabeca == 'n' && dorCorpo == 'n' && tosse == 'n') {
        printf("Consulte um médico\n");
    } else {
        printf("Consulte um médico para avaliação\n");
    }

    return 0;
}