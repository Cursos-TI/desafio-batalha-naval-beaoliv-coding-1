#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TAMANHO 10   // Tamanho do tabuleiro (10x10)
#define TAM_NAVIO 3  // Tamanho fixo de cada navio


int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

 /* =========================================
       1. REPRESENTAÇÃO DO TABULEIRO
       Matriz 10x10 inicializada com 0 (água)
    ========================================= */
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    /* =========================================
       2. DECLARAÇÃO DOS NAVIOS
       Cada navio é um vetor de 3 posições com valor 3
    ========================================= */
    int navio1[TAM_NAVIO] = {3, 3, 3}; // Navio horizontal
    int navio2[TAM_NAVIO] = {3, 3, 3}; // Navio vertical

    /* =========================================
       COORDENADAS INICIAIS DOS NAVIOS
       navio1: horizontal, começa em linha 2, coluna 1
       navio2: vertical,   começa em linha 5, coluna 7
    ========================================= */
    int linha1 = 2, coluna1 = 1; // Coordenadas do navio horizontal
    int linha2 = 5, coluna2 = 7; // Coordenadas do navio vertical

    /* =========================================
       VALIDAÇÃO DO NAVIO HORIZONTAL
       Verifica se o navio cabe dentro do tabuleiro
       (coluna inicial + tamanho não pode ultrapassar 10)
    ========================================= */
    if (linha1 < 0 || linha1 >= TAMANHO ||
        coluna1 < 0 || coluna1 + TAM_NAVIO > TAMANHO) {
        printf("Erro: Navio 1 fora dos limites do tabuleiro!\n");
        return 1;
    }

    /* =========================================
       VALIDAÇÃO DO NAVIO VERTICAL
       Verifica se o navio cabe dentro do tabuleiro
       (linha inicial + tamanho não pode ultrapassar 10)
    ========================================= */
    if (linha2 < 0 || linha2 + TAM_NAVIO > TAMANHO ||
        coluna2 < 0 || coluna2 >= TAMANHO) {
        printf("Erro: Navio 2 fora dos limites do tabuleiro!\n");
        return 1;
    }

    /* =========================================
       POSICIONAMENTO DO NAVIO 1 (HORIZONTAL)
       Copia o valor 3 para as colunas da linha fixada
    ========================================= */
    for (int i = 0; i < TAM_NAVIO; i++) {
        // Verifica sobreposição antes de posicionar
        if (tabuleiro[linha1][coluna1 + i] != 0) {
            printf("Erro: Navios se sobrepoem!\n");
            return 1;
        }
        tabuleiro[linha1][coluna1 + i] = navio1[i];
    }

    /* =========================================
       POSICIONAMENTO DO NAVIO 2 (VERTICAL)
       Copia o valor 3 para as linhas da coluna fixada
    ========================================= */
    for (int i = 0; i < TAM_NAVIO; i++) {
        // Verifica sobreposição antes de posicionar
        if (tabuleiro[linha2 + i][coluna2] != 0) {
            printf("Erro: Navios se sobrepoem!\n");
            return 1;
        }
        tabuleiro[linha2 + i][coluna2] = navio2[i];
    }

    /* =========================================
       3. EXIBIÇÃO DO TABULEIRO
       Loop aninhado percorre linhas e colunas
       0 = água | 3 = navio
    ========================================= */
    printf("Tabuleiro Batalha Naval:\n\n");

    // Cabeçalho com números das colunas
    printf("  ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%d ", j);
    }
    printf("\n");

    // Linhas do tabuleiro
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i); // Número da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]); // Valor da célula
        }
        printf("\n");
    }
return 0;

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

#include <stdio.h>

#define TAMANHO   10  // Dimensão do tabuleiro (10x10)
#define TAM_NAVIO  3  // Tamanho fixo de cada navio
#define AGUA       0  // Valor que representa água
#define NAVIO      3  // Valor que representa parte de um navio

/* =====================================================
   FUNÇÃO: posicionar_horizontal
   Valida e posiciona um navio na horizontal.
   Parâmetros:
     - tabuleiro: a matriz do jogo
     - linha, coluna: coordenada inicial do navio
   Retorno: 1 se ok, 0 se inválido
===================================================== */
int posicionar_horizontal(int tabuleiro[TAMANHO][TAMANHO],
                          int linha, int coluna) {
    // Verifica se o navio ultrapassa o limite direito
    if (coluna + TAM_NAVIO > TAMANHO) {
        printf("Erro: navio horizontal fora dos limites [%d][%d]\n",
               linha, coluna);
        return 0;
    }

    // Verifica sobreposição
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != AGUA) {
            printf("Erro: sobreposição no navio horizontal [%d][%d]\n",
                   linha, coluna);
            return 0;
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
    return 1;
}

/* =====================================================
   FUNÇÃO: posicionar_vertical
   Valida e posiciona um navio na vertical.
===================================================== */
int posicionar_vertical(int tabuleiro[TAMANHO][TAMANHO],
                        int linha, int coluna) {
    // Verifica se o navio ultrapassa o limite inferior
    if (linha + TAM_NAVIO > TAMANHO) {
        printf("Erro: navio vertical fora dos limites [%d][%d]\n",
               linha, coluna);
        return 0;
    }

    // Verifica sobreposição
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != AGUA) {
            printf("Erro: sobreposição no navio vertical [%d][%d]\n",
                   linha, coluna);
            return 0;
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
    return 1;
}

