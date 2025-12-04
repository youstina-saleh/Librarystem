#include "borrowreturn.h"
#include "ui_borrowreturn.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDate>


struct Book {
    QString id, title, author;
    int copies;
};

struct BorrowRecord {
    QString username;
    QString bookID;
    QDate dueDate;
};


BorrowReturn::BorrowReturn(QString currentUser, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BorrowReturn)
{
    ui->setupUi(this);
    this->username = currentUser;

    loadBooks();
    loadBorrowed();
    displayBooks();
}

BorrowReturn::~BorrowReturn() {
    delete ui;
}



QList<Book> books;
QList<BorrowRecord> borrowedList;


void BorrowReturn::loadBooks() {
    books.clear();

    QFile file("E:/AUC/Auc3/cs_lab/Librarystem/books.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split(",");
        if (parts.size() != 4) continue;

        Book b;
        b.id = parts[0].trimmed();
        b.title = parts[1].trimmed();
        b.author = parts[2].trimmed();
        b.copies = parts[3].trimmed().toInt();

        books.append(b);
    }
    file.close();
}


void BorrowReturn::saveBooks() {
    QFile file("books.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    for (auto &b : books) {
        out << b.id << ","
            << b.title << ","
            << b.author << ","
            << b.copies << "\n";
    }
    file.close();
}


void BorrowReturn::loadBorrowed() {
    borrowedList.clear();

    QFile file("borrow.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split(",");
        if (parts.size() != 3) continue;

        BorrowRecord r;
        r.username = parts[0].trimmed();
        r.bookID   = parts[1].trimmed();
        r.dueDate  = QDate::fromString(parts[2].trimmed(), "yyyy-MM-dd");

        borrowedList.append(r);
    }
    file.close();
}


void BorrowReturn::saveBorrowed() {
    QFile file("borrow.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    for (auto &r : borrowedList) {
        out << r.username << ","
            << r.bookID << ","
            << r.dueDate.toString("yyyy-MM-dd") << "\n";
    }
    file.close();
}


void BorrowReturn::displayBooks() {
    ui->tableWidget->setRowCount(books.size());
    ui->tableWidget->setColumnCount(4);
    QStringList headers = {"ID", "Title", "Author", "Copies"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    for (int i = 0; i < books.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(books[i].id));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(books[i].title));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(books[i].author));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(books[i].copies)));
    }
}


void BorrowReturn::on_borrowButton_clicked() {
    QString bookID = ui->borrowID->text().trimmed();
    if (bookID.isEmpty()) {
        ui->statusLabel->setText("Enter a Book ID.");
        return;
    }

    for (auto &r : borrowedList) {
        if (r.username == username && r.bookID == bookID) {
            ui->statusLabel->setText("You already borrowed this book.");
            return;
        }
    }

    int index = -1;
    for (int i = 0; i < books.size(); ++i) {
        if (books[i].id == bookID) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        ui->statusLabel->setText("Book not found.");
        return;
    }

    if (books[index].copies <= 0) {
        ui->statusLabel->setText("No copies available.");
        return;
    }

    books[index].copies--;

    BorrowRecord r;
    r.username = username;
    r.bookID = bookID;
    r.dueDate = QDate::currentDate().addDays(14);

    borrowedList.append(r);

    saveBooks();
    saveBorrowed();
    displayBooks();

    ui->statusLabel->setText("Book borrowed. Due: " + r.dueDate.toString("yyyy-MM-dd"));
}

void BorrowReturn::on_returnButton_clicked() {
    QString bookID = ui->returnID->text().trimmed();
    if (bookID.isEmpty()) {
        ui->statusLabel->setText("Enter a Book ID.");
        return;
    }

    int foundIndex = -1;
    for (int i = 0; i < borrowedList.size(); ++i) {
        if (borrowedList[i].username == username && borrowedList[i].bookID == bookID) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        ui->statusLabel->setText("You did not borrow this book.");
        return;
    }

    for (int i = 0; i < books.size(); ++i) {
        if (books[i].id == bookID) {
            books[i].copies++;
            break;
        }
    }

    QDate today = QDate::currentDate();
    QDate due   = borrowedList[foundIndex].dueDate;

    int fine = 0;
    if (today > due) {
        fine = due.daysTo(today) * 5;
    }

    borrowedList.removeAt(foundIndex);

    saveBooks();
    saveBorrowed();
    displayBooks();

    if (fine > 0)
        ui->statusLabel->setText("Returned. Overdue fine: " + QString::number(fine) + " EGP.");
    else
        ui->statusLabel->setText("Returned successfully.");
}
