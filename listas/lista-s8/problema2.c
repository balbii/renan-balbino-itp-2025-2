#include <stdio.h>
#include <string.h>

int main() {
    int chuva[12];
    char *meses[12] = {
        "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    for (int i = 0; i < 12; i++) {
        scanf("%d", &chuva[i]);
    }

    // Selection sort decrescente
    for (int i = 0; i < 12 - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < 12; j++) {
            if (chuva[j] > chuva[max_idx]) {
                max_idx = j;
            }
        }
        // Troca chuva
        int temp = chuva[i];
        chuva[i] = chuva[max_idx];
        chuva[max_idx] = temp;
        // Troca meses
        char *tmp_mes = meses[i];
        meses[i] = meses[max_idx];
        meses[max_idx] = tmp_mes;
    }

    for (int i = 0; i < 12; i++) {
        printf("%d %s\n", chuva[i], meses[i]);
    }
    return 0;
}
