#ifndef RUNTIME_H
#define RUNTIME_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <thread>

// Função para checar se o alarme foi acionado ou não
void alarmChecker(){
    system("py C:\\FC_Backend\\alarm.py");

   return;
}

#endif // RUNTIME_H
