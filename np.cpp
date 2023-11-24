#include <Python.h>
#include <numpy/arrayobject.h>
#include <iostream>
#include <chrono>

using namespace std;


int main() {
    Py_Initialize();

    import_array();

    int n = 10000;
    auto inicio_creacion = std::chrono::high_resolution_clock::now();

    npy_intp dims[2] = {n, n};
    PyObject* numpyArray = PyArray_SimpleNew(2, dims, NPY_DOUBLE);
    
    double* data = static_cast<double*>(PyArray_DATA(reinterpret_cast<PyArrayObject*>(numpyArray)));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            data[i * n + j] = i + j;
        }
    }

    auto fin_creacion = std::chrono::high_resolution_clock::now();

    auto inicio_operaciones = std::chrono::high_resolution_clock::now();
    double suma = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            suma += data[i*n+j];
        }
    }

    auto fin_operaciones = std::chrono::high_resolution_clock::now();

    auto duracion_operaciones = std::chrono::duration_cast<std::chrono::milliseconds>(fin_operaciones - inicio_operaciones);
    auto duracion_creacion = std::chrono::duration_cast<std::chrono::milliseconds>(fin_creacion - inicio_creacion);

    cout << "Tiempo de creación del array: " << duracion_creacion.count() << " milisegundos" << endl;
    cout << "Tiempo total de la suma: " << duracion_operaciones.count() << " milisegundos" << endl;
    
    printf("Sumatorio: ");
    printf("%f",suma);
    printf("\n");

    Py_DECREF(numpyArray);
    Py_Finalize();

    return 0;
}