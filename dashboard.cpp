#include "dashboard.h"
#include "ui_dashboard.h"
#include "bookrecords.h"
#include "borrowreturn.h"
#include "report.h"

#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QTableWidgetItem>

Dashboard::Dashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    currentUsername = "Guest";
    currentUserRole = "";
    setupDashboard();
    loadStatistics();
}

Dashboard::Dashboard(const QString& username, const QString& role, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
    , currentUsername(username)
    , currentUserRole(role)
{
    ui->setupUi(this);
    setupDashboard();
    loadStatistics();
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::setupDashboard()
{
    // Show welcome message with current username
    ui->welcomelabel->setText(QString("Welcome %1").arg(currentUsername));

    // Configure the summary table (one row, three columns)
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(3);
    QStringList headers;
    headers << "Total Books" << "Borrowed" << "Overdue";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
}

Dashboard::BookStatistics Dashboard::calculateStatistics()
{
    BookStatistics stats;

    // Read books.txt (supports '|' or ',' separated lines)
    QFile booksFile("books.txt");
    if (booksFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&booksFile);
        while (!in.atEnd()) {
            const QString line = in.readLine().trimmed();
            if (line.isEmpty())
                continue;

            QStringList parts = line.split('|');
            if (parts.size() < 4) {
                parts = line.split(','); // fallback for comma format
            }

            if (!parts.isEmpty()) {
                stats.totalBooks += 1;
                // try to add copies if available (column 4 for '|' format, 3 for ',' format)
                bool ok = false;
                if (parts.size() >= 5) {
                    int copies = parts.at(4).trimmed().toInt(&ok);
                    if (ok) stats.totalBooks += (copies - 1); // include extra copies
                } else if (parts.size() >= 4) {
                    int copies = parts.at(3).trimmed().toInt(&ok);
                    if (ok) stats.totalBooks += (copies - 1);
                }
            }
        }
    }

    // Read borrow.txt (per-user stats)
    QFile borrowFile("borrow.txt");
    if (borrowFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&borrowFile);
        const QDate today = QDate::currentDate();
        while (!in.atEnd()) {
            const QString line = in.readLine().trimmed();
            if (line.isEmpty())
                continue;

            const QStringList parts = line.split(',');
            if (parts.size() != 3)
                continue;

            // parts: username, bookID, dueDate
            const QString borrower = parts.at(0).trimmed();
            if (borrower != currentUsername)
                continue; // only count current user

            stats.borrowedBooks += 1;
            const QDate due = QDate::fromString(parts.at(2).trimmed(), "yyyy-MM-dd");
            if (due.isValid() && due < today)
                stats.overdueBooks += 1;
        }
    }

    return stats;
}

void Dashboard::updateStatisticsDisplay(int totalBooks, int borrowedBooks, int overdueBooks)
{
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QString::number(totalBooks)));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString::number(borrowedBooks)));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString::number(overdueBooks)));
}

void Dashboard::loadStatistics()
{
    BookStatistics stats = calculateStatistics();
    updateStatisticsDisplay(stats.totalBooks, stats.borrowedBooks, stats.overdueBooks);
}

void Dashboard::on_recordspushButton_clicked()
{
    // BookRecords is a QWidget, so just show it (no setModal/exec).
    BookRecords *records = new BookRecords(this);
    records->setAttribute(Qt::WA_DeleteOnClose);
    records->show();
}


void Dashboard::on_borrowReturnpushButton_2_clicked()
{
    // BorrowReturn is a QDialog and expects the current username.
    BorrowReturn *dialog = new BorrowReturn(currentUsername, this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->exec();

    // Refresh dashboard stats after borrow/return actions
    loadStatistics();
}


void Dashboard::on_pushButton_3_clicked()
{
    Report* report = new Report(this);
    report->show();
}

