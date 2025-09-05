#include<stdio.h>
#include<math.h>

int main() {
    float a, b, c; //lados do triângulo
    printf("Digite os três lados do triângulo: ");
    scanf("%f %f %f", &a, &b, &c);  

    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            printf("Triângulo Equilátero\n");
        } else if (a == b || a == c || b == c) {
            printf("Triângulo Isósceles\n");
        } else {
            printf("Triângulo Escaleno\n");
        }
        if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b) {
            printf("O triângulo é retângulo\n");
        } else if (a*a > b*b + c*c || b*b > a*a + c*c || c*c > a*a + b*b) {
            printf("O triângulo é obtusângulo\n");
        } else {
            printf("O triângulo é acutângulo\n");
        }
    } else {
        printf("Não é um triângulo válido\n");
    }

    return 0;
}