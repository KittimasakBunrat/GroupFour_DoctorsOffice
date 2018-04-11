#include "mainwindow.h"
#include "dbhelper.h"
#include <QApplication>


static const QString db_path { "C:/Sqlite/office.db" };
static const QString doctors_table { "doctors" };
static const QString patients_table { "patients" };
static const QString appointments_table { "appointments" };

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    DbHelper db(db_path);
    if (db.isOpen())
    {
        db.create_table(doctors_table);
        db.create_table(patients_table);
        db.create_table(appointments_table);
        qDebug() << "Database OK";
    }
    else
    {
        qDebug() << "Database not connected";
    }

    return a.exec();
}
