# Fila Circular em C

**Aluno:** Pedro
**Disciplina:** Estrutura de Dados
**Linguagem:** C

## Descrição

### Exercício 1 — Menu de operações (`exercicio1.c`)

Fila circular de inteiros com capacidade para 5 elementos, implementada com array e `struct`. O menu permite inserir, remover, listar os elementos e sair. A fila respeita a regra FIFO e usa o operador `%` para movimentar os índices `inicio` e `fim` de forma circular.

### Exercício 2 — Fila circular de atendimento (`exercicio2.c`)

Simulação de uma fila de atendimento com capacidade para 5 pessoas. Cada elemento é uma `struct Pessoa` com número da senha (gerado automaticamente) e nome. O programa permite inserir pessoas, chamar a próxima e visualizar a fila de espera.

Após cada operação são exibidos os valores de `inicio`, `fim` e `quantidade`. O programa identifica fila cheia e fila vazia, impede overflow e underflow e mostra em qual posição do array cada pessoa foi gravada ou liberada, demonstrando o reaproveitamento das posições.

## Compilação e execução

```bash
gcc -Wall -Wextra -o exercicio1 exercicio1.c
./exercicio1

gcc -Wall -Wextra -o exercicio2 exercicio2.c
./exercicio2
```

No Windows, execute `exercicio1.exe` e `exercicio2.exe`.

## Testes realizados

Os testes abaixo foram executados no Exercício 2 (capacidade = 5).

### 1. Inserção de elementos até completar a fila

```
Senha 001 gerada para Ana Souza (gravada na posicao 0 do array).
[Estado] inicio = 0 | fim = 1 | quantidade = 1/5
Senha 002 gerada para Bruno Lima (gravada na posicao 1 do array).
[Estado] inicio = 0 | fim = 2 | quantidade = 2/5
Senha 003 gerada para Carla Dias (gravada na posicao 2 do array).
[Estado] inicio = 0 | fim = 3 | quantidade = 3/5
Senha 004 gerada para Diego Rocha (gravada na posicao 3 do array).
[Estado] inicio = 0 | fim = 4 | quantidade = 4/5
Senha 005 gerada para Eva Martins (gravada na posicao 4 do array).
[Estado] inicio = 0 | fim = 0 | quantidade = 5/5 -> FILA CHEIA
```

### 2. Tentativa de inserção em fila cheia

```
Erro: fila cheia (overflow). Nao e possivel inserir.
[Estado] inicio = 0 | fim = 0 | quantidade = 5/5 -> FILA CHEIA
```

### 3. Remoção de elementos

```
Chamando senha 001 - Ana Souza (liberada a posicao 0 do array).
[Estado] inicio = 1 | fim = 0 | quantidade = 4/5
Chamando senha 002 - Bruno Lima (liberada a posicao 1 do array).
[Estado] inicio = 2 | fim = 0 | quantidade = 3/5
```

### 4. Nova inserção utilizando posições liberadas

As novas pessoas ocupam as posições 0 e 1, liberadas no teste anterior:

```
Senha 006 gerada para Felipe Alves (gravada na posicao 0 do array).
[Estado] inicio = 2 | fim = 1 | quantidade = 4/5
Senha 007 gerada para Gabi Nunes (gravada na posicao 1 do array).
[Estado] inicio = 2 | fim = 2 | quantidade = 5/5 -> FILA CHEIA

Fila de espera (ordem de atendimento):
  1. Senha 003 - Carla Dias (posicao do array: 2)
  2. Senha 004 - Diego Rocha (posicao do array: 3)
  3. Senha 005 - Eva Martins (posicao do array: 4)
  4. Senha 006 - Felipe Alves (posicao do array: 0)
  5. Senha 007 - Gabi Nunes (posicao do array: 1)
```

### 5. Remoção de todos os elementos e tentativa de remoção em fila vazia

```
Chamando senha 003 - Carla Dias (liberada a posicao 2 do array).
[Estado] inicio = 3 | fim = 2 | quantidade = 4/5
Chamando senha 004 - Diego Rocha (liberada a posicao 3 do array).
[Estado] inicio = 4 | fim = 2 | quantidade = 3/5
Chamando senha 005 - Eva Martins (liberada a posicao 4 do array).
[Estado] inicio = 0 | fim = 2 | quantidade = 2/5
Chamando senha 006 - Felipe Alves (liberada a posicao 0 do array).
[Estado] inicio = 1 | fim = 2 | quantidade = 1/5
Chamando senha 007 - Gabi Nunes (liberada a posicao 1 do array).
[Estado] inicio = 2 | fim = 2 | quantidade = 0/5 -> FILA VAZIA
Erro: fila vazia (underflow). Ninguem para chamar.
[Estado] inicio = 2 | fim = 2 | quantidade = 0/5 -> FILA VAZIA
```

### Exercício 1

Também foram testados no Exercício 1: remoção com a fila vazia (underflow), inserção de 10, 20, 30, 40 e 50 até encher, tentativa de inserir 60 (overflow), remoção de 10 e 20, e inserção de 70 e 80 nas posições 0 e 1 liberadas:

```
Elementos da fila (do primeiro ao ultimo):
  posicao[2] = 30
  posicao[3] = 40
  posicao[4] = 50
  posicao[0] = 70
  posicao[1] = 80
```
