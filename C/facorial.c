#include <stdio.h>
#include <time.h>

long long int facto_iterativo(int n) {
    long long int resultado = 1; 
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

long long int facto_recursivo(int n) {
    if (n <= 1) return 1;
    return n * facto_recursivo(n - 1);
}

int main() {
    clock_t inicio, fin;
    double tiempo_iterativo, tiempo_recursivo;
    int repeticiones = 1000000; // repetir para medir bien el tiempo

    printf("n\tTiempo Iterativo (s)\tTiempo Recursivo (s)\n");
    printf("-------------------------------------------------\n");

    for (int n = 1; n <= 20; n++) { // de 1 a 20
        // Medir iterativo
        inicio = clock();
        for (int j = 0; j < repeticiones; j++) {
            facto_iterativo(n);
        }
        fin = clock();
        tiempo_iterativo = (double)(fin - inicio) / CLOCKS_PER_SEC / repeticiones;

        // Medir recursivo
        inicio = clock();
        for (int j = 0; j < repeticiones; j++) {
            facto_recursivo(n);
        }
        fin = clock();
        tiempo_recursivo = (double)(fin - inicio) / CLOCKS_PER_SEC / repeticiones;

        printf("%d\t%.10f\t\t%.10f\n", n, tiempo_iterativo, tiempo_recursivo);
    }

    return 0;
}
