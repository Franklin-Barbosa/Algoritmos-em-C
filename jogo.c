#include <stdio.h>

int marcar_posicao(int x, int y, int jogador, int grade[3][3]) {
    if (x < 0 || x >= 3 || y < 0 || y >= 3 || grade[x][y] != 0) {
        return 0;
    }
    grade[x][y] = jogador;
    return 1;
}

int checar_vencedor(int grade[3][3]) {
    for (int i = 0; i < 3; i++) {
        // Verificar linha
        if (grade[i][0] != 0 && grade[i][0] == grade[i][1] && grade[i][1] == grade[i][2]) {
            return grade[i][0];
        }
        // Verificar coluna
        if (grade[0][i] != 0 && grade[0][i] == grade[1][i] && grade[1][i] == grade[2][i]) {
            return grade[0][i];
        }
    }
    // Verificar diagonal
    if (grade[0][0] != 0 && grade[0][0] == grade[1][1] && grade[1][1] == grade[2][2]) {
        return grade[0][0];
    }
    // Verificar a outra diagonal
    if (grade[0][2] != 0 && grade[0][2] == grade[1][1] && grade[1][1] == grade[2][0]) {
        return grade[0][2];
    }
    // Verificar empate
    int contador = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grade[i][j] != 0) {
                contador++;
            }
        }
    }
    if (contador == 9) {
        return -1; // Empate
    }
    return 0; // Partida não acabou
}

void print_grade(int grade[3][3]) {
    for (int l = 0; l < 3; l++) {
        printf("%d|%d|%d\n", grade[l][0], grade[l][1], grade[l][2]);
        if (l < 2) {
            printf("-----\n");
        }
    }
}

int main() {
    int grade[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int jogador = 1;

    print_grade(grade);
    while (checar_vencedor(grade) == 0) {
        printf("Jogador %d\n", jogador);
        int x, y;
        printf("Informe a linha: ");
        scanf("%d", &x);
        printf("Informe a coluna: ");
        scanf("%d", &y);

        int jogada_ok = marcar_posicao(x, y, jogador, grade);
        if (jogada_ok) {
            jogador = (jogador == 1) ? 2 : 1;
        } else {
            printf("Jogada inválida!\n");
        }
        print_grade(grade);
    }

    int vencedor = checar_vencedor(grade);
    if (vencedor == -1) {
        printf("Empate!\n");
    } else {
        printf("Jogador %d ganhou!\n", vencedor);
    }

    return 0;
}
