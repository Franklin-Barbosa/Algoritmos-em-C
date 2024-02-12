#include "indice.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar_entradas(const void *a, const void *b) {
    return strcmp(((entrada*)a)->termo, ((entrada*)b)->termo);
}

indice* criar_indice() {
    indice *ind = (indice*)malloc(sizeof(indice));
    if (ind == NULL) {
        exit(EXIT_FAILURE);
    }

    ind->entradas = NULL;
    ind->tamanho = 0;

    return ind;
}

unsigned int tamanho(indice *ind) {
    return ind->tamanho;
}

entrada* localizar(indice *ind, char *termo_de_busca) {
    unsigned int i;
    for (i = 0; i < ind->tamanho; i++) {
        if (strcmp(ind->entradas[i].termo, termo_de_busca) == 0) {
            return &(ind->entradas[i]);
        }
    }
    return NULL;
}

void inserir_entrada(indice *ind, char *termo, unsigned int *paginas, int n_paginas) {
    ind->entradas = (entrada*)realloc(ind->entradas, (ind->tamanho + 1) * sizeof(entrada));
    if (ind->entradas == NULL) {
        exit(EXIT_FAILURE);
    }

    ind->entradas[ind->tamanho].termo = strdup(termo);
    if (ind->entradas[ind->tamanho].termo == NULL) {
        exit(EXIT_FAILURE);
    }

    ind->entradas[ind->tamanho].paginas = (unsigned int*)malloc(n_paginas * sizeof(unsigned int));
    if (ind->entradas[ind->tamanho].paginas == NULL) {
        exit(EXIT_FAILURE);
    }
    memcpy(ind->entradas[ind->tamanho].paginas, paginas, n_paginas * sizeof(unsigned int));

    ind->entradas[ind->tamanho].n_paginas = n_paginas;
    ind->tamanho++;

    qsort(ind->entradas, ind->tamanho, sizeof(entrada), comparar_entradas);
}

void atualizar_entrada(indice *ind, char *termo, unsigned int *paginas, int n_paginas) {
    entrada *encontrada = localizar(ind, termo);

    if (encontrada != NULL) {
        free(encontrada->paginas);

        encontrada->paginas = (unsigned int*)malloc(n_paginas * sizeof(unsigned int));
        if (encontrada->paginas == NULL) {
            exit(EXIT_FAILURE);
        }
        memcpy(encontrada->paginas, paginas, n_paginas * sizeof(unsigned int));

        encontrada->n_paginas = n_paginas;
    }
}

void liberar_indice(indice *ind) {
    if (ind == NULL) {
        return;
    }
    unsigned int i;
    for (i = 0; i < ind->tamanho; i++) {
        free(ind->entradas[i].termo);
        free(ind->entradas[i].paginas);
    }

    free(ind->entradas);

    free(ind);
}

void imprimir(indice *ind) {
    unsigned int i;
    for (i = 0; i < ind->tamanho; i++) {
        printf("%s, ", ind->entradas[i].termo);
        int j;
        for (j = 0; j < ind->entradas[i].n_paginas; j++) {
            printf("%u%s", ind->entradas[i].paginas[j], (j == ind->entradas[i].n_paginas - 1) ? "\n" : ", ");
        }
    }
}
