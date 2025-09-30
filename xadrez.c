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
*/

int main()
{
    /* === Configuração === */
    const int passosTorre   = 5; // Direita
    const int passosBispo   = 5; // Cima Direita
    const int passosRainha  = 8; // Esquerda

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

  return 0;
}