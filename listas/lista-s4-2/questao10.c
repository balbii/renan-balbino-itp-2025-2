#include <stdio.h>

int main() {
    float p, q;
    int x, y;
    int melhor_x = 0, melhor_y = 0;
    float melhor_razao = 0;

    printf("Digite o preco de venda p: ");
    scanf("%f", &p);

    printf("Digite o preco de producao q: ");
    scanf("%f", &q);

    for (x = 2; x <= 10; x++) {       // x começa em 2, pois precisa ser > y
        for (y = 1; y < x; y++) {
            if (y * p >= x * q) {     // condição: sem prejuízo
                float razao = (float)x / y;
                if (razao > melhor_razao) {
                    melhor_razao = razao;
                    melhor_x = x;
                    melhor_y = y;
                }
            }
        }
    }

    if (melhor_x > 0) {
        printf("A melhor promocao eh: leve %d pague %d\n", melhor_x, melhor_y);
    } else {
        printf("Nao existe promocao possivel sem prejuizo.\n");
    }

    return 0;
}
