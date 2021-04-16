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
		cout << "\n --**-- Склад пуст --**--" << endl;
	
    else
    {
        Node* temp;
        temp = First;

        cout<<"\n\n__________Ваш склад___________\n\n";
        unsigned int k = 1;

        while (temp != NULL)
        {
            cout<<k<<".) "; k++;
            cout<< temp->name <<"  ";
            cout<< temp->volume <<" шт."<<"  ";
            cout<< temp->cost <<" руб. "<<endl;

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
		cout << "\n * Ваш склад пуст!" << endl;
        return;
	}
	else {

        if( First == temp)
         {
            temp = First->next;
            cout << "\n * Товар " << First->name << " удален." << endl;
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
                cout << "\n * Товар " << temp->name << " удален." << endl;
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

    cout<<"\n\nВведите название товара: "; 
    cin>> temp->name;
    cout<<"Введите количество: ";
    cin>> temp->volume;

    Node* temp1 = First; // Однотипный товар
    while (temp1 != NULL)
    {
        if( temp1->name == temp->name)
        {
            (temp1->volume) += temp->volume;
            cout<<"\n * Такой товар уже есть на складе, количесво изменено на "<< temp1->volume;
            Show();
            cout<<"\n Добавить ещё введите 1 >";
            cin>>k; if(k == 1) Get_Product();

            return;
        }
        temp1 = temp1->next; 
    }
    
    cout<<"Введите закупочную цену: ";
    cin>> temp->cost;

    Push(temp->name,  temp->volume, temp->cost);
    cout<<"\n * Товар "<<temp->name<<" добавлен";
    Show();
    cout<<"\n Добавить ещё введите 1 >";
    cin>>k; if(k == 1) Get_Product();


    system("cls");
}

void Sale(float& sold)
{
    Show();
    cout<<"\n 1.) Найти по имени";
    cout<<"\n 2.) Найти по номеру\n";
    cout<<" >"; int k; cin>>k;

    if(k == 1)
    {
        cout<<"\n Введите имя товара: ";
        string name; cin>>name;

        Node* temp;
        temp = First;
        bool flag=0;

       while (temp != NULL)
        {
            if( temp->name == name)
            {
                flag = 1;
                cout<<"\n Сколько штук продать: ";
                int i; cin>>i;
                if ( (temp->volume-i) >= 0){
                    temp->volume -= i;
                    cout<<"\n  + "<< i*(temp->cost*1.2) <<" руб."<< endl; //Наценка 20%
                    sold+= i*(temp->cost*1.2) - i*temp->cost;    //Наценка 20%
                }
                else cout<<"\n * Столько товара нет на складе!";

                if (temp->volume == 0) Pop(temp);
            
            }
            temp = temp->next; 
        }
        if(!flag) cout<< "\n * Товара с таким именем нет!";
    }

    if(k == 2)
    {
        cout<<"\n Введите номер товара: ";
        int q; cin>>q;
        if(q==0){cout<< "  * Ошибка!"; return; }

        Node* temp = First;

        for(q; q>1; q--)  // Сдвигаемся на нужный элемент
        {
            if(temp->next == NULL ){cout<< "  * Ошибка!"; return; }
            temp = temp->next;
        }

        cout<<"\n Сколько штук продать: ";
        int i; cin>>i;
        if ( (temp->volume-i) >= 0){
         temp->volume -= i;
         cout<<"\n  + "<< i*(temp->cost*1.2) <<" руб."<< endl; //Наценка 20%
         sold+= i*(temp->cost*1.2) - i*temp->cost;    //Наценка 20%
        }      
        else cout<<"\n * Столько товара нет на складе!";

         if (temp->volume == 0) Pop(temp);
    }
}

void Scan_File()
{
    ifstream fin("DATA_K.txt");

    int line = 0;     // Считает строки
    while ( !fin.eof() )
    {
        if (fin.get() == '\n') line++;
    }
    fin.clear();    // Возврат курсора на начало
    fin.seekg(0);

    cout<<" Колличество строк: "<< line;

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
    cout<<"\n Общее число товара на складе: "<<V;
    cout<<"   |    Общая сумма всех товаров: "<<S<<" руб.";
    cout<<"   |    Общая прибыль с продаж: " <<sold<<" руб.\n";
}

void Select(float& sold)
{
    cout<<"\n  _______________________________________";
    cout<<"\n |                                       ||";
    cout<<"\n |        ** Выбирите операцию **        ||";
    cout<<"\n |  1.) Поступление товара               ||";
    cout<<"\n |  2.) Продажа товара                   ||";
    cout<<"\n |  3.) Отчет                            ||";
    cout<<"\n |  4.) Отобразить склад                 ||";
    cout<<"\n |  0.) Выйти                            ||";
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
             cout<<"\n Выбирите другую цифру \n";

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