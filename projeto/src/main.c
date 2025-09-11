#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define BOMBAS 10

int tabuleiro[TAM][TAM];   // 0 = vazio, -1 = bomba

// Inicializa o tabuleiro com zeros e coloca bombas
void inicializar() {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int bombas_colocadas = 0;
    while (bombas_colocadas < BOMBAS) {
        int x = rand() % TAM;
        int y = rand() % TAM;
        if (tabuleiro[x][y] != -1) {
            tabuleiro[x][y] = -1;
            bombas_colocadas++;
        }
    }
}

// Mostra o tabuleiro (escondendo bombas)
void imprimir() {
    printf("\n   ");
    for (int j = 0; j < TAM; j++) printf("%d ", j);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d  ", i);
        for (int j = 0; j < TAM; j++) {
            printf(". ");  // sempre mostra oculto
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    inicializar();

    int x, y;
    imprimir();

    printf("\nDigite linha e coluna: ");
    scanf("%d %d", &x, &y);

    if (tabuleiro[x][y] == -1) {
        printf("\n💥 Você encontrou uma bomba! Fim de jogo.\n");
    } else {
        printf("\n✅ Posição segura!\n");
    }

    return 0;
}
