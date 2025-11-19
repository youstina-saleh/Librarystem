#include "dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_recordspushButton_clicked()
{

}


void Dashboard::on_borrowReturnpushButton_2_clicked()
{

}


void Dashboard::on_pushButton_3_clicked()
{

}

