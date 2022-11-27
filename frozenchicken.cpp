#include <fstream>
#include <QMessageBox>
#include <iostream>
#include <vector>

#include "frozenchicken.h"
#include "ui_frozenchicken.h"
#include "passwd.h"

FrozenChicken::FrozenChicken(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FrozenChicken)
{
    ui->setupUi(this);
}

FrozenChicken::~FrozenChicken()
{
    delete ui;
}


void FrozenChicken::on_switchbutton_clicked()
{
    std::fstream file;
    std::string txt;
    bool is_activated = false;

   file.open("C:\\FC_Backend\\alarm.fc", std::ios::in);

   // checar o status do alarme
   if (file.is_open()){
       while (getline(file, txt)){
           if (txt == "1"){
               is_activated = true;
           }else{
               QMessageBox msg;

               msg.setText("Alarme não está ativado!");
               msg.setStandardButtons(QMessageBox::Cancel);
               msg.setIcon(QMessageBox::Information);

               msg.exec();
           }
           break;
       }
   }

   file.close();

   // desligar o alarme
   if (is_activated){
       passwd password;
       password.exec();
   }

    return;
}


// Não consegui tirar isso, deixa isso quieto ok?
void FrozenChicken::on_pushButton_2_clicked(){
    std::cout << "Cliked";
}


void FrozenChicken::on_exit_clicked()
{
    //Para fechar a thread do alarme
    std::fstream dclose;
    std::fstream alarmfc;
    std::string txt;

    alarmfc.open("C:\\FC_Backend\\alarm.fc", std::ios::in);

    if (alarmfc.is_open()){
        while (getline(alarmfc, txt)){
            if (txt == "0"){
                dclose.open("C:\\FC_Backend\\pid\\alarm_thread", std::ios::out);
                dclose << "1";

                dclose.close();

                exit(0);
            }else{
                QMessageBox msg;

                msg.setText("Não foi possível fechar devido ao alarme estar ativado.");
                msg.setStandardButtons(QMessageBox::Cancel);
                msg.setIcon(QMessageBox::Warning);

                msg.exec();
            }
            break;
        }
    }
}


void FrozenChicken::on_verticalScrollBar_sliderMoved(int position)
{
    ui->registro2->scroll(0, position);
    return;
}


void FrozenChicken::on_registerbut_clicked()
{
    ui->registro2->setRowCount(5);
    ui->registro2->setColumnCount(2);
    int row = 0;
    int column = 0;


    for (row; row<5; row++){
        QTableWidgetItem *test = new QTableWidgetItem(tr("a"));
        ui->registro2->setItem(row, column, test);
    }
}

