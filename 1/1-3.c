#include <stdio.h>

int main() {
    float fahr = 0.0f;
    float celsius = 0.0f;
    float upper = 300.0f;
    float step = 20.0f;
    printf("=== Fahrenheit-Celsius Table ===\n");
    while (fahr <= upper) {
        celsius = (5.0f / 9.0f) * (fahr - 32.0f);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }
}