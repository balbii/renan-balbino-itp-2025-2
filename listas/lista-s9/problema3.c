#include <stdio.h>

int main() {
    int M;
    scanf("%d", &M);

    int placares[20][20];
    int empates = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &placares[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            if (placares[i][j] == placares[j][i]) {
                empates++;
            }
        }
    }

    printf("%d\n", empates);

    return 0;
}