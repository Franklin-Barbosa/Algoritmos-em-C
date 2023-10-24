#include <stdio.h>

// programa que calcule a média aritmética de quatro números reais informados pelo usuário.
float media(float a, float b, float c, float d){
    float m = (a+b+c+d)/4;
    return m;
}
int main(){
    float a, b, c, d;
    scanf("%f %f %f %f", &a,&b,&c,&d);
    printf("Média = %.1f\n",media(a,b,c,d));
    return 0;
}