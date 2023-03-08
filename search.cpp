#include "search.h"
#include "search_info.h"
#include "ui_search.h"


Search::Search(QStringList *string_list_combo_facultaties,QStringList *string_list_combo_subjects,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{

    ui->setupUi(this);
    string_list_combo_facultaties_1=(*string_list_combo_facultaties);
    string_list_combo_subjects_1=(*string_list_combo_subjects);
    ui->comboBox_sem->addItem("");
    ui->comboBox_sem->addItem("1");
    ui->comboBox_sem->addItem("2");
    ui->comboBox_sem->addItem("3");
    ui->comboBox_sem->addItem("4");
    ui->comboBox_sem->addItem("5");
    ui->comboBox_sem->addItem("6");
    ui->comboBox_sem->addItem("7");
    ui->comboBox_sem->addItem("8");
    ui->comboBox_sem->addItem("9");
    ui->comboBox_dep->addItem("");
    for (int i=0;string_list_combo_facultaties->size()!=i;i++)
    {
     ui->comboBox_dep->addItem(string_list_combo_facultaties->at(i));
    }
    ui->comboBox_3->addItem("");
    for (int i=0;string_list_combo_subjects->size()!=i;i++)
    {
     ui->comboBox_3->addItem(string_list_combo_subjects->at(i));
    }
    ui->dateEdit_edit->setDate(QDate::currentDate());
    ui->label->setVisible(0);
    ui->comboBox_3->setVisible(0);
    ui->label_7->setVisible(0);
    ui->label_8->setVisible(0);
    ui->label_9->setVisible(0);
    ui->departmen_teachers->setVisible(0);
    ui->academic_title_teachers->setVisible(0);
    ui->academic_degree_teachers->setVisible(0);

    ui->label->setVisible(0);

    int_role=0;
}

Str_search_students Search::get_serch_info()
{


    sss.name_str=ui->Name_edit->text();
    sss.lname_str=ui->Lname_edit->text();
    sss.patronymic_str=ui->Patronymic_edit->text();
    sss.semestr_str=ui->comboBox_sem->currentText();
    sss.department_str=ui->comboBox_dep->currentText();
    if(ui->dateEdit_edit->date()==QDate::currentDate())
    {
        sss.date_of_birth_str.clear();
    }
    else
    {
        sss.date_of_birth_str=ui->dateEdit_edit->date().toString("yyyy-MM-dd");
    }
    return sss;

}

Str_search_teachers Search::get_serch_info_1()
{
sss_1.name_str=ui->Name_edit->text();
sss_1.lname_str=ui->Lname_edit->text();
sss_1.patronymic_str=ui->Patronymic_edit->text();
sss_1.department=ui->departmen_teachers->text();
sss_1.academic_degree=ui->academic_degree_teachers->text();
sss_1.academic_title=ui->academic_title_teachers->text();
if(ui->dateEdit_edit->date()==QDate::currentDate())
{
    sss.date_of_birth_str.clear();
}
else
{
    sss.date_of_birth_str=ui->dateEdit_edit->date().toString("yyyy-MM-dd");
}
return sss_1;
}

Str_search_teachers_and_subjects Search::get_serch_info_2()
{
    sss_2.name_str=ui->Name_edit->text();
    sss_2.lname_str=ui->Lname_edit->text();
    sss_2.patronymic_str=ui->Patronymic_edit->text();
    sss_2.subject=ui->comboBox_3->currentText();
    return sss_2;

}

Str_search_subjects_and_faculties Search::get_serch_info_3()
{
 sss_3.faculties=ui->comboBox_dep->currentText();
 sss_3.subject=ui->comboBox_3->currentText();
 return sss_3;
}


Search::~Search()
{
    delete ui;
}






void Search::on_buttonBox_2_accepted()
{
    QDialog::accept();
    if(int_role==0)
    {
     Search::get_serch_info();
     string_search_query="SELECT id,fname,lname,patronymic,semestr,facultaty,date_of_birth from users ";
     QString where="WHERE";
     bool flag_correction=true;
     if(!sss.name_str.isEmpty())
     {
         string_search_query+="WHERE fname='"+sss.name_str+"'";
         flag_correction=false;
     }
     if(!sss.lname_str.isEmpty())
     {
         if (flag_correction==false)
         {
         string_search_query+=" AND lname='"+sss.lname_str+"'";
         }
         else
         {
            string_search_query+= where+" lname='"+sss.lname_str+"'";
            flag_correction=false;
         }
     }
     if(!sss.patronymic_str.isEmpty())
     {
         if (flag_correction==false)
         {
         string_search_query+=" AND patronymic='"+sss.patronymic_str+"'";
         }
         else
         {
         string_search_query+= where+" patronymic='"+sss.patronymic_str+"'";
         }
     }
     if(!sss.semestr_str.isEmpty())
     {
         if (flag_correction==false)
         {
         string_search_query+=" AND semestr='"+sss.semestr_str+"'";
         }
         else
         {
         string_search_query+=where+" semestr='"+sss.semestr_str+"'";
         flag_correction=false;
         }
     }
     if(!sss.department_str.isEmpty())
     {
         if (flag_correction==false)
         {
          string_search_query+=" AND facultaty='"+sss.department_str+"'";
         }
         else
         {
             string_search_query+=where+" facultaty='"+sss.department_str+"'";
             flag_correction=false;
         }
     }
     if(!sss.date_of_birth_str.isEmpty())
     {
         if (flag_correction==false)
         {
          string_search_query+=" AND date_of_birth='"+sss.date_of_birth_str+"'";
         }
         else
         {
             string_search_query+=where+" date_of_birth='"+sss.date_of_birth_str+"'";
         }

     }
    }
    if(int_role==1)
    {
        Search::get_serch_info_1();
        string_search_query="SELECT id,fname,lname,patronymic,department,academic_degree,academic_title,date_of_birth from teachers ";
        QString where="WHERE";
        bool flag_correction=true;
        if(!sss_1.name_str.isEmpty())
        {
            string_search_query+="WHERE fname='"+sss_1.name_str+"'";
            flag_correction=false;
        }
        if(!sss_1.lname_str.isEmpty())
        {
            if (flag_correction==false)
            {
            string_search_query+=" AND lname='"+sss_1.lname_str+"'";
            }
            else
            {
               string_search_query+= where+" lname='"+sss_1.lname_str+"'";
               flag_correction=false;
            }
        }
        if(!sss_1.patronymic_str.isEmpty())
        {
            if (flag_correction==false)
            {
            string_search_query+=" AND patronymic='"+sss_1.patronymic_str+"'";
            }
            else
            {
            string_search_query+= where+" patronymic='"+sss_1.patronymic_str+"'";
            }
        }
        if(!sss_1.department.isEmpty())
        {
            if (flag_correction==false)
            {
            string_search_query+=" AND department='"+sss_1.department+"'";
            }
            else
            {
            string_search_query+=where+" department='"+sss_1.department+"'";
            flag_correction=false;
            }
        }
        if(!sss_1.academic_degree.isEmpty())
        {
            if (flag_correction==false)
            {
             string_search_query+=" AND academic_degree='"+sss_1.academic_degree+"'";
            }
            else
            {
                string_search_query+=where+" academic_degree='"+sss_1.academic_degree+"'";
                flag_correction=false;
            }
        }
        if(!sss_1.academic_title.isEmpty())
        {
            if (flag_correction==false)
            {
             string_search_query+=" AND academic_title='"+sss_1.academic_title+"'";
            }
            else
            {
                string_search_query+=where+" academic_title='"+sss_1.academic_title+"'";
                flag_correction=false;
            }
        }
        if(!sss.date_of_birth_str.isEmpty())
        {
            if (flag_correction==false)
            {
             string_search_query+=" AND date_of_birth='"+sss.date_of_birth_str+"'";
            }
            else
            {
                string_search_query+=where+" date_of_birth='"+sss.date_of_birth_str+"'";
            }

        }

    }


    if(int_role==2)
    {
     Search::get_serch_info_2();
     string_search_query="SELECT e.id,e.lname,e.fname,e.patronymic,b.subject_teaching,b.teacher_subject_teching_id FROM teachers e JOIN subject_teaching b ON e.id=b.teacher_subject_teching_id ";
     QString where="WHERE";
     bool flag_correction=true;
     if(!sss_2.name_str.isEmpty())
     {
         string_search_query+="WHERE fname='"+sss_2.name_str+"'";
         flag_correction=false;
     }
     if(!sss_2.lname_str.isEmpty())
     {
         if (flag_correction==false)
         {
         string_search_query+=" AND lname='"+sss_2.lname_str+"'";
         }
         else
         {
            string_search_query+= where+" lname='"+sss_2.lname_str+"'";
            flag_correction=false;
         }
     }
     if(!sss_2.patronymic_str.isEmpty())
     {
         if (flag_correction==false)
         {
         string_search_query+=" AND patronymic='"+sss_2.patronymic_str+"'";
         }
         else
         {
         string_search_query+= where+" patronymic='"+sss_2.patronymic_str+"'";
         }
     }
     if(!sss_2.subject.isEmpty())
     {
         if (flag_correction==false)
         {
         string_search_query+=" AND subject_teaching='"+sss_2.subject+"'";
         }
         else
         {
         string_search_query+=where+" subject_teaching='"+sss_2.subject+"'";

         }
     }

    }
    if(int_role==3)
    {
     Search::get_serch_info_3();
     string_search_query="SELECT e.facultaty_name,b.subject_fac,b.facultaty_subj  FROM facultaty e JOIN facultaty_subjects b ON e.id_serial=b.facultaty_subj ";
     QString where="WHERE";
     bool flag_correction=true;
     if(!sss_3.faculties.isEmpty())
     {
         string_search_query+="WHERE facultaty_name='"+sss_3.faculties+"'";
         flag_correction=false;
     }
     if(!sss_3.subject.isEmpty())
     {
         if (flag_correction==false)
         {
         string_search_query+=" AND subject_fac='"+sss_3.subject+"'";
         }
         else
         {
            string_search_query+= where+" subject_fac='"+sss_3.subject+"'";
         }
     }
    }

     search_info *sd=new search_info(&string_list_combo_facultaties_1,&string_list_combo_subjects_1,&string_search_query,&int_role,this);
     sd->exec();

    }




void Search::on_buttonBox_2_rejected()
{
    QDialog::reject();
}





void Search::on_comboBox_main_currentIndexChanged(int index)
{
    if(index==0)
    {

        ui->label_1->setVisible(1);
        ui->label_2->setVisible(1);
        ui->label_3->setVisible(1);
        ui->Name_edit->setVisible(1);
        ui->Lname_edit->setVisible(1);
        ui->Patronymic_edit->setVisible(1);
        ui->label_4->setVisible(1);
        ui->label_5->setVisible(1);
        ui->comboBox_dep->setVisible(1);
        ui->comboBox_sem->setVisible(1);
        ui->dateEdit_edit->setVisible(1);
        ui->label_6->setVisible(1);
        ui->label->setVisible(0);
        ui->label_7->setVisible(0);
        ui->label_8->setVisible(0);
        ui->label_9->setVisible(0);
        ui->departmen_teachers->setVisible(0);
        ui->academic_title_teachers->setVisible(0);
        ui->academic_degree_teachers->setVisible(0);
        ui->comboBox_3->setVisible(0);
        int_role=0;


    }
    if(index==1)
    {
        ui->label_1->setVisible(1);
        ui->label_2->setVisible(1);
        ui->label_3->setVisible(1);
        ui->Name_edit->setVisible(1);
        ui->Lname_edit->setVisible(1);
        ui->Patronymic_edit->setVisible(1);
        ui->label_7->setVisible(1);
        ui->label_8->setVisible(1);
        ui->label_9->setVisible(1);
        ui->departmen_teachers->setVisible(1);
        ui->academic_title_teachers->setVisible(1);
        ui->academic_degree_teachers->setVisible(1);
        ui->dateEdit_edit->setVisible(1);
        ui->label_6->setVisible(1);
        ui->dateEdit_edit->setVisible(1);
        ui->label_4->setVisible(0);
        ui->label_5->setVisible(0);
        ui->comboBox_dep->setVisible(0);
        ui->comboBox_sem->setVisible(0);
        ui->label->setVisible(0);
        ui->comboBox_3->setVisible(0);
        int_role=1;
    }
    if(index==2)
    {
        ui->label_1->setVisible(1);
        ui->label_2->setVisible(1);
        ui->label_3->setVisible(1);
        ui->Name_edit->setVisible(1);
        ui->Lname_edit->setVisible(1);
        ui->Patronymic_edit->setVisible(1);
        ui->label->setVisible(1);
        ui->comboBox_3->setVisible(1);
        ui->label_4->setVisible(0);
        ui->label_5->setVisible(0);
        ui->comboBox_dep->setVisible(0);
        ui->comboBox_sem->setVisible(0);
        ui->dateEdit_edit->setVisible(0);
        ui->label_6->setVisible(0);
        ui->label_7->setVisible(0);
        ui->label_8->setVisible(0);
        ui->label_9->setVisible(0);
        ui->departmen_teachers->setVisible(0);
        ui->academic_title_teachers->setVisible(0);
        ui->academic_degree_teachers->setVisible(0);
        int_role=2;
    }

    if(index==3)
    {
    ui->label_4->setVisible(0);
    ui->label_5->setVisible(0);
    ui->comboBox_dep->setVisible(0);
    ui->comboBox_sem->setVisible(0);
    ui->dateEdit_edit->setVisible(0);
    ui->label_6->setVisible(0);
    ui->label_7->setVisible(0);
    ui->label_8->setVisible(0);
    ui->label_9->setVisible(0);
    ui->departmen_teachers->setVisible(0);
    ui->academic_title_teachers->setVisible(0);
    ui->academic_degree_teachers->setVisible(0);
    ui->label_1->setVisible(0);
    ui->label_2->setVisible(0);
    ui->label_3->setVisible(0);
    ui->Name_edit->setVisible(0);
    ui->Lname_edit->setVisible(0);
    ui->Patronymic_edit->setVisible(0);
    ui->label->setVisible(0);
    ui->label->setVisible(1);
    ui->label_5->setVisible(1);
    ui->comboBox_3->setVisible(1);
    ui->comboBox_dep->setVisible(1);
    int_role=3;
    }

}



