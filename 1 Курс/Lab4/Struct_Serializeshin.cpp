#include <iostream>
#include <fstream>
using namespace std;

struct Laptops
{
    char* data;
    int size;
    Laptops* next;  

    void Show();
};
    Laptops* First;


Laptops* Serializtion(string name, float c, double  d, float w )
{
    Laptops* temp = new Laptops;

    size_t s=name.size(); 
    int n0 = sizeof(size_t);
    int n1 = s;      
    int n2 = sizeof(float);   
    int n3 = sizeof(double); 
    int n4 = sizeof(float);   

    temp->size = n0+n1+n2+n3+n4;

    char* data = new char[temp->size];  

    char* d0=reinterpret_cast<char*>(&s); 
    char* d1=const_cast<char*>(name.c_str());
    char* d2=reinterpret_cast<char*>(&c);
    char* d3=reinterpret_cast<char*>(&d);
    char* d4=reinterpret_cast<char*>(&w);

    for(int i=0; i<n0; i++) data[i]=d0[i];   
    for(int i=0; i<n1; i++) data[i+n0]=d1[i];  
    for(int i=0; i<n2; i++) data[i+n0+n1]=d2[i];
    for(int i=0; i<n3; i++) data[i+n0+n1+n2]=d3[i];
    for(int i=0; i<n4; i++) data[i+n0+n1+n2+n3]=d4[i];

    temp->data = data;

    return temp;
}

void Push(Laptops* temp)
{
// Функция добавления элемента по принципу очереди
    if(First == NULL)   
    {
        //First = new Laptops;
        First = temp;
        First->next = NULL;
    }
    
    else
    {
        Laptops* temp1 = First;

        while (temp1->next != NULL){
            temp1 = temp1->next;
        }

        temp1->next = temp;
        temp1->next->next = NULL;
    }

}

bool InputBinaryFile()
{
    fstream f_in("out.dat", ios::in | ios::binary);
    if(!f_in)
    {
        cout<<"\n -->Error!\n";
        return false;
    }

    int n;
    Laptops* C;

    while(!f_in.eof())
    {
        if(f_in.read((char*)&n, sizeof(int)) )
        {
            C = new Laptops;
            C->data = new char[n];
            f_in.read(C->data, n);
            C->size = n;
            Push(C);

        }
    }
    f_in.close();
    return true;
}

void GetNode()
{
// Добавление элемента и его сериализация
    system("cls");

    string name;
    float cost, weight;
    double dioganal;

    cout<<"\n\nВведите название товара: "; 
    cin>> name;
    cout<<"\nВведите цену: ";
    cin>> cost;
    cout<<"\n\nВведите диоганаль: "; 
    cin>> dioganal;
    cout<<"\nВведите вес: ";
    cin>> weight;
 
    Push( Serializtion(name, cost, dioganal, weight) );

}

void Pop_Node()
{
// Удаление элемента и перестановка элементов
    
    cout<<"\n\n Введите номер товара: ";
    int q; cin>>q; 
    
    if(q<1){    //Для ложных значений
        cout<<"\n  * Ошибка!"; 
        return; }

    Laptops* temp = First;
    Laptops* temp1;

    for(int p=q; p>1; p--)  // Прверка на максимальынй номер
    {
        if(temp->next == NULL ){cout<<"  * Ошибка!"; return; }
        temp = temp->next;
    }


    while (q>1)  // Переношу элементы и останавливаюсь на искомом 
    {
        temp = First;
        First = temp->next;
        Push(temp);
        q--;
    }
    // Когда остановились на искомом удаляем
    temp = First;
    First = temp->next;

    delete [] temp->data;
    free(temp);
}

void Laptops::Show()
{
// Десериализация и отображение одного элемента
    int n0,n1,n2,n3,n4;
    n0 = sizeof(size_t);
    n2 = sizeof(float);   
    n3 = sizeof(double); 
    n4 = sizeof(float);   
    
    size_t p=*reinterpret_cast<size_t*>(data);
    n1 = p;

    string ss(data+n0, p); 
   
    cout<<" Имя: "<<ss
        <<"\t\tцена: "<<*reinterpret_cast<float*>(data+n0+n1)<<" руб."
        <<"\t\tдиоганаль: "<<*reinterpret_cast<double*>(data+n0+n1+n2)<<"'"
        <<"\t\tвес: "<<*reinterpret_cast<float*>(data+n0+n1+n2+n3)<<" кг.";
}

void Show()
{
// Отображение всех элментов очереди
    Laptops* temp = First;
    unsigned int k=1;

    if(First == NULL){
        cout<<" * Очередь пустая.";
        return;
    }

    else
    {
        
        while( temp != NULL)
        {
            cout<<endl<<k<<".)   ";
            temp->Show();
            temp = temp->next;
            k++;
        }
    }

}

void Clear()
{
// Очестка очереди

    if(First == NULL){
        cout<<"\n * Очередь уже пустая.";
        return; }

    Laptops* temp = First;

    while ( First != NULL)
    {
        temp = First;
        First = temp->next;
    
        delete [] temp->data;
        free(temp);
    }
    
}

void Menu()
{
    cout<<"\n  _______________________________________";
    cout<<"\n |                                       ||";
    cout<<"\n |        ** Выбирите операцию **        ||";
    cout<<"\n |  1.) Добавить элемент                 ||";
    cout<<"\n |  2.) Вытащить элемент                 ||";
    cout<<"\n |  3.) Очистить очередь                 ||";
    cout<<"\n |  4.) Отобразить склад                 ||";
    cout<<"\n |  0.) Выйти                            ||";
    cout<<"\n |_______________________________________||";
    cout<<"\n > ";
    int point; cin>>point;

    switch (point){
    case 1:
    {
        system("cls");
        GetNode();
        Menu();
        break;
    }

    case 2:
    {
        Show();
        Pop_Node();
        Show();
        Menu();
        break;
    }

    case 3:
    {
        system("cls");
        Clear();
        Menu();
        break;
    }

    case 4:
    {
        system("cls");
        Show();
        Menu();
        break;
    }

    case 0:
        {
           //exit(1);
           return;
            break;
        }
        
    
    default:
        cout<<"\n Выбирите другую цифру \n";
      
    }
}


int main()
{
    system ("chcp 1251"); system("cls"); 
    InputBinaryFile();

    Menu(); 
  
    return 0;
}