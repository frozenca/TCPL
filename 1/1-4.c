#include <stdio.h>

int main() {
    float celsius = 0.0f;
    float fahr = 0.0f;
    float upper = 300.0f;
    float step = 20.0f;
    while (celsius <= upper) {
        fahr = 32.0f + (9.0f / 5.0f) * celsius;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }
}