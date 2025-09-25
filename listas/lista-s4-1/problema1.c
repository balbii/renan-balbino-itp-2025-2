#include <stdio.h>

int main() {
    float comp, larg, bolso;
    int dobras = 0;

    printf("Digite o comprimento da folha: ");
    scanf("%f", &comp);

    printf("Digite a largura da folha: ");
    scanf("%f", &larg);

    printf("Digite o comprimento do bolso: ");
    scanf("%f", &bolso);

    while (comp > bolso && larg > bolso) {
        if (comp >= larg) {
            comp /= 2.0; // dobra o comprimento
        } else {
            larg /= 2.0; // dobra a largura
        }
        dobras++;
    }

    printf("Serao necessarias %d dobras.\n", dobras);

    return 0;
}
