#include <stdio.h>

int main(){
  float salario;
  float vendas;
  printf("Informe o salario: \n");
  scanf("%f", &salario);
  printf("Informe o valor das vendas: \n");
  scanf("%f", &vendas);

  // Calcular a comissão (4% das vendas)
  float comissao = vendas * 0.04;

  // Calcular o salário final (salário fixo + comissão)
  float salarioFinal = salario + comissao;

  printf("Valor da Comissao: R$ %.2f \n", comissao);
  printf("Valor do Novo Salario: R$ %.2f \n", salarioFinal);
  
  return 0;
}
