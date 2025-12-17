#ifndef PROCESSLIST_H
#define PROCESSLIST_H

#include "ListNode.h"
// класс управления связанным списком 

class ProcessList
{
private:
    ListNode* head; // указатель на первый элемент списка,

public:
    ProcessList(); // конструктор пустого списка
    ~ProcessList(); // деструктор освобождения динамической памяти

    bool insert(const PCB& newPCB); // вставка нового процесса PCB в список, отсортированного по ID 
    // true — если вставка успешна, false — если ID уже существует

    bool remove(int pid); // удаление процесса, где pid индитификатор его
    // true — если найден и удалён, false — если не найден
    
    void printList() const; // вывод всех процессов, не меняет список
};

#endif