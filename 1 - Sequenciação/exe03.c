#include <stdio.h>

// lê dois números inteiros a e b (−106 ≤ a, b ≤ 106) e mostra a soma dos mesmos.
// int soma(int a, int b){
// int s = a+b;
//     return s;
// }
// int main(){
// int a,b;
//     scanf("%d %d",&a,&b);
//     printf("%d\n",soma(a,b));
//     return 0;
// }

// multiplicação, ao invés da soma, entre a e b.
int mult(int a, int b){
    int s = a*b;
    return s;
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",mult(a,b));
    return 0;
}