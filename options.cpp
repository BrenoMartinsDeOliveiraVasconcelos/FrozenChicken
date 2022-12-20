#include "options.h"
#include "ui_options.h"
#include <QMessageBox>
#include <fstream>

options::options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::options)
{
    ui->setupUi(this);
    setWindowTitle("Opções");
}

options::~options()
{
    delete ui;
}

void options::on_exitopt_clicked()
{
    options::close();
}


void options::on_okps_clicked()
{
    std::fstream password;
    std::string correctps;
    QString qCorrectps;
    QString oldpswd = ui->oldps->text();
    QString newpswd = ui->newps->text();
    std::string utf8_newpswd = newpswd.toLocal8Bit().constData();

    password.open("C:\\FC_Backend\\backend.py", std::ios::in);

    // Para checar se a senha antiga foi digitada corretamente
    if (password.is_open()){
        while (std::getline(password, correctps)){
            qCorrectps = QString::fromStdString(correctps);
            break;
        }
    }else{
        QMessageBox::critical(this, "Falha ao abrir arquivo", "Um erro inesperado ocorreu ao abrir o arquivo.");
    }

    password.close();


    if (qCorrectps==oldpswd){
        // Trocar a senha pela nova
        password.open("C:\\FC_Backend\\backend.py", std::ios::out);
        password << utf8_newpswd;
        password.close();

        QMessageBox::information(this, "Senha alterada", "Senha alterada com sucesso");
    }else{
        QMessageBox::critical(this, "Senha incorreta", "Verifique a ortografia e tente novamente");
    }
}


void options::on_copy_clicked()
{
    QString path = ui->path->text();
    std::string strPath = path.toLocal8Bit().constData();
    std::ifstream r("C:\\FC_Backend\\registro.csv", std::ios::binary);
    std::ofstream destination(strPath+"\\registro.csv", std::ios::binary);

    // Checar o input
    if (strPath != ""){
        if (destination.is_open()){
            destination << r.rdbuf();
            QMessageBox::information(this, "Copiado", "Arquivo copiado para o caminho especificado.");
        }else{
            QMessageBox::critical(this, "Caminho inválido", "O caminho especificado é inválido ou já está em uso!");
        }
    }else{
        QMessageBox::warning(this, "Caminho vazio", "O caminho está incorreto!");
    }

    r.close();
    destination.close();
}
