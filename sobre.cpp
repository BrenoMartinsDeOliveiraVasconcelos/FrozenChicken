#include "sobre.h"
#include "ui_sobre.h"

sobre::sobre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sobre)
{
    ui->setupUi(this);
    setWindowTitle("Sobre");
}

sobre::~sobre()
{
    delete ui;
}

void sobre::on_Ok_clicked()
{
    sobre::close();
}

