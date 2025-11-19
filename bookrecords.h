#ifndef BOOKRECORDS_H
#define BOOKRECORDS_H

#include <QDialog>

namespace Ui {
class BookRecords;
}

class BookRecords : public QDialog
{
    Q_OBJECT

public:
    explicit BookRecords(QWidget *parent = nullptr);
    ~BookRecords();

private:
    Ui::BookRecords *ui;
};

#endif // BOOKRECORDS_H
