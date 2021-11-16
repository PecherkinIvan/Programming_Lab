#include <iostream>
#include <math.h>

using namespace std;

const double Pi = 3.1415926535, Fi = ( 1+sqrt(5) ) / 2;

class Figure
{
    public:

        virtual ~Figure() {cout<<"\n- Деструктор Figure() -";}

        virtual double Calc_Square() = 0;    
       // virtual Figure* Clone() = 0;       
};

class Circle: public Figure
{
    private:

        double r;

    public:

        Circle();
        Circle(double);
        virtual ~Circle();

        double GetRadius(){ return r; }
  
        virtual double Calc_Square();
       // virtual Figure* Clone(){ return new Circle(r); }

};

class Triangle: public Figure
{
    private:

        double a,b,c;

        bool Check(double ,double , double);   // Проверка на существование треугольника

    public:

        Triangle();
        Triangle(double ,double ,double );
        virtual ~Triangle();

        double GetSideA() { return a; }
        double GetSideB() { return b; }
        double GetSideC() { return c; }
        
        virtual double Calc_Square();
       // virtual Figure* Clone(){ return new Triangle(a, b, c); }

};

class Star: public Figure
{
    private:

        double d;   // Длинна основания луча (сторона внутреннего пятиугольника)

    public:

        Star();
        Star(double);
        virtual ~Star();

        double GetBaseRay() { return d; }

        virtual double Calc_Square();
       // virtual Figure* Clone(){ return new Star(d); }

};

