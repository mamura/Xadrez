#include <stdio.h>

/*
  Desafio: Movimentação de peças de xadrez com estruturas de repetição.

  Regras de impressão por casa:
    - "Cima"
    - "Baixo"
    - "Esquerda"
    - "Direita"
    - "Cima Esquerda"
    - "Cima Direita"
    - "Baixo Esquerda"
    - "Baixo Direita"

  Estruturas exigidas:
    - Torre  : for        → 5 casas para a Direita
    - Bispo  : while      → 5 casas na diagonal para Cima Direita
    - Rainha : do-while   → 8 casas para a Esquerda
    - Cavalo: for + while (aninhados) → 2 Baixo + 1 Esquerda
*/

/* Mensagens padronizadas (strings) */
static const char *CIMA       = "Cima";
static const char *BAIXO      = "Baixo";
static const char *ESQ        = "Esquerda";
static const char *DIR        = "Direita";

/* === Configuração dos passos === */
enum {
    PASSOS_TORRE    = 5,
    PASSOS_BISPO    = 5,
    PASSOS_RAINHA   = 8,
    CAVALO_UP       = 2,
    CAVALO_RIGHT    = 1
};

/*  ========================================================
    TORRE (recursivo): imprime "Direita" PASSOS_TORRE vezes
    --------------------------------------------------------
    Caso base: passos <= 0 -> retorna
    Passo recursivo: imprime "Direita", chama com passos - 1
    ======================================================== */
void moverTorreDireita(int passos)
{
    if (passos <= 0) {
        return;
    }

    printf("%s\n", DIR);

    moverTorreDireita(passos - 1);
}

/*  ==========================================================
    BISPO: recursivo + loops aninhados
    ----------------------------------------------------------
    Cada "passo diagonal" imprime DUAS linhas:
        1) loop externo (vertical): imprime "Cima"
        2) loop interno (horizontal): imprime "Direita"
    Assim, para N passos, teremos 2 * N linhas.

    A recursão controla QUANTOS passos diagonais serão feitos.
    ========================================================== */
static void passoBispoComLoopsAninhados()
{
    // Externo: vertical (Cima)
    for (int v = 0; v < 1; v++) {
        printf("%s\n", CIMA);

        // Interno: horizontal (Direita)
        int h = 0;
        while (h < 1) {
            printf("%s\n", DIR);
            h++;
        }
    }
}

void moverBispoCimaDireita(int passos)
{
    if (passos <= 0) {
        return;
    }

    passoBispoComLoopsAninhados();
    moverBispoCimaDireita(passos - 1);
}

/*  ==========================================================
    RAINHA (recursivo): imprime "Esquerda" PASSOS_RAINHA vezes
    ----------------------------------------------------------
    Caso base: passos <= 0 -> retorna
    Passo recursivo: imprime "Esquerda", chama passos - 1
    ========================================================== */
void moverRainhaEsquerda(int passos)
{
    if (passos <= 0) {
        return;
    }

    printf("%s\n", ESQ);
    moverRainhaEsquerda(passos - 1);
}

/*  ======================================================================
    CAVALO: loops aninhados "complexos" com multiplas variáveis
    ----------------------------------------------------------------------
    Movimento em L: para Cima e 1 para Direita.
    - Usamos um tabuleiro *X8 apenas para demonstrar boundary check.
    - Posição inicial arbitrária (linha,coluna) no meio do tabuleiro
    para evitar limites (0-index: 4,4).
    - Loops:
        * Externo: segmentos do L (0 = vertical; 1 = horizontal),
                    com condição adicional (printed < totalAlvo).
        * Interno: passos dentro do segmento, controlando 'alvo'
                    e usando 'continue' e 'break' conforme condições.
    - Imprime "Cima" dias vezes e "Direita" uma vez, totalizando 3 linhas.
    ====================================================================== */
void moverCavaloComLoops()
{
    const int linhas = 8, colunas = 8;
    int linha = 4, coluna = 4; // posição inicial (0,0 é topo-esquerda)

    const int totalAlvo = CAVALO_UP + CAVALO_RIGHT;
    int impressos = 0;

    // Para cada segmento do "L": 0 (Cima x2), 1 (Direita x1)
    for (int segmento = 0; segmento < 2 && impressos < totalAlvo; segmento++) {
        // alvo: quantas casas nesse segmento
        int alvo = (segmento == 0 ? CAVALO_UP : CAVALO_RIGHT);

        // Interno: percorre as casas do segmento atual
        for (int passo = 0; passo < alvo && impressos < totalAlvo; passo++) {
            /*
            Multiplicidade de variáveis/condicoes no loop:
                - Verificação de bounds do tabuleiro (exemplo de condição extra)
                - Uso de continue/break para controle de fluxo
            */
           int proxLinha = linha + (segmento == 0 ? -1 : 0); // Cima diminui linha
           int proxCol = coluna + (segmento == 0 ? 0 : 1); // Direita aumenta coluna

           // Exemplo de 'continue': se sair do tabuleiro, não imprime nem atualiza
           if (proxLinha < 0 || proxLinha >= linhas || proxCol < 0 || proxCol >= colunas) {
            continue; // pular esta iteração sem contar passo
           }

           // Impressão de acordo com o segmento
           if (segmento == 0) {
            printf("%s\n", CIMA);
           } else {
            printf("%s\n", DIR);
           }

           // Atualiza posição e contadores'
           linha    = proxLinha;
           coluna   = proxCol;
           impressos++;

           // Exemplo de 'break': se já atingimos o total desejado,
           // encerramos o loop interno imediatamente
           if (impressos >= totalAlvo) {
            break;
           }
        }

        // Encerrar o loop externo se já terminou tudo
        if (impressos >= totalAlvo) {
            break;
        }
    }

}

int main()
{
    /* === TORRE === */
    printf("=== Torre: %d casas para a Direita ===\n", PASSOS_TORRE);
    moverTorreDireita(PASSOS_TORRE);
    printf("\n");

    /* === BISPO === */
    printf("=== Bispo: %d casas na diagonal (Cima Direita) ===\n", PASSOS_BISPO);
    moverBispoCimaDireita(PASSOS_BISPO);
    printf("\n");

    /* === RAINHA === */
    printf("=== Rainha: %d casas para a Esquerda ===\n", PASSOS_RAINHA);
    moverRainhaEsquerda(PASSOS_RAINHA);
    printf("\n");
    /* === CAVALO === */
    printf("=== Cavalo: 2 casas para Baixo e 1 casa para a Esquerda (movimento em L) ===\n");
    moverCavaloComLoops();

    return 0;
}