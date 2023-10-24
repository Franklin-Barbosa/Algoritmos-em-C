#include <stdio.h>
#include <math.h> // biblioteca de matemática padrão do C

int main() {
    double x1, y1, x2, y2;
    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);

    // Calcular a distância usando a fórmula
    double distancia = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    printf("Distância entre os pontos P e Q é: %.1lf\n", distancia);

    return 0;
}
