#include <math.h>
#include <stdio.h>

int main() {
    float consumo, valorConta;
    char tipoConsumidor;
    printf("Digite o consumo de energia (kWh) e o tipo de consumidor (R, C, I): ");
    scanf("%f %c", &consumo, &tipoConsumidor);

    if (tipoConsumidor == 'R' || tipoConsumidor == 'r') {
        valorConta = 15 + consumo * 0.60;
    } else if (tipoConsumidor == 'C' || tipoConsumidor == 'c') {
        valorConta = 15 + consumo * 0.48;
    } else if (tipoConsumidor == 'I' || tipoConsumidor == 'i') {
        valorConta = 15 + consumo * 1.29;
    } else {
        printf("Tipo de consumidor inválido.\n");
        return 1;
    }
    printf("Valor da conta de energia: R$ %.2f\n", valorConta);

    return 0;
}