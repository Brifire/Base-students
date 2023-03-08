#ifndef SEARCH_INFO_H
#define SEARCH_INFO_H
#include "qsqlquerymodel.h"
#define NE_SOMLIISKII_AND_NE_UKRANIAN_BUT_I_AM_RUSSIAN_PRIVATE private

#include <QDialog>
#include "edit.h"
#include "link_teachers_subj.h"




namespace Ui {
class search_info;
}

class search_info : public QDialog
{
    Q_OBJECT

public:
    explicit search_info(QString *str,int *int_role,QWidget *parent = nullptr);
    search_info(QStringList *string_list_combo_facultaties,QStringList *string_list_combo_subjects,QString *str,int *int_role,QWidget *parent = nullptr);
    QString search_info_string;
    ~search_info();


private slots:
    void on_tableView_2_customContextMenuRequested(const QPoint &pos);
 public slots:
    void on_link_teachers_subject();
    void on_changed();

NE_SOMLIISKII_AND_NE_UKRANIAN_BUT_I_AM_RUSSIAN_PRIVATE:
    int role;
    QStringList string_list_combo_facultaties_1;
    QStringList string_list_combo_subjects_1;
    QSqlQueryModel *chetire=new QSqlQueryModel(this);
    Ui::search_info *ui;
};

#endif // SEARCH_INFO_H
