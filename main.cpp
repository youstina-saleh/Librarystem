#include "loginwindow.h"
#include "usermanager.h"
#include "bookrecords.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BookRecords records;
    records.show();

    return a.exec();
}
