#include "bookrecords.h"
#include "ui_bookrecords.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QInputDialog>
#include <QTableWidget>
#include <QHeaderView>

static const char *BOOKS_FILE_NAME = "Y:\\AUC\\CS II\\CS2 Lab\\Project\\Librarystem\\books.txt";

BookRecords::BookRecords(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BookRecords)
{
    ui->setupUi(this);

    setupTable();
    loadBooksFromFile();
}

BookRecords::~BookRecords()
{
    delete ui;
}

void BookRecords::setupTable()
{
    ui->tableBooks->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableBooks->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableBooks->horizontalHeader()->setStretchLastSection(true);
    ui->tableBooks->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void BookRecords::loadBooksFromFile()
{
    ui->tableBooks->setRowCount(0);

    QFile file(BOOKS_FILE_NAME);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        const QString line = in.readLine().trimmed();
        if (line.isEmpty())
            continue;

        const QStringList parts = line.split('|');
        if (parts.size() < 6)
            continue;

        int row = ui->tableBooks->rowCount();
        ui->tableBooks->insertRow(row);
        for (int col = 0; col < 6; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(parts.at(col));
            ui->tableBooks->setItem(row, col, item);
        }
    }
}

void BookRecords::saveBooksToFile()
{
    QFile file(BOOKS_FILE_NAME);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"),
        tr("Cannot open books file for writing."));
        return;
    }

    QTextStream out(&file);
    const int rows = ui->tableBooks->rowCount();
    const int cols = ui->tableBooks->columnCount();

    for (int r = 0; r < rows; ++r) {
        QStringList parts;
        for (int c = 0; c < cols; ++c) {
            QTableWidgetItem *item = ui->tableBooks->item(r, c);
            parts << (item ? item->text() : QString());
        }
        out << parts.join('|') << '\n';
    }
}

void BookRecords::showAllRows()
{
    const int rows = ui->tableBooks->rowCount();
    for (int r = 0; r < rows; ++r) {
        ui->tableBooks->setRowHidden(r, false);
    }
}

int BookRecords::searchColumnIndex() const
{
    const int index = ui->comboSearchType->currentIndex();
    switch (index) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    default:
        return 1;
    }
}

void BookRecords::applySearchFilter()
{
    const QString searchText = ui->lineSearch->text().trimmed();

    if (searchText.isEmpty()) {
        showAllRows();
        return;
    }

    const int col = searchColumnIndex();
    const int rows = ui->tableBooks->rowCount();

    for (int r = 0; r < rows; ++r) {
        QTableWidgetItem *item = ui->tableBooks->item(r, col);
        const bool match = item && item->text().contains(searchText, Qt::CaseInsensitive);
        ui->tableBooks->setRowHidden(r, !match);
    }
}

void BookRecords::on_btnAddBook_clicked()
{
    bool ok = false;

    QString id = QInputDialog::getText(this, tr("Add Book"),
    tr("ID:"), QLineEdit::Normal,
    QString(), &ok);
    if (!ok || id.trimmed().isEmpty())
        return;

    QString title = QInputDialog::getText(this, tr("Add Book"),
    tr("Title:"), QLineEdit::Normal,
    QString(), &ok);
    if (!ok || title.trimmed().isEmpty())
        return;

    QString author = QInputDialog::getText(this, tr("Add Book"),
    tr("Author:"), QLineEdit::Normal,
    QString(), &ok);
    if (!ok || author.trimmed().isEmpty())
        return;

    QString category = QInputDialog::getText(this, tr("Add Book"),
    tr("Category:"), QLineEdit::Normal,
    QString(), &ok);
    if (!ok || category.trimmed().isEmpty())
        return;

    QString copies = QInputDialog::getText(this, tr("Add Book"),
    tr("Copies:"), QLineEdit::Normal,
    QString(), &ok);
    if (!ok || copies.trimmed().isEmpty())
        return;

    QString status = QInputDialog::getText(this, tr("Add Book"),
    tr("Status:"), QLineEdit::Normal,
    QString(), &ok);
    if (!ok || status.trimmed().isEmpty())
        return;

    int row = ui->tableBooks->rowCount();
    ui->tableBooks->insertRow(row);
    ui->tableBooks->setItem(row, 0, new QTableWidgetItem(id));
    ui->tableBooks->setItem(row, 1, new QTableWidgetItem(title));
    ui->tableBooks->setItem(row, 2, new QTableWidgetItem(author));
    ui->tableBooks->setItem(row, 3, new QTableWidgetItem(category));
    ui->tableBooks->setItem(row, 4, new QTableWidgetItem(copies));
    ui->tableBooks->setItem(row, 5, new QTableWidgetItem(status));

    saveBooksToFile();
}

