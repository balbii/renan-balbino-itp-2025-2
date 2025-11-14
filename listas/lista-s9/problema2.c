#include <stdio.h>

int main() {
    int M;
    scanf("%d", &M);

    int amizades[100][100];
    int x;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &amizades[i][j]);
        }
    }

    scanf("%d", &x);

    for (int j = 0; j < M; j++) {
        
        if (j == x) {
            continue;
        }

        if (amizades[x][j] == 0) {
            int tem_amigo_comum = 0;

            for (int k = 0; k < M; k++) {
                if (amizades[x][k] == 1 && amizades[j][k] == 1) {
                    tem_amigo_comum = 1;
                    break;
                }
            }

            if (tem_amigo_comum == 1) {
                printf("%d ", j);
            }
        }
    }
    
    printf("\n");

    return 0;
}