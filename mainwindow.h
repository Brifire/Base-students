#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "edit.h"
#include "qsqltablemodel.h"
#include "search.h"
#include "insert_data.h"
#include <QComboBox>
#include "help.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QString string_search;
    QString string_insert;
    QStringList *qq=new QStringList;
    QString string_edit;
    ~MainWindow();
    bool create_connetction();
    void init_facultaties_data();
    void init_tableview();
    void init_tableview_2();
    void init_tableview_3();
    void init_tableview_4();
    void init_tableview_5();
    void init_tableview_6();

public slots:
    void on_delete_students();
    void on_delete_teachers();
    void on_link_teachers();

private slots:

    void on_SEARCH_triggered();
    void on_INSERT_triggered();
    void on_EDIT_triggered();
    void on_tableView_customContextMenuRequested(const QPoint &pos);
    void on_tableView_2_customContextMenuRequested(const QPoint &pos);


    void on_Quest_triggered();

private:
    int Current_row_int;
    int role;
    help *hhelp=new help;
    Str_search_students sss;
    Struct_edit sss_2;
    QStringList department_data;
    QStringList string_list_combo_subjects;
    QStringList string_list_combo_facultaties;
    QStringList string_list_combo_teachers_lname;
    QStringList string_list_combo_teachers_fname;
    QStringList string_list_combo_teachers_patr;

    QSqlTableModel *raz;
    QSqlTableModel *dva;
    QSqlTableModel *tri;
    QSqlQueryModel *chetire;
    QSqlTableModel *pyat;
    QSqlQueryModel *shest;
    Ui::MainWindow *ui;   


};
#endif // MAINWINDOW_H
