#include <stdio.h>
long long int facto_iterativo(int n){
    if ( n < 0)
    {
        return "error";
    }
    else if (n == 1)
    {
        return 1; 
    }
    else
    {
        int resultado = 1; 
        for ( int i = 1; i < n+1; i++)
        {
            resultado *= i;
        }
        return resultado;
    }
}
long long int facto_recursivo(int n){
    if ( n < 0)
    {
        return "error";
    }
    else if (n == 1)
    {
        return 1; 
    }
    else
    {
        return n*facto_recursivo(n-1);
    }
}
    int main()
    {
        printf("%lld\n", facto_iterativo(5));
        printf("%lld\n", facto_recursivo(5));
        return 0;
    }
    
