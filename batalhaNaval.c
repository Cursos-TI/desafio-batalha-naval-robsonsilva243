#include <stdio.h>

#define BOARD_SIZE 10
#define SKILL_SIZE 5

// Definição do tabuleiro
int board[BOARD_SIZE][BOARD_SIZE] = {0};

// Matrizes de habilidade
int cone[SKILL_SIZE][SKILL_SIZE] = {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0},
};

int cruz[SKILL_SIZE][SKILL_SIZE] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0},
};

int octaedro[SKILL_SIZE][SKILL_SIZE] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0},
};

// Função para aplicar a matriz de habilidade no tabuleiro
void apply_skill(int skill[SKILL_SIZE][SKILL_SIZE], int start_row, int start_col) {
    for (int i = 0; i < SKILL_SIZE; i++) {
        for (int j = 0; j < SKILL_SIZE; j++) {
            if (skill[i][j] == 1) {
                int row = start_row + i - 2; // Centraliza a habilidade
                int col = start_col + j - 2; // Centraliza a habilidade
                if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
                    board[row][col] = 5; // Marcando a área afetada
                }
            }
        }
    }
}

// Função para exibir o tabuleiro
void display_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                printf("0 "); // Água
            } else if (board[i][j] == 3) {
                printf("3 "); // Navio
            } else if (board[i][j] == 5) {
                printf("5 "); // Área afetada pela habilidade
            }
        }
        printf("\n");
    }
}

int main() {
    // Posicionando navios (exemplo)
    board[4][4] = 3; // Colocando um navio no tabuleiro

    // Aplicando habilidades
    apply_skill(cone, 4, 4); // A habilidade Cone a partir da posição (4, 4)
    apply_skill(cruz, 2, 2); // A habilidade Cruz a partir da posição (2, 2)
    apply_skill(octaedro, 6, 6); // A habilidade Octaedro a partir da posição (6, 6)

    // Exibindo o tabuleiro
    display_board();

    return 0;
}