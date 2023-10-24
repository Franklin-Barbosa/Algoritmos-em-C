#include <stdio.h>

int main() {
    double salario_base;
    printf("SALARIO ATUAL ......: R$ ");
    scanf("%lf", &salario_base);

    double aumento = salario_base * 0.10;
    double novo_salario = salario_base + aumento;

    printf("VALOR DO AUMENTO ...: R$ %.2f \n", aumento);
    printf("NOVO SALARIO .......: R$ %.2f \n", novo_salario);
    return 0;
}
