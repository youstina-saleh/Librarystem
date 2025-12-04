#include "loginwindow.h"
#include "usermanager.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UserManager userManager("C:\\Users\\Youstina Abouelkher\\Desktop\\LibrarySystem\\users.txt");
    LoginWindow login(&userManager);
    login.show();

    return a.exec();
}
