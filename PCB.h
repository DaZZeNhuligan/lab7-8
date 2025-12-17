#ifndef PCB_H
#define PCB_H

#include <string>
// здесь будет находится PCB - структура однго процесса

struct PCB
{
    int processID; // индитификатор процесса хранящий номер 
    std::string processName; // строка имени 
    std::string processStatus; // статус 
    int commandCounter; // счётчик следующих команд
    int cpuRegisters[4]; // массив значения регистра
};

#endif