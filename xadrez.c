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

int main()
{
    /* === Configuração === */
    const int passosTorre   = 5; // Direita
    const int passosBispo   = 5; // Cima Direita
    const int passosRainha  = 8; // Esquerda

    /* Cavalo (movimento em L): 2 para baixo + 1 para esquerda */
    const int cavaloParaBaixo       = 2;
    const int cavaloParaEsquerda    = 1;

    /* Mensagens padronizadas (strings) */
    const char *DIR        = "Direita";
    const char *ESQ        = "Esquerda";
    const char *CIMA       = "Cima";
    const char *BAIXO      = "Baixo";
    const char *CIMA_DIR   = "Cima Direita";

    /* === TORRE (for) === */
    /*
    Lógica: a torre move-se em linha reta. Aqui, simulamos 5 casas para a Direita.
    Implementação: loop for com contador de 1 a passosTorre, imprimindo "Direita"a cada iteração.
    */
   printf("=== Torre: %d casas para a Direita ===\n", passosTorre);
   for(int i = 1; i <= passosTorre; i++) {
    printf("%s\n", DIR);
   }
   printf("\n");

   /* === BISPO (while) === */
   /*
   Lógica: o Bispo move-se nas diagonais. Aqui, simulamos 5 casas para Cima Direita.
   Implementação: loop while até alcançar 'passosBispo', imprimindo "Cima Direita" a cada iteração
   */
  printf("=== Bispo: %d casas na diagonal (Cima Direita) ===\n", passosBispo);
  int contadorBispo = 0;
  while (contadorBispo < passosBispo) {
    printf("%s\n", CIMA_DIR);
    contadorBispo++;
  }
  printf("\n");

  /* === RAINHA (do-while) === */
  /*
  Lógica: a Rainha pode mover-se em qualquer direção. Aqui, simulamos 8 casas para a esquerda.
  Implementação: loop do-while garantindo pelo menos uma impressão, repetindo até 'passosRainha'
  */
  printf("=== Rainha: %d casas para a Esquerda ===\n", passosRainha);
  int contadorRainha = 0;
  do {
    printf("%s\n", ESQ);
    contadorRainha++;
  } while (contadorRainha < passosRainha);

  /* === CAVALO (for + while, aninhado) === */
  /*
  Lógica: o Cavalo move em "L": 2 casas numa direção + 1 perpendicular.
  Neste desafio: 2 para baixo e 1 para esquerda;
  Requisito: usar loops aninhados, sendo um deles obrigatoriamente um 'for'.
  Implementação:
    - loop 'for' percorre os dois segmentos do "L" (segmento 0 = vertical; segmento 1 = horizontal)
    - Para cada segmento, um loop 'while'interno imprime cada casa daquele segmento.
  */
 printf("=== Cavalo: 2 casas para Baixo e 1 casa para a Esquerda (movimento em L) ===\n");

 for (int segmento = 0; segmento < 2; segmento++) {
    /* escolhe a quantidade de passos e direção de segmento atual */
    const int passosSegmento    = (segmento == 0) ? cavaloParaBaixo : cavaloParaEsquerda;
    const char *direcao         = (segmento == 0) ? BAIXO : ESQ;

    int realizados = 0;
    while (realizados < passosSegmento) {
        printf("%s\n", direcao);
        realizados++;
    }
 }

  return 0;
}