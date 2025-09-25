#include <stdio.h>

// Função para verificar se um número é primo
int ehPrimo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int a, b;

    // Garantir que a > b
    do {
        printf("Digite dois numeros inteiros (a > b): ");
        scanf("%d %d", &a, &b);
    } while (a <= b);

    printf("Numeros primos entre %d e %d:\n", b, a);

    for (int i = b + 1; i < a; i++) {
        if (ehPrimo(i)) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}
