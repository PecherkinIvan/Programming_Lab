#include <iostream>
#include <fstream>
using namespace std;

struct DATA
{
    string name;
    float  cost;
    float  weight;
    double diameter;
};

////// ДВУСВЯЗНЫЙ СПИСОК  /////

struct DLList
{
    struct Node
    {
        DATA  data;
        Node* next;
        Node* prev;
    };

    Node* F = NULL;    // Первый элемент
    Node* L = NULL;   // Последний элемент
    Node* C = NULL;  // Текущий элемент
    unsigned int count = 0;   // Количесво элементов

    void Show();  // Отображение списка
    
    bool MoveNext();     // Передвижения указателя текущего узла вперед на одну позицию
    bool MovePrev();    // Передвижения указателя текущего узла назад на одну позицию
    bool MoveFirst();  // Передвижения указателя текущего узла в начало
    bool MoveLast();  // Передвижения указателя текущего узла в конец

    bool Init(DATA);         // Инициализация списка
    bool AddNext(DATA);     // Добавление после текущего
    bool AddPrev(DATA);    // Добавление перед текущим
    bool AddFirst(DATA);  // Добавление в начало 
    bool AddLast(DATA);  // Добавление в конец

    bool DelFirst();      // Удаление первого элемента
    bool DelLast();      // Удаление последнего элемента
    bool DelCurrent();  // Удаление текущеги элемента

    void Clear();    // Очистка списка

    void GetFail();     // Загрузка базы
    void GiveFail();   // Сохранение

    void Swap();   // Меняет текущий и предыдущий
    void SortAlfo();   // Сортировка по алфавиту
    void Sort(int,short int); // Сортировка
};


