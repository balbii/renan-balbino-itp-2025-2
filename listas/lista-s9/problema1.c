#include <stdio.h>

int main() {
    int M, N;
    int campo[10][10];
    int irrigado[10][10] = {0}; 
    
    int ferteis_irrigados = 0;
    int ferteis_nao_irrigados = 0;

    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &campo[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (campo[i][j] == 2) {
                irrigado[i - 1][j] = 1; 
                irrigado[i + 1][j] = 1; 
                irrigado[i][j + 1] = 1; 
                irrigado[i][j - 1] = 1; 
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (campo[i][j] == 1) {
                if (irrigado[i][j] == 1) {
                    ferteis_irrigados++;
                } else {
                    ferteis_nao_irrigados++;
                }
            }
        }
    }

    printf("%d %d\n", ferteis_irrigados, ferteis_nao_irrigados);

    return 0;
}

