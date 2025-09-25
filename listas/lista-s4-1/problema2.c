#include <stdio.h>
#include <math.h>

int main() {
    float x, y, L;
    int n;

    // Entrada inicial
    printf("Digite a coordenada inicial (x y): ");
    scanf("%f %f", &x, &y);

    printf("Digite o comprimento maximo da teia: ");
    scanf("%f", &L);

    printf("Digite a quantidade de alvos: ");
    scanf("%d", &n);

    int ok = 1; // flag de sucesso

    for (int i = 0; i < n; i++) {
        float ax, ay;
        printf("Digite a coordenada do alvo %d (x y): ", i+1);
        scanf("%f %f", &ax, &ay);

        // Calcula distância até o alvo
        float dist = sqrtf((ax - x) * (ax - x) + (ay - y) * (ay - y));

        if (dist > L) {
            ok = 0; // não alcança
            break;
        }

        // Atualiza a posição do Homem-Aranha
        float x0 = 2 * ax - x;
        float y0 = ay;
        x = x0;
        y = y0;
    }

    if (ok)
        printf("S\n");
    else
        printf("N\n");

    return 0;
}
