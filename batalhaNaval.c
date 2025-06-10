#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    int matriz[10][10];

    // Inicializar matriz com 0 (mar)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz[i][j] = 0; //faz quando a tabela for impressa aparecer só o numero 0, se n tivesse ia ser uma mini tabuada
        }
    }

    // Posicição navio vertical (1)
    int linha1 = 3; // A contagem sempre começa no 0, ou 2 ali, significa que vai mover 0 e 1, qe an tabela vai cair no nº3;
    int coluna1 = 4; // pela mesma logica que em cima, vai ir ABC e aprar no D. Com os dois juntos começa na casa D3;
    for (int i = 0; i < 3; i++) { //com isso to falando, o i que começa vale 0, acrescenta 3 vezes (0,1 e 2) e para;
        matriz[linha1 + i][coluna1] = 3;      //aqui direciona pra onde o acrescimo vai, como ta no linha o "+ i" ele vai acrescentar 
    }                                         //a partir do ponto inicial 3 vezes em direção ao 10, colocando o número 3 que pedi;

    // Posicição navio horizontal (2)
    int linha2 = 8; // linha 8
    int coluna2 = 1; // coluna B
    for (int i = 0; i < 3; i++) {
        matriz[linha2][coluna2 + i] = 3; //como no de cima, aqui ta na coluna, então vai percorres as caras a partir da inicial, horizontalmente
    }

    // letras A a J no cabeçalho
    printf("   "); // Espaço para alinhar com os números da esquerda
    for (char letra = 'A'; letra <= 'J'; letra++) {
        printf(" %c", letra);// o espaço no %c faz dar margem e um espaçamento melhor
    }
    printf("\n");//importante pra formatação e parecer um jogo da velha

    // linhas numeradas de 1 a 10
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1); // Números da linha (1 a 10) o "i + 1"" faz a contagem começar do 1 (i = 0, 0 + 1 = 1). (o %2d deixa bonitinho e organizado)
        for (int j = 0; j < 10; j++) {
            printf(" %d", matriz[i][j]); //com os 2 for aqui, to fazendo imprimir a tabela 10 x 10, que já denifi no inico que apareceria paenas o nº 0;
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0