#include <stdio.h>

float fah2cel(float far) {
    return (5.0f / 9.0f) * (far - 32.0f);
}

int main() {
    float fahr = 0.0f;
    float celsius = 0.0f;
    float upper = 300.0f;
    float step = 20.0f;
    printf("=== Fahrenheit-Celsius Table ===\n");
    while (fahr <= upper) {
        celsius = fah2cel(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }
}