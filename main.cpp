#include "loginwindow.h"
#include "usermanager.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Use relative path instead of absolute path
    UserManager userManager("C:\\Users\\wassi\\Downloads\\users.txt");
    LoginWindow login(&userManager);
    login.show();

    return a.exec();
}
