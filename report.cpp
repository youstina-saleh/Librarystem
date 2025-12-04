#include "report.h"
#include "ui_report.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QMap>

Report::Report(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);
}

Report::~Report()
{
    delete ui;
}

void Report::on_btnBorrowed_clicked()
{
    loadBorrowedBooks();
}

void Report::loadBorrowedBooks()
{
    ui->tableReports->clear();
    ui->tableReports->setColumnCount(3);
    ui->tableReports->setHorizontalHeaderLabels({"Username", "Book ID", "Due Date"});

    QFile file("borrow.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QStringList parts;
    int row = 0;

    while (!in.atEnd())
    {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        parts = line.split(",");
        if (parts.size() != 3) continue;

        ui->tableReports->insertRow(row);
        ui->tableReports->setItem(row, 0, new QTableWidgetItem(parts[0]));
        ui->tableReports->setItem(row, 1, new QTableWidgetItem(parts[1]));
        ui->tableReports->setItem(row, 2, new QTableWidgetItem(parts[2]));
        row++;
    }
}

void Report::on_btnOverdue_clicked()
{
    loadOverdueBooks();
}

void Report::loadOverdueBooks()
{
    ui->tableReports->clear();
    ui->tableReports->setColumnCount(4);
    ui->tableReports->setHorizontalHeaderLabels({"Username", "Book ID", "Due Date", "Days Late"});

    QFile file("borrow.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QDate today = QDate::currentDate();
    int row = 0;

    while (!in.atEnd())
    {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split(",");
        if (parts.size() != 3) continue;

        QDate due = QDate::fromString(parts[2], "yyyy-MM-dd");

        if (today > due)
        {
            int daysLate = due.daysTo(today);

            ui->tableReports->insertRow(row);
            ui->tableReports->setItem(row, 0, new QTableWidgetItem(parts[0]));
            ui->tableReports->setItem(row, 1, new QTableWidgetItem(parts[1]));
            ui->tableReports->setItem(row, 2, new QTableWidgetItem(parts[2]));
            ui->tableReports->setItem(row, 3, new QTableWidgetItem(QString::number(daysLate)));

            row++;
        }
    }
}


void Report::on_btnMostBorrowed_clicked()
{
    loadMostBorrowedBooks();
}

void Report::loadMostBorrowedBooks()
{
    ui->tableReports->clear();
    ui->tableReports->setColumnCount(2);
    ui->tableReports->setHorizontalHeaderLabels({"Book ID", "Times Borrowed"});

    QFile file("borrow.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QMap<QString, int> borrowCount;

    while (!in.atEnd())
    {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split(",");
        if (parts.size() != 3) continue;

        borrowCount[parts[1]]++;
    }

    int row = 0;
    for (auto it = borrowCount.begin(); it != borrowCount.end(); ++it)
    {
        ui->tableReports->insertRow(row);
        ui->tableReports->setItem(row, 0, new QTableWidgetItem(it.key()));
        ui->tableReports->setItem(row, 1, new QTableWidgetItem(QString::number(it.value())));
        row++;
    }
}

void Report::on_btnExportCSV_clicked()
{
    exportCSV("report.csv");
}

void Report::exportCSV(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);

    int rows = ui->tableReports->rowCount();
    int cols = ui->tableReports->columnCount();

    for (int r = 0; r < rows; r++)
    {
        QStringList line;
        for (int c = 0; c < cols; c++)
        {
            QTableWidgetItem *item = ui->tableReports->item(r, c);
            line << (item ? item->text() : "");
        }
        out << line.join(",") << "\n";
    }

    QMessageBox::information(this, "Export", "Report exported to report.csv");
}
