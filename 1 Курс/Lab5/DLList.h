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

////// ���������� ������  /////

struct DLList
{
    struct Node
    {
        DATA  data;
        Node* next;
        Node* prev;
    };

    Node* F = NULL;    // ������ �������
    Node* L = NULL;   // ��������� �������
    Node* C = NULL;  // ������� �������
    unsigned int count = 0;   // ��������� ���������

    void Show();  // ����������� ������
    
    bool MoveNext();     // ������������ ��������� �������� ���� ������ �� ���� �������
    bool MovePrev();    // ������������ ��������� �������� ���� ����� �� ���� �������
    bool MoveFirst();  // ������������ ��������� �������� ���� � ������
    bool MoveLast();  // ������������ ��������� �������� ���� � �����

    bool Init(DATA);         // ������������� ������
    bool AddNext(DATA);     // ���������� ����� ��������
    bool AddPrev(DATA);    // ���������� ����� �������
    bool AddFirst(DATA);  // ���������� � ������ 
    bool AddLast(DATA);  // ���������� � �����

    bool DelFirst();      // �������� ������� ��������
    bool DelLast();      // �������� ���������� ��������
    bool DelCurrent();  // �������� �������� ��������

    void Clear();    // ������� ������

    void GetFail();     // �������� ����
    void GiveFail();   // ����������

    void Swap();   // ������ ������� � ����������
    void SortAlfo();   // ���������� �� ��������
    void Sort(int,short int); // ����������
};


