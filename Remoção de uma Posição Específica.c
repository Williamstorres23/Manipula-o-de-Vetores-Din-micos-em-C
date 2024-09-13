#include <stdio.h>
#include <stdlib.h>


int* adicionarElemento(int *vetor, int *tamanho, int valor) {
    int novoTamanho = (*tamanho) + 1;
    vetor = (int *)realloc(vetor, novoTamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Falha na realocação de memória\n");
        exit(1);
    }

    vetor[*tamanho] = valor;

    *tamanho = novoTamanho;

    return vetor;
}

int* removerElemento(int *vetor, int *tamanho, int posicao) {
    if (posicao < 0 || posicao >= *tamanho) {
        printf("Posição inválida\n");
        return vetor;
    }

    for (int i = posicao; i < (*tamanho) - 1; i++) {
        vetor[i] = vetor[i + 1];
    }

    int novoTamanho = (*tamanho) - 1;

    int* novoVetor = (int *)realloc(vetor, novoTamanho * sizeof(int));
    if (novoVetor == NULL && novoTamanho > 0) {
        printf("Falha na realocação de memória\n");
        exit(1);
    }

    vetor = novoVetor;
    *tamanho = novoTamanho;

    return vetor;
}

int main() {
    int *vetor;
    int tamanho = 0;
    int valor, posicao;

    vetor = NULL;

    for (int i = 0; i < 5; i++) {
        printf("Digite um valor para adicionar ao vetor: ");
        scanf("%d", &valor);
        vetor = adicionarElemento(vetor, &tamanho, valor);
    }

    printf("Conteúdo do vetor antes da remoção:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Digite a posição do valor a ser removido: ");
    scanf("%d", &posicao);

    vetor = removerElemento(vetor, &tamanho, posicao);

    printf("Conteúdo do vetor após a remoção:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);

    return 0;
}
