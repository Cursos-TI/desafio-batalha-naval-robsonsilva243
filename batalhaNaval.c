#include <stdio.h>

#define TAM 10 // Tamanho do tabuleiro
#define NAVIO 3 // Representação dos navios

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar os navios
int posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int orientacao, int tamanho) {
    // Verifica se a posição é válida
    for (int i = 0; i < tamanho; i++) {
        int l = linha + (orientacao == 0 ? 0 : (orientacao == 1 ? i : (orientacao == 2 ? i : -i)));
        int c = coluna + (orientacao == 0 ? i : (orientacao == 1 ? 0 : (orientacao == 2 ? -i : i)));
        
        if (l < 0 || l >= TAM || c < 0 || c >= TAM || tabuleiro[l][c] != 0) {
            return 0; // Posição inválida
        }
    }
    
    // Posiciona o navio
    for (int i = 0; i < tamanho; i++) {
        int l = linha + (orientacao == 0 ? 0 : (orientacao == 1 ? i : (orientacao == 2 ? i : -i)));
        int c = coluna + (orientacao == 0 ? i : (orientacao == 1 ? 0 : (orientacao == 2 ? -i : i)));
        tabuleiro[l][c] = NAVIO; // Coloca o navio
    }
    return 1; // Posição válida e navio posicionado
}

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Inicializa o tabuleiro com água
    int navioTamanho = 3; // Tamanho fixo do navio
    int sucesso;

    // Posiciona os navios
    sucesso = posicionarNavio(tabuleiro, 0, 0, 0, navioTamanho); // Horizontal
    sucesso &= posicionarNavio(tabuleiro, 2, 2, 1, navioTamanho); // Vertical
    sucesso &= posicionarNavio(tabuleiro, 5, 5, 2, navioTamanho); // Diagonal para baixo
    sucesso &= posicionarNavio(tabuleiro, 8, 5, 3, navioTamanho); // Diagonal para cima

    // Exibe o tabuleiro após o posicionamento dos navios
    exibirTabuleiro(tabuleiro);

    return 0;
}