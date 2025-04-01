#include <stdio.h>

#define TamanhoTabuleiro 10
#define TamanhoNavio 3

int main() {
    // Representa o tabuleiro
    int tabuleiro[TamanhoTabuleiro][TamanhoTabuleiro] = {0};

    // Coordenadas do navio horizontal
    int linhaHorizontal = 2;
    int colunaHorizontal = 3;

    // Coordenadas do navio vertical
    int linhaVertical = 5;
    int colunaVertical = 5;

    // Posiciona o navio horizontal
    for (int i = 0; i < TamanhoNavio; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
    }

    // Posiciona o navio vertical
    for (int i = 0; i < TamanhoNavio; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = 3;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TamanhoTabuleiro; i++) {
        for (int j = 0; j < TamanhoTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
