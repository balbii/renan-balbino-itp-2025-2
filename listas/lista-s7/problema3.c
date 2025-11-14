#include <stdio.h>
#include <string.h>
#include <ctype.h>

int eh_data(const char *s) {
    // Verifica se está no formato DD/MM
    return strlen(s) == 5 && isdigit(s[0]) && isdigit(s[1]) && s[2] == '/' && isdigit(s[3]) && isdigit(s[4]);
}

int main() {
    char aluno[11];
    char relatorio[1001];
    
    scanf("%s", aluno);
    getchar(); // Consome o \n após o nome
    fgets(relatorio, 1000, stdin);

    int faltas = 0;
    char *token = strtok(relatorio, " \n");
    int presente = 0;

    while (token) {
        if (eh_data(token)) {
            // Nova aula, reseta presença
            if (presente == 0 && faltas > 0) faltas++; // já contou na aula anterior
            presente = 0;
            faltas++; // Assume falta, vai corrigir se achar o aluno
        } else if (strcmp(token, aluno) == 0) {
            // Encontrou o aluno, está presente nesta aula
            if (presente == 0) {
                presente = 1;
                faltas--; // Corrige a falta assumida
            }
        }
        token = strtok(NULL, " \n");
    }

    if (faltas < 0) faltas = 0;
    printf("%d\n", faltas);
    
    return 0;
}