#include "adminpage.h"
#include "ui_adminpage.h"
#include <QMessageBox>
adminpage::adminpage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminpage)
{
    ui->setupUi(this);
}
adminpage::adminpage(UserManager* userManager, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminpage), userManager1(userManager)
{
    ui->setupUi(this);
}

adminpage::~adminpage()
{
    delete ui;
}

void adminpage::on_pushButton_add_clicked()
{
    QString qUsername = ui->lineEdit_username->text().trimmed();
    QString qPassword = ui->lineEdit_password->text();
    QString qRole;
    if (ui->radioButton_member->isChecked())
        qRole = "member";
    else if (ui->radioButton_librarian->isChecked())
        qRole = "librarian";

    string username = qUsername.toStdString();
    string password = qPassword.toStdString();
    string role     = qRole.toStdString();

    if (userManager1->usernameExists(username)) {
        QMessageBox::warning(this, "Failed", "Username already exists.");
        return;
    }
    User newUser(username, password, role);
    bool ok = userManager1->addUser(newUser);

    if (!ok) {
        QMessageBox::warning(this, "Error", "Failed to add user! Password must be 8+ chars and contain a digit.");
        return;
    }

    QMessageBox::information(this, "Success", "User added successfully!");

    ui->lineEdit_username->clear();
    ui->lineEdit_password->clear();
    ui->radioButton_member->setChecked(false);
    ui->radioButton_librarian->setChecked(false);
}


void adminpage::on_pushButton_load_clicked()
{

}

