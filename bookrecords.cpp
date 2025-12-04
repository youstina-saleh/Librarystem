#include "bookrecords.h"
#include "ui_bookrecords.h"

BookRecords::BookRecords(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BookRecords)
{
    ui->setupUi(this);
}

BookRecords::~BookRecords()
{
    delete ui;
}
