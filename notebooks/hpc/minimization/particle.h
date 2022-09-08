#ifndef PARTICLE_H_
#define PARTICLE_H_

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "structmember.h"

typedef struct {
    PyObject_HEAD
    uint32_t id;
    double x;
    double y;
    double mass;
} Particle;

// Prep Particle to be garbage collected
static void Particle_dealloc(Particle *self) {
    Py_XDECREF(self->id);
    Py_XDECREF(self->mass);
    Py_XDECREF(self->x);
    Py_XDECREF(self->y);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject* Particle_new(PyTypeObject *type, PyObject *args, PyObject *kwargs) {
    Particle *self;
    self = (Particle *) type->tp_alloc(type, 0);
    if (self != NULL) {
        self->id = 0;
        self->mass = 1.0;
        self->x = 0.0;
        self->y = 0.0;
    }

    return (PyObject *) self;
}

static int Particle_init(Particle *self, PyObject *args, PyObject *kwargs) {
    static char *kwlist[] = {"id", "mass", "x", "y", NULL};
    uint32_t *id = NULL;
    double *mass = NULL;
    double *x = NULL;
    double *y = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "|Iddd", kwlist, &id, &mass, &x, &y)) {
        return -1;
    }

    if (id) {
        self->id = *id;
        Py_XDECREF(id);
    }
    if (mass) {
        self->mass = *mass;
        Py_XDECREF(mass);
    }
    if (x) {
        self->x = *x;
        Py_XDECREF(x);
    }
    if (y) {
        self->y = *y;
        Py_XDECREF(y);
    }

    return 0;
}

static PyMemberDef Particle_members[] = {
    {"id", T_UINT}
}


static PyTypeObject MDParticleType {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pymd.Particle",
    .tp_doc = PyDoc_STR("Basic MD Particle type"),
    .tp_basicsize = sizeof(Particle),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew
};



#endif