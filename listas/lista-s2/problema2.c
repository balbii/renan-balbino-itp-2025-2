#include <math.h>
#include <stdio.h>

int main() {
    
    float celsius;
    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &celsius);
    float fahrenheit = (celsius * 9/5) + 32;
    printf("A temperatura em Fahrenheit é: %.1f\n", fahrenheit);
    float kelvin = celsius + 273.15;
    printf("A temperatura em Kelvin é: %.1f\n", kelvin);

    return 0;
}