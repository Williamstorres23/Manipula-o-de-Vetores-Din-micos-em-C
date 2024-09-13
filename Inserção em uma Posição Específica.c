#include <stdio.h>
#include <stdlib.h>


int* inserirElemento(int *vetor, int *tamanho, int valor, int posicao) {
    if (posicao < 0 || posicao > *tamanho) {
        printf("Posição inválida\n");
        return vetor;
    }

    int novoTamanho = (*tamanho) + 1;
    

    vetor = (int *)realloc(vetor, novoTamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Falha na realocação de memória\n");
        exit(1);
    }


    for (int i = *tamanho; i > posicao; i--) {
        vetor[i] = vetor[i - 1];
    }

    vetor[posicao] = valor;

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
        vetor = inserirElemento(vetor, &tamanho, valor, tamanho); 
    }

    printf("Conteúdo do vetor antes da inserção:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Digite o valor a ser inserido: ");
    scanf("%d", &valor);
    printf("Digite a posição onde o valor deve ser inserido: ");
    scanf("%d", &posicao);

    vetor = inserirElemento(vetor, &tamanho, valor, posicao);

    printf("Conteúdo do vetor após a inserção:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    free(vetor);
    return 0;
}
