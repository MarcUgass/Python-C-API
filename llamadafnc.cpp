#include <Python.h>

int main() {
    Py_Initialize();

    PyRun_SimpleString(
        "def multiplicar(a, b):"
        "    return a * b\n"
    );

    PyObject* pModule = PyImport_AddModule("__main__");
    PyObject* pDict = PyModule_GetDict(pModule);

    // Obtén la función 'multiplicar'
    PyObject* pFunc = PyDict_GetItemString(pDict, "multiplicar");

    if (pFunc && PyCallable_Check(pFunc)) {
        // Prepara los argumentos y llama a la función
        PyObject* pArgs = PyTuple_Pack(2, PyLong_FromLong(5), PyLong_FromLong(3));
        PyObject* pValue = PyObject_CallObject(pFunc, pArgs);

        if (pValue) {
            // Muestra el resultado obtenido en C++
            long resultado = PyLong_AsLong(pValue);
            printf("El resultado de la multiplicación es: %ld\n", resultado);
            Py_DECREF(pValue);
        } else {
            PyErr_Print();
        }

        Py_DECREF(pArgs);
    } else {
        PyErr_Print();
    }

    Py_Finalize();

    return 0;
}