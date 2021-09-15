#include <iostream>
#include <fstream>
#include <Windows.h>
                            ////  ������� 12  ////
using namespace std;           

struct Date
{
    struct Node
    {
        int second;
        int minute;
        int hour;
        int day;
        int month;
        int year;

        Node* next;
        Node* prev;

        unsigned int n;   // �����
    };

    Node* first;
    
    void DisplayNode(Node* temp);
    void Show_all();
 
    void Push(Node* temp);
    void GetFail();
    void Task_12();

    void GetSystemDate();

    void Clear();
    
};


Date datetime;
//Date timedelta;




void Date::Push(Node* temp)
{
    if(!first)
    {
        first = temp;
        first->next = NULL;
        first->prev = NULL;

        temp->n=1;
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
        temp->prev = temp1;

        temp->n = (temp->prev->n)+1;
    }
}

void Date::GetFail()
{
    ifstream fin("INPUT.txt");

    Node* temp;

    while(!fin.eof())
    {
        temp = new Node;
        fin >> temp->second;
        fin >> temp->minute;
        fin >> temp->hour;
        fin >> temp->day;
        fin >> temp->month;
        fin >> temp->year;

        datetime.Push(temp);  // ? 
    }

    fin.close();
}

void Date::Show_all()
{
    if(!first) 
    {
        cout<<"\n *  ������ ����   * \n";
        return;
    }

    Node* temp = first;

    cout<<"\n------------------------------------------------------------------------------------";
    cout<<"\n          ����             |       ��������� ����       |       ���������� ����     |\n";
    cout<<"-------------------------------------------------------------------------------------\n";

    do
    {

        DisplayNode(temp);
        temp = temp->next;

    } while(temp);

    cout<<endl;

}

void Date::DisplayNode(Node* temp)
{

    cout<<temp->n<<".   "<<temp->second<<":"<<temp->minute<<":"<<temp->hour
        <<"  "<<temp->day<<"."<<temp->month<<"."<<temp->year<<"       ";     // ����


        if(temp->next != NULL)                          // ���. ����
        {   
         cout<<temp->next->second<<":"<<temp->next->minute<<":"<<temp->next->hour      // ���. ����
         <<"  "<<temp->next->day<<"."<<temp->next->month<<"."<<temp->next->year;
        }
        else
        {
            cout<<"__"<<":"<<"__"<<":"<<"__"
         <<"  "<<"__"<<"."<<"__"<<"."<<"__";
        }
        cout<<"               ";

            if(temp->prev != NULL)                     // ����. ����
            {
                cout<<temp->prev->second<<":"<<temp->prev->minute<<":"<<temp->prev->hour   
                <<"  "<<temp->prev->day<<"."<<temp->prev->month<<"."<<temp->prev->year;
            }
            else
            {
                    cout<<"__"<<":"<<"__"<<":"<<"__"
                <<"  "<<"__"<<"."<<"__"<<"."<<"__";
            }
        
        cout<<endl;
}

void Date::Task_12()
{
    if(!first)
    {
        cout<<"\n * ������ �� �������. ";
        return;
    }

    Node* temp = first;
    bool flag = 0;

    do
    {
       if(temp->next != NULL && temp->day%2 != 0  && temp->next->day%2 != 0)
       {
           if(!flag)
           {
            cout<<"\n------------------------------------------------------------------------------------";
            cout<<"\n          ����             |       ��������� ����       |       ���������� ����     |\n";
            cout<<"-------------------------------------------------------------------------------------\n";
           }

            DisplayNode(temp);

            flag = 1;
       }

        temp = temp->next;

    } while (temp);
    
    if(!flag) cout<<"\n * ������ �� �������. ";

}

void Date::GetSystemDate()
{
    SYSTEMTIME st;  // ����� �������� ���������� �������

    Node* temp;
    temp = new Node;
    GetLocalTime(&st);  // ������ �������
  
    temp->second = int(st.wSecond);  // �������������� ������
    temp->minute = int(st.wMinute);
    temp->hour = int(st.wHour);
    temp->day = int(st.wDay);
    temp->month = int(st.wMonth);
    temp->year = int(st.wYear);
    
    Push(temp);

    cout<<"\n\n * ���� "<<temp->second<<":"<<temp->minute<<":"<<temp->hour
        <<"  "<<temp->day<<"."<<temp->month<<"."<<temp->year<<" ������� ���������.\n";
}

void Date::Clear()
{

    if(!first)
    {
        cout<<"\n * ������� ��� ������.";
        return; 
    }

    Node* temp = first;

    while (first)
    {
        temp = first;
        first = temp->next;
    
        free(temp);
    }
    
}


void MENU()
{

    cout<<"\n  ________________________________________"
        <<"\n |                                        ||"
        <<"\n |        ** �������� �������� **         ||"
        <<"\n |  1.) ��������� ������ �� �����         ||"
        <<"\n |  2.) ������� 12                        ||"
        <<"\n |  3.) ���������� ������                 ||"
        <<"\n |  4.) �������� ������                   ||"
        <<"\n |  5.) �������� ��������� ����� � ����   ||"
        <<"\n |  0.) �����                             ||"
        <<"\n |________________________________________||"
        <<"\n  > ";

    int point;  cin>>point;

    switch(point) {
        case 1:
        {
            system("cls");
            datetime.GetFail();
            cout<<"\n * ������ ������� ���������.";
            datetime.Show_all();
            MENU();

              break;
        }      

         case 2:
        {
            datetime.Task_12();
            MENU();

              break;
        }  

        case 3:
        {
            datetime.Show_all();
            MENU();

              break;
        } 

        case 4:
        {
            datetime.Clear();
            cout<<"\n\n * ������ ������� ������.\n";
            MENU();

              break;
        }     

        case 5:
        {
            datetime.GetSystemDate();
            cout<<"\n\n * ����� ��������.\n";
            MENU();

              break;
        }              

       

        case 0:
        {
            exit(1);
            break;
        }
        
        default:
        {
            cout<<"\n * ������";
            system("cls");
            MENU();
            break;
        }

    }

}

int main()
{
    system ("chcp 1251");
    
    MENU();
   


    return 0;
}

