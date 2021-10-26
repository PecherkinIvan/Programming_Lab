#include <iostream>
#include <math.h>

using namespace std;

const double Pi = 3.1415926535, Fi = ( 1+sqrt(5) ) / 2;

class Figure
{
    public:

        virtual double Calc_Square() = 0;    // Метод нахождения площади фигуры
        virtual Figure* GetType() = 0;        // Возращает new Фигура_N(параметры);

        virtual ~Figure() {cout<<"\n- Деструктор Figure() -";}

};

class Circle: public Figure
{
    private:

        double r;

    public:

        Circle();
        Circle(double);

        virtual ~Circle();

        virtual double Calc_Square();
        virtual Figure* GetType()
        {
            return new Circle(r);
        }

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
        
        
        virtual double Calc_Square();
        virtual Figure* GetType()
        {
            return new Triangle(a, b, c);
        }

};

class Star: public Figure
{
    private:

        double d;   // Длинна основания луча (сторона внутреннего пятиугольника)

    public:

        Star();
        Star(double);

        virtual ~Star();

        virtual double Calc_Square();
        virtual Figure* GetType()
        {
            return new Star(d);
        }

};

