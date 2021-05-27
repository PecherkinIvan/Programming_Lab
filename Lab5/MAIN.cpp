#include "DLList.h"
#include <fstream>

void MENU();
void TaskOne();
void TaskTwo();
void TaskThree();
DATA GetData();
DLList List;

int main()
{
    system("chcp 1251"); system("cls");
    List.GetFail();

    MENU();
   
    return 0;
}

void MENU()
{

    cout<<"\n  ________________________________________"
        <<"\n |                                        ||"
        <<"\n |        ** Выбирите операцию **         ||"
        <<"\n |  1.) Добавить элемент                  ||"
        <<"\n |  2.) Удалить элемент                   ||"
        <<"\n |  3.) Упорядочить элементы очереди      ||"
        <<"\n |  4.) Очистить список                   ||"
        <<"\n |  5.) Выгрузить данные из списка в файл ||"
        <<"\n |  6.) Отобразить список                 ||"
        <<"\n |  0.) Выйти                             ||"
        <<"\n |________________________________________||"
        <<"\n  > ";

    int point;  cin>>point;

    switch(point) {
        case 1:
        {
            system("cls");

            TaskOne();
            MENU();

              break;
        }      

         case 2:   
        {
            system("cls");

            if(List.count>0)
            {
               List.Show();
               TaskTwo();
               MENU();
            }
            else{
                cout<<"\n * Список уже пуст\n";
                system("pause");
                MENU();
            }

             break;
        }

         case 3:
        {
            cout<<"\n   Как отcортировать список?";
            cout<<"\n\n 1.) По алфавиту";
            cout<<"\n 2.) По цене";
            cout<<"\n 3.) По весу";
            cout<<"\n 4.) По диаметру";
            cout<<"\n  >";

            int p; cin>>p;

            if( p==2 || p==3 || p==4)
            {
                cout<<"\n\n 1.) По убыванию";
                cout<<"\n 2.) По возрастанию";
                cout<<"\n  >";

                short int p1; cin>>p1;
                if(p1==1 || p1==2)
                  List.Sort(p, p1);
                else {cout<<"\n * Ошибка"; MENU();}

                List.Show();
                MENU();
            }

            switch(p) {

                case 1:
                {
                    List.SortAlfo();
                    List.Show();
                    MENU();
                    break;
                }   

                default:
                {
                    cout<<"\n * Ошибка\n";
                    system("pause");
                    system("cls");
                    MENU();
                    break;
                } 
            }

            break;
        }

        case 4:
        {
            List.Clear();
            MENU();
            break;
        }

        case 5:
        {
              
            List.GiveFail();
            MENU();
            break;
        }

        case 6:
        {
            system("cls");
            List.Show();
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
            cout<<"\n * Ошибка";
            system("cls");
            MENU();
            break;
        }

    }

}

void TaskOne()
{
    system("cls");
    List.Show();
    cout<<"\n  ________________________________________"
        <<"\n |                                        ||"
        <<"\n |        ** Добавить элемент **          ||"
        <<"\n |  1.) В начало                          ||"
        <<"\n |  2.) В конец                           ||"
        <<"\n |  3.) На k-ую позицию                   ||"
        <<"\n |________________________________________||"
        <<"\n  > ";

    int point;  cin>>point;

    switch(point) {
        case 1:
        {
            
            List.AddFirst(GetData());
            List.Show();
            

              break;
        }      

         case 2:
        {
            List.AddLast(GetData());
            List.Show();

              break;
        }  

        case 3:
        {
            List.Show();
            cout<<"\n Выбирете k: ";
            unsigned int k;
            cin>>k; 
            system("cls");

            if( k<0 || k>(List.count) )
            {
                cout<<"\n * Вы ввели не верное значение\n";
                system("pause");
                TaskOne();
            }

            List.MoveFirst();

            for(k; k>1; k--)
                List.MoveNext();
            
            List.AddPrev(GetData());
            List.Show();
            
              break;
        }  

    }

}

void TaskTwo()
{
    cout<<"\n  ________________________________________"
        <<"\n |                                        ||"
        <<"\n |        ** Удалить элемент **           ||"
        <<"\n |  1.) В начале                          ||"
        <<"\n |  2.) В конеце                          ||"
        <<"\n |  3.) На k-ой позиции                   ||"
        <<"\n |________________________________________||"
        <<"\n  > ";

    int point;  cin>>point;

    switch(point) {
        case 1:
        {
            List.DelFirst();
            List.Show();
            
              break;
        }      

        case 2:
        {
            List.DelLast();
            List.Show();
            
              break;
        }   
        case 3:
        {
            cout<<"\n Выбирете k: ";
            unsigned int k;
            cin>>k; 

            if( k<0 || k>(List.count) )
            {
                cout<<"\n * Вы ввели не верное значение\n";
                system("pause");
                TaskTwo();
            }

            List.MoveFirst();

            for(k; k>1; k--)
                List.MoveNext();

            List.DelCurrent();
            List.Show();
            
              break;
        }  

    }    
}

void TaskThree()
{
    system("cls");

    cout<<"\n  ________________________________________"
        <<"\n |                                        ||"
        <<"\n |     ** Как отсортировать список? **    ||"
        <<"\n |  1.) По алфвиту                        ||"
        <<"\n |  2.) По цене                           ||"
        <<"\n |  3.) По весу                           ||"
        <<"\n |  4.) По диаметру                       ||"
        <<"\n |________________________________________||"
        <<"\n  > ";

    int point;  cin>>point;

    switch(point) {
        case 1:
        {
            List.DelFirst();
            List.Show();
            
              break;
        }      

    }
}

DATA GetData()
{
    system("cls");
    DATA new_data;

    cout<<"\n Введите имя: ";
    cin>>new_data.name;
    cout<<"\n Введите цену: ";
    cin>>new_data.cost;
    cout<<"\n Введите вес: ";
    cin>>new_data.weight;
    cout<<"\n Введите диаметр: ";
    cin>>new_data.diameter;

    return new_data;
}
