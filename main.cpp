#include "loginwindow.h"
#include "usermanager.h"
#include "bookrecords.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UserManager userManager("Y:\\AUC\\CS II\\CS2 Lab\\Project\\Librarystem\\users.txt");
    LoginWindow login(&userManager);
    login.show();

    return a.exec();
}
