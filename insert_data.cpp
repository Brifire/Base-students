#include "insert_data.h"
#include "ui_insert_data.h"
#include <QMessageBox>
#include <QtSql>
Insert_data::Insert_data(QStringList *string_list_combo_facultaties,QStringList *string_list_combo_subjects, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Insert_data)
{
    ui->setupUi(this);
    ui->comboBox_sem_2->addItem("");
    ui->comboBox_sem_2->addItem("1");
    ui->comboBox_sem_2->addItem("2");
    ui->comboBox_sem_2->addItem("3");
    ui->comboBox_sem_2->addItem("4");
    ui->comboBox_sem_2->addItem("5");
    ui->comboBox_sem_2->addItem("6");
    ui->comboBox_sem_2->addItem("7");
    ui->comboBox_sem_2->addItem("8");
    ui->comboBox_sem_2->addItem("9");
    ui->comboBox_dep_2->addItem("");
    for (int i=0;string_list_combo_facultaties->size()!=i;i++)
    {
     ui->comboBox_dep_2->addItem(string_list_combo_facultaties->at(i));
    }
    ui->comboBox_subjects->addItem("");
    for (int i=0;string_list_combo_subjects->size()!=i;i++)
    {
        ui->comboBox_subjects->addItem(string_list_combo_subjects->at(i));
    }
    ui->dateEdit_edit_2->setDate(QDate::currentDate());
    ui->label_academ_title->setVisible(0);
    ui->academic_title_teachers_2->setVisible(0);
    ui->label_subject->setVisible(0);
    ui->comboBox_subjects->setVisible(0);
    ui->label_academic_degree->setVisible(0);
    ui->academic_degree_teachers_2->setVisible(0);
    ui->label_department->setVisible(0);
    ui->departmen_teachers_2->setVisible(0);
    ui->label_subject_insert->setVisible(0);
    ui->lineEdit_subject_insert->setVisible(0);
    ui->label_facultaty_insert->setVisible(0);
    ui->lineEdit_facultaty_insert->setVisible(0);
    ui->dateEdit_edit_2->setDate(QDate::currentDate());
    int_role=0;
}

void Insert_data::get_data()
{
if(int_role==0)
{
    sss.name_str=ui->Name_edit_2->text();
    sss.lname_str=ui->Lname_edit_2->text();
    sss.patronymic_str=ui->Patronymic_edit_2->text();
    sss.semestr_str=ui->comboBox_sem_2->currentText();
    sss.department_str=ui->comboBox_dep_2->currentText();
    if(ui->dateEdit_edit_2->date()==QDate::currentDate())
    {
        sss.date_of_birth_str.clear();
    }
    else
    {
        sss.date_of_birth_str=ui->dateEdit_edit_2->date().toString("yyyy-MM-dd");
    }
}

if(int_role==1)
{

       sss_1.name_str=ui->Name_edit_2->text();
        sss_1.lname_str=ui->Lname_edit_2->text();
        sss_1.patronymic_str=ui->Patronymic_edit_2->text();
        sss_1.department=ui->departmen_teachers_2->text();
        sss_1.academic_degree=ui->academic_degree_teachers_2->text();
        sss_1.academic_title=ui->academic_title_teachers_2->text();
    if(ui->dateEdit_edit_2->date()==QDate::currentDate())
    {
        sss.date_of_birth_str.clear();
    }
    else
    {
            sss.date_of_birth_str=ui->dateEdit_edit_2->date().toString("yyyy-MM-dd");
    }

}

if(int_role==2)
{
    sss_2.subject_str=ui->lineEdit_subject_insert->text();
}
if(int_role==3)
{
    sss_3.facultaties_str=ui->lineEdit_facultaty_insert->text();
}

}



Insert_data::~Insert_data()
{
    delete ui;
}



void Insert_data::on_comboBox_main_2_currentIndexChanged(int index)