void BookRecords::on_btnEditBook_clicked()
{
    QList<QTableWidgetItem*> selection = ui->tableBooks->selectedItems();
    if (selection.isEmpty()) {
        QMessageBox::information(this, tr("Edit Book"),
        tr("Please select a book to edit."));
        return;
    }

    int row = selection.first()->row();

    bool ok = false;

    QTableWidgetItem *idItem = ui->tableBooks->item(row, 0);
    QTableWidgetItem *titleItem = ui->tableBooks->item(row, 1);
    QTableWidgetItem *authorItem = ui->tableBooks->item(row, 2);
    QTableWidgetItem *categoryItem = ui->tableBooks->item(row, 3);
    QTableWidgetItem *copiesItem = ui->tableBooks->item(row, 4);
    QTableWidgetItem *statusItem = ui->tableBooks->item(row, 5);

    QString id = QInputDialog::getText(this, tr("Edit Book"),
    tr("ID:"), QLineEdit::Normal,
    idItem ? idItem->text() : QString(),
    &ok);
    if (!ok || id.trimmed().isEmpty())
        return;

    QString title = QInputDialog::getText(this, tr("Edit Book"),
    tr("Title:"), QLineEdit::Normal,
    titleItem ? titleItem->text() : QString(),
    &ok);
    if (!ok || title.trimmed().isEmpty())
        return;

    QString author = QInputDialog::getText(this, tr("Edit Book"),
    tr("Author:"), QLineEdit::Normal,
    authorItem ? authorItem->text() : QString(),
    &ok);
    if (!ok || author.trimmed().isEmpty())
        return;

    QString category = QInputDialog::getText(this, tr("Edit Book"),
    tr("Category:"), QLineEdit::Normal,
    categoryItem ? categoryItem->text() : QString(),
    &ok);
    if (!ok || category.trimmed().isEmpty())
        return;

    QString copies = QInputDialog::getText(this, tr("Edit Book"),
    tr("Copies:"), QLineEdit::Normal,
    copiesItem ? copiesItem->text() : QString(),
    &ok);
    if (!ok || copies.trimmed().isEmpty())
        return;

    QString status = QInputDialog::getText(this, tr("Edit Book"),
    tr("Status:"), QLineEdit::Normal,
    statusItem ? statusItem->text() : QString(),
    &ok);
    if (!ok || status.trimmed().isEmpty())
        return;

    ui->tableBooks->setItem(row, 0, new QTableWidgetItem(id));
    ui->tableBooks->setItem(row, 1, new QTableWidgetItem(title));
    ui->tableBooks->setItem(row, 2, new QTableWidgetItem(author));
    ui->tableBooks->setItem(row, 3, new QTableWidgetItem(category));
    ui->tableBooks->setItem(row, 4, new QTableWidgetItem(copies));
    ui->tableBooks->setItem(row, 5, new QTableWidgetItem(status));

    saveBooksToFile();
}

void BookRecords::on_btnDeleteBook_clicked()
{
    QList<QTableWidgetItem*> selection = ui->tableBooks->selectedItems();
    if (selection.isEmpty()) {
        QMessageBox::information(this, tr("Delete Book"),
        tr("Please select a book to delete."));
        return;
    }

    int row = selection.first()->row();

    const QMessageBox::StandardButton reply =
            QMessageBox::question(this, tr("Delete Book"),
            tr("Are you sure you want to delete this book?"),
            QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        ui->tableBooks->removeRow(row);
        saveBooksToFile();
    }
}

void BookRecords::on_btnLowStock_clicked()
{
    const int rows = ui->tableBooks->rowCount();

    for (int r = 0; r < rows; ++r) {
        QTableWidgetItem *copiesItem = ui->tableBooks->item(r, 4);
        bool ok = false;
        int copies = copiesItem ? copiesItem->text().toInt(&ok) : 0;

        bool low = ok && copies <= 2;
        ui->tableBooks->setRowHidden(r, !low);
    }
}

void BookRecords::on_btnSearch_clicked()
{
    applySearchFilter();
}

void BookRecords::on_btnClearSearch_clicked()
{
    ui->lineSearch->clear();
    showAllRows();
}

void BookRecords::on_btnRefresh_clicked()
{
    loadBooksFromFile();
    ui->lineSearch->clear();
    showAllRows();
}
