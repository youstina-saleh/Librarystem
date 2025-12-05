#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "adminpage.h"
#include "dashboard.h"

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

    if (role == "admin"){
        adminpage *adm = new adminpage(userManager);
        adm->setAttribute(Qt::WA_DeleteOnClose);
        adm->show();
        this->close();
    }
    else if (role == "member" || role == "librarian"){
        Dashboard* d = new Dashboard(username, QString::fromStdString(role), nullptr);
        d->setAttribute(Qt::WA_DeleteOnClose);
        d->show();
        this->close();
    }

}



