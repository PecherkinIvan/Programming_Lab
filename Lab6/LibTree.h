#include <iostream>
#include <fstream>
using namespace std;

struct DATA        ///  8.) Книга
{
    string name;
    string author;
    int size;
    int year;
};

 struct Tree
{
    DATA data;
    Tree* left;
    Tree* right;
};


void Add_Num(Tree*&, DATA, short int);       // Добавить
void Add_String(Tree*&, DATA, short int);


void PrintLRR(Tree*);      // Отобразить Л-К-П

void PrintVelue(Tree*, int, short int);
void PrintLetter(Tree*, char, short int);

void GetFail(Tree*&, short int);

void Delete(Tree*&);     // Очистить