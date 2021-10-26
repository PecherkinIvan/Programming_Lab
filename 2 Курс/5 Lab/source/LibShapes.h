#include <iostream>
#include <math.h>

using namespace std;

const double Pi = 3.1415926535, Fi = ( 1+sqrt(5) ) / 2;

class Figure
{
    public:

        virtual double Calc_Square() = 0;    // ����� ���������� ������� ������
        virtual Figure* GetType() = 0;        // ��������� new ������_N(���������);

        virtual ~Figure() {cout<<"\n- ���������� Figure() -";}

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

        bool Check(double ,double , double);   // �������� �� ������������� ������������

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

        double d;   // ������ ��������� ���� (������� ����������� �������������)

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

