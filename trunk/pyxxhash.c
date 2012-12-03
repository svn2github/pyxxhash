#include <Python.h>
#include "xxhash.h"

static char pyxxhash_docstring[]= "Python wrapper for fast hash library xxhash";

static PyObject *pyxxhash_fast32(PyObject *self,PyObject *args)
{
  const char *input;
  int len;
  unsigned int seed,result;
  if (!PyArg_ParseTuple(args,"s|i|I",&input,&len,&seed)) return NULL;
  result=XXH_fast32(input,len,seed);
  return Py_BuildValue("I",result);
}
static PyObject *pyxxhash_strong32(PyObject *self,PyObject *args)
{
  const char *input;
  int len;
  unsigned int seed,result;
  if (!PyArg_ParseTuple(args,"s|i|I",&input,&len,&seed)) return NULL;
  result=XXH_strong32(input,len,seed);
  return Py_BuildValue("I",result);
}

static PyMethodDef pyxxhash_methods[]={
  {"fast32",pyxxhash_fast32,METH_VARARGS,pyxxhash_docstring},
  {"strong32",pyxxhash_strong32,METH_VARARGS,pyxxhash_docstring},
  {NULL,NULL,0,NULL}
};

PyMODINIT_FUNC initpyxxhash(void)
{
  PyObject *m=Py_InitModule("pyxxhash",pyxxhash_methods);
  if (m==NULL) return;
}
