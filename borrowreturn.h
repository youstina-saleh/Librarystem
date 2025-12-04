#ifndef BORROWRETURN_H
#define BORROWRETURN_H

#include <QDialog>
#include <QString>

namespace Ui {
class BorrowReturn;
}

class BorrowReturn : public QDialog
{
    Q_OBJECT

public:
    explicit BorrowReturn(QString currentUser, QWidget *parent = nullptr);
    ~BorrowReturn();

private slots:
    void on_borrowButton_clicked();
    void on_returnButton_clicked();

private:
    Ui::BorrowReturn *ui;
    QString username;


    void loadBooks();
    void saveBooks();
    void loadBorrowed();
    void saveBorrowed();
    void displayBooks();
};

#endif // BORROWRETURN_H
