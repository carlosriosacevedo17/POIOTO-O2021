#include <iostream>
using namespace std;
template<typename T>
void imprimeVector(T a[], int n, string mensaje)
{
    cout << mensaje;
    for (int i = 0; i < n; i++)
        cout << " " << a[i] << " ";
}
template<typename T>
void intercambiar(T& x, T& y)
{
    T aux = x;
    x = y;
    y = aux;
}
template<typename T>
void ordSeleccion(T a[], int n)
{
    int indiceMenor, i, j;
    for (i = 0; i < n-1; i++)
    {
        indiceMenor = i;
        for (j = i + 1; j < n; j++)
         {
            if (a[j] < a[indiceMenor])
                indiceMenor = j;
         }
        if (i != indiceMenor)//Cuando el elemento más pequeño es el inicial
            intercambiar(a[i], a[indiceMenor]);
    }
}
int main()
{
    char vector[5] = { 'z','w','a','c','d' };
    imprimeVector(vector, 5, " Vector Original: ");
    ordSeleccion(vector, 5);
    imprimeVector(vector, 5, "\nVector Ordenado: ");
    return 0;
}

