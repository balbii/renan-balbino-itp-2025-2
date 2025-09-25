#include <stdio.h>
#include <math.h>

int pontuacao_principal(double d) {
    if (d <= 1.0) return 10;
    else if (d <= 2.0) return 6;
    else if (d <= 3.0) return 4;
    else return 0;
}

int main() {
    double x, y;
    double dist_atual, dist_anterior;
    int total = 0;
    int pontos, bonus;

    for (int i = 0; i < 10; i++) {
        printf("Lançamento %d (x y): ", i + 1);
        scanf("%lf %lf", &x, &y);

        dist_atual = sqrt(x * x + y * y);
        pontos = pontuacao_principal(dist_atual);
        bonus = 0;

        if (i > 0) {
            // compara distâncias com tolerância para evitar problemas de ponto flutuante
            if (fabs(dist_atual - dist_anterior) < 1e-6) {
                bonus = pontos / 2;
            }
        }

        total += pontos + bonus;
        dist_anterior = dist_atual;

        printf("Distância = %.2f | Pontos = %d | Bônus = %d | Total parcial = %d\n",
               dist_atual, pontos, bonus, total);
    }

    printf("\nPontuação final: %d\n", total);
    return 0;
}
