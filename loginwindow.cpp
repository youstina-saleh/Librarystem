#include "loginwindow.h"
#include "ui_loginwindow.h"
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
    if (role == "Admin")
        ui->label_empty_error->setText("Logged in as Admin");
    else if (role == "Member")
        ui->label_empty_error->setText("Logged in as Member");
    else
        ui->label_empty_error->setText("Logged in as " + QString::fromStdString(role));
}