/* =====================================================
   FUNÇÃO: posicionar_diagonal_principal
   Valida e posiciona navio na diagonal ↘
   (linha e coluna aumentam juntas)
===================================================== */
int posicionar_diagonal_principal(int tabuleiro[TAMANHO][TAMANHO],
                                  int linha, int coluna) {
    // Verifica se o navio ultrapassa os limites inferior e direito
    if (linha + TAM_NAVIO > TAMANHO || coluna + TAM_NAVIO > TAMANHO) {
        printf("Erro: navio diagonal principal fora dos limites [%d][%d]\n",
               linha, coluna);
        return 0;
    }

    // Verifica sobreposição
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != AGUA) {
            printf("Erro: sobreposição no navio diagonal principal [%d][%d]\n",
                   linha, coluna);
            return 0;
        }
    }

    // Posiciona o navio: linha e coluna crescem juntas
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = NAVIO;
    }
    return 1;
}

/* =====================================================
   FUNÇÃO: posicionar_diagonal_secundaria
   Valida e posiciona navio na diagonal ↙
   (linha aumenta, coluna diminui)
===================================================== */
int posicionar_diagonal_secundaria(int tabuleiro[TAMANHO][TAMANHO],
                                   int linha, int coluna) {
    // Verifica se o navio ultrapassa os limites inferior e esquerdo
    if (linha + TAM_NAVIO > TAMANHO || coluna - TAM_NAVIO + 1 < 0) {
        printf("Erro: navio diagonal secundaria fora dos limites [%d][%d]\n",
               linha, coluna);
        return 0;
    }

    // Verifica sobreposição
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna - i] != AGUA) {
            printf("Erro: sobreposição no navio diagonal secundaria [%d][%d]\n",
                   linha, coluna);
            return 0;
        }
    }

    // Posiciona o navio: linha cresce, coluna decresce
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = NAVIO;
    }
    return 1;
}

/* =====================================================
   FUNÇÃO: exibir_tabuleiro
   Exibe a matriz completa com cabeçalho de índices
===================================================== */
void exibir_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n  Tabuleiro Batalha Naval\n\n");

    // Cabeçalho das colunas
    printf("   ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%d ", j);
    }
    printf("\n   ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("--");
    }
    printf("\n");

    // Linhas da matriz
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d |", i); // Índice da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n  Legenda: 0 = agua  |  3 = navio\n");
}

/* =====================================================
   MAIN
===================================================== */
int main() {

    /* -------------------------------------------------
       1. TABULEIRO: matriz 10x10 inicializada com água
    ------------------------------------------------- */
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    /* -------------------------------------------------
       2. POSICIONAMENTO DOS QUATRO NAVIOS

       Navio 1 — Horizontal:  linha 1, coluna 2  →  [1][2..4]
       Navio 2 — Vertical:    linha 5, coluna 7  →  [5..7][7]
       Navio 3 — Diagonal ↘:  linha 0, coluna 0  →  [0][0],[1][1],[2][2]
       Navio 4 — Diagonal ↙:  linha 0, coluna 9  →  [0][9],[1][8],[2][7]
    ------------------------------------------------- */
    posicionar_horizontal        (tabuleiro, 1, 2);
    posicionar_vertical          (tabuleiro, 5, 7);
    posicionar_diagonal_principal(tabuleiro, 0, 0);
    posicionar_diagonal_secundaria(tabuleiro, 0, 9);

    /* -------------------------------------------------
       3. EXIBIÇÃO DO TABULEIRO
    ------------------------------------------------- */
    exibir_tabuleiro(tabuleiro);

    return 0;
}

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

    #include <stdio.h>

#define TAMANHO     10  // Dimensão do tabuleiro (10x10)
#define TAM_NAVIO    3  // Tamanho fixo de cada navio
#define TAM_HAB      5  // Tamanho das matrizes de habilidade (5x5)

#define AGUA         0  // Célula vazia
#define NAVIO        3  // Parte de um navio
#define HABILIDADE   5  // Área afetada por habilidade

