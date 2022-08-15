#ifndef PYTHONBRIDGE_LIBRARY_H
#define PYTHONBRIDGE_LIBRARY_H

#if defined _WIN32 || defined _WIN64
//WINDOWS OS INCLUDES
#include <Python.h>
#include <string.h>
#elif defined __linux__
//LINUX OS INCLUDES
#include <python3.9/Python.h>
#include <cstring>
#else
//MAC OS INCLUDES
#endif
#include <iostream>


using namespace std;


class PYTHONBRIDGE_LIBRARY_H PythonBridge
{
public:
    PythonBridge();
    void hello();

    // Setup virtual enviroment
    const char *GetCurrentEnviromentDir();
    void SetEnviromentDir(const wchar_t *dir);

    //Run Scripts
    int PyRunScript(const char* command);

    //python object
    PyObject GetPythonObject();

    //Variables
    PyObject *pyObject;
};

#endif //PYTHONBRIDGE_LIBRARY_H
