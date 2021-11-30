#include <iostream>
#include <math.h>
#include "MyEx.h"

using namespace std;

const double Pi = 3.1415926535, Fi = ( 1+sqrt(5) ) / 2;

class Figure
{
    public:

        virtual ~Figure() {cout<<"\n- Деструктор Figure() -";}

        virtual double Calc_Square() = 0;    
       // virtual Figure* Clone() = 0;       
};

template <typename type>
class Circle: public Figure
{
    private:

        type r;

    public:

        Circle()
        {
            cout<<"\n- Конструктор Circle -";
            r = 4;     
        }

        Circle(type new_r)
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

        virtual ~Circle(){  cout<<"\n- Деструктор Circle() -"; }

        type GetRadius(){ return r; }
  
        virtual type Calc_Square()
        {
            return r*r * Pi;
        }

       // virtual Figure* Clone(){ return new Circle(r); }
};




template <typename type>
class Triangle: public Figure
{
    private:

        type a,b,c;

        bool Check(type a, type b, type c)    // Проверка на существование треугольника
        {
            if ( c<a+b && a<b+c && b<c+a)
            {
                return true;
            }
            
            else return false;
        }  

    public:

        Triangle()
        {
            cout<<"\n- Конструктор Tringle -";
            a=3;
            b=4;
            c=5;
        }

        Triangle(type new_a, type new_b, type new_c)
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

        virtual ~Triangle(){ cout<<"\n- Деструктор Triangle() -"; }

        type GetSideA() { return a; }
        type GetSideB() { return b; }
        type GetSideC() { return c; }
        
        virtual type Calc_Square()
        {
            double p = (a+b+c) / 2;

            return sqrt( p* (p-a)*(p-b)*(p-c) );  // Формула Герона
        }

       // virtual Figure* Clone(){ return new Triangle(a, b, c); }

};

template <typename type>
class Star: public Figure
{
    private:

        type d;   // Длинна основания луча (сторона внутреннего пятиугольника)

    public:

        Star()
        {
            cout<<"\n- Конструктор Star -";
            d = 5;
        }

        Star(type new_d)
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

        virtual ~Star(){ cout<<"\n- Деструктор Star() -"; }

        type GetBaseRay() { return d; }

        virtual type Calc_Square()
        {
            double AreaPentagon = (5 * d * d) / (4 * tan(Pi/5) );  // Площадь внутреннего пятиугольника


            double c = Fi * d;           // Ребро луча

            double p = (d+c+c) / 2;   // Полупериметр

            double AreaTriangle = sqrt( p * (p-c)*(p-c)*(p-d) );   // Формула Герона

            
            return AreaPentagon + AreaTriangle * 5;
        }
        
       // virtual Figure* Clone(){ return new Star(d); }

};



