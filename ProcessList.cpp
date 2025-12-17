#include "ProcessList.h"
#include <iostream>

using namespace std; // чтобы не писать std::

// класс ListNode 
ListNode::ListNode(const PCB& pcb) // конструктор узла списка
{
    data = pcb; // копирование структуры pcb, для  хранения собственныхданных процесса
    next = nullptr; // указатель типа ListNode, означает что ни на кого не указывает, является последним в списке
}

ListNode::~ListNode() // деструктор пустой, так как удалением занимается ProcessList
{
  
}

// класс ProcessList
ProcessList::ProcessList()
{
    head = nullptr; // указатель на первый элемент списка, пустой, в списке нет элементов
}

ProcessList::~ProcessList() // деструктор списка, пройдет по всему списку, удалит каждый узел и освободит память 
{
    ListNode* current = head; // вспомогательный указатель, для обхода списка и вначале указывает на первый узел

    while (current != nullptr) // пока указывает на существующий узел

    {
        ListNode* temp = current->next; //  сохранение адреса следующего узла
        delete current; // освобождение памяти, убирает текущий узел
        current = temp; // переход к следующему узлу
    
    }
}


// вставка элемента 

bool ProcessList::insert(const PCB& newPCB) // добавляет процесс в список
{
    ListNode* newNode = new ListNode(newPCB); // указатель, выделяет память и вызывает конструктор
   
    // если пустой список или вставка в начало 

    if (head == nullptr ||
        newPCB.processID < head->data.processID)
    {
        newNode->next = head; // новый узел указывает на прошлый первый элемент
        head = newNode; // теперь указывает на новый первый элемент
      
        return true;
    }

    // если вставка в середину или конец

    ListNode* current = head; // для обхода списка с первого элемента

    while (current->next != nullptr &&
           current->next->data.processID < newPCB.processID)
    {
        current = current->next;
    }

    // проверка повторений

    if (current->data.processID ==newPCB.processID ||
        (current->next != nullptr &&
         current->next->data.processID == newPCB.processID))
    {

        delete newNode; // удаляем узел созданный

        return false;
    }

    // вставка

    newNode->next = current->next; // новый узел указывает на след элемент
    current->next = newNode; // текущий указывает на новый узел

    return true;
}


// удаление 
bool ProcessList::remove(int pid) // удаляет по ID
{

    if (head == nullptr) // если список пуст то и удалять нечего
    {
        return false;
    }

    // если удаление первого элемента

    if (head->data.processID == pid)
    {
        ListNode* temp = head; // сохранения адреса первого узла
        head = head->next; // теперь указывает на второй элемент
        delete temp; // удаляет старый первый узел

        return true;
    }

    // если удаление в середине или в коцне

    ListNode* current = head;

    while (current->next != nullptr &&
           current->next->data.processID != pid)
    {
    // ищем узел перед тем который нужно удалить

        current = current->next;
    }
    // если дошли до конца, а нужный не найден
    if (current->next == nullptr)
    {
      
        return false;
    }

    ListNode* temp = current->next; // узел который нужно удалить

    current->next = temp->next; // меняем на следующий узел
    delete temp; // освобождаем память 

    return true;
}


// вывод списка

void ProcessList::printList() const 
{
    ListNode* current = head; // указатель обхода списка

    if (current == nullptr)
    {
        cout << "Список процессов пуст\n";
        return;
    }

    while (current != nullptr)
    {
    // вывод данных процесса
        cout << "ID: " << current->data.processID
             << ", Name: " << current->data.processName
             << ", Status: " << current->data.processStatus
             << ", PC: " << current->data.commandCounter
             << endl;

        current = current->next; // переход к след узлу
    }
}