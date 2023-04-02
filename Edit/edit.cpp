#include "edit.h"
#include "qdebug.h"
#include "qsqlerror.h"
#include "qsqlquery.h"
#include "ui_edit.h"

Edit::Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{

    ui->setupUi(this);
}





Edit::Edit(QSqlRecord *record,QStringList *string_list_combo_facultaties,QStringList *string_list_combo_subjects,int *role, QWidget *parent):QDialog(parent),ui(new Ui::Edit)
{
ui->setupUi(this);
for (int i=0;string_list_combo_facultaties->size()!=i;i++)
{
 ui->comboBox_dep_2->addItem(string_list_combo_facultaties->at(i));
}
for (int i=0;string_list_combo_subjects->size()!=i;i++)
{
 ui->comboBox_subj->addItem(string_list_combo_subjects->at(i));
}
for(int i=1;i<=9;++i)
{
    ui->comboBox_sem_2->addItem(QString("%1").arg(i));
}
ui->comboBox_main_2->setEnabled(0);
private_int_role=(*role);
id=record->value(0).toInt();
if(*role==3)id=record->value(2).toInt();

if(*role==0)
{
    ui->comboBox_main_2->setCurrentIndex(students);
    show_stuff(*role);
    ui->Name_edit_2->setText(record->value(1).toString());
    ui->Lname_edit_2->setText(record->value(2).toString());
    ui->Patronymic_edit_2->setText(record->value(3).toString());
     ui->comboBox_sem_2->setCurrentText(record->value(4).toString());
    ui->comboBox_dep_2->setCurrentText(record->value(5).toString());
    ui->dateEdit_edit_2->setDate(QDate(record->value(6).toDate()));
}

if(*role==1)
{
show_stuff(*role);
ui->comboBox_main_2->setCurrentIndex(teachers);
ui->Name_edit_2->setText(record->value(1).toString());
ui->Lname_edit_2->setText(record->value(2).toString());
ui->Patronymic_edit_2->setText(record->value(3).toString());
ui->departmen_teachers_2->setText(record->value(4).toString());
ui->academic_degree_teachers_2->setText(record->value(5).toString());
ui->academic_title_teachers_2->setText(record->value(6).toString());
ui->dateEdit_edit_2->setDate(QDate(record->value(7).toDate()));
}
if(*role==2)
{

    show_stuff(*role);
    ui->comboBox_main_2->setCurrentIndex(teachers_and_subjects);
    ui->Name_edit_2->setText(record->value(1).toString());
    ui->Lname_edit_2->setText(record->value(2).toString());
    ui->Patronymic_edit_2->setText(record->value(3).toString());
    ui->comboBox_subj->setCurrentText(record->value(4).toString());
}
if(*role==3)
{
    show_stuff(*role);
    ui->comboBox_main_2->setCurrentIndex(facultaty_and_subject);
    ui->comboBox_subj->setCurrentText(record->value(1).toString());
    ui->comboBox_dep_2->setCurrentText(record->value(0).toString());

}




}

Struct_edit Edit::get_info_edit()
{


}

void Edit::show_stuff(int stuff)
{

    switch (stuff)
    {
    case students:
        ui->departmen_teachers_2->setVisible(0);
        ui->label_department->setVisible(0);
        ui->academic_degree_teachers_2->setVisible(0);
        ui->label_academic_degree->setVisible(0);
        ui->academic_title_teachers_2->setVisible(0);
        ui->label_academic_title->setVisible(0);
        ui->comboBox_subj->setVisible(0);
        ui->label_subject->setVisible(0);

        break;

     case teachers:
        ui->label_subject->setVisible(0);
        ui->comboBox_subj->setVisible(0);
        ui->label_semestr->setVisible(0);
        ui->comboBox_sem_2->setVisible(0);
        ui->label_facultaty->setVisible(0);
        ui->comboBox_dep_2->setVisible(0);
        ui->label_subject->setVisible(0);
        ui->comboBox_subj->setVisible(0);

        break;

     case teachers_and_subjects:
        ui->label_subject->setVisible(1);
        ui->comboBox_subj->setVisible(1);
        ui->label_semestr->setVisible(0);
        ui->comboBox_sem_2->setVisible(0);
        ui->label_facultaty->setVisible(0);
        ui->comboBox_dep_2->setVisible(0);
        ui->departmen_teachers_2->setVisible(0);
        ui->label_department->setVisible(0);
        ui->academic_degree_teachers_2->setVisible(0);
        ui->label_academic_degree->setVisible(0);
        ui->academic_title_teachers_2->setVisible(0);
        ui->label_academic_title->setVisible(0);
        ui->comboBox_dep_2->setVisible(0);
        ui->label_facultaty->setVisible(0);
        ui->label_date->setVisible(0);
        ui->dateEdit_edit_2->setVisible(0);
        ui->Name_edit_2->setEnabled(0);
        ui->Lname_edit_2->setEnabled(0);
        ui->Patronymic_edit_2->setEnabled(0);
        break;

    case facultaty_and_subject:
        ui->comboBox_subj->setVisible(1);
        ui->label_subject->setVisible(1);
        ui->label_facultaty->setVisible(1);
        ui->comboBox_dep_2->setVisible(1);
        ui->label_name->setVisible(0);
        ui->Name_edit_2->setVisible(0);
        ui->label_lname->setVisible(0);
        ui->Lname_edit_2->setVisible(0);
        ui->label_patro->setVisible(0);
        ui->Patronymic_edit_2->setVisible(0);
        ui->label_date->setVisible(0);
        ui->dateEdit_edit_2->setVisible(0);
        ui->label_semestr->setVisible(0);
        ui->comboBox_sem_2->setVisible(0);
        ui->departmen_teachers_2->setVisible(0);
        ui->label_department->setVisible(0);
        ui->academic_degree_teachers_2->setVisible(0);
        ui->label_academic_degree->setVisible(0);
        ui->academic_title_teachers_2->setVisible(0);
        ui->label_academic_title->setVisible(0);
        ui->comboBox_dep_2->setEnabled(0);

        break;

    default:
        break;
    }
}





