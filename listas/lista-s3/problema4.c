#include <math.h>
#include <stdio.h>

int main() {

    char jogador1, jogador2;
    printf("Jogador 1 (P, A, T): "); // P = Pedra, A = Papel, T = Tesoura
    scanf(" %c", &jogador1);
    printf("Jogador 2 (P, A, T): ");
    scanf(" %c", &jogador2);

    if (jogador1 == jogador2) {
        printf("Empate!\n");
    } else if ((jogador1 == 'P' && jogador2 == 'T') ||
               (jogador1 == 'A' && jogador2 == 'P') ||
               (jogador1 == 'T' && jogador2 == 'A')) {
        printf("Jogador 1 vence!\n");
    } else if ((jogador2 == 'P' && jogador1 == 'T') ||
               (jogador2 == 'A' && jogador1 == 'P') ||
               (jogador2 == 'T' && jogador1 == 'A')) {
        printf("Jogador 2 vence!\n");
    } else {
        printf("Entrada inválida.\n");
    }
    
    return 0;
}