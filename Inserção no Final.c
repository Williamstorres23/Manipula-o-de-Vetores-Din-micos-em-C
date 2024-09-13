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

int main() {
    int *vetor;
    int tamanho = 0;
    int valor;

    vetor = NULL;

    for (int i = 0; i < 5; i++) {
        printf("Digite um valor para adicionar ao vetor: ");
        scanf("%d", &valor);
        vetor = adicionarElemento(vetor, &tamanho, valor);
    }

    printf("Conteúdo do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);

    return 0;
}
