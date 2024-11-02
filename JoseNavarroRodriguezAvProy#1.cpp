#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Pilas // Estructura de la pila de NODOS
{
    int valor;
    Pilas *dir_sig;
} *primero, *nuevo, *auxiliar;

/*
   PILA =  27  14  7  8 9  NULL
                                                                            dirección
    primero = 27 ->  14  ->  7 -> 8 -> 9 -> null 					nuevo =  27 -> 14

*/

void Insertar()
{
    nuevo = new (Pilas);
    cout << "\n Digite el dato a almacenar: ";
    cin >> nuevo->valor;
    cout << "\n Se ha ingresado el dato correctamente en la Pila " << endl;

    nuevo->dir_sig = primero;
    primero = nuevo;

    system("pause");
}

void Eliminar()
{
    if (primero == NULL)
    {
        cout << "\n Pila vacia, no se puede eliminar datos. " << endl;
        system("pause");
        return;
    }

    nuevo = new (Pilas);
    nuevo = primero;
    cout << "\n Eliminando dato de la Pila...." << endl;
    cout << "\n El dato eliminado de la Pila es: " << nuevo->valor << endl;
    primero = nuevo->dir_sig;
    delete (nuevo);
    system("pause");
}

/*
   PILA =  27  14  7  8 9  NULL

    primero = 27 -> 14  -> 7 -> 8 -> 9 -> null 			nuevo =  27 -> 14  ->     7->  8 ->    9 -> NULL

*/

void Mostrar()
{
    if (primero == NULL)
    {
        cout << "\n  Pila vacía, no se puede mostrar ningún dato. " << endl;
        system("pause");
        return;
    }
    int i = 0;
    nuevo = primero;
    cout << "\n *** Elementos de la Pila *** " << endl;
    while (nuevo != NULL)
    {
        cout << "\n Elementos No. " << i << ": " << nuevo->valor << endl;
        nuevo = nuevo->dir_sig;
        i++;
    }
    system("pause");
}

void Mayor_Menor() // función para mostrar el dato mayor de la pila
{

    if (primero == NULL)
    {
        cout << "\n Lo sentimos, la pila no contiene datos";
        system("pause");
    }
    else
    {
        int mayor = primero->valor;
        int menor = primero->valor;

        // Auxiliar para recorrer la pila
        auxiliar = primero;

        // Recorrer la pila
        while (auxiliar != NULL)
        {
            if (auxiliar->valor > mayor)
            {
                mayor = auxiliar->valor; // Actualizar mayor
            }
            if (auxiliar->valor < menor)
            {
                menor = auxiliar->valor; // Actualizar menor
            }

            auxiliar = auxiliar->dir_sig; // Avanzar al siguiente nodo
        }

        cout << "\n El dato mayor de la pila es: " << mayor;
        cout << "\n Y el menor de la Pila es: " << menor << endl;
    }
}
void Ascend_Descend()
{

    if (primero == NULL)
    {
        cout << "\n Lo sentimos, la pila no contiene datos";
        system("pause");
    }
    else
    {
        vector<int> valores;
        auxiliar = primero;

        // Paso 1: Extraer los valores de la
        while (auxiliar != NULL)
        {
            valores.push_back(auxiliar->valor);
            auxiliar = auxiliar->dir_sig;
        }

        // Paso 2: Ordenar los valores en orden ascendente
        sort(valores.begin(), valores.end());

        // Paso 3: Mostrar los valores en orden ascendente
        cout << "\n Los valores ascendentemente son: ";
        for (int valor : valores)
        {
            cout << valor << " ";
        }

        // Paso 4: Mostrar los valores en orden descendente
        cout << "\n Los valores descendentemente son: ";
        for (auto it = valores.rbegin(); it != valores.rend(); ++it)
        {
            cout << *it << " ";
        }

        cout << endl;
        system("pause");
    }
}

void Buscar_dato()
{
    if (primero == NULL)
    {
        cout << "\n Pila vacía, no se puede buscar ningún dato. " << endl;
        return;
    }

    int datoBuscado, posicion = 0;
    bool encontrado = false;
    cout << "\n Ingrese el dato a buscar: ";
    cin >> datoBuscado;

    auxiliar = primero;
    while (auxiliar != NULL)
    {
        if (auxiliar->valor == datoBuscado)
        {
            cout << "\n Dato encontrado en la posición: " << posicion << endl;
            encontrado = true;
        }
        auxiliar = auxiliar->dir_sig;
        posicion++;
    }

    if (!encontrado)
    {
        cout << "\n El dato no se encuentra en la pila." << endl;
    }
}
void Modificar_dato()
{
    if (primero == NULL)
    {
        cout << "\n Pila vacía, no se puede modificar ningún dato. " << endl;
        return;
    }

    int datoBuscado, nuevoValor;
    bool encontrado = false;
    cout << "\n Ingrese el dato a buscar para modificar: ";
    cin >> datoBuscado;

    auxiliar = primero;
    while (auxiliar != NULL)
    {
        if (auxiliar->valor == datoBuscado)
        {
            cout << "\n Dato encontrado. Ingrese el nuevo valor: ";
            cin >> nuevoValor;
            auxiliar->valor = nuevoValor;
            cout << "\n Dato modificado con éxito." << endl;
            encontrado = true;
            break;
        }
        auxiliar = auxiliar->dir_sig;
    }

    if (!encontrado)
    {
        cout << "\n El dato no se encuentra en la pila." << endl;
    }
}
void Eliminar_dato()
{
    if (primero == NULL)
    {
        cout << "\n Pila vacía, no se puede eliminar ningún dato. " << endl;
        return;
    }

    int datoBuscado;
    bool encontrado = false;
    cout << "\n Ingrese el dato a buscar para eliminar: ";
    cin >> datoBuscado;

    auxiliar = primero;
    Pilas *anterior = NULL;

    while (auxiliar != NULL)
    {
        if (auxiliar->valor == datoBuscado)
        {
            if (anterior == NULL) // Si el nodo a eliminar es el primero
            {
                primero = auxiliar->dir_sig;
            }
            else
            {
                anterior->dir_sig = auxiliar->dir_sig;
            }
            delete auxiliar;
            cout << "\n Dato eliminado con éxito." << endl;
            encontrado = true;
            break;
        }
        anterior = auxiliar;
        auxiliar = auxiliar->dir_sig;
    }

    if (!encontrado)
    {
        cout << "\n El dato no se encuentra en la pila." << endl;
    }
}

