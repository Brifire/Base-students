#ifndef SSEARCH_H
#define SSEARCH_H

#include <QDialog>
struct Search
{
    QString name_search;
    QString lname_search;
    QString patronymic_search;
    QString semestr_search;
    QString department_search;
    QString Date_of_birth_search;
};

namespace Ui {
class SSEARCH;
}

class SSEARCH : public QDialog
{
    Q_OBJECT

public:
    explicit Sorting(QWidget *parent = nullptr);
    Search get_search_info();
    ~SSEARCH();

private slots:

private:
    Ui::SSEARCH *ui;
};

#endif // SSEARCH_H
