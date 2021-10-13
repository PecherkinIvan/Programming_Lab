#include <iostream>
#include <fstream>
#include <Windows.h>

#include "Date.h"

using namespace std;

class List
{
    private:

        Node* first = NULL;

    public:
       
        void Push(Node*);
        void SetSystemDate(Node*);
        void Show_all();
     
};

List datetime;

void List::Show_all()
{

    if(!first) 
    {
        cout<<"\n *  Список пуст   * \n";
        return;
    }

    Node* temp = first;

    cout<<"\n--------------------------------------------------------------------------------------------";
    cout<<"\n             дата                |     следующая дата               |    предыдущая дата    |\n";
    cout<<"----------------------------------------------------------------------------------------------\n";

    do
    {

        temp->DisplayNode();
        temp = temp->next;

    } while(temp);

    cout<<endl;
}

void List::Push(Node* temp)
{

    if(!first)
    {
        first = temp;
        first->next = NULL;
        first->prev = NULL;

        first->n = 1;
    }
    
    else
    {
        Node* temp1 = first;

        while ( temp1->next != NULL)
        {
            temp1 = temp1->next;
        }


        temp1->next = temp;
        temp1->next->next = NULL;
        temp1->next->prev = temp1;

        temp->n = temp->prev->n + 1;
    }
}

void List::SetSystemDate(Node* temp)
{
    SYSTEMTIME st;  // буфер хранения системного времени

    GetLocalTime(&st);  // Запись времени
    // Распеределение данных

    temp->date->SetAdd(int(st.wMilliseconds), (st.wSecond), int(st.wMinute), int(st.wHour), int(st.wDay), int(st.wMonth), int(st.wYear));

    Push(temp);

    cout<<"\n\n * Дата ";
    temp->DisplayDate();
    cout<<" успешно добавлена.\n";
}

int main()
{
    system("chcp 1251");

    Node* temp;

    int v;
	cout << "Enter value:" << endl;
    cin>>v;

    while(v>0)
    {

        if (v <= 3 ) {
        temp = new NodeExt;
        
        datetime.SetSystemDate(temp);

    }
    else 
    {

        temp = new Node;		
        
        datetime.SetSystemDate(temp);
    }  

        system("sleep 1");
        v--;
    }

    datetime.Show_all();


    return 0;
}