#include <map> // Para el cálculo de la moda

void Sumar_Aumentar()
{
    if (primero == NULL)
    {
        cout << "\n Pila vacía, no se puede realizar la suma." << endl;
        return;
    }

    int suma = 0;
    auxiliar = primero;

    while (auxiliar != NULL)
    {
        suma += auxiliar->valor;
        auxiliar = auxiliar->dir_sig;
    }

    float sumaAumentada = suma * 2.5; // Incrementa el 150% (1 + 1.5 = 2.5)

    cout << "\n El resultado de la suma de los datos de la pila es: " << suma;
    cout << "\n La suma aumentada en un 150% es: " << sumaAumentada << endl;
}

void Promedio_Moda()
{
    if (primero == NULL)
    {
        cout << "\n Pila vacía, no se puede calcular el promedio ni la moda." << endl;
        return;
    }

    int suma = 0, cantidad = 0;
    map<int, int> frecuencias; // Mapa para calcular la frecuencia de cada valor
    auxiliar = primero;

    // Calcular suma, cantidad de elementos, y frecuencias de cada valor
    while (auxiliar != NULL)
    {
        suma += auxiliar->valor;
        frecuencias[auxiliar->valor]++;
        cantidad++;
        auxiliar = auxiliar->dir_sig;
    }

    // Calcular el promedio
    float promedio = static_cast<float>(suma) / cantidad;
    cout << "\n El resultado del promedio de los datos de la pila es: " << promedio;

    // Encontrar la moda
    int moda = 0, maxFrecuencia = 0;
    bool hayModa = false;
    for (const auto &par : frecuencias)
    {
        if (par.second > maxFrecuencia)
        {
            moda = par.first;
            maxFrecuencia = par.second;
            hayModa = true;
        }
        else if (par.second == maxFrecuencia)
        {
            hayModa = false; // No hay moda si múltiples valores tienen la misma frecuencia máxima
        }
    }

    if (hayModa && maxFrecuencia > 1)
    {
        cout << "\n El resultado de la moda de los datos de la pila es: " << moda << endl;
    }
    else
    {
        cout << "\n En la pila no se repite ningún dato." << endl;
    }
}

int main()
{
    int opc;

    do
    {
        cout << "\n     MENU DE OPCIONES A REALIZAR    \n";
        cout << "\n          1.  Insertar datos a la pila     \n";
        cout << "\n          2.  Eliminar datos al inicio de la pila     \n";
        cout << "\n          3.  Mostrar datos de la pila  \n";
        cout << "\n          4.  Buscar un dato específico  \n";
        cout << "\n          5.  Modificar un dato específico  \n";
        cout << "\n          6.  Eliminar un dato específico  \n";
        cout << "\n          7.  Mostrar Dato Mayor y Menor de la pila     \n";
        cout << "\n          8.  Ordenar Ascendente y Descendentemente la pila     \n";
        cout << "\n          9.  Sumar y aumentar datos de la pila     \n";
        cout << "\n          10. Promedio y Moda de la pila     \n";
        cout << "\n          11. Salir     \n";
        cout << "\n    Ingresa la opcion: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            Insertar();
            system("pause");
            break;

        case 2:
            Eliminar();
            system("pause");
            break;

        case 3:
            Mostrar();
            system("pause");
            break;
        case 4:
            Buscar_dato();
            system("pause");
            break;
        case 5:
            Modificar_dato();
            system("pause");
            break;
        case 6:
            Eliminar_dato();
            system("pause");
            break;
        case 7:
            Mayor_Menor();
            system("pause");
            break;

        case 8:
            Ascend_Descend();
            system("pause");
            break;
        case 9:
            Sumar_Aumentar();
            system("pause");
            break;
        case 10:
            Promedio_Moda();
            system("pause");
            break;
        case 11:
            exit(EXIT_SUCCESS);
            system("pause");
            break;
        default:
            cout << "\n Opcion Invalida, debe hacer una pausa y volver al menu. \n ";
            system("pause");
            opc = 1;
        }

        system("cls");

    } while (opc <= 11);
}
