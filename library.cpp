#include "library.h"

#include <iostream>

PythonBridge::PythonBridge()
{

}

void PythonBridge::hello()
{
    std::cout << "Hello, World!" << std::endl;
}

const char *PythonBridge::GetCurrentEnviromentDir()
{

    Py_Initialize();

    const char* output = (char*)Py_GetPath();
    Py_Finalize();

    return output;
}

void PythonBridge::SetEnviromentDir(const wchar_t *dir)
{
    Py_SetPath(dir);
    return;
}

int PythonBridge::PyRunScript(const char *command)
{
    int badarg = 0;

    Py_Initialize();

    badarg = PyRun_SimpleString(command);

    Py_Finalize();

    return badarg;
}

PyObject PythonBridge::GetPythonObject() {
    return PyObject();
}

