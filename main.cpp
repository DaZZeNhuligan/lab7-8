#include "ProcessList.h"
#include <iostream>

using namespace std;

int main()
{
setlocale(LC_ALL, ".UTF-8");

    ProcessList plist;

    // созданние процессов
    PCB p1 = {1, "ProcessA", "Running", 100, {1, 2, 3, 4}};
    PCB p2 = {3, "ProcessC", "Waiting", 200, {5, 6, 7, 8}};
    PCB p3 = {2, "ProcessB", "Stopped", 150, {9, 10, 11, 12}};

    // вставка в список
    plist.insert(p1);
    plist.insert(p2);
    plist.insert(p3);

    cout << "После вставки:\n";
    plist.printList(); // вызов метода, проходит по всему списку и выводит инфу по каждому
    plist.remove(2);

    cout << "\nПосле удаления процесса с ID=2:\n";
    plist.printList(); 

    cout << "\nПопытка удалить несуществующий процесс:\n";
    plist.remove(99);

    cout << "\nПопытка вставить дубликат:\n";
    plist.insert(p1);

    cout << "\nФинальное состояние списка:\n";
    plist.printList();

    return 0;

}