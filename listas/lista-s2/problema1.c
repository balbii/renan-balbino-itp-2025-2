#include <math.h>
#include <stdio.h>

int main() {

    float peso, altura;
    printf("Digite seu peso (kg) e altura (m): ");
    scanf("%f %f", &peso, &altura);
    float imc = peso / (altura * altura);
    printf("Seu IMC é: %.2f\n", imc);

    return 0;
}
