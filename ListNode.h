#ifndef LISTNODE_H
#define LISTNODE_H

#include "PCB.h"
// здесь связанный список 
class ListNode
{
public:
    PCB data; // хранит данные одного процесса

    ListNode* next; // указывает на следующий узел списка
 
    ListNode(const PCB& pcb); // конструктор с ссылкой на PCB для копировании данных процесса 
    ~ListNode(); // деструктор остается пустым чтобы не освобождаласть память два раза 
 
};

#endif