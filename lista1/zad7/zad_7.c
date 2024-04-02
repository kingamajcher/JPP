// zadanie_7.c

#include "zad_7.h"
#include <python3.10/Python.h>

long long wrapped_factorialL(unsigned n) {
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    long long result = -1;

    Py_Initialize();
    pName = PyUnicode_DecodeFSDefault("python_lib");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, "factorialL");
        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(1);
            PyTuple_SetItem(pArgs, 0, PyLong_FromUnsignedLong(n));

            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                result = PyLong_AsLongLong(pValue);
                Py_DECREF(pValue);
            }
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }

    Py_FinalizeEx();
    return result;
}

long long wrapped_factorialR(unsigned n) {
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    long long result = -1;

    Py_Initialize();
    pName = PyUnicode_DecodeFSDefault("python_lib");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, "factorialR");
        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(1);
            PyTuple_SetItem(pArgs, 0, PyLong_FromUnsignedLong(n));

            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                result = PyLong_AsLongLong(pValue);
                Py_DECREF(pValue);
            }
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }

    Py_FinalizeEx();
    return result;
}

unsigned wrapped_gcdL(unsigned a, unsigned b) {
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    unsigned result = -1;

    Py_Initialize();
    pName = PyUnicode_DecodeFSDefault("python_lib");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, "gcdL");
        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(2);
            PyTuple_SetItem(pArgs, 0, PyLong_FromUnsignedLong(a));
            PyTuple_SetItem(pArgs, 1, PyLong_FromUnsignedLong(b));

            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                result = PyLong_AsUnsignedLong(pValue);
                Py_DECREF(pValue);
            }
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }

    Py_FinalizeEx();
    return result;
}

unsigned wrapped_gcdR(unsigned a, unsigned b) {
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    unsigned result = -1;

    Py_Initialize();
    pName = PyUnicode_DecodeFSDefault("python_lib");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, "gcdR");
        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(2);
            PyTuple_SetItem(pArgs, 0, PyLong_FromUnsignedLong(a));
            PyTuple_SetItem(pArgs, 1, PyLong_FromUnsignedLong(b));

            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                result = PyLong_AsUnsignedLong(pValue);
                Py_DECREF(pValue);
            }
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }

    Py_FinalizeEx();
    return result;
}

DiophantineSolution wrapped_diophantineL(int a, int b, int c) {
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    DiophantineSolution result = {-1, -1, -1, -1};

    Py_Initialize();
    pName = PyUnicode_DecodeFSDefault("python_lib");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, "diophantineEqL");
        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(3);
            PyTuple_SetItem(pArgs, 0, PyLong_FromLong(a));
            PyTuple_SetItem(pArgs, 1, PyLong_FromLong(b));
            PyTuple_SetItem(pArgs, 2, PyLong_FromLong(c)); // Ensure c is passed as a long

            pValue = PyObject_CallObject(pFunc, pArgs);
            if (pValue != NULL) {
                result.x = PyFloat_AsDouble(PyTuple_GetItem(pValue, 0));
                result.y = PyFloat_AsDouble(PyTuple_GetItem(pValue, 1));
                result.xk = PyFloat_AsDouble(PyTuple_GetItem(pValue, 2));
                result.yk = PyFloat_AsDouble(PyTuple_GetItem(pValue, 3));
                Py_DECREF(pValue);
            }
            Py_DECREF(pArgs);
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }

    Py_FinalizeEx();
    return result;
}

DiophantineSolution wrapped_diophantineR(int a, int b, int c) {
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    DiophantineSolution result = {-1, -1, -1, -1};

    Py_Initialize();
    pName = PyUnicode_DecodeFSDefault("python_lib");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, "diophantineEqR");
        if (pFunc && PyCallable_Check(pFunc)) {
            pArgs = PyTuple_New(3);
            PyTuple_SetItem(pArgs, 0, PyLong_FromLong(a));
            PyTuple_SetItem(pArgs, 1, PyLong_FromLong(b));
            PyTuple_SetItem(pArgs, 2, PyLong_FromLong(c)); // Ensure c is passed as a long

            pValue = PyObject_CallObject(pFunc, pArgs);
            if (pValue != NULL) {
                result.x = PyFloat_AsDouble(PyTuple_GetItem(pValue, 0));
                result.y = PyFloat_AsDouble(PyTuple_GetItem(pValue, 1));
                result.xk = PyFloat_AsDouble(PyTuple_GetItem(pValue, 2));
                result.yk = PyFloat_AsDouble(PyTuple_GetItem(pValue, 3));
                Py_DECREF(pValue);
            }
            Py_DECREF(pArgs);
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }

    Py_FinalizeEx();
    return result;
}
