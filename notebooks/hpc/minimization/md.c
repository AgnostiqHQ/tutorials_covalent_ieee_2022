#include "particle.h"


static PyModuleDef pymd = {
    PyModuleDef_HEAD_INIT,
    .m_name = "pymd",
    .m_doc = "Simple molecular dynamics in Python",
    .m_size = -1,
};


PyMODINIT_FUNC PyInit_md(void) {
    PyObject *m;
    if (PyType_Ready(&MDParticleType) < 0) {
        return NULL;
    }

    m = PyModule_Create(&pymd);
    if (m == NULL) {
        return NULL;
    }

    Py_INCREF(&MDParticleType);
    if (PyModule_AddObject(m, "Particle", (PyObject *) &MDParticleType) < 0) {
        Py_DECREF(&MDParticleType);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}