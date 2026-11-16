# fila-circular-em-c

Nome: Pedro Lucas Gonçalves de Lima
Disciplina: Estrutura de Dados

## Exercícios

exercicio1.c: fila circular de inteiros com menu para inserir, remover, listar e sair.
exercicio2.c: fila de atendimento com senha e nome, usando struct. Mostra inicio, fim e quantidade depois de cada operação.

As duas filas têm tamanho 5 e usam % para voltar ao começo do array.

## Como compilar

gcc exercicio1.c -o exercicio1
./exercicio1

gcc exercicio2.c -o exercicio2
./exercicio2

## Testes

1. Inseri 5 pessoas até a fila ficar cheia (inicio = 0, fim = 0, quantidade = 5).
2. Tentei inserir mais uma e apareceu a mensagem de fila cheia.
3. Removi 2 pessoas (inicio foi para 2, quantidade = 3).
4. Inseri mais 2 pessoas e elas ficaram nas posições 0 e 1, que tinham sido liberadas.
5. Removi todas e, ao tentar remover de novo, apareceu a mensagem de fila vazia.
