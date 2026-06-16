#include <stdio.h>
#include <string.h>
#include "analise.h"

/* ===================================================================
 * analise.c
 * Funcoes de analise de sequencias.
 * =================================================================== */

/* ---------- IMPLEMENTADO: calculo do GC ---------- */
/* Esta funcao serve de exemplo para os alunos. As outras devem ser
 * implementadas seguindo o mesmo padrao.                            */
float calcularGC(char *dna, int tamanho) {
    if (tamanho == 0) return 0.0;

    int gc = 0;
    for (int i = 0; i < tamanho; i++) {
        if (dna[i] == 'G' || dna[i] == 'C') {
            gc++;
        }
    }
    return (float)gc / tamanho * 100.0;
}

/* ---------- IMPLEMENTADO: contagem das 4 bases ----------
 * Esta funcao deve receber a string DNA e ponteiros para as 4
 * contagens (qtdA, qtdT, qtdC, qtdG). Ela deve percorrer toda a
 * sequencia e incrementar o contador correspondente a cada base.
 *
 * Dica: use 'switch' para selecionar qual contador incrementar.
 * Atencao: lembre-se de zerar os contadores no inicio!
 * ------------------------------------------------------------- */
void contarBases(char *dna, int *qtdA, int *qtdT, int *qtdC, int *qtdG) {
    /* TODO: zerar os 4 contadores usando os ponteiros */

    /* TODO: percorrer a string dna ate encontrar '\0' */

    /* TODO: para cada caractere, usar switch para incrementar
     *       o contador correto via ponteiro (lembrar dos parenteses:
     *       (*qtdA)++; e nao *qtdA++; - sao coisas diferentes!)    */

    /* Por enquanto so para nao quebrar a compilacao: */
    (void)dna;
    *qtdA = *qtdT = *qtdC = *qtdG = 0;

    for(int i = 0; dna[i] != '\0'; i++){
        char base = dna[i];
        switch (base)
        {
        case 'A':
            (*qtdA)++;
            break;
        case 'T':
            (*qtdT)++;
            break;
        case 'C':
            (*qtdC)++;
            break;
        case 'G':
            (*qtdG)++;
            break;
        
        default:
            break;
        }
    }
}

/* ---------- IMPLEMENTADO: menu de contagem de bases ---------- */
void menuContarBases(Sequencia *banco, int total) {
    if (total == 0) {
        printf("\n>> Cadastre ao menos uma sequencia primeiro.\n");
        return;
    }

    char nome[TAM_NOME];
    printf("\nNome da sequencia: ");
    scanf(" %30[^\n]", nome);

    int idx = -1;
    for (int i = 0; i < total; i++) {
        if (strcmp(banco[i].nome, nome) == 0) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf(">> Sequencia '%s' nao encontrada.\n", nome);
        return;
    }

    int a, t, c, g;
    contarBases(banco[idx].dna, &a, &t, &c, &g);

    printf("\nSequencia: %s (%d bases)\n", banco[idx].nome,
                                            banco[idx].tamanho);
    printf("A: %d    T: %d    C: %d    G: %d\n", a, t, c, g);
}

/* ---------- IMPLEMENTADO: menu de calculo de GC ---------- */
void menuCalcularGC(Sequencia *banco, int total) {
    if (total == 0) {
        printf("\n>> Cadastre ao menos uma sequencia primeiro.\n");
        return;
    }

    char nome[TAM_NOME];
    printf("\nNome da sequencia: ");
    scanf(" %30[^\n]", nome);

    for (int i = 0; i < total; i++) {
        if (strcmp(banco[i].nome, nome) == 0) {
            printf("\nSequencia %s: GC = %.2f%%\n",
                   banco[i].nome, banco[i].gc);
            return;
        }
    }

    printf(">> Sequencia '%s' nao encontrada.\n", nome);
}

/* ---------- IMPLEMENTADO - busca de motif ----------
 * A funcao deve percorrer a sequencia comparando cada janela
 * de tamanho igual ao padrao. Para cada posicao i da sequencia:
 *   - compare dna[i], dna[i+1], ... dna[i+tamPad-1] com o padrao
 *   - se todos baterem, imprima a posicao (base 1) e incremente
 *     o contador
 *
 * Dica: use uma flag 'encontrou' que comeca em 1 e vira 0 ao
 *       encontrar a primeira diferenca, usando 'break' para sair
 *       do laco interno.
 *
 * Retornar a quantidade total de ocorrencias encontradas.
 * ------------------------------------------------------------- */
int buscarMotif(char *dna, char *padrao) {
    int tamDna = strlen(dna);
    int tamPad = strlen(padrao);

    if (tamPad == 0 || tamPad > tamDna) {
        return 0;
    }

    int qtd = 0;

    for (int i = 0; i <= tamDna - tamPad; i++) {

        int encontrou = 1;

        for (int j = 0; j < tamPad; j++) {

            if (dna[i + j] != padrao[j]) {
                encontrou = 0;
                break;
            }
        }

        if (encontrou) {
            printf("Ocorrencia encontrada na posicao %d\n", i + 1);
            qtd++;
        }
    }

    return qtd;
}

/* ---------- IMPLEMENTADO: menu de busca de motif ---------- */
void menuBuscarMotif(Sequencia *banco, int total) {
    if (total == 0) {
        printf("\n>> Cadastre ao menos uma sequencia primeiro.\n");
        return;
    }

    char nome[TAM_NOME];
    char padrao[50];

    printf("\nNome da sequencia: ");
    scanf(" %30[^\n]", nome);

    printf("Motif a buscar (apenas A, T, C, G): ");
    scanf(" %49s", padrao);

    /* Valida o padrao */
    for (int i = 0; padrao[i] != '\0'; i++) {
        if (padrao[i] != 'A' && padrao[i] != 'T' &&
            padrao[i] != 'C' && padrao[i] != 'G') {
            printf(">> Erro: motif contem caractere invalido '%c'.\n",
                   padrao[i]);
            return;
        }
    }

    /* Busca a sequencia pelo nome */
    int idx = -1;
    for (int i = 0; i < total; i++) {
        if (strcmp(banco[i].nome, nome) == 0) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf(">> Sequencia '%s' nao encontrada.\n", nome);
        return;
    }

    printf("\nBuscando '%s' em '%s'...\n", padrao, banco[idx].nome);
    int qtd = buscarMotif(banco[idx].dna, padrao);
    printf("Total de ocorrencias: %d\n", qtd);
}
