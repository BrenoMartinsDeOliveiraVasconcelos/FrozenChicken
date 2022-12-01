#include <fstream>
#include <QMessageBox>
#include <iostream>
#include <vector>
#include <sstream>
#include <QDebug>

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
                QMessageBox::warning(this, "Aviso", "Alarme está ativado! Não é possivel fechar.");
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
    ui->registro2->clearContents();
    ui->registro2->setRowCount(1);
    ui->registro2->setColumnCount(2);

    int row = -1;
    std::fstream csvfile;
    std::string line;
    std::vector<std::string>split_line;
    std::string part;

    csvfile.open("C:\\FC_Backend\\registro.csv", std::ios::in);
    if (csvfile.is_open() && csvfile.good()){
        while (std::getline(csvfile, line)){
            row++;
            ui->registro2->insertRow(row);
            std::istringstream ln(line);

            while (std::getline(ln, part, ';')){
                split_line.push_back(part);
            }

            for (int column=0; column<2; column++){
                QTableWidgetItem *C = new QTableWidgetItem(tr(split_line[column].c_str()));
                ui->registro2->setItem(row, column, C);
            }

            split_line.clear();
        }
        row = -1;
        csvfile.close();
    }
}

