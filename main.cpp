#include "loginwindow.h"
#include "usermanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UserManager userManager;
    LoginWindow login(&userManager);
    login.show();

    return a.exec();
}
