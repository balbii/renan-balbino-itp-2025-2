#include <math.h>
#include <stdio.h>

int main() {

    float nota1, nota2, nota3, notaFinal, media;
    printf("Digite as três notas: ");
    scanf("%f %f %f", &nota1, &nota2, &nota3);
    media = (nota1 + nota2 + nota3) / 3;
    printf("Média: %.2f\n", media);
    if (media >= 7.0) {
        printf("Aprovado\n");
    } else if (media >= 4.0) {
        printf("Recuperação\n");
        notaFinal = 10 - media;
        printf("Nota necessária na prova final: %.2f\n", notaFinal);
    } else {
        printf("Reprovado\n");
    }

    return 0;
}