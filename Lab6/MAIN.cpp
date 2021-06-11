#include "LibTree.h"

void MENU(Tree*&);
int Menu1(Tree*&);
int Menu2(Tree*&);
int Menu3(Tree*&);
int Menu4(Tree*&);
char SelectingLetter(Tree*&);
int  SelectngValue(Tree*&);


int main()
{
    system("chcp 1251"); 
    system("cls");

    Tree* T = NULL;
 
    MENU(T);


    return 0;
}

void MENU(Tree*& T)
{
    cout<<"\n  ________________________________________________________________________________"
        <<"\n |                                                                               ||"
        <<"\n |        ** Выбирите операцию **                                                ||"
        <<"\n |  1.) Упорядочить данные об объектах по строковому полю                        ||"
        <<"\n |  2.) Упорядочить данные об объектах по числовому полю.                        ||"
        <<"\n |  3.) Вывести информацию о всех объектах, для которых значение числового поля  ||"
        <<"\n |      будет меньше заданного пользователем значения                            ||"
        <<"\n |  4.) Вывести информацию о всех объектах, для которых значение строкового      ||"
        <<"\n |      поля начинается с заданной пользователем буквы                           ||"
        <<"\n |  0.) Выйти                                                                    ||"
        <<"\n |_______________________________________________________________________________||"
        <<"\n  > ";

    short int point;  cin>>point;

    switch(point) {
        case 1:
        {
            Delete(T);

            GetFail(T, Menu1(T));
            PrintLRR(T);
            MENU(T);
              break;
        }      

         case 2:   
        {
            Delete(T);

            GetFail(T, Menu2(T));
            PrintLRR(T);
            
            MENU(T);
             break;
        }

        case 3:   
        {
            if(!T)
            {
                Delete(T);
                GetFail(T, -1);
            }

            PrintVelue(T, SelectngValue(T), Menu3(T));
            
            MENU(T);
             break;
        }

        case 4:   
        {
           if(!T)
            {
                Delete(T);
                GetFail(T, 1);
            } 

           PrintLetter(T, SelectingLetter(T), Menu4(T));
            
            MENU(T);
             break;
        }

           

        case 0:
        {
            exit(1);
            break;
        }
        
        default:
        {
            cout<<"\n * Ошибка. ";
            system("pause");
            system("cls");
            MENU(T);
            break;
        }

    }
}

int Menu1(Tree*& T)
{
    short int p;            

     cout<<"\n  1.) Отсортировать по названию"
         <<"\n  2.) Отсортировать по автору"
         <<"\n  0.) Вернуться"                                                                                             
         <<"\n  > ";
    cin>>p;

    switch (p)
    {
        case 1:   
        {
            return 1;
             break;
        }

        case 2:   
        {
            return 2;
             break;
        }

        case 0:   
        {
            system("cls");
            MENU(T);
             break;
        }
    
        default:
        {
            cout<<"\n * Ошибка  ";
            system("pause");
            system("cls");
            MENU(T);
            break;
        }
    }
}

int Menu2(Tree*& T)
{
    short int p;            

     cout<<"\n  1.) Отсортировать по количесву страниц"
         <<"\n  2.) Отсортировать по дате публикации"
         <<"\n  0.) Вернуться"                                                                                             
         <<"\n  > ";
    cin>>p;

    switch (p)
    {
        case 1:   
        {
            return -1;
             break;
        }

        case 2:   
        {
            return -2;
             break;
        }

        case 0:   
        {
            system("cls");
            MENU(T);
             break;
        }
    
        default:
        {
            cout<<"\n * Ошибка  ";
            system("pause");
            system("cls");
            MENU(T);
            break;
        }
    }
}

int Menu3(Tree*& T)
{
    short int p;

    cout<<"\n  1.) Количесво страниц "
        <<"\n  2.) Дата выпуска"
        <<"\n  0.) Вернуться"
        <<"\n > ";
    
    cin>>p;

     switch (p)
    {
        case 1:   
        {
            return 1;
             break;
        }

        case 2:   
        {
            return 2;
             break;
        }

        case 0:   
        {
            system("cls");
            MENU(T);
             break;
        }
    
        default:
        {
            cout<<"\n * Ошибка  ";
            system("pause");
            system("cls");
            MENU(T);
            break;
        }
    }

}

int Menu4(Tree*& T)
{
    short int p;            

     cout<<"\n  1.) Наименование"
         <<"\n  2.) Автор"
         <<"\n  0.) Вернуться"                                                                                             
         <<"\n  > ";
    cin>>p;

     

    switch (p)
    {
        case 1:   
        {
            return 1;
             break;
        }

        case 2:   
        {
            return 2;
             break;
        }

        case 0:   
        {
            system("cls");
            MENU(T);
             break;
        }
    
        default:
        {
            cout<<"\n * Ошибка  ";
            system("pause");
            system("cls");
            MENU(T);
            break;
        }
    }
}

char SelectingLetter(Tree*& T)
{
    char p;            

    cout<<"\n  ** Введите букву **"                                                                                         
         <<"\n  > ";
    cin>>p;

    return p;
}

int SelectngValue(Tree*& T)
{
    int p;

    cout<<"\n  ** Введите значение **"                                                                                         
         <<"\n  > ";
    cin>>p;

    return p;
}