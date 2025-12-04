#include "borrowreturn.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BorrowReturn br("testUser");
    br.show();

    return a.exec();
}
