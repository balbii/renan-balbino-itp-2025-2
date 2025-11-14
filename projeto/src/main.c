#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_NOME 50

int **tabuleiro;    // 0 = vazio, -1 = bomba
int **visivel;      // 0 = oculto, 1 = revelado
int TAM;            // tamanho do tabuleiro (definido pelo usuário)
int BOMBAS;         // número de bombas (definido como TAM)

void inicializar() {
    // Aloca dinamicamente tabuleiro e visivel
    tabuleiro = malloc(TAM * sizeof(int*));
    visivel = malloc(TAM * sizeof(int*));
    for (int i = 0; i < TAM; i++) {
        tabuleiro[i] = malloc(TAM * sizeof(int));
        visivel[i] = malloc(TAM * sizeof(int));
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

void calcular_perigo() {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == -1) continue;
            int cont = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    int nx = i + dx;
                    int ny = j + dy;
                    if (nx >= 0 && nx < TAM && ny >= 0 && ny < TAM) {
                        if (tabuleiro[nx][ny] == -1) cont++;
                    }
                }
            }
            tabuleiro[i][j] = cont;
        }
    }
}

void imprimir() {
    printf("\n   ");
    for (int j = 0; j < TAM; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d  ", i+1);
        for (int j = 0; j < TAM; j++) {
            if (visivel[i][j] == 0) {
                printf(". ");
            } else if (tabuleiro[i][j] == -1) {
                printf("* ");
            } else {
                printf("%d ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
}

int venceu() {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] != -1 && visivel[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void liberar_memoria() {
    for (int i = 0; i < TAM; i++) {
        free(tabuleiro[i]);
        free(visivel[i]);
    }
    free(tabuleiro);
    free(visivel);
}

int main() {
    srand(time(NULL));

    char nome[MAX_NOME];
    printf("Digite seu nome: ");
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = 0; // remove o \n

    printf("Olá, %s!\n", nome);

    printf("Escolha o tamanho do tabuleiro (mínimo 3, máximo 7): ");
    scanf("%d", &TAM);
    if (TAM < 3) TAM = 3;
    if (TAM > 7) TAM = 7;
    BOMBAS = TAM; // define bombas igual ao tamanho

    inicializar();
    calcular_perigo();

    int linha;
    char coluna;
    int ativo = 1;

    while (ativo) {
        imprimir();
        printf("\nDigite linha e coluna (ex: 2 B) ou -1 para sair: ");
        int entrada_linha;
        scanf("%d", &entrada_linha);

        if (entrada_linha == -1) {
            printf("\n👋 Você saiu do jogo.\n");
            break;
        }

        linha = entrada_linha - 1;
        scanf(" %c", &coluna);
        coluna = toupper(coluna);
        int col = coluna - 'A';

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
                printf("\n🎉 Parabéns, %s! Você venceu o jogo!\n", nome);
                ativo = 0;
            } else {
                printf("\n✅ Posição segura!\n");
            }
        }
    }

    liberar_memoria();
    return 0;
}
