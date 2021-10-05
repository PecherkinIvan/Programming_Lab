#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

class Date
{
    private:

        int second;
        int minute;
        int hour;
        int day;
        int month;
        int year;

        
    public:

       /*  Date();
         Date(int sd, int me, int hr, int dy, int mh, int yr);
        ~Date();*/

        void DisplayDate();
        void SetAdd(int sd, int me, int hr, int dy, int mh, int yr);
        bool Check();

};

class Node
        {
            public:

            unsigned int n;
            Date* date;

            Node* next;
            Node* prev;

            Node();

            void DisplayNode();
        };

class List
{
     private:

        Node* first = NULL;


    public:
       
        void Push(Node* temp);
        void GetFail();

        void Show_all();
        void Clear();
        void Task_12();
        void SetSystemDate();


};

List datetime;

Node::Node()
{
    date = new Date;

    cout<<"\n- ����������� Node -\n";
}



/////// ������ Date ////////

void Date::SetAdd(int sd, int me, int hr, int dy, int mh, int yr)
{
    second = sd;
    minute = me;
    hour   = hr;
    day    = dy;
    month = mh;
    year   = yr;
}

void Date::DisplayDate()
{
    cout<<second<<":"<<minute<<":"<<hour
        <<"  "<<day<<"."<<month<<"."<<year;
}

bool Date::Check()
{
    if( day%2 )
    {
        return true;
    }
    else
    {
        return false;
    }
}


void Node::DisplayNode()
{

    cout<<n<<".\t";  date->DisplayDate();  // ������� ����


        cout<<"\t";

    if(next != NULL)                     // ������� ����. ����               
    {   
        next->date->DisplayDate();
    }
    else
    {
        cout<<"__"<<":"<<"__"<<":"<<"__"
        <<"  "<<"__"<<"."<<"__"<<"."<<"__";
    }
        cout<<"\t";


    if(prev != NULL)                  // ������� ����. ����    
    {
        prev->date->DisplayDate();
    }
    else
    {
        cout<<"__"<<":"<<"__"<<":"<<"__"
        <<"  "<<"__"<<"."<<"__"<<"."<<"__";
    }
        
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

void List::GetFail()
{
    ifstream fin("INPUT.txt");

    Node* temp;
    int sd, me, hr, dy, mh, yr;
    
    while(!fin.eof())
    {
        temp = new Node;

        fin >> sd;
        fin >> me;
        fin >> hr;
        fin >> dy;
        fin >> mh;
        fin >> yr;

        temp->date->SetAdd(sd,me,hr,dy,mh,yr);
        
        Push(temp); 
        
    }

    fin.close();
}

void List::Show_all()
{

    if(!first) 
    {
        cout<<"\n *  ������ ����   * \n";
        return;
    }

    Node* temp = first;

    cout<<"\n-----------------------------------------------------------------------------";
    cout<<"\n             ����            |     ��������� ����    |    ���������� ����    |\n";
    cout<<"-----------------------------------------------------------------------------\n";

    do
    {

        temp->DisplayNode();
        temp = temp->next;

    } while(temp);

    cout<<endl;


}

void List::Task_12()
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
       if(temp->next != NULL && temp->date->Check() && temp->next->date->Check() )
       {
           if(!flag)
           {
            cout<<"\n------------------------------------------------------------------------------------";
            cout<<"\n          ����             |       ��������� ����       |       ���������� ����     |\n";
            cout<<"-------------------------------------------------------------------------------------\n";
           }

            temp->DisplayNode();

            flag = 1;
       }

       temp = temp->next;

    } while (temp);
    
    if(!flag) cout<<"\n * ������ �� �������. ";

}

void List::SetSystemDate()
{
    SYSTEMTIME st;  // ����� �������� ���������� �������

    Node* temp = new Node;
    GetLocalTime(&st);  // ������ �������
    // �������������� ������

    temp->date->SetAdd(int(st.wSecond), int(st.wMinute), int(st.wHour), int(st.wDay), int(st.wMonth), int(st.wYear));

    Push(temp);

    cout<<"\n\n * ���� ";
    temp->date->DisplayDate();
    cout<<" ������� ���������.\n";
}

void List::Clear()
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
    
        free(temp->date);
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
            datetime.SetSystemDate();
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


