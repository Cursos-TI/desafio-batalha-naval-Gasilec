#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define TAM_HABILIDADE 5


//tem que estar fora o int main, pois teram variaveis que só vou usar aqui;
int aplicarHabilidade(int matriz[LINHAS][COLUNAS], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int linhaOrigem, int colunaOrigem) {
    int centro = 2; // Centro da matriz 5x5 (posição [2][2]) pra definir o centro basta criar didir a habilidade por 2, independente se fica 1 ou da 0, é o nunero 5/2 = 2

    for (int i = 0; i < TAM_HABILIDADE; i++) {          // Varre as linhas da matriz da habilidade
        for (int j = 0; j < TAM_HABILIDADE; j++) {      // Varre as colunas da matriz da habilidade
            if (habilidade[i][j] == 1) {   // Só aplica onde estiver marcado com 1
                int linhaAlvo = linhaOrigem - centro + i;     // Calcula linha no tabuleiro
                int colunaAlvo = colunaOrigem - centro + j;   // Calcula coluna no tabuleiro

                // Não vai deixar sair dos limites do tabuleiro
                if (linhaAlvo >= 0 && linhaAlvo < LINHAS && colunaAlvo >= 0 && colunaAlvo < COLUNAS) {
                    matriz[linhaAlvo][colunaAlvo] = 5;  // Marca como área afetada
                }
            }
        }
    }

    return 0; // Indica que terminou normalmente
}

int main() {
    int matriz[LINHAS][COLUNAS];

    // Inicializar matriz com 0 (mar)
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = 0;
        }
    }

    // Posicição navio vertical (1)
    int linha1 = 3;
    int coluna1 = 4;
    for (int i = 0; i < 3; i++) {
        matriz[linha1 + i][coluna1] = 3;
    }

    // Posicição navio horizontal (2)
    int linha2 = 8;
    int coluna2 = 1;
    for (int i = 0; i < 3; i++) {
        matriz[linha2][coluna2 + i] = 2;
    }

    // Vertical diagonal simples (3)
    int linha3 = 7;
    int coluna3 = 5;
    for (int i = 0; i < 3; i++) {
        matriz[linha3 + i][coluna3 + i] = 3;
    }

    // Navio na diagonal mais difícil (4)
    int linha4 = 1;
    int coluna4 = 8;
    for (int i = 0; i < 3; i++) {
        matriz[linha4 + i][coluna4 - i] = 2;
    }

    //###MATRIZES DE HABILIDADE (5x5)### Foi complicado chegar na conclusão q tinha q desenhar, espero q tenha outra forma kk eu resolvi fazer como o professor e poupar espaço na vertical.
    int cone[TAM_HABILIDADE][TAM_HABILIDADE] = {{0, 0, 1, 0, 0}, {0, 1, 1, 1, 0}, {1, 1, 1, 1, 1}, {0, 0, 0, 0, 0},{0, 0, 0, 0, 0}
    };

    int cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {{0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}, {1, 1, 1, 1, 1}, {0, 0, 1, 0, 0},{0, 0, 1, 0, 0}
    };

    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {{0, 0, 1, 0, 0}, {0, 1, 1, 1, 0}, {1, 1, 1, 1, 1}, {0, 1, 1, 1, 0}, {0, 0, 1, 0, 0} 
    };

    aplicarHabilidade(matriz, cone, 2, 4);      // origem linha 2, coluna 4 (terceira linha, quinta coluna)
    aplicarHabilidade(matriz, cruz, 5, 7);      // origem linha 5, coluna 7
    aplicarHabilidade(matriz, octaedro, 7, 2);  // origem linha 7, coluna 2

    printf("BATALHA NAVAL!!!! THE GAME\n\n");

    // letras A a J no cabeçalho
    printf("   ");
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf(" %c", letra);
    }
    printf("\n");

    // linhas numeradas de 1 a 10
    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < COLUNAS; j++) {
            printf(" %d", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}

//cara, esse foi difícil...