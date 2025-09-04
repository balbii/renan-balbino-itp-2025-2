#include <math.h>
#include <stdio.h>  

int main() {
    
    float capitalInicial, taxaJuros, tempo;
    printf("Digite o capital inicial, a taxa de juros (em porcentagem) e o tempo (em anos): ");
    scanf("%f %f %f", &capitalInicial, &taxaJuros, &tempo);

    float montante = capitalInicial * pow((1 + taxaJuros / 100), tempo);
    printf("O montante após %.1f anos é: R$%.2f\n", tempo, montante);
    
    return 0;
}