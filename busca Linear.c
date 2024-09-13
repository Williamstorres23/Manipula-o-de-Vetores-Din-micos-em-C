#include <stdio.h>
#include <stdlib.h>

int buscaLinear(int *vetor, int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int *vetor;
    int tamanho, i, valorProcurado, resultado;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Falha na alocação de memória\n");
        return 1;
    }

  
    printf("Digite os valores do vetor:\n");
    for (i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

   
    printf("Digite o valor a ser procurado: ");
    scanf("%d", &valorProcurado);

   
    resultado = buscaLinear(vetor, tamanho, valorProcurado);

  
    if (resultado != -1) {
        printf("Valor %d encontrado no índice %d\n", valorProcurado, resultado);
    } else {
        printf("Valor %d não encontrado no vetor\n", valorProcurado);
    }

   
    free(vetor);

    return 0;
}
