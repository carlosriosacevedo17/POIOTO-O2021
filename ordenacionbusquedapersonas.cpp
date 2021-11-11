#include <iostream>
using namespace std;
class Persona
{
private:
    string nombre;
    float peso;
public:
    void setNombre(string n) { nombre = n; }
    void setPeso(float p) { peso = p; }
    float getPeso() { return peso; }
    string getNombre() { return nombre; }
    Persona(string n = "", float p = 0.0)
    {
        nombre = n;
        peso = p;
    }
};

void intercambiar(Persona v[],int j)
{
    Persona p;
    p = v[j];
    v[j] = v[j + 1];
    v[j + 1] = p;
}

void ordShell(Persona a[], int n)
{
    int salto, i, j, k;
    salto = n / 2;
    while (salto > 0) {
        for (int i = salto; i < n; i++)
        {
            j = i - salto;
            while (j >= 0)
            {
                k = j + salto;
                if (a[j].getPeso() <= a[k].getPeso())
                    j = -1;
                else
                {
                    intercambiar(a, j);
                    j -= salto;
                }
            }
        }
        salto = salto / 2;
    }
}

void mostrarVector(Persona vectorPersona[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNombre Persona " << i + 1 << ": " << vectorPersona[i].getNombre() << endl;
        cout << "\nPeso Persona " << i + 1 << ": " << vectorPersona[i].getPeso() <<" kg "<< endl;
    }
}
Persona busquedaLinealPersonas(Persona vectorPersona[],string nombre,int numPersonas)
{
    Persona p;
    for (int i = 0; i < numPersonas; i++)
    {
        if (vectorPersona[i].getNombre() == nombre)
        {
            p = vectorPersona[i];
            break;
        }
            
    }
    return p;
}

void PersonaABuscar(Persona vectorPersona[],int numPersonas)
{
    string nombre;
    cout << "\nEscribe el nombre de la Persona que buscas: ";
    cin >> nombre;
    Persona paux;
    paux = busquedaLinealPersonas(vectorPersona, nombre, numPersonas);
    if (paux.getPeso() > 0.0)
    {
        cout << "\nEl nombre de la persona es: " << paux.getNombre() << endl;
        cout << "\nEl peso de la persona es: " << paux.getPeso() << endl;
    }
    else
        cout << "\nLa persona que buscas no se encuentra con ese nombre" << endl;
}

int main()
{
    Persona vectorPersona[100];
    Persona p;
    int i = 0;
    string nombre;
    float peso;
    int numPersonas;
    cout << "\nEscribe el numero de Personas a ingresar: ";
    cin >> numPersonas;
    do
    {
        cout << "\nNombre Persona " << i+1 << ": ";
        cin >> nombre;
        cout << "\nPeso Persona " << i+1 << ": ";
        cin >> peso;
        p.setNombre(nombre);
        p.setPeso(peso);
        vectorPersona[i] = p;
        i++;
    } while (i<numPersonas);
    //ordShell(vectorPersona, numPersonas);
    //mostrarVector(vectorPersona, numPersonas);
    PersonaABuscar(vectorPersona, numPersonas);
    return 0;
}
