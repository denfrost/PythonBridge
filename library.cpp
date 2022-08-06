#include "library.h"

#include <iostream>

PythonBridge::PythonBridge()
{

}

void PythonBridge::hello()
{
    std::cout << "Hello, World!" << std::endl;
}

int PythonBridge::PyRunScript(const char *command)
{
    int badarg = 0;

    Py_Initialize();

    PyRun_SimpleString(command);
    badarg = PyErr_BadArgument();

    Py_Finalize();

    return badarg;
}
