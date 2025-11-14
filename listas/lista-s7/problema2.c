#include <stdio.h>
#include <string.h>
#include <ctype.h>

int eh_brasileiro(const char *placa) {
    // Formato: LLL-AAAA (total 8 caracteres)
    if (strlen(placa) != 8) return 0;
    for (int i = 0; i < 3; i++)
        if (!isupper(placa[i])) return 0;
    if (placa[3] != '-') return 0;
    for (int i = 4; i < 8; i++)
        if (!isdigit(placa[i])) return 0;
    return 1;
}

int eh_mercosul(const char *placa) {
    // Formato: LLLALAA (total 7 caracteres)
    if (strlen(placa) != 7) return 0;
    for (int i = 0; i < 3; i++)
        if (!isupper(placa[i])) return 0;
    if (!isdigit(placa[3])) return 0;
    if (!isupper(placa[4])) return 0;
    if (!isdigit(placa[5])) return 0;
    if (!isdigit(placa[6])) return 0;
    return 1;
}

int main() {
    char placa[11];
    scanf("%s", placa);

    if (eh_brasileiro(placa)) {
        printf("brasileiro\n");
    } else if (eh_mercosul(placa)) {
        printf("mercosul\n");
    } else {
        printf("inválido\n");
    }
    return 0;
}
