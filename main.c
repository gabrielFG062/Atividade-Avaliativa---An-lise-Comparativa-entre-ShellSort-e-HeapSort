#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// --- FUNCOES DO HEAPSORT ---
void heapify(int arr[], int n, int i) {
    int maior = i; 
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && arr[esquerda] > arr[maior])
        maior = esquerda;

    if (direita < n && arr[direita] > arr[maior])
        maior = direita;

    if (maior != i) {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;
        heapify(arr, n, maior);
    }
}

void heapSort(int arr[], int n) {
    // Monta o heap (rearranja o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrai um por um os elementos do heap
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// --- FUNCAO DO SHELLSORT ---
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Funcao auxiliar para imprimir o vetor (usar apenas em vetores pequenos)
void imprimirVetor(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int dados[] = {30, 12, 45, 6, 18, 3};
    int n = 6;

    printf("Vetor original: ");
    imprimirVetor(dados, n);

    // Testando ShellSort
    shellSort(dados, n);
    printf("Vetor ordenado (ShellSort): ");
    imprimirVetor(dados, n);

    // Reiniciando vetor para testar HeapSort
    int dados2[] = {30, 12, 45, 6, 18, 3};
    heapSort(dados2, n);
    printf("Vetor ordenado (HeapSort): ");
    imprimirVetor(dados2, n);

    return 0;
}