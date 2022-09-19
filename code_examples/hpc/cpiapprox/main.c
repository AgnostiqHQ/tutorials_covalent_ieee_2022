#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "stdio.h"

static PyObject* compute_pi(PyObject *self, PyObject *args) {
    unsigned int partitions;

    double area = 0.0;
    double dh;

    if (!PyArg_ParseTuple(args, "I", &partitions)) {
        return NULL;
    }

    dh = 1.0/partitions;

    for (int i = 0; i < partitions; i++) {
        double x = dh * (i - 0.5);
        area += (4.0/(1.0 + x*x));
    }

    // pi approximation
    return PyFloat_FromDouble(area*dh);
}

static PyMethodDef PiapproxMethods[] = {
    {"compute_pi", compute_pi, METH_VARARGS, "compute an approximation to PI using Reimann integration"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef cpiapprox = {
    PyModuleDef_HEAD_INIT,
    "cpiapprox",
    NULL,
    -1,
    PiapproxMethods
};

PyMODINIT_FUNC PyInit_cpiapprox(void) {
    return PyModule_Create(&cpiapprox);
}
