#include "add_department.h"
#include "ui_add_department.h"

Add_department::Add_department(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_department)
{
    ui->setupUi(this);
}

Add_department::~Add_department()
{
    delete ui;
}
