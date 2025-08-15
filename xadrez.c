#include <stdio.h>

/* ---------------------------------------------------------------------------
   MateCheck - Movimentos com Recursividade e Loops Complexos (Nível Mestre)
   Requisitos atendidos:
   - Recursão: Torre (Direita), Rainha (Esquerda), Bispo (Diagonal Cima+Direita)
   - Loops complexos: Cavalo (2x Cima, 1x Direita) com continue/break
   - Loops aninhados (Bispo): externo vertical (Cima), interno horizontal (Direita)
   - Saída por casa percorrida: "Cima", "Baixo", "Esquerda", "Direita"
   - Sem entrada do usuário: constantes definidas em código
   - Apenas int e string: usamos char* para "string"
   - Comentários detalhados e legibilidade
   --------------------------------------------------------------------------- */

typedef char* string;

/* === 1) Helpers de impressão (uma direção por casa) ====================== */
static void print_cima(void)    { printf("Cima\n");    }
static void print_baixo(void)   { printf("Baixo\n");   }
static void print_esquerda(void){ printf("Esquerda\n");}
static void print_direita(void) { printf("Direita\n"); }

/* === 2) Funções RECURSIVAS =============================================== */
/* Torre: mover N casas para a Direita, imprimindo uma casa por chamada.     */
static void mover_torre_direita_rec(int casas) {
    /* Caso base: nenhuma casa restante → retorna sem imprimir. */
    if (casas <= 0) return;

    /* Passo recursivo: consome 1 casa (Direita) e recursa no restante. */
    print_direita();
    mover_torre_direita_rec(casas - 1);
}

/* Rainha: mover N casas para a Esquerda, imprimindo uma casa por chamada.   */
static void mover_rainha_esquerda_rec(int casas) {
    if (casas <= 0) return;
    print_esquerda();
    mover_rainha_esquerda_rec(casas - 1);
}

/* Bispo (recursivo): diagonal Cima+Direita (1 Cima e 1 Direita por casa).
   Cada "casa diagonal" é decomposta em dois movimentos unitários (ordem: Cima, depois Direita). */
static void mover_bispo_cima_direita_rec(int casas) {
    if (casas <= 0) return;

    /* Uma casa diagonal: primeiro vertical, depois horizontal */
    print_cima();
    print_direita();

    mover_bispo_cima_direita_rec(casas - 1);
}

/* === 3) Loops aninhados (Bispo) ========================================== */
/* Bispo (loops): externo → vertical (Cima); interno → horizontal (Direita).
   Para cada "casa diagonal", subimos 1 (externo) e andamos 1 à direita (interno). */
static void mover_bispo_cima_direita_loops(int casas) {
    for (int passo_vertical = 0; passo_vertical < casas; ++passo_vertical) {
        /* Movimento vertical (externo) — 1 casa para cima */
        print_cima();

        /* Movimento horizontal (interno) — 1 casa para a direita */
        for (int passo_horizontal = 0; passo_horizontal < 1; ++passo_horizontal) {
            print_direita();
        }
    }
}

/* === 4) Loops complexos (Cavalo) ========================================= */
/* Cavalo: 2 casas para Cima e 1 para Direita (um único "L").
   Requisito: loops aninhados com múltiplas variáveis e uso de continue/break.

   Estratégia:
   - Loop externo controla os dois passos "Cima" (i = 0,1).
   - Loop interno decide se haverá movimento horizontal nesta iteração.
   - Usamos 'continue' para pular qualquer horizontal na primeira subida.
   - Na segunda subida, imprimimos "Direita" uma única vez e usamos 'break'.
*/
static void mover_cavalo_cima_direita_loops(void) {
    for (int i = 0; i < 2; ++i) {          /* i: contador de subidas (2x Cima) */
        print_cima();                       /* executa a parte vertical */

        for (int j = 0; j < 2; ++j) {      /* j: auxiliar para controle fino */
            if (i == 0) {
                /* Na primeira subida, explicitamente pulamos qualquer horizontal. */
                continue;                  /* ← atende ao requisito 'continue' */
            }

            /* Chegamos aqui somente na segunda subida (i == 1).
               Imprimimos "Direita" uma única vez e interrompemos o loop interno. */
            if (j == 0) {
                print_direita();
                break;                     /* ← atende ao requisito 'break' */
            }
        }
    }
}

/* ======================================================================== */
int main(void) {
    /* --- Parâmetros do desafio (sem entrada do usuário) ----------------- */
    const int CASAS_BISPO  = 5;  /* diagonal: Cima+Direita (rec e loops) */
    const int CASAS_TORRE  = 5;  /* Direita (recursivo)                   */
    const int CASAS_RAINHA = 8;  /* Esquerda (recursivo)                  */
    /* Cavalo: 1 movimento em 'L' (2x Cima, 1x Direita) por loops complexos */

    /* --- Execuções ------------------------------------------------------- */

    /* BISPO — Recursivo (5 casas diagonal Cima+Direita) */
    mover_bispo_cima_direita_rec(CASAS_BISPO);
    printf("\n");

    /* BISPO — Loops aninhados (externo vertical, interno horizontal) */
    mover_bispo_cima_direita_loops(CASAS_BISPO);
    printf("\n");

    /* TORRE — Recursivo (5 casas para Direita) */
    mover_torre_direita_rec(CASAS_TORRE);
    printf("\n");

    /* RAINHA — Recursivo (8 casas para Esquerda) */
    mover_rainha_esquerda_rec(CASAS_RAINHA);
    printf("\n");

    /* CAVALO — Loops aninhados + continue/break (2x Cima, 1x Direita) */
    mover_cavalo_cima_direita_loops();
    printf("\n");

    return 0;
}