#ifndef PASSWD_H
#define PASSWD_H

#include <QDialog>

namespace Ui {
class passwd;
}

class passwd : public QDialog
{
    Q_OBJECT

public:
    explicit passwd(QWidget *parent = nullptr);
    ~passwd();

private slots:
    void on_ok_clicked();

private:
    Ui::passwd *ui;
};

#endif // PASSWD_H
