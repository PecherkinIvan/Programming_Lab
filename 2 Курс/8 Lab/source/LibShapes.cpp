#include "LibShapes.h"

//////   Methods for Circle   /////

Circle::Circle()
{  
    cout<<"\n- Конструктор Circle -";
    r = 4;      
}

Circle::Circle(double new_r)
{
    if( new_r > 0)
    {
        cout<<"\n- Конструктор Circle() -";
        r = new_r;
    }
    else
    {
        MyEx e(new_r, " Неверное значение радиуса! ");
        throw e;
    }
}

Circle::~Circle()
{
    cout<<"\n- Деструктор Circle() -";
}

double Circle::Calc_Square()
{
    return r*r * Pi;
}



//////   Methods for Triangle   /////

bool Triangle::Check(double a, double b, double c)
{
    if ( c<a+b && a<b+c && b<c+a)
    {
        return true;
    }
    
    else return false;
}

Triangle::Triangle()
{
     cout<<"\n- Конструктор Tringle -";
     a=3;
     b=4;
     c=5;
}

Triangle::Triangle(double new_a, double new_b, double new_c)
{
    if( Check(new_a,new_b,new_c) )
    {
        cout<<"\n- Конструктор Tringle() -";
        a=new_a;
        b=new_b;
        c=new_c;
    }

    else
    {
        MyEx e(0, " * Значения треугольника неверные! ");
        throw e;
    }
    
}

Triangle::~Triangle()
{
    cout<<"\n- Деструктор Triangle() -";
}

double Triangle::Calc_Square()
{   
    double p = (a+b+c) / 2;

    return sqrt( p* (p-a)*(p-b)*(p-c) );  // Формула Герона
}



//////   Methods for Star  /////

Star::Star()
{
    cout<<"\n- Конструктор Star -";
    d = 5;
}

Star::Star(double new_d)
{
    if( new_d > 0)
    {
        cout<<"\n- Конструктор Star() -";
        d = new_d;
    }
    
    else
    {
        MyEx e(new_d, " Неверное значение длинны основания луча! ");
        throw e;
    }  

}

Star::~Star()
{
    cout<<"\n- Деструктор Star() -";
}

double Star::Calc_Square()
{
    
    double AreaPentagon = (5 * d * d) / (4 * tan(Pi/5) );  // Площадь внутреннего пятиугольника


    double c = Fi * d;           // Ребро луча

    double p = (d+c+c) / 2;   // Полупериметр

    double AreaTriangle = sqrt( p * (p-c)*(p-c)*(p-d) );   // Формула Герона

    
    return AreaPentagon + AreaTriangle * 5;
    
}




