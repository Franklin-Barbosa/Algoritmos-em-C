#include <stdio.h>

int main() {
    int numero, inverso;

    // Solicita ao usuário que insira um número de 3 dígitos
    printf("Digite um número inteiro de 3 dígitos: ");
    scanf("%d", &numero);

    // Verifica se o número tem exatamente 3 dígitos
    if (numero >= 100 && numero <= 999) {
        // Calcula o inverso
        inverso = (numero % 10) * 100 + ((numero / 10) % 10) * 10 + (numero / 100);

        // Exibe o número invertido
        printf("O número invertido é: %d\n", inverso);
    } else {
        printf("Por favor, insira um número de 3 dígitos.\n");
    }

    return 0;
}
