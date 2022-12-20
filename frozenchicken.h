#ifndef FROZENCHICKEN_H
#define FROZENCHICKEN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FrozenChicken; }
QT_END_NAMESPACE

class FrozenChicken : public QMainWindow
{
    Q_OBJECT

public:
    FrozenChicken(QWidget *parent = nullptr);
    ~FrozenChicken();

private slots:
    void on_switchbutton_clicked();

    void on_pushButton_2_clicked();

    void on_exit_clicked();

    void on_verticalScrollBar_sliderMoved(int position);

    void on_registerbut_clicked();


    void on_pushButton_clicked();

    void on_sobre_clicked();

private:
    Ui::FrozenChicken *ui;

    void keyPressEvent(QKeyEvent *k);
};
#endif // FROZENCHICKEN_H
