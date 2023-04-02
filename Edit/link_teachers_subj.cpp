#include "link_teachers_subj.h"
#include "qsqlquery.h"
#include "ui_link_teachers_subj.h"

link_teachers_subj::link_teachers_subj(QStringList *string_list_combo_subjects,QSqlRecord *qq, QWidget *parent):
    QDialog(parent),
    ui(new Ui::link_teachers_subj)
{
    ui->setupUi(this);
    ui->lineEdit_teachers_lname->setText(qq->value(1).toString());
    ui->lineEdit_teachers_fname->setText(qq->value(2).toString());
    ui->lineEdit_patronymic->setText(qq->value(3).toString());
    ui->lineEdit_teachers_lname->setEnabled(0);
    ui->lineEdit_teachers_fname->setEnabled(0);
    ui->lineEdit_patronymic->setEnabled(0);
    ui->comboBox_subj->addItem("");
    for (int i=0;string_list_combo_subjects->size()!=i;i++)
    {
     ui->comboBox_subj->addItem(string_list_combo_subjects->at(i));
    }
   id=qq->value(0).toInt();
}

link_teachers_subj::~link_teachers_subj()
{
    delete ui;
}

void link_teachers_subj::on_buttonBox_accepted()
{
    QDialog::accept();
    QString das("INSERT into subject_teaching(teacher_subject_teching_id,subject_teaching) VALUES()");
    QSqlQuery query;
    query.prepare("INSERT into subject_teaching(teacher_subject_teching_id,subject_teaching) VALUES(:id,:subject_teaching)");
    query.bindValue(":id",id);
    query.bindValue(":subject_teaching",ui->comboBox_subj->currentText());
    query.exec();

}


void link_teachers_subj::on_buttonBox_rejected()
{
    QDialog::reject();
}

