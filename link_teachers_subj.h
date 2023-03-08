#ifndef LINK_TEACHERS_SUBJ_H
#define LINK_TEACHERS_SUBJ_H

#include "qsqlrecord.h"
#include <QDialog>
#include <QSql>

namespace Ui {
class link_teachers_subj;
}

class link_teachers_subj : public QDialog
{
    Q_OBJECT

public:
    explicit link_teachers_subj(QStringList *string_list_combo_subjects,QSqlRecord *qq, QWidget *parent = nullptr);
    ~link_teachers_subj();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::link_teachers_subj *ui;
    int id;
};

#endif // LINK_TEACHERS_SUBJ_H