/* =====================================================
   FUNÇÃO: construir_cone
   Preenche a matriz com 1s em forma de cone ▽
   O cone aponta para baixo: cada linha i permite
   colunas dentro do intervalo central que cresce
   conforme i aumenta.
===================================================== */
void construir_cone(int hab[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2; // coluna central (2 para 5x5)

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Na linha i, a largura permitida é i colunas
            // para cada lado do centro
            if (j >= centro - i && j <= centro + i)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

/* =====================================================
   FUNÇÃO: construir_cruz
   Preenche a matriz com 1s em forma de cruz (+)
   A linha central e a coluna central são afetadas.
===================================================== */
void construir_cruz(int hab[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Afeta toda a linha central OU toda a coluna central
            if (i == centro || j == centro)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

/* =====================================================
   FUNÇÃO: construir_octaedro
   Preenche a matriz com 1s em forma de losango (◇)
   Condição: distância de Manhattan até o centro <= raio
   dist = |i - centro| + |j - centro|
===================================================== */
void construir_octaedro(int hab[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    int raio   = TAM_HAB / 2; // raio do losango

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Distância de Manhattan entre (i,j) e o centro
            int dist = (i - centro < 0 ? centro - i : i - centro)
                     + (j - centro < 0 ? centro - j : j - centro);

            if (dist <= raio)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

/* =====================================================
   FUNÇÃO: aplicar_habilidade
   Sobrepõe a matriz de habilidade ao tabuleiro,
   centrando-a no ponto de origem (origemL, origemC).
   Apenas células com valor 1 na habilidade e dentro
   dos limites do tabuleiro são marcadas com HABILIDADE.
===================================================== */
void aplicar_habilidade(int tabuleiro[TAMANHO][TAMANHO],
                        int hab[TAM_HAB][TAM_HAB],
                        int origemL, int origemC) {
    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Calcula a posição real no tabuleiro
            int linha  = origemL + (i - centro);
            int coluna = origemC + (j - centro);

            // Verifica limites e se a célula da habilidade é ativa
            if (linha  >= 0 && linha  < TAMANHO &&
                coluna >= 0 && coluna < TAMANHO &&
                hab[i][j] == 1) {
                // Só marca se não houver navio (preserva navios)
                if (tabuleiro[linha][coluna] != NAVIO)
                    tabuleiro[linha][coluna] = HABILIDADE;
            }
        }
    }
}

/* =====================================================
   FUNÇÃO: exibir_tabuleiro
   Exibe a matriz com símbolos distintos por valor.
===================================================== */
void exibir_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n  Tabuleiro Batalha Naval\n\n");

    // Cabeçalho de colunas
    printf("   ");
    for (int j = 0; j < TAMANHO; j++) printf("%d ", j);
    printf("\n   ");
    for (int j = 0; j < TAMANHO; j++) printf("--");
    printf("\n");

    // Linhas da matriz
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d |", i);
        for (int j = 0; j < TAMANHO; j++) {
            // Caractere diferente para cada tipo de célula
            if      (tabuleiro[i][j] == NAVIO)       printf(" N");
            else if (tabuleiro[i][j] == HABILIDADE)  printf(" *");
            else                                      printf(" ~");
        }
        printf("\n");
    }

    printf("\n  Legenda:  ~ agua  |  N navio  |  * habilidade\n\n");
}

/* =====================================================
   FUNÇÃO: exibir_habilidade (debug auxiliar)
   Mostra a matriz 5x5 de uma habilidade isolada.
===================================================== */
void exibir_habilidade(int hab[TAM_HAB][TAM_HAB], const char *nome) {
    printf("Habilidade: %s\n", nome);
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++)
            printf("%d ", hab[i][j]);
        printf("\n");
    }
    printf("\n");
}

/* =====================================================
   MAIN
===================================================== */
int main() {

    /* -------------------------------------------------
       1. TABULEIRO 10x10 inicializado com água
    ------------------------------------------------- */
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    /* -------------------------------------------------
       2. NAVIOS (mantidos do nível anterior)
    ------------------------------------------------- */
    // Horizontal: linha 1, coluna 2 → [1][2..4]
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[1][2 + i] = NAVIO;

    // Vertical: linha 5, coluna 7 → [5..7][7]
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[5 + i][7] = NAVIO;

    // Diagonal ↘: linha 0, coluna 0 → [0][0],[1][1],[2][2]
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[i][i] = NAVIO;

    // Diagonal ↙: linha 0, coluna 9 → [0][9],[1][8],[2][7]
    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[i][9 - i] = NAVIO;

    /* -------------------------------------------------
       3. MATRIZES DE HABILIDADE (construídas via loops
          e condicionais — sem valores fixos no código)
    ------------------------------------------------- */
    int cone     [TAM_HAB][TAM_HAB];
    int cruz     [TAM_HAB][TAM_HAB];
    int octaedro [TAM_HAB][TAM_HAB];

    construir_cone    (cone);
    construir_cruz    (cruz);
    construir_octaedro(octaedro);

    // Exibe cada habilidade isolada para conferência
    exibir_habilidade(cone,     "Cone     (▽)");
    exibir_habilidade(cruz,     "Cruz     (+)");
    exibir_habilidade(octaedro, "Octaedro (◇)");

    /* -------------------------------------------------
       4. APLICAÇÃO DAS HABILIDADES NO TABULEIRO
       Ponto de origem de cada habilidade:
         Cone:     centro em [7][2]
         Cruz:     centro em [4][5]
         Octaedro: centro em [7][7]
    ------------------------------------------------- */
    aplicar_habilidade(tabuleiro, cone,     7, 2);
    aplicar_habilidade(tabuleiro, cruz,     4, 5);
    aplicar_habilidade(tabuleiro, octaedro, 7, 7);

    /* -------------------------------------------------
       5. EXIBIÇÃO FINAL DO TABULEIRO
    ------------------------------------------------- */
    exibir_tabuleiro(tabuleiro);

    return 0;
}

    
