#include <QString>

#define V_VER_MAJOR 1
#define V_VER_MINOR 0
#define V_VER_BUILD 1


#define V_VERSION QString("%1.%2.%3").arg(V_VER_MAJOR).arg(V_VER_MINOR).arg(V_VER_BUILD)
#define ALQUDS_VERSION QString("AlQuds v. %1").arg(V_VERSION)
#define V_DATE "2012-11-18"
#define V_COPYRIGHT "Copyright (c) 2012 Ghannami"
#define VERSION_COPYRIGHT_DATE QString("%1.%2.%3").arg(V_VERSION).arg(V_COPYRIGHT).arg(V_DATE)
