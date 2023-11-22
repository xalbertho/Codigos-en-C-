#include <stdio.h>

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Imprimir la matriz
    printf("Matriz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Calcular la suma de todos los elementos de la matriz
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }
    printf("La suma de los elementos de la matriz es: %d\n", sum);

    // Calcular la media de los elementos de la diagonal principal de la matriz
    float media = 0.0;
    for (int i = 0; i < 3; i++) {
        media += matrix[i][i];
    }
    media /= 3;
    printf("La media de los elementos de la diagonal principal de la matriz es: %.2f\n", media);

    // Multiplicar la matriz por un escalar
    int escalar = 2;
    printf("Matriz multiplicada por %d:\n", escalar);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j] * escalar);
        }
        printf("\n");
    }

    return 0;
}
