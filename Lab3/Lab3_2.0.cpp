#include <iostream>
#include <fstream>
using namespace std;


struct Node {
    
    string name;
    int volume;
    float cost;
    Node* next;
};
    Node* First;


void Show()
{
    if (First == NULL)
		cout << "\n --**-- ����� ���� --**--" << endl;
	
    else
    {
        Node* temp;
        temp = First;

        cout<<"\n\n__________��� �����___________\n\n";
        unsigned int k = 1;

        while (temp != NULL)
        {
            cout<<k<<".) "; k++;
            cout<< temp->name <<"  ";
            cout<< temp->volume <<" ��."<<"  ";
            cout<< temp->cost <<" ���. "<<endl;

            temp = temp->next; 
        }
      cout<<"_____________________________\n";
    }
}

void Push(string new_name, int new_volume, float new_cost)
{
    if(First == NULL)
    {
        First = new Node;
        First->next = NULL;
        First->name = new_name;
        First->volume = new_volume;
        First->cost = new_cost;
    }

    else
    {
        Node* temp;
        temp = First;
        while (temp->next != NULL)
		{
			temp = temp->next;
		}

        temp->next = new Node;
        temp->next->name = new_name;
        temp->next->volume = new_volume;
        temp->next->cost = new_cost;

        temp->next->next = NULL;

    }

}

void Pop(Node* temp)
{
	if (First == NULL) {
		cout << "\n * ��� ����� ����!" << endl;
        return;
	}
	else {

        if( First == temp)
         {
            temp = First->next;
            cout << "\n * ����� " << First->name << " ������." << endl;
            free(First);
            First = temp;
            return;
        }

		Node* temp1;
		temp1 = First;

        while (temp1 != NULL)
        {
            if (temp1->next == temp)
            {
                temp1->next = temp->next;
                cout << "\n * ����� " << temp->name << " ������." << endl;
                temp->next = NULL;
                free(temp);
            }
            temp1 = temp1->next;
        }
	}
}

void Get_Product()
{
    system ("cls");
    int k=0;
    
    Node* temp = new Node;

    cout<<"\n\n������� �������� ������: "; 
    cin>> temp->name;
    cout<<"������� ����������: ";
    cin>> temp->volume;

    Node* temp1 = First; // ���������� �����
    while (temp1 != NULL)
    {
        if( temp1->name == temp->name)
        {
            (temp1->volume) += temp->volume;
            cout<<"\n * ����� ����� ��� ���� �� ������, ��������� �������� �� "<< temp1->volume;
            Show();
            cout<<"\n �������� ��� ������� 1 >";
            cin>>k; if(k == 1) Get_Product();

            return;
        }
        temp1 = temp1->next; 
    }
    
    cout<<"������� ���������� ����: ";
    cin>> temp->cost;

    Push(temp->name,  temp->volume, temp->cost);
    cout<<"\n * ����� "<<temp->name<<" ��������";
    Show();
    cout<<"\n �������� ��� ������� 1 >";
    cin>>k; if(k == 1) Get_Product();


    system("cls");
}

void Sale(float& sold)
{
    Show();
    cout<<"\n 1.) ����� �� �����";
    cout<<"\n 2.) ����� �� ������\n";
    cout<<" >"; int k; cin>>k;

    if(k == 1)
    {
        cout<<"\n ������� ��� ������: ";
        string name; cin>>name;

        Node* temp;
        temp = First;
        bool flag=0;

       while (temp != NULL)
        {
            if( temp->name == name)
            {
                flag = 1;
                cout<<"\n ������� ���� �������: ";
                int i; cin>>i;
                if ( (temp->volume-i) >= 0){
                    temp->volume -= i;
                    cout<<"\n  + "<< i*(temp->cost*1.2) <<" ���."<< endl; //������� 20%
                    sold+= i*(temp->cost*1.2) - i*temp->cost;    //������� 20%
                }
                else cout<<"\n * ������� ������ ��� �� ������!";

                if (temp->volume == 0) Pop(temp);
            
            }
            temp = temp->next; 
        }
        if(!flag) cout<< "\n * ������ � ����� ������ ���!";
    }

    if(k == 2)
    {
        cout<<"\n ������� ����� ������: ";
        int q; cin>>q;
        if(q==0){cout<< "  * ������!"; return; }

        Node* temp = First;

        for(q; q>1; q--)  // ���������� �� ������ �������
        {
            if(temp->next == NULL ){cout<< "  * ������!"; return; }
            temp = temp->next;
        }

        cout<<"\n ������� ���� �������: ";
        int i; cin>>i;
        if ( (temp->volume-i) >= 0){
         temp->volume -= i;
         cout<<"\n  + "<< i*(temp->cost*1.2) <<" ���."<< endl; //������� 20%
         sold+= i*(temp->cost*1.2) - i*temp->cost;    //������� 20%
        }      
        else cout<<"\n * ������� ������ ��� �� ������!";

         if (temp->volume == 0) Pop(temp);
    }
}

void Scan_File()
{
    ifstream fin("DATA_K.txt");

    int line = 0;     // ������� ������
    while ( !fin.eof() )
    {
        if (fin.get() == '\n') line++;
    }
    fin.clear();    // ������� ������� �� ������
    fin.seekg(0);

    cout<<" ����������� �����: "<< line;

    for (line; line>0 ; line--)
    {
        Node* temp = new Node;
        fin >> temp->name; fin >> temp->volume; fin >> temp->cost; 

        Push(temp->name, temp->volume,  temp->cost);
    }

    fin.close();
    //systeam("cls");
} 

void Info(float& sold)
{
    Node* temp;
    temp = First; 
    unsigned int V=0;
    float S=0;

    while (temp != NULL)
    {
        V+= temp->volume;
        S+= temp->cost*temp->volume;
        temp = temp->next;
    }
    cout<<"\n ����� ����� ������ �� ������: "<<V;
    cout<<"   |    ����� ����� ���� �������: "<<S<<" ���.";
    cout<<"   |    ����� ������� � ������: " <<sold<<" ���.\n";
}

void Select(float& sold)
{
    cout<<"\n  _______________________________________";
    cout<<"\n |                                       ||";
    cout<<"\n |        ** �������� �������� **        ||";
    cout<<"\n |  1.) ����������� ������               ||";
    cout<<"\n |  2.) ������� ������                   ||";
    cout<<"\n |  3.) �����                            ||";
    cout<<"\n |  4.) ���������� �����                 ||";
    cout<<"\n |  0.) �����                            ||";
    cout<<"\n |_______________________________________||";
    cout<<"\n > ";
    int point;
    cin>>point;

    switch(point) {
        case 1:
        {
            Get_Product();
            Select(sold);
              break;
        }      

         case 2:   
        {
            Sale(sold);
            Select(sold);
             break;
        }

         case 3:
        {
           Info(sold);
           Select(sold);
            break;
        }

        case 4:
        {
            Show();
            Select(sold);
            break;
        }

        case 0:
        {
           exit(1);
            break;
        }
        
        default:
             cout<<"\n �������� ������ ����� \n";

    }


}

int main()
{
    system ("chcp 1251"); 
    float sold=0;
    Scan_File();
    Select(sold);

    return 0;
}