#ifndef SOBRE_H
#define SOBRE_H

#include <QDialog>

namespace Ui {
class sobre;
}

class sobre : public QDialog
{
    Q_OBJECT

public:
    explicit sobre(QWidget *parent = nullptr);
    ~sobre();

private slots:
    void on_Ok_clicked();

private:
    Ui::sobre *ui;
};

#endif // SOBRE_H
