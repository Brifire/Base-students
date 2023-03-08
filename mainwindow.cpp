#include "mainwindow.h"
#include "edit.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QDebug>
#include "search.h"
#include "search_info.h"
#include "insert_data.h"
#include <QMessageBox>
#include <QStringList>
#include <QSqlTableModel>
#include "link_teachers_subj.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    create_connetction();
   this->init_tableview();
   this->init_tableview_2();
   this->init_tableview_3();
   this->init_tableview_4();
   this->init_tableview_5();
   this->init_tableview_6();


}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::create_connetction()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setHostName("localhost");
    db.setPassword("36300");
            if(!db.open())
    {
        qDebug() <<"Error: "<<db.lastError();
        return false;
    }
            qDebug() << "Success";
            QStringList lst=db.tables();
            foreach (QString str, lst)
            {
            qDebug()<<"Table:"<<str;
            }

            return true;

}

void MainWindow::init_tableview()
{
    raz=new QSqlTableModel(this);
    raz->setTable("users");
    raz->select();
    ui->tableView->setModel(raz);
    ui->tableView->hideColumn(0);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableView->resizeColumnToContents(5);
    ui->tableView->setColumnWidth(6,148);

}

void MainWindow::init_tableview_2()
{
    dva=new QSqlTableModel(this);
    dva->setTable("teachers");
    dva->select();
    for(int i=0;i<=dva->rowCount();i++)
      {
          string_list_combo_teachers_lname.push_back(dva->record(i).value(2).toString());
      };
    ui->tableView_2->setModel(dva);
    ui->tableView_2->hideColumn(0);
}

void MainWindow::init_tableview_3()
{
    tri=new QSqlTableModel(this);
    tri->setTable("subjects");
    tri->select();
    ui->tableView_3->setModel(tri);
    for(int i=0;i<=tri->rowCount();i++)
      {
          string_list_combo_subjects.push_back(tri->record(i).value(1).toString());
      };
    ui->tableView_3->hideColumn(0);
}

void MainWindow::init_tableview_4()
{
    chetire= new QSqlQueryModel(this);
    chetire->setQuery("SELECT e.id,e.lname,e.fname,e.patronymic,b.subject_teaching,b.teacher_subject_teching_id FROM teachers e JOIN subject_teaching b ON e.id=b.teacher_subject_teching_id");
    ui->tableView_4->setModel(chetire);
    ui->tableView_4->hideColumn(0);
    ui->tableView_4->hideColumn(5);



}

void MainWindow::init_tableview_5()
{
    pyat=new QSqlTableModel(this);
    pyat->setTable("facultaty");
    pyat->select();
    ui->tableView_5->setModel(pyat);
    for(int i=0;i<=pyat->rowCount();i++)
    {
        string_list_combo_facultaties.push_back(pyat->record(i).value(0).toString());
    };
    ui->tableView_5->hideColumn(1);
}

void MainWindow::init_tableview_6()
{
    shest=new QSqlQueryModel(this);
    shest->setQuery("SELECT e.facultaty_name,b.subject_fac,b.facultaty_subj  FROM facultaty e JOIN facultaty_subjects b  ON e.id_serial=b.facultaty_subj");
    ui->tableView_6->setModel(shest);
     ui->tableView_6->hideColumn(2);
}



void MainWindow::on_delete_students()
{

QModelIndex index;
index=ui->tableView->currentIndex();
raz->removeRow(index.row());
raz->select();

}

void MainWindow::on_delete_teachers()
{
    QModelIndex index;
    index=ui->tableView_2->currentIndex();
    dva->removeRow(index.row());
    dva->select();
}

void MainWindow::on_link_teachers()
{
    QSqlRecord record;
    QModelIndex index;
    index=ui->tableView_2->currentIndex();
    record=dva->record(index.row());
    link_teachers_subj ex(&string_list_combo_subjects,&record,this);
    ex.exec();
    chetire->setQuery("SELECT e.id,e.lname,e.fname,e.patronymic,b.subject_teaching,b.teacher_subject_teching_id FROM teachers e JOIN subject_teaching b ON e.id=b.teacher_subject_teching_id");
    ui->tableView_4->setModel(chetire);


}

void MainWindow::on_SEARCH_triggered()
{
    Search *ss_rch=new Search(&string_list_combo_facultaties,&string_list_combo_subjects,this);
    ss_rch->exec();
    raz->select();
    dva->select();
    tri->select();
    pyat->select();



}


void MainWindow::on_INSERT_triggered()
{
Insert_data *nw_data=new Insert_data(&string_list_combo_facultaties,&string_list_combo_subjects,this);
nw_data->exec();
raz->select();
dva->select();
tri->select();
pyat->select();

}

void MainWindow::on_EDIT_triggered()
{
    for (int i = 0; i < 6; ++i)
    {
      qq->append("");
    }


}
void MainWindow::on_tableView_customContextMenuRequested(const QPoint &pos)
{
QMenu *sd=new QMenu;
QAction *action = new QAction(tr("Удалить"),sd);
connect(action,SIGNAL(triggered(bool)),this,SLOT(on_delete_students()));
sd->addAction(action);
sd->exec(ui->tableView->mapToGlobal(pos));
}


void MainWindow::on_tableView_2_customContextMenuRequested(const QPoint &pos)
{
    QMenu *sds=new QMenu;
    QAction *actions = new QAction(tr("Удалить"),sds);
    QAction *actions_2 = new QAction(tr("Связать с предметом "),sds);
    connect(actions,SIGNAL(triggered(bool)),this,SLOT(on_delete_teachers()));
    connect(actions_2,SIGNAL(triggered(bool)),this,SLOT(on_link_teachers()));
    sds->addAction(actions);
    sds->addAction(actions_2);
    sds->exec(ui->tableView_2->mapToGlobal(pos));
}




void MainWindow::on_Quest_triggered()
{
hhelp->show();


}

