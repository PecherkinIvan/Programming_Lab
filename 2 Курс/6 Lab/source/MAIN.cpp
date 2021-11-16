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
    cout<<endl<<"\n Обьем фигуры = "<<V<<endl;

    delete Cyl;
    
    return 0;
}




double Select_Height()
{
    cout<<"\n Введите высоту фигуры: ";
    double h; cin>>h;

    return h;
}

Cylinder* Select_Figure()
{
    Cylinder* Cyl;
    Figure* figure;
    short int v;

    cout<<"\n    __ Выбирете фигуру __"
        <<"\n\n 1.) Треугольник"
        <<"\n 2.) Круг"
        <<"\n 3.) Правильная звезда"
        <<"\n\n #>";

    cin>> v;
  
    if( v == 1)
    {
        double a,b,c;
        cout<<"\n\n Введите стороны треугольника\n";
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
	        cout << "Catch ...:" << "Неизвестная ошибка" << endl;			    
	        exit(1);
	    }
        
        
    }
    if( v == 2)
    {
        double r;
        cout<<"\n\n Введите радиус круга\n";
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
	        cout << "Catch ...:" << "Неизвестная ошибка" << endl;			    
	        exit(1);
	    }

    }
    if( v == 3 )
    {
        double d;
        cout<<"\n\n Введите длинну основания луча\n";
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
	        cout << "Catch ...:" << "Неизвестная ошибка" << endl;			    
	        exit(1);
	    }
    }

    delete figure;

    return Cyl;
}
