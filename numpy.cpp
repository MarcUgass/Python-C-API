#include <Python.h>
#include <numpy/arrayobject.h>

int main() {
    // Inicializar Python
    Py_Initialize();

    // Importar el módulo NumPy
    import_array();

    // Crear un array de NumPy
    npy_intp dims[2] = {3, 3};
    PyObject* numpyArray = PyArray_SimpleNew(2, dims, NPY_DOUBLE);

    // Obtener el puntero a los datos del array
    double* data = static_cast<double*>(PyArray_DATA(reinterpret_cast<PyArrayObject*>(numpyArray)));

    // Llenar el array con algunos valores
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            data[i * 3 + j] = i + j;
        }
    }

    // Imprimir el contenido del array
    printf("Contenido del array:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%f ", data[i * 3 + j]);
        }
        printf("\n");
    }

    // Realizar una operación de suma usando NumPy
    PyObject* result = PyRun_String(
        "import numpy as np\n"
        "result = numpyArray + 1.0",
        Py_eval_input,
        nullptr,
        PyDict_New(),
        nullptr
    );

    // Obtener el resultado y imprimirlo
    PyObject* resultArray = PyObject_GetAttrString(result, "result");
    double* resultData = static_cast<double*>(PyArray_DATA(reinterpret_cast<PyArrayObject*>(resultArray)));

    printf("\nResultado de la operación de suma:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%f ", resultData[i * 3 + j]);
        }
        printf("\n");
    }

    // Liberar referencias y finalizar Python
    Py_DECREF(numpyArray);
    Py_DECREF(result);
    Py_DECREF(resultArray);
    Py_Finalize();

    return 0;
}