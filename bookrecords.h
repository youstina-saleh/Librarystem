#ifndef BOOKRECORDS_H
#define BOOKRECORDS_H

#include <QWidget>

namespace Ui {
class BookRecords;
}

class BookRecords : public QWidget
{
    Q_OBJECT

public:
    explicit BookRecords(QWidget *parent = nullptr);
    ~BookRecords();

private:
    Ui::BookRecords *ui;

    void setupTable();
    void loadBooksFromFile();
    void saveBooksToFile();
    void showAllRows();
    int searchColumnIndex() const;
    void applySearchFilter();

private slots:
    void on_btnAddBook_clicked();
    void on_btnEditBook_clicked();
    void on_btnDeleteBook_clicked();
    void on_btnLowStock_clicked();
    void on_btnSearch_clicked();
    void on_btnClearSearch_clicked();
    void on_btnRefresh_clicked();
};

#endif // BOOKRECORDS_H
