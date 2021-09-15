#include <iostream>
#include <fstream>
using namespace std;

struct DATA        ///  8.) �����
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


void Add_Num(Tree*&, DATA, short int);       // ��������
void Add_String(Tree*&, DATA, short int);


void PrintLRR(Tree*);      // ���������� �-�-�

void PrintVelue(Tree*, int, short int);
void PrintLetter(Tree*, char, short int);

void GetFail(Tree*&, short int);

void Delete(Tree*&);     // ��������