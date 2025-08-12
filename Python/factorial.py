from memory_profiler import memory_usage
import time
import matplotlib.pyplot as plt

def facto_iterativo(n): 
    if n < 0:
        return "error"
    elif n == 1 or n == 0: 
        return 1
    else:
        resultado = 1
        for i in range(1, n+1): 
            resultado *= i
        return resultado

def facto_recursivo(n):
    if n < 0:
        return "error"
    elif n == 1 or n == 0: 
        return 1
    else:
        return n * facto_recursivo(n-1)

if __name__ == "__main__":
    lista_tiempos_i = []
    lista_tiempos_r = []
    lista_memoria_i = []
    lista_memoria_r = []

    n_valores = list(range(1, 20))

    # Iterativo
    for i in n_valores:
        inicio = time.perf_counter()
        mem, _ = memory_usage((facto_iterativo, (i,)), retval=True, max_iterations=1)
        fin = time.perf_counter()
        lista_tiempos_i.append(fin - inicio)
        lista_memoria_i.append(max(mem))

    # Recursivo
    for i in n_valores:
        inicio = time.perf_counter()
        mem, _ = memory_usage((facto_recursivo, (i,)), retval=True, max_iterations=1)
        fin = time.perf_counter()
        lista_tiempos_r.append(fin - inicio)
        lista_memoria_r.append(max(mem))

    # ======= GRAFICAR =======
    plt.figure(figsize=(10, 4))

    # Gráfica de tiempos
    plt.subplot(1, 2, 1)
    plt.plot(n_valores, lista_tiempos_i, marker='o', label="Iterativo")
    plt.plot(n_valores, lista_tiempos_r, marker='o', label="Recursivo")
    plt.title("Comparación de Tiempos")
    plt.xlabel("n")
    plt.ylabel("Tiempo (segundos)")
    plt.legend()
    plt.grid(True)

    # Gráfica de memoria
    plt.subplot(1, 2, 2)
    plt.plot(n_valores, lista_memoria_i, marker='o', label="Iterativo")
    plt.plot(n_valores, lista_memoria_r, marker='o', label="Recursivo")
    plt.title("Comparación de Uso de Memoria")
    plt.xlabel("n")
    plt.ylabel("Memoria (MB)")
    plt.legend()
    plt.grid(True)

    plt.tight_layout()
    plt.show()