#include "search_info.h"
#include "qmenu.h"
#include "qobjectdefs.h"
#include "ui_search_info.h"
#include <QtSql>
#include <QDebug>
#include <mainwindow.h>

search_info::search_info(QStringList *string_list_combo_facultaties,QStringList *string_list_combo_subjects,QString *str,int *int_role,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search_info)
{
    string_list_combo_facultaties_1=(*string_list_combo_facultaties);
    string_list_combo_subjects_1=(*string_list_combo_subjects);
    ui->setupUi(this);
    QSqlQuery query_search_info(*str);
    chetire->setQuery(*str);
    ui->tableView_2->setModel(chetire);
    role=(*int_role);


}

search_info::~search_info()
{
    delete ui;
}

void search_info::on_tableView_2_customContextMenuRequested(const QPoint &pos)
{
    QMenu *sd=new QMenu;
    QAction *action = new QAction(tr("Редактировать"),sd);
    QAction *action_2 = new QAction(tr("Связать с предметом "),sd);
    connect(action,SIGNAL(triggered(bool)),this,SLOT(on_changed()));
    connect(action_2,SIGNAL(triggered(bool)),this,SLOT(on_link_teachers_subject()));
    sd->addAction(action);
    sd->addAction(action_2);
    sd->exec(ui->tableView_2->mapToGlobal(pos));

}

void search_info::on_link_teachers_subject()
{
    QModelIndex dsa=ui->tableView_2->currentIndex();
    QSqlRecord record=chetire->record(dsa.row());
    link_teachers_subj ds(&string_list_combo_subjects_1,&record,this);
    ds.exec();
}

void search_info::on_changed()
{
    QModelIndex dsa=ui->tableView_2->currentIndex();
    QSqlRecord record=chetire->record(dsa.row());
    Edit ds(&record,&string_list_combo_facultaties_1,&string_list_combo_subjects_1,&role,this);
    ds.exec();
}