{
if(index==0)
{
    ui->label_fname->setVisible(1);
    ui->label_lname->setVisible(1);
    ui->label_patroni->setVisible(1);
    ui->Name_edit_2->setVisible(1);
    ui->Lname_edit_2->setVisible(1);
    ui->Patronymic_edit_2->setVisible(1);
    ui->label_semestr->setVisible(1);
    ui->label_facultaty->setVisible(1);
    ui->comboBox_dep_2->setVisible(1);
    ui->comboBox_sem_2->setVisible(1);
    ui->dateEdit_edit_2->setVisible(1);
    ui->label_birth->setVisible(1);
    ui->label_academ_title->setVisible(0);
    ui->label_academic_degree->setVisible(0);
    ui->label_department->setVisible(0);
    ui->label_subject->setVisible(0);
    ui->departmen_teachers_2->setVisible(0);
    ui->academic_title_teachers_2->setVisible(0);
    ui->academic_degree_teachers_2->setVisible(0);
    ui->comboBox_subjects->setVisible(0);
    ui->label_subject_insert->setVisible(0);
    ui->lineEdit_subject_insert->setVisible(0);
    ui->label_subject_insert->setVisible(0);
    ui->lineEdit_subject_insert->setVisible(0);
    ui->label_facultaty_insert->setVisible(0);
    ui->lineEdit_facultaty_insert->setVisible(0);
    int_role=0;


}
if(index==1)
{
    ui->label_fname->setVisible(1);
    ui->label_lname->setVisible(1);
    ui->label_patroni->setVisible(1);
    ui->Name_edit_2->setVisible(1);
    ui->Lname_edit_2->setVisible(1);
    ui->Patronymic_edit_2->setVisible(1);;
    ui->label_department->setVisible(1);
    ui->label_academ_title->setVisible(1);
    ui->label_academic_degree->setVisible(1);
    ui->departmen_teachers_2->setVisible(1);
    ui->academic_title_teachers_2->setVisible(1);
    ui->academic_degree_teachers_2->setVisible(1);
    ui->dateEdit_edit_2->setVisible(1);
    ui->label_birth->setVisible(1);
    ui->dateEdit_edit_2->setVisible(1);
    ui->label_semestr->setVisible(0);
    ui->comboBox_subjects->setVisible(0);
    ui->comboBox_dep_2->setVisible(0);
    ui->comboBox_sem_2->setVisible(0);
    ui->label_subject->setVisible(0);
    ui->comboBox_subjects->setVisible(0);
    ui->label_subject_insert->setVisible(0);
    ui->lineEdit_subject_insert->setVisible(0);
    ui->label_facultaty->setVisible(0);
    ui->label_facultaty_insert->setVisible(0);
    ui->lineEdit_facultaty_insert->setVisible(0);
    int_role=1;
}
if(index==2)
{
    ui->label_subject_insert->setVisible(1);
    ui->lineEdit_subject_insert->setVisible(1);
    ui->label_fname->setVisible(0);
    ui->label_lname->setVisible(0);
    ui->label_patroni->setVisible(0);
    ui->Name_edit_2->setVisible(0);
    ui->Lname_edit_2->setVisible(0);
    ui->Patronymic_edit_2->setVisible(0);
    ui->label_academ_title->setVisible(0);
    ui->label_academic_degree->setVisible(0);
    ui->label_department->setVisible(0);
    ui->label_subject->setVisible(0);
    ui->departmen_teachers_2->setVisible(0);
    ui->academic_title_teachers_2->setVisible(0);
    ui->academic_degree_teachers_2->setVisible(0);
    ui->comboBox_subjects->setVisible(0);
    ui->label_semestr->setVisible(0);
    ui->comboBox_subjects->setVisible(0);
    ui->comboBox_dep_2->setVisible(0);
    ui->comboBox_sem_2->setVisible(0);
    ui->label_subject->setVisible(0);
    ui->comboBox_subjects->setVisible(0);
    ui->label_birth->setVisible(0);
    ui->dateEdit_edit_2->setVisible(0);
    ui->label_facultaty_insert->setVisible(0);
    ui->lineEdit_facultaty_insert->setVisible(0);
    ui->label_facultaty->setVisible(0);
    int_role=2;
}

if(index==3)
{
    ui->label_facultaty_insert->setVisible(1);
    ui->lineEdit_facultaty_insert->setVisible(1);
    ui->label_fname->setVisible(0);
    ui->label_lname->setVisible(0);
    ui->label_patroni->setVisible(0);
    ui->Name_edit_2->setVisible(0);
    ui->Lname_edit_2->setVisible(0);
    ui->Patronymic_edit_2->setVisible(0);
    ui->label_academ_title->setVisible(0);
    ui->label_academic_degree->setVisible(0);
    ui->label_department->setVisible(0);
    ui->label_subject->setVisible(0);
    ui->departmen_teachers_2->setVisible(0);
    ui->academic_title_teachers_2->setVisible(0);
    ui->academic_degree_teachers_2->setVisible(0);
    ui->comboBox_subjects->setVisible(0);
    ui->label_semestr->setVisible(0);
    ui->comboBox_subjects->setVisible(0);
    ui->comboBox_dep_2->setVisible(0);
    ui->comboBox_sem_2->setVisible(0);
    ui->label_subject->setVisible(0);
    ui->comboBox_subjects->setVisible(0);
    ui->label_subject_insert->setVisible(0);
    ui->lineEdit_subject_insert->setVisible(0);
    ui->label_birth->setVisible(0);
    ui->dateEdit_edit_2->setVisible(0);
    ui->label_facultaty->setVisible(0);

int_role=3;
}


}


