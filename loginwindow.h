#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include "usermanager.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWindow; }

QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
     explicit LoginWindow(UserManager* mgr, QWidget *parent = nullptr);

private slots:
    void on_pushButton_login_clicked();

private:
     Ui::LoginWindow *ui;
     UserManager* userManager;
};
#endif // LOGINWINDOW_H

