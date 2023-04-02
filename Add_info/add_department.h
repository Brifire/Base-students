#ifndef ADD_DEPARTMENT_H
#define ADD_DEPARTMENT_H

#include <QDialog>

namespace Ui {
class Add_department;
}

class Add_department : public QDialog
{
    Q_OBJECT

public:
    explicit Add_department(QWidget *parent = nullptr);
    ~Add_department();

private:
    Ui::Add_department *ui;
};

#endif // ADD_DEPARTMENT_H
