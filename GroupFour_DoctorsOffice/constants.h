#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QStandardPaths>

    static const QString GLOBAL_CONST_app_data_path { QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/GroupFour_DoctorsOffice" };
    static const QString GLOBAL_CONST_db_path { GLOBAL_CONST_app_data_path + "/SQLite/office.db" };
#endif // CONSTANTS_H
