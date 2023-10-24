#include <stdio.h>

// programa para calcular e exibir a média ponderada de 2 notas 
// (nota1 = peso 6 e nota2 = peso 4).
float media(float nota1, float nota2){
    float m = ((nota1*6)+(nota2*4))/10;
    return m;
}
int main(){
    float nota1, nota2;
    scanf("%f %f", &nota1,&nota2);
    printf("Média = %.1f\n",media(nota1, nota2));
    return 0;
}