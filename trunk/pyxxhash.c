/*
   pyxxhash - python wrapper of Fast Hash algorithm library xxhash
   Copyright (C) 2012, Qi Gao.
   BSD 2-Clause License (http://www.opensource.org/licenses/bsd-license.php)

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:

       * Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
       * Redistributions in binary form must reproduce the above
   copyright notice, this list of conditions and the following disclaimer
   in the documentation and/or other materials provided with the
   distribution.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

	You can contact the author at :
	- pyxxhash source repository : http://code.google.com/p/pyxxhash/
*/
#include <Python.h>
#include "xxhash.h"

static char pyxxhash_docstring[]= "Python wrapper for fast hash library xxhash";
void *pstate=0;

static PyObject *pyxxhash_XXH32(PyObject *self,PyObject *args)
{
  const void *input;
  int len;
  unsigned int seed,result;
  if (!PyArg_ParseTuple(args,"s|i|I",&input,&len,&seed)) return NULL;
  result=XXH32(input,len,seed);
  return Py_BuildValue("I",result);
}
static PyObject *pyxxhash_init(PyObject *self,PyObject *args)
{
  unsigned int result,seed;

  if (!PyArg_ParseTuple(args,"I",&seed)) return NULL;
  pstate=XXH32_init(seed);
  if (pstate==0)
    {
      result=1;
    }else
    result=0;
  return Py_BuildValue("I",result);
}
static PyObject *pyxxhash_feed(PyObject *self,PyObject *args)
{
  const void *input;
  int len,result;
  if (!PyArg_ParseTuple(args,"s|i",&input,&len)) return NULL;
  result=XXH32_feed(pstate,input,len);
  return Py_BuildValue("i",result);
}
static PyObject *pyxxhash_result(PyObject *self,PyObject *args)
{
  unsigned int result;
  result=XXH32_result(pstate);
  return Py_BuildValue("I",result);
}
static PyMethodDef pyxxhash_methods[]={
  {"xxh32",pyxxhash_XXH32,METH_VARARGS,pyxxhash_docstring},
  {"init",pyxxhash_init,METH_VARARGS,pyxxhash_docstring},
  {"feed",pyxxhash_feed,METH_VARARGS,pyxxhash_docstring},
  {"result",pyxxhash_result,METH_VARARGS,pyxxhash_docstring},
  {NULL,NULL,0,NULL}
};

PyMODINIT_FUNC initpyxxhash(void)
{
  PyObject *m=Py_InitModule("pyxxhash",pyxxhash_methods);
  if (m==NULL) return;
}
