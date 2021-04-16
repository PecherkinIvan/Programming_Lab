#include <iostream>
#include <fstream>        /// 8.) �������
using namespace std;

struct DATA { string name; float cost; double dioganal; float weight; };

struct Node
{
    DATA data;
    Node* next;
};
Node* top = NULL;

void Scan_Stack()
{
    ifstream fin("DATA.txt");

    int line = 0; // ������� ������
    while ( !fin.eof() )
    {
        if (fin.get() == '\n') line++;
    }
    fin.clear(); // ������� ������� �� ������
    fin.seekg(0);

    cout<<" ���������� �����: "<< line;

    for (line; line>0 ; line--)
    {
        Node* temp = new Node;
        fin>>temp->data.name;      fin>> temp->data.cost; 
        fin>> temp->data.dioganal;  fin>>  temp->data.weight;

        temp->next = top;
        top = temp;
    }

    fin.close();
}

void Show()
{
    if(top == NULL){
        cout << "\n ���� ����" << endl; 
        return;
    }

    else {
        Node* temp = top;
		cout << "\n\n������� ����: \n";
		while (temp != NULL) 
        {
			cout << temp->data.name <<"    ";
            cout << temp->data.cost <<" ���.   ";
            cout << temp->data.dioganal << "' (������)   ";
            cout << temp->data.weight <<"��."<< endl;

			temp = temp->next;
		}
	}
}

void PushTop()
{
    Node* temp = new Node;

    cout<<"������� ������ ��������: "<<endl;
        cout<<"��� ��������: "; cin>>temp->data.name;
         cout<<"����: "; cin>>temp->data.cost;
          cout<<"���������: "; cin>>temp->data.dioganal;
           cout<<"���: "; cin>>temp->data.weight;

        temp->next = top;
        top = temp;

}

void PullNode(string name)
{
    if (top == NULL) {
		cout << "\n ���� ����" << endl;  
        return;
	}
    else
    {
        Node* temp;  // temp ��� ��������� �� ������� �������
        temp = top; 
           
        while ( (temp->data.name)!=name && temp!=NULL) 
        {  // ������ ������� ������� (name - �������)
            temp = temp->next; 
        }

        if(temp == top)  // ���������� ��� �������� ��������
        {
            top = top->next;
            temp->next = NULL;
            free(temp);
            return;
        }

        Node* temp1 = top;
        while (temp1 != NULL)  
        {
            if( (temp1->next) == temp ) 
            {
              temp1->next = temp->next; // ������������ ����� ������� (������ temp ��� temp->next)
              temp->next = NULL;   // ��������� ����� ��� ���������� ����
              free(temp);        // ����������� ������ ����
            }
            else temp1 = temp1->next;
        }
    }

}

void Clear()
{
    Node* temp;

    if (top == NULL){
        cout<< "\n ���� ��� ����" << endl;
        return;
    }
    else {
        temp = top;
        while (temp != NULL)
        {
            top = top->next;
            temp->next = NULL;
            free(temp);
            temp = top;
        }
        cout<< "\n ���� ������"<<endl;
    }
}

void Select()
{
    cout<<"\n  _______________________________________";
    cout<<"\n |                                       ||";
    cout<<"\n |        ** �������� �������� **        ||";
    cout<<"\n |  1.) �������� ����� � �������         ||";
    cout<<"\n |  2.) �������� ����� �� �������        ||";
    cout<<"\n |  3.) �������� �������                 ||";
    cout<<"\n |  0.) �����                            ||";
    cout<<"\n |_______________________________________||";
    cout<<"\n > ";
    int point;
    cin>>point;

    switch(point) {
        case 1:
        {
          PushTop();
           Show();
           Select();
              break;
        }      

         case 2:   
        {
          string name;
          cout<<"\n ������� ��� ���������� ������: ";
          cin>>name;

          PullNode(name);
           Show();
            Select();
             break;
        }

         case 3:
        {
          Clear();
           Show();
            Select();
            break;
        }

        case 0:
        {
           exit(1);
            break;
        }
        
        default:
        {
             cout<<"\n �������� ������ ����� \n";
             Select();
        }

    }

}

int main ()
{
    system ("chcp 1251");
    Scan_Stack();

    Show();
    Select();

    return 0;
}
