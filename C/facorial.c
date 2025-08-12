#include <stdio.h>
#include <time.h>
#include <sys/resource.h> // Para getrusage()

// Factorial iterativo
unsigned long long facto_iterativo(int n) {
    unsigned long long resultado = 1; 
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

// Factorial recursivo
unsigned long long facto_recursivo(int n) {
    if (n <= 1) return 1;
    return n * facto_recursivo(n - 1);
}

// Función para obtener uso de memoria en KB
long get_memory_usage_kb() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss; 
}

int main() {
    clock_t inicio, fin;
    double tiempo_iterativo, tiempo_recursivo;
    int repeticiones = 1000000; 

    printf("n\tTiempo Iterativo (s)\tMemoria Iterativa (KB)\tTiempo Recursivo (s)\tMemoria Recursiva (KB)\n");
    printf("-------------------------------------------------------------------------------------------------\n");

    for (int n = 1; n <= 20; n++) {
        // --- Medir iterativo ---
        inicio = clock();
        for (int j = 0; j < repeticiones; j++) {
            facto_iterativo(n);
        }
        fin = clock();
        tiempo_iterativo = (double)(fin - inicio) / CLOCKS_PER_SEC / repeticiones;
        long mem_iter = get_memory_usage_kb();

        // --- Medir recursivo ---
        inicio = clock();
        for (int j = 0; j < repeticiones; j++) {
            facto_recursivo(n);
        }
        fin = clock();
        tiempo_recursivo = (double)(fin - inicio) / CLOCKS_PER_SEC / repeticiones;
        long mem_rec = get_memory_usage_kb();

        printf("%d\t%.10f\t\t%ld\t\t\t%.10f\t\t%ld\n", n, tiempo_iterativo, mem_iter, tiempo_recursivo, mem_rec);
    }

    return 0;
}
