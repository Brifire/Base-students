#ifndef EDIT_H
#define EDIT_H

#include "qsqlrecord.h"
#include <QDate>
#include <QDialog>
#include <QComboBox>
struct Struct_edit
{
    QString name_str;
    QString lname_str;
    QString patronymic_str;
    QString semestr_str;
    QString department_str;
    QString date_of_birth_str;
};
enum variant
{
    students,teachers,teachers_and_subjects,facultaty_and_subject
};

namespace Ui {
class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = nullptr);
    Edit(QSqlRecord *record,QStringList *string_list_combo_facultaties,QStringList *string_list_combo_subjects,int *role,QWidget *parent = nullptr);
    Struct_edit get_info_edit();
    void show_stuff(int stuff);

    ~Edit();

private:
    int private_int_role;
    int id;
    Ui::Edit *ui;
    QString insert;

public slots:

private slots:

    void on_buttonBox_3_accepted();
    void on_buttonBox_3_rejected();
};

#endif // EDIT_H
