// Source code of the Python extension module.

#include <Python.h>

#define UNUSED(var) (void)(var)

/// @brief A number-crunching function
PyObject* crunch(PyObject* self, PyObject* args) {
  UNUSED(self);
  double x { 0 };
  if (not PyArg_ParseTuple(args, "d", &x)) {
    return nullptr;
  }
  x += 1;
  return PyFloat_FromDouble(x);
}

PyMethodDef core_methods[] = {
  { "crunch",  crunch, METH_VARARGS, "A number-crunching function." },
  { nullptr, nullptr, 0, nullptr }
};

struct PyModuleDef core_module = {
  PyModuleDef_HEAD_INIT,
  "_core",
  nullptr,
  -1,
  core_methods
};

/// @brief The module initialization function.
/// @note Notice the two underscores trailing `core`.
PyMODINIT_FUNC PyInit__core(void) {
  return PyModule_Create(&core_module);
}
