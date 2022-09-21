#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "stdio.h"


void vecadd(unsigned int N, double *__restrict__ a, double *__restrict__ b, double *__restrict__ c) {
    for (unsigned int i = 0; i < N; i++) {
        c[i] = a[i] + b[i];
    }
}

void vecmul(unsigned int N, double *__restrict__ a, double *__restrict__ b, double *__restrict__ c) {
    for (unsigned int i = 0; i < N; i++) {
        c[i] = a[i]*b[i];
    }
}


void vecdiv(unsigned int N, double *__restrict__ a, double *__restrict__ b, double *__restrict__ c) {
    for (unsigned int i = 0; i < N; i++) {
        c[i] = a[i]/b[i];
    }
}


static PyObject* pyvecadd(PyObject* self, PyObject *args) {
    int arraySize;

    PyObject *listA, *listB, *listC;

    if (!PyArg_ParseTuple(args, "O!O!", &PyList_Type, &listA, &PyList_Type, &listB)) {
        return Py_None;
    }

    arraySize = PyList_Size(listA);

    // Allocate memory and copy values
    double *a = (double*)PyMem_Calloc(arraySize, sizeof(double));
    double *b = (double*)PyMem_Calloc(arraySize, sizeof(double));
    double *c = (double*)PyMem_Calloc(arraySize, sizeof(double));

    for (int i = 0; i < arraySize; i++) {
        a[i] = PyFloat_AS_DOUBLE(PyList_GetItem(listA, i));
        b[i] = PyFloat_AS_DOUBLE(PyList_GetItem(listB, i));
    }

    // Call vecadd
    vecadd(arraySize, a, b, c);

    // Create the return list
    listC = PyList_New(arraySize);
    Py_INCREF(listC);

    for (int i = 0; i < arraySize; i++) {
        PyList_SET_ITEM(listC, i, PyFloat_FromDouble(c[i]));
    }

    PyMem_Free(a);
    PyMem_Free(b);
    PyMem_Free(c);

    return listC;
}

static PyObject *pyvecmul(PyObject *self, PyObject *args) {
    int arraySize;

    PyObject *listA, *listB, *listC;

    if (!PyArg_ParseTuple(args, "O!O!", &PyList_Type, &listA, &PyList_Type, &listB)) {
        return Py_None;
    }

    arraySize = PyList_Size(listA);

    // Allocate memory and copy values
    double *a = (double*)PyMem_Calloc(arraySize, sizeof(double));
    double *b = (double*)PyMem_Calloc(arraySize, sizeof(double));
    double *c = (double*)PyMem_Calloc(arraySize, sizeof(double));

    for (int i = 0; i < arraySize; i++) {
        a[i] = PyFloat_AS_DOUBLE(PyList_GetItem(listA, i));
        b[i] = PyFloat_AS_DOUBLE(PyList_GetItem(listB, i));
    }

    // Call vecmul
    vecmul(arraySize, a, b, c);

    // Create the return list
    listC = PyList_New(arraySize);
    Py_INCREF(listC);

    for (int i = 0; i < arraySize; i++) {
        PyList_SET_ITEM(listC, i, PyFloat_FromDouble(c[i]));
    }

    PyMem_Free(a);
    PyMem_Free(b);
    PyMem_Free(c);

    return listC;

}

static PyObject *pyvecdiv(PyObject *self, PyObject *args) {
    int arraySize;

    PyObject *listA, *listB, *listC;

    if (!PyArg_ParseTuple(args, "O!O!", &PyList_Type, &listA, &PyList_Type, &listB)) {
        return Py_None;
    }

    arraySize = PyList_Size(listA);

    // Allocate memory and copy values
    double *a = (double*)PyMem_Calloc(arraySize, sizeof(double));
    double *b = (double*)PyMem_Calloc(arraySize, sizeof(double));
    double *c = (double*)PyMem_Calloc(arraySize, sizeof(double));

    for (int i = 0; i < arraySize; i++) {
        a[i] = PyFloat_AS_DOUBLE(PyList_GetItem(listA, i));
        b[i] = PyFloat_AS_DOUBLE(PyList_GetItem(listB, i));
    }

    // Call vecdiv
    vecdiv(arraySize, a, b, c);

    // Create the return list
    listC = PyList_New(arraySize);
    Py_INCREF(listC);

    for (int i = 0; i < arraySize; i++) {
        PyList_SET_ITEM(listC, i, PyFloat_FromDouble(c[i]));
    }

    PyMem_Free(a);
    PyMem_Free(b);
    PyMem_Free(c);

    return listC;

}

static PyMethodDef carthimeticMethods[] = {
    {"vecadd", pyvecadd, METH_VARARGS, ""},
    {"vecmul", pyvecmul, METH_VARARGS, ""},
    {"vecdiv", pyvecdiv, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef carthimetic = {
    PyModuleDef_HEAD_INIT,
    "carthimetic",
    "",
    -1,
    carthimeticMethods,
};

PyMODINIT_FUNC PyInit_carthimetic(void) {
    return PyModule_Create(&carthimetic);
}