Edit::~Edit()
{
    delete ui;
}


void Edit::on_buttonBox_3_accepted()
{
    QDialog::accept();
    if(private_int_role==0)
    {
        QSqlQuery ds;
        ds.prepare("UPDATE users set fname= :fname,lname=:lname,patronymic=:patron,semestr=:semestr,facultaty=:facultaty,date_of_birth=:date_of_birth WHERE id=:id");
        ds.bindValue(":fname",ui->Name_edit_2->text());
        ds.bindValue(":lname",ui->Lname_edit_2->text());
        ds.bindValue(":patron",ui->Patronymic_edit_2->text());
        ds.bindValue(":semestr",ui->comboBox_sem_2->currentText());
        ds.bindValue(":facultaty",ui->comboBox_dep_2->currentText());
        ds.bindValue(":id",id);
        ds.bindValue(":date_of_birth",ui->dateEdit_edit_2->date().toString("yyyy-MM-dd"));
        ds.exec();
        QSqlError qqqq=ds.lastError();
        qDebug()<<qqqq.text();
    }
    if(private_int_role==1)
        {
            QSqlQuery ds;
            ds.prepare("UPDATE teachers set fname= :fname,lname=:lname,patronymic=:patron,department=:department,academic_degree=:academic_degree,academic_title=:academic_title,date_of_birth=:date_of_birth WHERE id=:id");
            ds.bindValue(":fname",ui->Name_edit_2->text());
            ds.bindValue(":lname",ui->Lname_edit_2->text());
            ds.bindValue(":patron",ui->Patronymic_edit_2->text());
            ds.bindValue(":department",ui->departmen_teachers_2->text());
            ds.bindValue(":academic_degree",ui->academic_degree_teachers_2->text());
            ds.bindValue(":academic_title",ui->academic_title_teachers_2->text());
            ds.bindValue(":date_of_birth",ui->dateEdit_edit_2->date().toString("yyyy-MM-dd"));
            ds.bindValue(":id",id);
            ds.exec();
            QSqlError qqqq=ds.lastError();
            qDebug()<<qqqq.text();
        }

     if(private_int_role==2)
     {
         QSqlQuery ds;
         ds.prepare("UPDATE subject_teaching set subject_teaching=:subject_teaching WHERE id_of_subject_teaching=:id_of_subject_teaching");
         ds.bindValue(":subject_teaching",ui->comboBox_subj->currentText());
         ds.bindValue(":id_of_subject_teaching",id);
         ds.exec();
         QSqlError qqqq=ds.lastError();
         qDebug()<<qqqq.text();

     }
     if(private_int_role==3)
     {

         QSqlQuery ds;
         ds.prepare("UPDATE facultaty_subjects set subject_fac=:subject_fac WHERE facultaty_subj=:facultaty_subj");
         ds.bindValue(":subject_fac",ui->comboBox_subj->currentText());
         ds.bindValue(":facultaty_subj",id);
         ds.exec();
         QSqlError qqqq=ds.lastError();
         qDebug()<<qqqq.text();
     }




}


void Edit::on_buttonBox_3_rejected()
{
QDialog::reject();
}

