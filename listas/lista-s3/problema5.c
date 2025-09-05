#include <math.h>
#include <stdio.h>

int main() {

    float valorCompra, desconto;
    printf("Digite o valor da compra: ");
    scanf("%f", &valorCompra);

    if (valorCompra > 1000) {
        valorCompra *= 0.8; // Aplica 20% de desconto
        desconto = valorCompra * 0.2;
        printf("Desconto aplicado: R$ %.2f\n", desconto);
    } else if (valorCompra >= 500) {
        valorCompra *= 0.85; // Aplica 15% de desconto
        desconto = valorCompra * 0.15;
        printf("Desconto aplicado: R$ %.2f\n", desconto);
    } else if (valorCompra >= 100) {
        valorCompra *= 0.9; // Aplica 10% de desconto
        desconto = valorCompra * 0.1;
        printf("Desconto aplicado: R$ %.2f\n", desconto);
    } else {
        printf("Nenhum desconto aplicado.\n");
    }

    printf("Valor a pagar: R$ %.2f\n", valorCompra);
    
    return 0;
}