#include <stdio.h>

int main() {
    int p1, p2, dinheiro;
    int i, j, gasto, resto;
    int melhor_i = 0, melhor_j = 0, menor_resto;

    printf("Digite o preco do primeiro fornecedor: ");
    scanf("%d", &p1);

    printf("Digite o preco do segundo fornecedor: ");
    scanf("%d", &p2);

    printf("Digite a quantia disponivel: ");
    scanf("%d", &dinheiro);

    menor_resto = dinheiro; // pior caso: não comprar nada

    for (i = 0; i <= 10; i++) {        // unidades do fornecedor 1
        for (j = 0; j <= 10; j++) {    // unidades do fornecedor 2
            gasto = i * p1 + j * p2;
            if (gasto <= dinheiro) {   // só vale se a compra for possível
                resto = dinheiro - gasto;
                if (resto < menor_resto) {
                    menor_resto = resto;
                    melhor_i = i;
                    melhor_j = j;
                }
            }
        }
    }

    printf("Resta menos comprando %d do primeiro e %d do segundo\n", melhor_i, melhor_j);

    return 0;
}
