#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;

    for (a = 1; a < 1000; a++) {
        for (b = a; b < 1000; b++) {  // começa em a para não repetir combinações
            c = (int) sqrt(a * a + b * b);
            if (c < 1000 && c * c == a * a + b * b) {
                printf("(%d, %d, %d)\n", a, b, c);
            }
        }
    }

    return 0;
}
