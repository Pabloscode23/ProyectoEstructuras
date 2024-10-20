#include <iostream>
#include <vector>

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
        cout << "\n          9. Sumar y aumentar datos de la pila     \n";
        cout << "\n          10.Promedio y Moda de la pila     \n";
        cout << "\n          11.  Salir     \n";
        cout << "\n    Ingresa la opcion: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            system("pause");
            Insertar();
            break;

        case 2:
            system("pause");
            Eliminar();
            break;

        case 3:
            system("pause");
            Mostrar();
            break;

        case 7:
            Mayor_Menor();
            system("pause");
            break;

        case 8:
            Ascend_Descend();
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

    } while (opc <= 6);
}
