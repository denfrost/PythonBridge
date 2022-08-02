#ifndef QTPYTHONBRIDGE_H
#define QTPYTHONBRIDGE_H

#include "QtPythonBridge_global.h"
#include "QString"

#if defined _WIN32 || defined _WIN64
//WINDOWS OS INCLUDES
#pragma push_macro("slots")
#undef slots
#include <Python.h>
#pragma pop_macro("slots")
#elif defined __linux__
//LINUX OS INCLUDES
#include <python3.10/Python.h>
#else
//MAC OS INCLUDES
#endif

class QTPYTHONBRIDGE_EXPORT QtPythonBridge
{
public:
    QtPythonBridge();

    bool RunSimplePyCommand(const char* command);
};

#endif // QTPYTHONBRIDGE_H
