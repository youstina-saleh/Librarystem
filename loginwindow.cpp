#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "adminpage.h"
#include "dashboard.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

LoginWindow::LoginWindow(UserManager* mgr, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::LoginWindow), userManager(mgr)
{
    ui->setupUi(this);
}

void LoginWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    std::string role;
    bool ok = userManager->login(username.toStdString(), password.toStdString(), role);

    if (!ok) {
        ui->label_empty_error->setText("Invalid username or password");
        return;
    }

    // login success
    if (role == "admin"){
        this->hide();
        adminpage *adm = new adminpage(userManager);
        adm->exec();
        this->show();
        delete adm;
    }
    else if (role == "member" || role == "librarian"){
        this->hide();
        // Create and show Dashboard modally
        Dashboard* d = new Dashboard(username, QString::fromStdString(role), this);
        d->exec();
        this->show();
        delete d;
    }
}
