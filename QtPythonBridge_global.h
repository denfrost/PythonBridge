#ifndef QTPYTHONBRIDGE_GLOBAL_H
#define QTPYTHONBRIDGE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTPYTHONBRIDGE_LIBRARY)
#  define QTPYTHONBRIDGE_EXPORT Q_DECL_EXPORT
#else
#  define QTPYTHONBRIDGE_EXPORT Q_DECL_IMPORT
#endif

#endif // QTPYTHONBRIDGE_GLOBAL_H
