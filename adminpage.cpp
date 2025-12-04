#include "adminpage.h"
#include "ui_adminpage.h"
#include <QMessageBox>
#include <QMenu>
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
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableWidget, &QTableWidget::customContextMenuRequested,
            this, &adminpage::showContextMenu);
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
    if(username == ""){
        QMessageBox::warning(this, "Error", "Failed to add user! There is no username.");
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
    ui->tableWidget->setRowCount(0);

    vector<User> users = userManager1->loadUsers();

    for (int i = 0; i < users.size(); ++i) {
        ui->tableWidget->insertRow(i);

        QString qUsername = QString::fromStdString(users[i].getUsername());
        QString qRole     = QString::fromStdString(users[i].getRole());

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(qUsername));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(qRole));
    }

}

void adminpage::showContextMenu(const QPoint &pos)
{
    QModelIndex index = ui->tableWidget->indexAt(pos);
    if (!index.isValid())
        return; // clicked outside any row

    QMenu menu;
    QAction* deleteAction = menu.addAction("Delete User");

    QAction* selectedAction = menu.exec(ui->tableWidget->viewport()->mapToGlobal(pos));
    if (selectedAction == deleteAction) {
        deleteSelectedUser();
    }
}

void adminpage::deleteSelectedUser()
{
    int row = ui->tableWidget->currentRow();
    if (row < 0) return;

    QString qUsername = ui->tableWidget->item(row, 0)->text();
    std::string username = qUsername.toStdString();

    // Call UserManager to delete user
    bool ok = userManager1->deleteUser(username);
    if (ok) {
        QMessageBox::information(this, "Deleted", "User deleted successfully!");
        ui->tableWidget->removeRow(row);
    } else {
        QMessageBox::warning(this, "Error", "Failed to delete user.");
    }
}



