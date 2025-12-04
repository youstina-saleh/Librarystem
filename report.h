#ifndef REPORT_H
#define REPORT_H

#include <QDialog>
#include <QTableWidget>
#include <QString>
#include <QDate>

namespace Ui {
class Report;
}

class Report : public QDialog
{
    Q_OBJECT

public:
    explicit Report(QWidget *parent = nullptr);
    ~Report();

private slots:
    void on_btnBorrowed_clicked();
    void on_btnOverdue_clicked();
    void on_btnMostBorrowed_clicked();
    void on_btnExportCSV_clicked();

private:
    Ui::Report *ui;

    void loadBorrowedBooks();
    void loadOverdueBooks();
    void loadMostBorrowedBooks();
    void exportCSV(const QString &filename);
};

#endif // REPORT_H
