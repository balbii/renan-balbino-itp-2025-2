#include <math.h>
#include <stdio.h>

int main() {

    int a, b;
    printf("Digite dois números inteiros: ");
    scanf("%d %d", &a, &b);
    int soma = a + b;
    printf("A soma de %d e %d é: %d\n", a, b, soma);
    int diferenca = a - b;
    printf("A diferença entre %d e %d é: %d\n", a, b, diferenca);
    int produto = a * b;
    printf("O produto de %d e %d é: %d\n", a, b, produto);
    float divisaoReal = (float)a / b;
    printf("A divisão real de %d por %d é: %.2f\n", a, b, divisaoReal);
    int resto = a % b;
    printf("O resto da divisão de %d por %d é: %d\n", a, b, resto);
    float media = (a + b) / 2.0;
    printf("A média entre %d e %d é: %.2f\n", a, b, media);

    return 0;
}