void Insert_data::on_buttonBox_3_accepted()
{
QDialog::accept();
Insert_data::get_data();
if(int_role==0)
{
    if(sss.name_str.isEmpty()||sss.lname_str.isEmpty()||sss.semestr_str.isEmpty()||sss.patronymic_str.isEmpty()||sss.date_of_birth_str.isEmpty()||sss.department_str.isEmpty())
    {
        QMessageBox sds;
        sds.setIcon(QMessageBox::Critical);
        sds.setText("Неправильно ввдеденны данные");
        sds.exec();
        return;

    }
     string_search_query="INSERT into users(fname,lname,patronymic,semestr,facultaty,date_of_birth) VALUES(";
     string_search_query+="'"+sss.name_str+"',"+"'"+sss.lname_str+"',"+"'"+sss.patronymic_str+"',"+sss.semestr_str+","+"'"+sss.department_str+"',"+"'"+sss.date_of_birth_str+"')";
     QSqlQuery query(string_search_query);


}
if(int_role==1)
{
    if(sss_1.name_str.isEmpty()||sss_1.lname_str.isEmpty()||sss_1.patronymic_str.isEmpty()||sss_1.academic_degree.isEmpty()||sss_1.academic_title.isEmpty()||sss_1.department.isEmpty()||sss_1.date_of_birth_str.isEmpty())
    {
        QMessageBox sds;
        sds.setIcon(QMessageBox::Critical);
        sds.setText("Неправильно ввдеденны данные");
        sds.exec();
        return;
    }
    string_search_query="INSERT into teachers(fname,lname,patronymic,department,academic_degree,academic_title,date_of_birth) VALUES(";
    string_search_query+="'"+sss_1.name_str+"',"+"'"+sss_1.lname_str+"',"+"'"+sss_1.patronymic_str+"',"+sss_1.department+","+"'"+sss_1.academic_degree+"',"+"'"+sss_1.academic_title+"',"+"'"+sss.date_of_birth_str+"')";
    QSqlQuery query(string_search_query);
}
if(int_role==2)
{
    if(sss_2.subject_str.isEmpty())
    {
        QMessageBox sds;
        sds.setIcon(QMessageBox::Critical);
        sds.setText("Неправильно ввдеденны данные");
        sds.exec();
        return;
    }
    QSqlQuery query;
    query.prepare("INSERT into subjects(subject_name) VALUES(:subject_name)");
    query.bindValue(":subject_name",sss_2.subject_str);
    query.exec();
}
if(int_role==3)
{
    if(sss_3.facultaties_str.isEmpty())
    {
        QMessageBox sds;
        sds.setIcon(QMessageBox::Critical);
        sds.setText("Неправильно ввдеденны данные");
        sds.exec();
        return;
    }
    QSqlQuery query((QString("INSERT into facultaty(facultaty_name) VALUES('%1')").arg(sss_3.facultaties_str)));
    query.exec();
}


}

void Insert_data::on_buttonBox_3_rejected()
{
    QDialog::reject();
}

