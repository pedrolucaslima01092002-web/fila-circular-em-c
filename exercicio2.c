#include <stdio.h>

#define TAMANHO 5
#define TAM_NOME 50

typedef struct {
    int senha;
    char nome[TAM_NOME];
} Pessoa;

typedef struct {
    Pessoa itens[TAMANHO];
    int inicio;
    int fim;
    int quantidade;
} FilaAtendimento;

void inicializar(FilaAtendimento *f) {
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

int estaCheia(FilaAtendimento *f) {
    return f->quantidade == TAMANHO;
}

int estaVazia(FilaAtendimento *f) {
    return f->quantidade == 0;
}

void mostrarEstado(FilaAtendimento *f) {
    printf("[Estado] inicio = %d | fim = %d | quantidade = %d/%d",
           f->inicio, f->fim, f->quantidade, TAMANHO);
    if (estaCheia(f)) {
        printf(" -> FILA CHEIA");
    } else if (estaVazia(f)) {
        printf(" -> FILA VAZIA");
    }
    printf("\n");
}

int inserir(FilaAtendimento *f, Pessoa p) {
    if (estaCheia(f)) {
        return -1;
    }
    int posicao = f->fim;
    f->itens[posicao] = p;
    f->fim = (f->fim + 1) % TAMANHO;
    f->quantidade++;
    return posicao;
}

int chamarProximo(FilaAtendimento *f, Pessoa *p) {
    if (estaVazia(f)) {
        return -1;
    }
    int posicao = f->inicio;
    *p = f->itens[posicao];
    f->inicio = (f->inicio + 1) % TAMANHO;
    f->quantidade--;
    return posicao;
}

void visualizar(FilaAtendimento *f) {
    int i, pos;
    if (estaVazia(f)) {
        printf("Fila de espera vazia.\n");
        return;
    }
    printf("Fila de espera (ordem de atendimento):\n");
    for (i = 0; i < f->quantidade; i++) {
        pos = (f->inicio + i) % TAMANHO;
        printf("  %d. Senha %03d - %s (posicao do array: %d)\n",
               i + 1, f->itens[pos].senha, f->itens[pos].nome, pos);
    }
}

void limparEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    FilaAtendimento fila;
    Pessoa pessoa;
    int opcao, posicao;
    int proximaSenha = 1;

    inicializar(&fila);

    do {
        printf("\n===== FILA DE ATENDIMENTO =====\n");
        printf("1 - Inserir pessoa\n");
        printf("2 - Chamar proxima pessoa\n");
        printf("3 - Visualizar fila de espera\n");
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
                if (estaCheia(&fila)) {
                    printf("Erro: fila cheia (overflow). Nao e possivel inserir.\n");
                    break;
                }
                printf("Nome da pessoa: ");
                if (scanf(" %49[^\n]", pessoa.nome) != 1) {
                    limparEntrada();
                    printf("Nome invalido.\n");
                    break;
                }
                pessoa.senha = proximaSenha;
                posicao = inserir(&fila, pessoa);
                proximaSenha++;
                printf("Senha %03d gerada para %s (gravada na posicao %d do array).\n",
                       pessoa.senha, pessoa.nome, posicao);
                break;
            case 2:
                posicao = chamarProximo(&fila, &pessoa);
                if (posicao == -1) {
                    printf("Erro: fila vazia (underflow). Ninguem para chamar.\n");
                } else {
                    printf("Chamando senha %03d - %s (liberada a posicao %d do array).\n",
                           pessoa.senha, pessoa.nome, posicao);
                }
                break;
            case 3:
                visualizar(&fila);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

        if (opcao >= 1 && opcao <= 3) {
            mostrarEstado(&fila);
        }
    } while (opcao != 4);

    return 0;
}
