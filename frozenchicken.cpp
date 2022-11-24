#include <fstream>
#include <QMessageBox>
#include <iostream>

#include "frozenchicken.h"
#include "ui_frozenchicken.h"

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
       file.open("C:\\FC_Backend\\alarm.fc", std::ios::out);

       if (file.is_open()){
          file << "0";
       }

       file.close();
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

    dclose.open("C:\\FC_Backend\\pid\\alarm_thread", std::ios::out);
    dclose << "1";

    dclose.close();

    exit(0);
}

