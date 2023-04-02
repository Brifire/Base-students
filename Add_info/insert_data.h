#ifndef INSERT_DATA_H
#define INSERT_DATA_H

#include <QDialog>
#include "Struct_search_students.h"
#include "Struct_search_teachers.h"
#include "Struct_search_subjects.h"
#include "Struct_search_facultaties.h"
#include "Struct_search_teachers_and_subjects.h"
#include "Struct_search_subjects_and_faculties.h"


namespace Ui {
class Insert_data;
}

class Insert_data : public QDialog
{
    Q_OBJECT

public:
    explicit Insert_data(QStringList *string_list_combo_facultaties,QStringList *string_list_combo_subjects,QWidget *parent = nullptr);
    void get_data();
    ~Insert_data();

private:
   int int_role;
   Str_search_students sss;
   Str_search_teachers sss_1;
   Str_search_subjects sss_2;
   Str_search_facultaties sss_3;
   QString string_search_query;


    Ui::Insert_data *ui;
public slots:

private slots:
      void on_buttonBox_3_accepted();
      void on_comboBox_main_2_currentIndexChanged(int index);
      void on_buttonBox_3_rejected();
};

#endif // INSERT_DATA_H
