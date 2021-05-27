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
        <<"\n |        ** �������� �������� **         ||"
        <<"\n |  1.) �������� �������                  ||"
        <<"\n |  2.) ������� �������                   ||"
        <<"\n |  3.) ����������� �������� �������      ||"
        <<"\n |  4.) �������� ������                   ||"
        <<"\n |  5.) ��������� ������ �� ������ � ���� ||"
        <<"\n |  6.) ���������� ������                 ||"
        <<"\n |  0.) �����                             ||"
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
                cout<<"\n * ������ ��� ����\n";
                system("pause");
                MENU();
            }

             break;
        }

         case 3:
        {
            cout<<"\n   ��� ��c���������� ������?";
            cout<<"\n\n 1.) �� ��������";
            cout<<"\n 2.) �� ����";
            cout<<"\n 3.) �� ����";
            cout<<"\n 4.) �� ��������";
            cout<<"\n  >";

            int p; cin>>p;

            if( p==2 || p==3 || p==4)
            {
                cout<<"\n\n 1.) �� ��������";
                cout<<"\n 2.) �� �����������";
                cout<<"\n  >";

                short int p1; cin>>p1;
                if(p1==1 || p1==2)
                  List.Sort(p, p1);
                else {cout<<"\n * ������"; MENU();}

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
                    cout<<"\n * ������\n";
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
            cout<<"\n * ������";
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
        <<"\n |        ** �������� ������� **          ||"
        <<"\n |  1.) � ������                          ||"
        <<"\n |  2.) � �����                           ||"
        <<"\n |  3.) �� k-�� �������                   ||"
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
            cout<<"\n �������� k: ";
            unsigned int k;
            cin>>k; 
            system("cls");

            if( k<0 || k>(List.count) )
            {
                cout<<"\n * �� ����� �� ������ ��������\n";
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
        <<"\n |        ** ������� ������� **           ||"
        <<"\n |  1.) � ������                          ||"
        <<"\n |  2.) � ������                          ||"
        <<"\n |  3.) �� k-�� �������                   ||"
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
            cout<<"\n �������� k: ";
            unsigned int k;
            cin>>k; 

            if( k<0 || k>(List.count) )
            {
                cout<<"\n * �� ����� �� ������ ��������\n";
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
        <<"\n |     ** ��� ������������� ������? **    ||"
        <<"\n |  1.) �� �������                        ||"
        <<"\n |  2.) �� ����                           ||"
        <<"\n |  3.) �� ����                           ||"
        <<"\n |  4.) �� ��������                       ||"
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

    cout<<"\n ������� ���: ";
    cin>>new_data.name;
    cout<<"\n ������� ����: ";
    cin>>new_data.cost;
    cout<<"\n ������� ���: ";
    cin>>new_data.weight;
    cout<<"\n ������� �������: ";
    cin>>new_data.diameter;

    return new_data;
}
