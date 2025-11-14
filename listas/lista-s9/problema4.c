#include <stdio.h>

int main() {
    int M;
    scanf("%d", &M);

    int precos[10][10];
    int X, Z;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &precos[i][j]);
        }
    }

    scanf("%d %d", &X, &Z);

    int menor_custo = precos[X][Z];
    int cidade_intermediaria = -1; 

    for (int y = 0; y < M; y++) {
        int custo_com_parada = precos[X][y] + precos[y][Z];

        if (custo_com_parada < menor_custo) {
            menor_custo = custo_com_parada;
            cidade_intermediaria = y;
        }
    }

    if (cidade_intermediaria == -1) {
        printf("%d-%d R$%d\n", X, Z, menor_custo);
    } else {
        printf("%d-%d-%d R$%d\n", X, cidade_intermediaria, Z, menor_custo);
    }

    return 0;
}