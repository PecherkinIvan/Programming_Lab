#include <iostream>
#include <math.h>

#include "LibShapes.h" 
#include "LibCylinder.h"

using namespace std;


Cylinder* Select_Figure();
double Select_Height();

int main()
{
    system("chcp 1251"); system("cls");
   
    double V;
    Cylinder* Cyl;

    Cyl = Select_Figure();
    

    V = Cyl->CalcValume(); 
    cout<<endl<<"\n ����� ������ = "<<V<<endl;

    delete Cyl;
    
    return 0;
}




double Select_Height()
{
    cout<<"\n ������� ������ ������: ";
    double h; cin>>h;

    return h;
}

Cylinder* Select_Figure()
{
    Cylinder* Cyl;
    Figure* figure;
    short int v;

    cout<<"\n    __ �������� ������ __"
        <<"\n\n 1.) �����������"
        <<"\n 2.) ����"
        <<"\n 3.) ���������� ������"
        <<"\n\n #>";

    cin>> v;
  
    if( v == 1)
    {
        double a,b,c;
        cout<<"\n\n ������� ������� ������������\n";
        cin>> a >> b >> c;

        try
        {
            figure = new Triangle(a,b,c);
            Cyl = TringleCylinder::CreateInstance(static_cast<Triangle*>(figure), Select_Height());
        }
        catch(const char* e)
        {
            cout<<endl<<endl<< e;
            exit(1);
        }
        catch (...) 
        {	
	        cout << "Catch ...:" << "����������� ������" << endl;			    
	        exit(1);
	    }
        
        
    }
    if( v == 2)
    {
        double r;
        cout<<"\n\n ������� ������ �����\n";
        cin>> r;

        try
        {
            figure = new Circle(r);
            Cyl = CircleCylinder::CreateInstance(static_cast<Circle*>(figure), Select_Height());
        }
        catch(const char* e)
        {
            cout<<endl<<endl<< e;
            exit(1);
        }
        catch (...) 
        {	
	        cout << "Catch ...:" << "����������� ������" << endl;			    
	        exit(1);
	    }

    }
    if( v == 3 )
    {
        double d;
        cout<<"\n\n ������� ������ ��������� ����\n";
        cin>> d;

        try
        {
            figure = new Star(d);
            Cyl = StarCylinder::CreateInstance(static_cast<Star*>(figure), Select_Height());
        }
        catch(const char* e)
        {
            cout<<endl<<endl<< e;
            exit(1);
        }
        catch (...) 
        {	
	        cout << "Catch ...:" << "����������� ������" << endl;			    
	        exit(1);
	    }
    }

    delete figure;

    return Cyl;
}
