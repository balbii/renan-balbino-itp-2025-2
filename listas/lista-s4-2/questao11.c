#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 4

int tab[N]; // tab[i] guarda a coluna onde a rainha da linha i está

// Verifica se pode colocar a rainha na linha atual
int podeColocar(int linha, int col) {
    for (int i = 0; i < linha; i++) {
        if (tab[i] == col) return 0; // mesma coluna
        if (abs(tab[i] - col) == abs(i - linha)) return 0; // mesma diagonal
    }
    return 1;
}

// Imprime uma solução encontrada
void imprimeSolucao() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tab[i] == j) printf(" Q ");
            else printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

// Backtracking recursivo
void resolve(int linha) {
    if (linha == N) {
        imprimeSolucao();
        return;
    }
    for (int col = 0; col < N; col++) {
        if (podeColocar(linha, col)) {
            tab[linha] = col;
            resolve(linha + 1);
        }
    }
}

int main() {
    resolve(0);
    return 0;
}
