from memory_profiler import memory_usage
import time

def facto_iteratico(n): 
    if n < 0:
        return "error"
    elif n == 1: 
        return 1
    else:
        resultado = 1
        for i in range(1, n+1): 
            resultado *= i
        return resultado

def facto_recursivo(n):
    if n < 0:
        return "error"
    elif n == 1: 
        return 1
    else:
        return n * facto_recursivo(n-1)

if __name__ == "__main__":
    lista_tiempos_i = []
    lista_tiempos_r = []
    lista_resultados_i = []
    lista_resultados_r = []
    lista_memoria_i = []
    lista_memoria_r = []

    # Iterativo
    for i in range(1, 20):
        inicio = time.perf_counter()
        mem = memory_usage((facto_iteratico, (i,)), max_iterations=20)
        lista_resultados_i.append(facto_iteratico(i)) 
        fin = time.perf_counter()
        
        lista_tiempos_i.append(fin - inicio)
        lista_memoria_i.append(max(mem))  # Guardar valor máximo de RAM

    # Recursivo
    for i in range(1, 20):
        inicio = time.perf_counter()
        mem = memory_usage((facto_recursivo, (i,)), max_iterations=20)
        lista_resultados_r.append(facto_recursivo(i)) 
        fin = time.perf_counter()
        
        lista_tiempos_r.append(fin - inicio)
        lista_memoria_r.append(max(mem))

    # Resultados
    print("tiempos iterativo")
    print(lista_tiempos_i)
    print("memoria iterativo (MB)")
    print(lista_memoria_i)
    print("resultados iterativo")
    print(lista_resultados_i)
    print("-"*30)
    print("tiempos recursivo")
    print(lista_tiempos_r)
    print("memoria recursivo (MB)")
    print(lista_memoria_r)
    print("resultados recursivo")
    print(lista_resultados_r)
