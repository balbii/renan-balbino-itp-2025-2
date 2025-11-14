#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);
    int grid_largada[20];
    int grid_chegada[20];

    for (int i = 0; i < n; i++) {
        scanf("%d", &grid_largada[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &grid_chegada[i]);
    }

    int max_ganho = 0;    
    int piloto_vencedor = -1; 
    int houve_empate = 0;   

    for (int piloto_id = 1; piloto_id <= n; piloto_id++) {
        
        int pos_largada = -1;
        int pos_chegada = -1;

        for (int i = 0; i < n; i++) {
            if (grid_largada[i] == piloto_id) {
                pos_largada = i + 1; 
                break; 
            }
        }

        for (int i = 0; i < n; i++) {
            if (grid_chegada[i] == piloto_id) {
                pos_chegada = i + 1;
                break; 
            }
        }

        int ganho = pos_largada - pos_chegada;

        if (ganho > max_ganho) {
            max_ganho = ganho;
            piloto_vencedor = piloto_id;
            houve_empate = 0; 
     } 
        else if (ganho == max_ganho && max_ganho > 0) {
            houve_empate = 1; 
        }
    }

    if (max_ganho == 0 || houve_empate == 1) {
        printf("empate\n");
    } else {
        printf("%d\n", piloto_vencedor);
    }

    return 0;
}