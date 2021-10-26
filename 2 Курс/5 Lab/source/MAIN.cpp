#include <iostream>
#include <math.h>

#include "LibShapes.h"

using namespace std;


class Cylinder
{
    private:

        Figure* f;
        double h;

    public:

        Cylinder(double, Figure*);

        double CalcValume();
    
};


Cylinder::Cylinder(double new_h, Figure* new_f)
{
    h = new_h;
    f = new_f->GetType();

}

double Cylinder::CalcValume()
{
    return h *(f->Calc_Square());
}



Figure* Select_Figure();

int main()
{
    system("chcp 1251"); system("cls");

    double S;
    Figure* f;
    Cylinder* c;

    f = Select_Figure();

    
    cout<<"\n Введите высоту фигуры: ";
    double h; cin>>h;

    c = new Cylinder(h, f);

    delete f;
    // f = new Circle(1); // Для примера, изменяю данные первичного указателя.


    S = c->CalcValume(); 
    cout<<endl<<"\n Обьем фигуры = "<<S<<endl;
    

    return 0;
}

Figure* Select_Figure()
{
    Figure* f;
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

        f = new Triangle(a,b,c);
       
    }
    if( v == 2)
    {
        double r;
        cout<<"\n\n Введите радиус круга\n";
        cin>> r;

        f = new Circle(r);
        
    
    }
    if( v == 3 )
    {
        double d;
        cout<<"\n\n Введите длинну основания луча\n";
        cin>> d;

        f = new Star(d);
    }

    return f;
}
