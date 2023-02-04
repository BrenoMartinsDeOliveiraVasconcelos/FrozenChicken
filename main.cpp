#include "frozenchicken.h"

#include <QApplication>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <runtime.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    FrozenChicken w;
    w.show();

    // Thread para o alarme
    std::thread alarmThread(alarmChecker);

    return a.exec();
}
