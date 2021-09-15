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
        <<"\n |        ** �������� �������� **                                                ||"
        <<"\n |  1.) ����������� ������ �� �������� �� ���������� ����                        ||"
        <<"\n |  2.) ����������� ������ �� �������� �� ��������� ����.                        ||"
        <<"\n |  3.) ������� ���������� � ���� ��������, ��� ������� �������� ��������� ����  ||"
        <<"\n |      ����� ������ ��������� ������������� ��������                            ||"
        <<"\n |  4.) ������� ���������� � ���� ��������, ��� ������� �������� ����������      ||"
        <<"\n |      ���� ���������� � �������� ������������� �����                           ||"
        <<"\n |  0.) �����                                                                    ||"
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
            cout<<"\n * ������. ";
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

     cout<<"\n  1.) ������������� �� ��������"
         <<"\n  2.) ������������� �� ������"
         <<"\n  0.) ���������"                                                                                             
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
            cout<<"\n * ������  ";
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

     cout<<"\n  1.) ������������� �� ��������� �������"
         <<"\n  2.) ������������� �� ���� ����������"
         <<"\n  0.) ���������"                                                                                             
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
            cout<<"\n * ������  ";
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

    cout<<"\n  1.) ��������� ������� "
        <<"\n  2.) ���� �������"
        <<"\n  0.) ���������"
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
            cout<<"\n * ������  ";
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

     cout<<"\n  1.) ������������"
         <<"\n  2.) �����"
         <<"\n  0.) ���������"                                                                                             
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
            cout<<"\n * ������  ";
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

    cout<<"\n  ** ������� ����� **"                                                                                         
         <<"\n  > ";
    cin>>p;

    return p;
}

int SelectngValue(Tree*& T)
{
    int p;

    cout<<"\n  ** ������� �������� **"                                                                                         
         <<"\n  > ";
    cin>>p;

    return p;
}