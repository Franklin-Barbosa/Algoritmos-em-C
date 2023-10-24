#include <stdio.h>
#include <math.h>

int main(){
  float p_saco;
  int q_gato_1, q_gato_2;
  printf("Qual o peso em kg do saco de racao? \n");
  scanf("%f", &p_saco);
  printf("Qual a quantidade de racao para gato 1 em gramas? \n");
  scanf("%d", &q_gato_1);
  printf("Qual a quantidade de racao para gato 2 em gramas? \n");
  scanf("%d", &q_gato_2);

  int consumo = (q_gato_1 + q_gato_2) * 5;
  int resto = (int)(p_saco * 1000) - consumo;
  resto = fmax(resto, 0.0);

  printf("Resto de racao apos cinco dias: %d gramas \n", resto);
  
  return 0;
}
