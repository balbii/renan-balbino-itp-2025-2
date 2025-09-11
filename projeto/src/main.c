#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> // para toupper

#define TAM 5
#define BOMBAS 5

int tabuleiro[TAM][TAM];    // 0 = vazio, -1 = bomba
int visivel[TAM][TAM];      // 0 = oculto, 1 = revelado

// Inicializa o tabuleiro com zeros e coloca bombas
void inicializar() {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
            visivel[i][j] = 0;
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

// Mostra o tabuleiro na tela
void imprimir() {
    printf("\n   ");
    for (int j = 0; j < TAM; j++) {
        printf("%c ", 'A' + j);  // colunas em letras
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d  ", i);
        for (int j = 0; j < TAM; j++) {
            if (visivel[i][j] == 0) {
                printf(". ");
            } else if (tabuleiro[i][j] == -1) {
                printf("* ");  // bomba
            } else {
                printf("%d ", tabuleiro[i][j]);  // número (por enquanto só 0)
            }
        }
        printf("\n");
    }
}

// Verifica se todas as casas seguras foram abertas
int venceu() {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] != -1 && visivel[i][j] == 0) {
                return 0; // ainda existe casa segura oculta
            }
        } 
    }
    return 1; // venceu!
}

int main() {
    srand(time(NULL));
    inicializar();

    int linha;
    char coluna;
    int ativo = 1;

    while (ativo) {
        imprimir();

        printf("\nDigite linha e coluna (ex: 2 B) ou -1 para sair: ");
        scanf("%d", &linha);

        if (linha == -1) {
            printf("\n👋 Você saiu do jogo.\n");
            break;
        }

        scanf(" %c", &coluna);  // lê a letra da coluna
        coluna = toupper(coluna);     // converte para maiúscula
        int col = coluna - 'A';       // transforma em índice da matriz

        if (linha < 0 || linha >= TAM || col < 0 || col >= TAM) {
            printf("\n⚠️ Posição inválida! Tente de novo.\n");
            continue;
        }

        if (tabuleiro[linha][col] == -1) {
            visivel[linha][col] = 1;
            imprimir();
            printf("\n💥 Você encontrou uma bomba! Fim de jogo.\n");
            ativo = 0;
        } else {
            visivel[linha][col] = 1;
            if (venceu()) {
                imprimir();
                printf("\n🎉 Parabéns! Você venceu o jogo!\n");
                ativo = 0;
            } else {
                printf("\n✅ Posição segura!\n");
            }
        }
    }

    return 0;
}
