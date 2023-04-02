#include "ssearch.h"
#include "ui_sorting.h"

SSEARCH::SSEARCH(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SSEARCH)
{
    ui->setupUi(this);

}
SSEARCH::~SSEARCH()
{
    delete ui;
}

void Sorting::on_buttonBox_accepted()
{
   Search srch;
   srch.name_search=ui->Name_edit->text();
   srch.lname_search=ui->Lname_edit->text();
   srch.patronymic_search=ui->Patronymic_edit->text();
   srch.semestr_search=ui->Semestr_edit->text();
   srch.department_search=ui->Department_edit->text();
   srch.Date_of_birth_search=ui->Date_of_birth_edit->text();

}

Search Sorting::get_search_info()
{
    Search srch;
    srch.name_search=ui->Name_edit->text();
    srch.lname_search=ui->Lname_edit->text();
    srch.patronymic_search=ui->Patronymic_edit->text();
    srch.semestr_search=ui->Semestr_edit->text();
    srch.department_search=ui->Department_edit->text();
    srch.Date_of_birth_search=ui->Date_of_birth_edit->text();
}
