#include <math.h>
#include <stdio.h>

int main() {

    float peso, altura;
    printf("Digite seu peso (kg) e altura (m): ");
    scanf("%f %f", &peso, &altura);
    float imc = peso / (altura * altura);
    printf("Seu IMC é: %.2f\n", imc);

    if (imc < 18.5) {
        printf("Classificação: Abaixo do peso\n");
    } else if (imc < 24.9) {
        printf("Classificação: Peso normal\n");
    } else if (imc < 29.9) {
        printf("Classificação: Sobrepeso\n");
    } else {
        printf("Classificação: Obesidade\n");
    }

    return 0;
}