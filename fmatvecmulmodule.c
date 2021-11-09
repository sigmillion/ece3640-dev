#include <Python.h>
#include <numpy/arrayobject.h>

static PyObject *method_matvecmul(PyObject *self, PyObject *args) {
    char *str, *filename = NULL;
    int bytes_copied = -1;

    /* Parse arguments */
    if(!PyArg_ParseTuple(args, "ss", &str, &filename)) {
        return NULL;
    }

    FILE *fp = fopen(filename, "w");
    bytes_copied = fputs(str, fp);
    fclose(fp);

    return PyLong_FromLong(bytes_copied);
}

static PyMethodDef MatvecmulMethods[] = {
    {"matvecmul", method_matvecmul, METH_VARARGS, "Python method for matrix-vector multiplication."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef matvecmulmodule = {
    PyModuleDef_HEAD_INIT,
    "matvecmul",
    "Python module for matrix-vector multiplication.",
    -1,
    MatvecmulMethods
};

PyMODINIT_FUNC PyInit_matvecmul(void) {
    return PyModule_Create(&matvecmulmodule);
}
