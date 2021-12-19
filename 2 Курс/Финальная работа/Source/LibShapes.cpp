#include "LibShapes.h"

//////***************   Methods for Circle      *********************/////



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
        MyEx e(" Неверное значение радиуса! ");
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

Figure* Circle::Clone()
{
    return new Circle(r);
}

void Circle::Set_Radius(double new_r)
{
    if( new_r > 0)
    {
        r = new_r;
    }
    else
    {
        MyEx e(" Неверное значение радиуса! ");
        throw e;
    }
}
double Circle::Get_Radius()
{
    return r;
}

//////************       Methods for Triangle      *****************/////



bool Triangle::Check(double a, double b, double c)
{
    if ( c<a+b && a<b+c && b<c+a)
    {
        return true;
    }
    else
    {
        return false;
    }
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
        MyEx e(" Значения треугольника неверные! ");
        throw e;
        return;
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

Figure* Triangle::Clone()
{
    return new Triangle(a, b, c);
}

void Triangle::Set_Data(double new_a,double new_b,double new_c)
{
    if( Check(new_a,new_b,new_c) )
    {
        a=new_a;
        b=new_b;
        c=new_c;
    }
    else
    {
        MyEx e(" Значения треугольника неверные! ");
        throw e;
        return;
    }
}

double Triangle::Get_A()
{
    return a;
}
double Triangle::Get_B()
{
    return b;
}
double Triangle::Get_C()
{
    return c;
}



//////*********************   Methods for Star     *************************/////



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
        MyEx e(" Неверное значение длинны основания луча! ");
        throw e;
        return;
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

Figure* Star::Clone()
{
    return new Star(d);
}

void Star::Set_D(double new_d)
{
    if( new_d > 0)
    {
        d = new_d;
    }
    else
    {
        MyEx e(" Неверное значение длинны основания луча! ");
        throw e;
        return;
    }
}
double Star::Get_D()
{
    return d;
}



