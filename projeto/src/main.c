#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

int **tabuleiro;    // 0 = vazio, -1 = bomba
int **visivel;      // 0 = oculto, 1 = revelado
int TAM = 4;        // padrão
int BOMBAS = 4;     // padrão

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

void creditos() {
    printf("\n=== CRÉDITOS ===\n");
    printf("Projeto desenvolvido por Renan Balbino.\n");
    printf("ITP - 2025\n");
}

void configurar_tabuleiro() {
    int novo_tam, novas_bombas;
    printf("\n=== CONFIGURAR TABULEIRO ===\n");
    printf("Digite o tamanho do tabuleiro (mínimo 3, máximo 7): ");
    scanf("%d", &novo_tam);
    if (novo_tam < 3) novo_tam = 3;
    if (novo_tam > 7) novo_tam = 7;
    printf("Digite o número de bombas (mínimo 1, máximo %d): ", novo_tam * 2);
    scanf("%d", &novas_bombas);
    if (novas_bombas < 1) novas_bombas = 1;
    if (novas_bombas > novo_tam * 2) novas_bombas = novo_tam * 2;
    TAM = novo_tam;
    BOMBAS = novas_bombas;
    printf("Configuração atual: Tabuleiro %dx%d, Bombas: %d\n", TAM, TAM, BOMBAS);
}

// FloodFill: revela blocos conectados de zeros
void floodFill(int **visivel, int **vizinhos, int l, int c, int linhas, int colunas) {
    // Fora dos limites
    if (l < 0 || l >= linhas || c < 0 || c >= colunas) return;
    // Já revelada
    if (visivel[l][c] == 1) return;
    // Revela a casa
    visivel[l][c] = 1;
    // Se tem bombas ao redor, não expande
    if (vizinhos[l][c] > 0) return;
    // Se é zero, expande para os 8 vizinhos
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            floodFill(visivel, vizinhos, l + dx, c + dy, linhas, colunas);
        }
    }
}

void jogar(const char* nome) {
    inicializar();
    calcular_perigo();

    int linha;
    char coluna;
    int ativo = 1;

    // Início do tempo
    time_t inicio = time(NULL);

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
            // Se é zero, revela bloco de zeros
            if (tabuleiro[linha][col] == 0) {
                floodFill(visivel, tabuleiro, linha, col, TAM, TAM);
            } else {
                visivel[linha][col] = 1;
            }
            if (venceu()) {
                imprimir();
                printf("\n🎉 Parabéns, %s! Você venceu o jogo!\n", nome);
                ativo = 0;
            } else {
                printf("\n✅ Posição segura!\n");
            }
        }
    }

    // Fim do tempo
    time_t fim = time(NULL);
    double tempo = difftime(fim, inicio);
    printf("\n⏱️ Tempo de jogo: %.0f segundos\n", tempo);

    liberar_memoria();
}

int main() {
    srand(time(NULL));
    char nome[20];

    printf("Digite seu nome: ");
    fgets(nome, 20, stdin);
    nome[strcspn(nome, "\n")] = 0;

    int opcao = 0;
    while (1) {
        printf("\n=== CAMPO MINADO ===\n");
        printf("1. Jogar\n");
        printf("2. Configurar o tabuleiro\n");
        printf("3. Créditos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            jogar(nome);
        } else if (opcao == 2) {
            configurar_tabuleiro();
        } else if (opcao == 3) {
            creditos();
        } else if (opcao == 4) {
            printf("\nSaindo...\n");
            break;
        } else {
            printf("\nOpção inválida!\n");
        }
    }
    return 0;
}
