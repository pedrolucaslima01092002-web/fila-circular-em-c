#include <stdio.h>

#define TAMANHO 5

typedef struct {
    int dados[TAMANHO];
    int inicio;
    int fim;
    int quantidade;
} FilaCircular;

void inicializar(FilaCircular *f) {
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

int estaCheia(FilaCircular *f) {
    return f->quantidade == TAMANHO;
}

int estaVazia(FilaCircular *f) {
    return f->quantidade == 0;
}

int inserir(FilaCircular *f, int valor) {
    if (estaCheia(f)) {
        return 0;
    }
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % TAMANHO;
    f->quantidade++;
    return 1;
}

int remover(FilaCircular *f, int *valor) {
    if (estaVazia(f)) {
        return 0;
    }
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % TAMANHO;
    f->quantidade--;
    return 1;
}

void listar(FilaCircular *f) {
    int i, pos;
    if (estaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Elementos da fila (do primeiro ao ultimo):\n");
    for (i = 0; i < f->quantidade; i++) {
        pos = (f->inicio + i) % TAMANHO;
        printf("  posicao[%d] = %d\n", pos, f->dados[pos]);
    }
}

void limparEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    FilaCircular fila;
    int opcao, valor;

    inicializar(&fila);

    do {
        printf("\n===== FILA CIRCULAR =====\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Listar elementos\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            if (feof(stdin)) {
                break;
            }
            limparEntrada();
            printf("Opcao invalida.\n");
            continue;
        }

        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir: ");
                if (scanf("%d", &valor) != 1) {
                    limparEntrada();
                    printf("Valor invalido.\n");
                    break;
                }
                if (inserir(&fila, valor)) {
                    printf("Valor %d inserido com sucesso.\n", valor);
                } else {
                    printf("Erro: fila cheia (overflow). Nao foi possivel inserir.\n");
                }
                break;
            case 2:
                if (remover(&fila, &valor)) {
                    printf("Valor %d removido da fila.\n", valor);
                } else {
                    printf("Erro: fila vazia (underflow). Nada para remover.\n");
                }
                break;
            case 3:
                listar(&fila);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 4);

    return 0;
}
