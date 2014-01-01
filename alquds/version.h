#include <QString>

#define V_VER_MAJOR 1
#define V_VER_MINOR 2
#define V_VER_BUILD 0



#define V_VERSION QString("%1.%2.%3").arg(V_VER_MAJOR).arg(V_VER_MINOR).arg(V_VER_BUILD)
#define ALQUDS_VERSION QString("alQuds v. %1").arg(V_VERSION)
#define V_DATE "2013-12-25"
#define V_COPYRIGHT "Copyright (c) 2014 ndalus.com"
#define VERSION_COPYRIGHT_DATE QString("%1.%2.%3").arg(V_VERSION).arg(V_COPYRIGHT).arg(V_DATE)
