#include <iostream>
#include <fstream>        /// 8.) Ноутбук
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

    int line = 0; // Считает строки
    while ( !fin.eof() )
    {
        if (fin.get() == '\n') line++;
    }
    fin.clear(); // Возврат курсора на начало
    fin.seekg(0);

    cout<<" Количество строк: "<< line;

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
        cout << "\n Стек пуст" << endl; 
        return;
    }

    else {
        Node* temp = top;
		cout << "\n\nТекущий стек: \n";
		while (temp != NULL) 
        {
			cout << temp->data.name <<"    ";
            cout << temp->data.cost <<" руб.   ";
            cout << temp->data.dioganal << "' (дюймов)   ";
            cout << temp->data.weight <<"кг."<< endl;

			temp = temp->next;
		}
	}
}

void PushTop()
{
    Node* temp = new Node;

    cout<<"Введите данные элемента: "<<endl;
        cout<<"Имя ноутбука: "; cin>>temp->data.name;
         cout<<"Цена: "; cin>>temp->data.cost;
          cout<<"Диоганаль: "; cin>>temp->data.dioganal;
           cout<<"Вес: "; cin>>temp->data.weight;

        temp->next = top;
        top = temp;

}

void PullNode(string name)
{
    if (top == NULL) {
		cout << "\n Стек пуст" << endl;  
        return;
	}
    else
    {
        Node* temp;  // temp это указатель на искомый элемент
        temp = top; 
           
        while ( (temp->data.name)!=name && temp!=NULL) 
        {  // Нахожу искомый элемент (name - элемнта)
            temp = temp->next; 
        }

        if(temp == top)  // Исключение для верхнего элемента
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
              temp1->next = temp->next; // перескакиваю через элемент (вместо temp это temp->next)
              temp->next = NULL;   // разрушаем связь для удаляемого узла
              free(temp);        // освобождаем память узла
            }
            else temp1 = temp1->next;
        }
    }

}

void Clear()
{
    Node* temp;

    if (top == NULL){
        cout<< "\n Стек уже пуст" << endl;
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
        cout<< "\n Стек очищен"<<endl;
    }
}

void Select()
{
    cout<<"\n  _______________________________________";
    cout<<"\n |                                       ||";
    cout<<"\n |        ** Выбирите операцию **        ||";
    cout<<"\n |  1.) Добавить товар в корзину         ||";
    cout<<"\n |  2.) Вытащить товар из корзины        ||";
    cout<<"\n |  3.) Очистить корзину                 ||";
    cout<<"\n |  0.) Выйти                            ||";
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
          cout<<"\n Введите имя удаляемого товара: ";
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
             cout<<"\n Выбирите другую цифру \n";
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
