struct elemento{ /* é permitida a alteração desta estrutura */
  char *termo;
  unsigned int *paginas;
  unsigned int n_paginas; /* quantidade de elementos do campo paginas */
};
typedef struct elemento entrada; /* NÂO é permitida a alteração desta instrução */

struct estrutura_indice{ /* Você DEVE definir os campos desta estrutura de acordo com sua implementação de índice */
  entrada *entradas;
  unsigned int tamanho;
};
typedef struct estrutura_indice indice; /* NÂO é permitida a alteração desta instrução */

/* NÃO é permitida a alteração dos protótipos das funções a seguir */
indice* criar_indice();
unsigned int tamanho(indice *ind);
entrada* localizar(indice *ind, char *termo_de_busca);
void inserir_entrada(indice *ind, char *termo, unsigned int *paginas, int n_paginas);
void atualizar_entrada(indice *ind, char *termo, unsigned int *paginas, int n_paginas);
void imprimir(indice *ind);
