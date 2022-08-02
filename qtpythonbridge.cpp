#include "qtpythonbridge.h"

QtPythonBridge::QtPythonBridge()
{
}

bool QtPythonBridge::RunSimplePyCommand(const char* command)
{
    bool success = true;

    Py_Initialize();

    PyRun_SimpleString(command);
    if (PyErr_BadArgument() != 0)
        success = false;

    Py_Finalize();

    return success;
}
