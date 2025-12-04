#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>
#include "usermanager.h"

namespace Ui {
class adminpage;
}

class adminpage : public QDialog
{
    Q_OBJECT

public:
    explicit adminpage(UserManager* userManager, QWidget *parent = nullptr);
    explicit adminpage(QWidget *parent = nullptr);

    ~adminpage();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_load_clicked();

    void showContextMenu(const QPoint &pos);

    void deleteSelectedUser();

private:
    Ui::adminpage *ui;
    UserManager* userManager1; //to access add and load users
};

#endif // ADMINPAGE_H
