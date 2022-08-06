#ifndef PYTHONBRIDGE_LIBRARY_H
#define PYTHONBRIDGE_LIBRARY_H

#if defined _WIN32 || defined _WIN64
//WINDOWS OS INCLUDES
#include <Python.h>
#elif defined __linux__
//LINUX OS INCLUDES
#include <python3.9/Python.h>
#else
//MAC OS INCLUDES
#endif

class PYTHONBRIDGE_LIBRARY_H PythonBridge
{
public:
    PythonBridge();
    void hello();

    int PyRunScript(const char* command);

    PyObject* GetPythonObject;
};

#endif //PYTHONBRIDGE_LIBRARY_H
