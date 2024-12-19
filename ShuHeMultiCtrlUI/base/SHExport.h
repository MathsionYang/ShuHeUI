#pragma once

#include <qglobal.h>


#if defined(SH_DLL)
#define SH_EXPORT Q_DECL_EXPORT
#else
#define SH_EXPORT Q_DECL_IMPORT
#endif  // MULTI_MAKDDLL
