#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include <time.h> // Para medir el tiempo con clock()

// Factorial recursivo
unsigned long long facto_r(int n) {  // utilizamos long long para que pueda ampliarse los digitos
    if (n == 0 || n == 1) return 1;
    return n * facto_r(n - 1);
}

// Factorial iterativo
unsigned long long facto_i(int n) {   // utilizamos long long para que pueda ampliarse los digitos
    unsigned long long res = 1;
    for (int i = 2; i <= n; i++) {   // empieza desde 2 para que sea mas eficiente 
        res *= i;
    }
    return res;
}

// Función para medir uso de memoria (en KB)
long get_memory_usage_kb() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;   // Memoria mAxima usada (en KB)
}


int main() {
    int valores[] = {5, 50, 100, 500, 1000};  // Valores de prueba
    int num_valores = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < num_valores; i++) {
        int val = valores[i];

        //RECURSIVO 
        long mem_before = get_memory_usage_kb();  // Memoria antes de calcular
        clock_t start_r = clock(); // tiempo inicio  // Tiempo de inicio
        unsigned long long res_r = facto_r(val);  // Calcular factorial
        clock_t end_r = clock();   // tiempo fin// Tiempo de fin
        long mem_after = get_memory_usage_kb();  // Memoria después
        long mem_r = mem_after - mem_before;     // Diferencia de memoria
        double time_r = ((double)(end_r - start_r)) / CLOCKS_PER_SEC;  // tiempo en segundos

        //  ITERATIVO 
        mem_before = get_memory_usage_kb();
        clock_t start_i = clock();
        unsigned long long res_i = facto_i(val);
        clock_t end_i = clock();
        mem_after = get_memory_usage_kb();
        long mem_i = mem_after - mem_before;
        double time_i = ((double)(end_i - start_i)) / CLOCKS_PER_SEC;

        // MOSTRAR RESULTADOS 
        printf("Valor: %d\n", val);
        printf("  Recursivo: factorial = %llu, Memoria: %ld KB, Tiempo: %f s\n",
               res_r, mem_r, time_r);
        printf("  Iterativo: factorial = %llu, Memoria: %ld KB, Tiempo: %f s\n\n",
               res_i, mem_i, time_i);
    }

    return 0;
}