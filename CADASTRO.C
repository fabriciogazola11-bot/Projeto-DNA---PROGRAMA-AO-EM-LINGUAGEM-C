#include <stdio.h>
#include <string.h>
#include "cadastro.h"
#include "analise.h"     /* para calcular GC no cadastro */

/* ===================================================================
 * cadastro.c
 * Implementacao das funcoes de cadastro e listagem (PARTE I).
 * =================================================================== */

/* ---------- IMPLEMENTADO: validacao de sequencia ---------- */
int sequenciaValida(char *dna) {
    if (dna == NULL || dna[0] == '\0') {
        return 0;  /* sequencia vazia tambem e invalida */
    }
    for (int i = 0; dna[i] != '\0'; i++) {
        if (dna[i] != 'A' && dna[i] != 'T' &&
            dna[i] != 'C' && dna[i] != 'G') {
            return 0;
        }
    }
    return 1;
}

/* ---------- IMPLEMENTADO: verificacao de nome duplicado ---------- */
int nomeJaExiste(Sequencia *banco, int total, char *nome) {
    for (int i = 0; i < total; i++) {
        if (strcmp(banco[i].nome, nome) == 0) {
            return 1;
        }
    }
    return 0;
}

/* ---------- IMPLEMENTADO: cadastro de sequencia ---------- */
void cadastrarSequencia(Sequencia *banco, int *total) {
    /* Verifica se ainda ha espaco */
    if (*total >= MAX_SEQ) {
        printf("\n>> Erro: limite de %d sequencias atingido.\n", MAX_SEQ);
        return;
    }

    char nomeTmp[TAM_NOME];
    char dnaTmp[TAM_DNA];

    /* Le o nome */
    printf("\nNome da sequencia (max %d caracteres): ", TAM_NOME - 1);
    scanf(" %30[^\n]", nomeTmp);

    /* Valida nome duplicado */
    if (nomeJaExiste(banco, *total, nomeTmp)) {
        printf(">> Erro: ja existe uma sequencia com esse nome.\n");
        return;
    }

    /* Le o DNA */
    printf("Sequencia de DNA (apenas A, T, C, G - max %d bases): ",
           TAM_DNA - 1);
    scanf(" %200s", dnaTmp);

    /* Valida o DNA */
    if (!sequenciaValida(dnaTmp)) {
        printf(">> Erro: sequencia invalida! Use apenas A, T, C, G.\n");
        return;
    }

    /* Tudo OK: armazena no banco */
    strcpy(banco[*total].nome, nomeTmp);
    strcpy(banco[*total].dna, dnaTmp);
    banco[*total].tamanho = strlen(dnaTmp);
    banco[*total].gc = calcularGC(banco[*total].dna,
                                  banco[*total].tamanho);
    (*total)++;

    printf(">> Sequencia cadastrada com sucesso! (Total: %d)\n", *total);
}

/* ---------- IMPLEMENTADO: listagem ---------- */
void listarSequencias(Sequencia *banco, int total) {
    if (total == 0) {
        printf("\n>> Nenhuma sequencia cadastrada.\n");
        return;
    }

    printf("\n");
    printf("ID | %-25s | Tamanho | DNA\n", "Nome");
    printf("---+---------------------------+---------+");
    printf("-----------------------------\n");

    for (int i = 0; i < total; i++) {
        /* Mostra apenas os primeiros 25 caracteres do DNA na listagem */
        char preview[30];
        strncpy(preview, banco[i].dna, 25);
        preview[25] = '\0';
        if (banco[i].tamanho > 25) {
            strcat(preview, "...");
        }

        printf("%2d | %-25s | %7d | %s\n",
               i + 1, banco[i].nome, banco[i].tamanho, preview);
    }
}

/* ---------- IMPLEMENTADO: busca por nome ---------- */
int buscarPorNome(Sequencia *banco, int total, char *nome) {
    for (int i = 0; i < total; i++) {
        if (strcmp(banco[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}
