#include <stdio.h>

int main() {
    int p1, p2, dinheiro;
    int i, j, gasto, resto;

    printf("Digite o preco do primeiro fornecedor: ");
    scanf("%d", &p1);

    printf("Digite o preco do segundo fornecedor: ");
    scanf("%d", &p2);

    printf("Digite a quantia disponivel: ");
    scanf("%d", &dinheiro);

    for (i = 0; i <= 10; i++) { // unidades do fornecedor 1
        for (j = 0; j <= 10; j++) { // unidades do fornecedor 2
            gasto = i * p1 + j * p2;
            if (gasto <= dinheiro) {
                resto = dinheiro - gasto;
                printf("Comprando %d do primeiro e %d do segundo resta: %d\n", i, j, resto);
            }
        }
    }

    return 0;
}
