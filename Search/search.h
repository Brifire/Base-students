#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include "Struct_search_students.h"
#include "Struct_search_teachers.h"
#include "Struct_search_teachers_and_subjects.h"
#include "Struct_search_subjects_and_faculties.h"


namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QStringList *string_list_combo_facultaties,QStringList *string_list_combo_subjects,QWidget *parent = nullptr);
    Str_search_students get_serch_info();
    Str_search_teachers get_serch_info_1();
    Str_search_teachers_and_subjects get_serch_info_2();
    Str_search_subjects_and_faculties get_serch_info_3();
    ~Search();

private slots:
    void on_buttonBox_2_accepted();
    void on_buttonBox_2_rejected();
    void on_comboBox_main_currentIndexChanged(int index);


private:
    Ui::Search *ui;
    int int_role;
    Str_search_students sss;
    Str_search_teachers sss_1;
    Str_search_teachers_and_subjects sss_2;
    Str_search_subjects_and_faculties sss_3;
    QString string_search_query;
    QStringList string_list_combo_facultaties_1;
    QStringList string_list_combo_subjects_1;

};

#endif // SEARCH_H
