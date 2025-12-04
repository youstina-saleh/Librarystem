#include "borrowreturn.h"
#include "ui_borrowreturn.h"

BorrowReturn::BorrowReturn(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BorrowReturn)
{
    ui->setupUi(this);
}

BorrowReturn::~BorrowReturn()
{
    delete ui;
}
