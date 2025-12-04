#ifndef BORROWRETURN_H
#define BORROWRETURN_H

#include <QDialog>

namespace Ui {
class BorrowReturn;
}

class BorrowReturn : public QDialog
{
    Q_OBJECT

public:
    explicit BorrowReturn(QWidget *parent = nullptr);
    ~BorrowReturn();

private:
    Ui::BorrowReturn *ui;
};

#endif // BORROWRETURN_H
