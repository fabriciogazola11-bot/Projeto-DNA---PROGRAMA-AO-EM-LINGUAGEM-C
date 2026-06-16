# Analisador de Sequências de DNA

**Trabalho Prático Final** — Linguagem de Programação (Linguagem C)  
Fatec Ourinhos — Tecnologia em Análise e Desenvolvimento de Sistemas

---

## 📂 Estrutura do Projeto

```
analisador_dna/
├── main.c              # Programa principal (menu)
├── sequencia.h         # Definição da struct Sequencia e constantes
├── cadastro.h / .c     # Parte I: cadastro, listagem, validação
├── analise.h / .c      # Parte I e II: contagem, GC, motif
├── ordenacao.h / .c    # Parte II: ordenação por tamanho
├── arquivo.h / .c      # Parte III: salvar/carregar arquivo
├── comparacao.h / .c   # Parte III: distância de Hamming
├── Makefile            # Automação de compilação
└── README.md           # Este arquivo
```

---

## 🚀 Como compilar e executar

### Usando o Makefile (recomendado)

```bash
make           # compila
make run       # compila e executa
make clean     # remove arquivos gerados
```

### Compilação manual (sem Makefile)

```bash
gcc -Wall -Wextra -std=c99 -g -o analisador_dna \
    main.c cadastro.c analise.c ordenacao.c arquivo.c comparacao.c

./analisador_dna
```

---

## ✏️ O que precisa ser implementado

O esqueleto vem com a estrutura pronta. Os locais que devem ser implementados pelo grupo estão marcados com **`TODO`** nos comentários dos arquivos `.c`.

### Parte I — Básico (6,0 pts)

| Arquivo | Função | Status |
|---|---|---|
| `cadastro.c` | `sequenciaValida()` | ✅ Pronta |
| `cadastro.c` | `nomeJaExiste()` | ✅ Pronta |
| `cadastro.c` | `cadastrarSequencia()` | ✅ Pronta |
| `cadastro.c` | `listarSequencias()` | ✅ Pronta |
| `cadastro.c` | `buscarPorNome()` | ✅ Pronta |
| `analise.c` | `calcularGC()` | ✅ Pronta |
| `analise.c` | **`contarBases()`** **| ✅ Pronta |

### Parte II — Intermediário (2,0 pts)

| Arquivo | Função | Status |
|---|---|---|
| `analise.c` | **`buscarMotif()`** | ✅ Pronta |
| `ordenacao.c` | **`ordenarPorTamanho()`** | ✅ Pronta |
### Parte III — Avançado (2,0 pts)

| Arquivo | Função | Status |
|---|---|---|
| `arquivo.c` | **`salvarArquivo()`** | ✅ Pronta |
| `arquivo.c` | **`carregarArquivo()`** | ✅ Pronta |
| `comparacao.c` | **`distanciaHamming()`** | ✅ Pronta | 

---

## 🧪 Como testar enquanto implementa

Compile e execute o programa logo no início — ele já vai rodar com o menu funcionando. A cada função que você implementar, teste a opção correspondente no menu.

### Sequências sugeridas para teste

```
Seq_A   ATGCCGTAACGGATTAGCC     (19 bases, mista)
Seq_B   GCGCGCGCATATATCGCGCG    (20 bases, rica em GC)
Seq_C   AAAATTTTAAAATTTTAAAAT   (21 bases, rica em AT)
Seq_D   ATGCCGTAACGGATTAGCC     (19 bases, idêntica a Seq_A)
Seq_E   ATGCCGTAACGGATTAGCT     (19 bases, 1 diferença de Seq_A)
```

### Resultados esperados (resumo)

- **Seq_A**: A=5, T=4, C=5, G=5, GC=52.63%
- **Seq_B**: A=2, T=2, C=8, G=8, GC=80.00%
- **Seq_C**: A=12, T=8, C=0, G=0, GC=0.00%
- **Hamming(Seq_A, Seq_D)** = 0 (idênticas)
- **Hamming(Seq_A, Seq_E)** = 1 (uma diferença)
- **Motif `GAT` em Seq_A** = 1 ocorrência (posição 11)

---

## 📋 Dicas de implementação

1. **Comece pela função `contarBases`** — ela é simples e te ajuda a entender o uso de ponteiros como parâmetros de saída.
2. **Compile com frequência** — depois de cada `TODO` implementado, rode `make` para conferir.
3. **Use o `printf` para debugar** — imprima valores intermediários para acompanhar a execução.
4. **Leia os comentários** — cada `TODO` tem instruções passo a passo do que fazer.
5. **Não compile sem `-Wall -Wextra`** — esses *warnings* pegam bugs antes deles virarem problema.

---

## 👥 Divisão sugerida entre os integrantes

| Integrante | Responsabilidade |
|---|---|
| 1 | `cadastro.c` (já está pronto — revisa, testa, ajusta UX) |
| 2 | `analise.c` — `contarBases()` e `buscarMotif()` |
| 3 | `ordenacao.c` — escolher e implementar 1 algoritmo |
| 4 | `arquivo.c` — `salvarArquivo()` e `carregarArquivo()` |
| 5 | `comparacao.c` — `distanciaHamming()` + planilha de testes |

> Todos devem entender o código todo! A divisão é só para quem **escreve primeiro** cada parte.

---

## 📚 Conceitos aplicados (revisão)

- **Variáveis e tipos** (`int`, `float`, `char[]`)
- **Operadores** (aritméticos, relacionais, lógicos)
- **`if`/`switch`** (validações, menu)
- **Laços `for`/`while`/`do-while`** (percorrer sequências, menu)
- **Funções e modularização** (cada arquivo `.c` é um módulo)
- **Vetores e strings** (sequências de DNA)
- **`struct`** (`Sequencia`)
- **Ordenação** (algoritmo escolhido pelo grupo)
- **Ponteiros** (parâmetros de saída, `Sequencia *`)
- **Manipulação de arquivos** (`fopen`, `fprintf`, `fgets`, `fclose`)

---

## AUTOR
INICIADO pelo Professor ALEX MARINO. 
Programação à partir de FUNÇÕES/CONTARBASES e finalizado em DISTANCIA HAMMING por FABRICIO
