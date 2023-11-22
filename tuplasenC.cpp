#include <Python.h>
#include <iostream>
#include <chrono>

using namespace std;

PyObject* crear_tupla_grande(int n) {
    PyObject* tupla = PyTuple_New(n);
    for (int i = 0; i < n; ++i) {
        PyObject* num = PyLong_FromLong(i);
        PyTuple_SetItem(tupla, i, num);
    }
    return tupla;
}


long long suma_elementos(PyObject* tupla) {
    long long suma = 0;
    Py_ssize_t size = PyTuple_Size(tupla);
    for (Py_ssize_t i = 0; i < size; ++i) {
        suma += PyLong_AsLong(PyTuple_GetItem(tupla, i));
    }
    return suma;
}

int contar_elementos_impares(PyObject* tupla) {
    int count = 0;
    Py_ssize_t size = PyTuple_Size(tupla);
    for (Py_ssize_t i = 0; i < size; ++i) {
        if (PyLong_AsLong(PyTuple_GetItem(tupla, i)) % 2 != 0) {
            ++count;
        }
    }
    return count;
}

long encontrar_maximo(PyObject* tupla) {
    long maximo = LONG_MIN;
    Py_ssize_t size = PyTuple_Size(tupla);
    for (Py_ssize_t i = 0; i < size; ++i) {
        long elemento = PyLong_AsLong(PyTuple_GetItem(tupla, i));
        if (elemento > maximo) {
            maximo = elemento;
        }
    }
    return maximo;
}


int main() {
    Py_Initialize();
    int n = 100000000; // 100 millones

    auto inicio_creacion = std::chrono::high_resolution_clock::now();
    PyObject* tupla_grande = crear_tupla_grande(n);
    auto fin_creacion = std::chrono::high_resolution_clock::now();

    auto inicio_operaciones = std::chrono::high_resolution_clock::now();
    long long suma = suma_elementos(tupla_grande);
    int impares = contar_elementos_impares(tupla_grande);
    long maximo = encontrar_maximo(tupla_grande);
    auto fin_operaciones = std::chrono::high_resolution_clock::now();


    // Calcula los tiempos de ejecución
    auto duracion_creacion = std::chrono::duration_cast<std::chrono::milliseconds>(fin_creacion - inicio_creacion);
    auto duracion_operaciones = std::chrono::duration_cast<std::chrono::milliseconds>(fin_operaciones - inicio_operaciones);

    // Muestra los tiempos
    cout << "Tiempo de creación de la tupla: " << duracion_creacion.count() << " milisegundos" << endl;
    cout << "Tiempo total de operaciones: " << duracion_operaciones.count() << " milisegundos" << endl;
    cout << "Resultado de la suma: " << suma << endl;
    cout << "Cantidad de elementos impares: " << impares << endl;
    cout << "Valor máximo en la tupla: " << maximo << endl;

    Py_Finalize();
    return 0;
}

