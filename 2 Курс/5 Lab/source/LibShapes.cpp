#include "LibShapes.h"

//////   Methods for Circle   /////

Circle::Circle()
{  
    cout<<"\n- ����������� Circle -";
    r = 4;      
}

Circle::Circle(double new_r)
{
    if( new_r > 0)
    {
        cout<<"\n- ����������� Circle() -";
        r = new_r;
    }
    else
    {
        cout<<"\n �������� �������� �������! ";
        return;
    }
}

Circle::~Circle()
{
    cout<<"\n- ���������� Circle() -";
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
    else
    {
        cout<<"\n\n * �������� ������������ ��������! ";
        return false;
    }
}

Triangle::Triangle()
{
     cout<<"\n- ����������� Tringle -";
     a=3;
     b=4;
     c=5;
}

Triangle::Triangle(double new_a, double new_b, double new_c)
{
    if( Check(new_a,new_b,new_c) )
    {
        cout<<"\n- ����������� Tringle() -";
        a=new_a;
        b=new_b;
        c=new_c;
    }

    else  return;
    
}

Triangle::~Triangle()
{
    cout<<"\n- ���������� Triangle() -";
}

double Triangle::Calc_Square()
{   
    double p = (a+b+c) / 2;

    return sqrt( p* (p-a)*(p-b)*(p-c) );  // ������� ������
}



//////   Methods for Star  /////

Star::Star()
{
    cout<<"\n- ����������� Star -";
    d = 5;
}

Star::Star(double new_d)
{
    if( new_d > 0)
    {
        cout<<"\n- ����������� Star() -";
        d = new_d;
    }
    else
    {
        cout<<"\n �������� �������� ������ ��������� ����! ";
        return;
    }
}

Star::~Star()
{
    cout<<"\n- ���������� Star() -";
}

double Star::Calc_Square()
{
    
    double AreaPentagon = (5 * d * d) / (4 * tan(Pi/5) );  // ������� ����������� �������������


    double c = Fi * d;           // ����� ����

    double p = (d+c+c) / 2;   // ������������

    double AreaTriangle = sqrt( p * (p-c)*(p-c)*(p-d) );   // ������� ������

    
    return AreaPentagon + AreaTriangle * 5;
    
}




