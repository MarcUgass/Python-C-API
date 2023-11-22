#include <Python.h>
#include <iostream>

using namespace std;

int main() {
    // Inicializar el intérprete de Python
    Py_Initialize();

    // Crear una lista de Python
    PyObject *pList = PyList_New(0);

    for (int i = 0; i < 5; ++i) {
        string input;
        int number;

        // Pedir al usuario que ingrese un número
        cout << "Ingrese un número: ";
        getline(cin, input);

        try {
            // Convertir la entrada a un número
            number = stoi(input);

            // Añadir el número a la lista
            PyList_Append(pList, PyLong_FromLong(number));

        } catch (const invalid_argument &e) {
            // Manejar el error si el usuario ingresa algo que no es un número
            cerr << "Error: Ingrese un número válido." << endl;
            i--;  // Decrementar el índice para pedir nuevamente
        }
    }

    // Mostrar la lista resultante
    cout << "Lista resultante: [";
    for (Py_ssize_t i = 0; i < PyList_Size(pList); ++i) {
        PyObject *pItem = PyList_GetItem(pList, i);
        long number = PyLong_AsLong(pItem);
        cout << number;

        if (i < PyList_Size(pList) - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // Liberar la lista y finalizar el intérprete de Python
    Py_DECREF(pList);
    Py_Finalize();

    return 0;
}
