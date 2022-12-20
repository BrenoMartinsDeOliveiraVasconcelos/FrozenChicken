#include "passwd.h"
#include "ui_passwd.h"

#include <QMessageBox>
#include <cstdlib>
#include <fstream>

passwd::passwd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::passwd)
{
    ui->setupUi(this);
}

passwd::~passwd()
{
    delete ui;
}

void passwd::on_ok_clicked()
{
    auto input = ui->camp->text();
    std::fstream alarm_passwd;
    std::string password;
    QString qPassword;

    alarm_passwd.open("C:\\FC_Backend\\backend.py", std::ios::in);

    if (alarm_passwd.is_open()){
        while (std::getline(alarm_passwd, password)){
            qPassword = QString::fromStdString(password);
            break;
        }
    }

    if (input ==  qPassword){
        std::fstream alarm;
        alarm.open("C:\\FC_Backend\\alarm.fc", std::ios::out);

        alarm << "0";
        alarm.close();

        QMessageBox::information(this, "Sucesso!", "Alarme foi desligado com sucesso!");
        close();
    }else{
        QMessageBox::critical(this, "Senha incorreta", "Senha incorreta! Tente novamente quando tiver a senha."
                                                      "");
    }
}

