#include <iostream>
#include <math.h>

#include "MyExp.h"

using namespace std;

const double Pi = 3.1415926535, Fi = ( 1+sqrt(5) ) / 2;

class Figure
{
    public:

        virtual double Calc_Square() = 0;  
        virtual Figure* Clone() = 0;

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
        virtual Figure* Clone();

        void Set_Radius(double);
        double Get_Radius();
};

class Triangle: public Figure
{
    private:

        double a,b,c;

        bool Check(double ,double , double);   
    public:

        Triangle();
        Triangle(double ,double ,double );

        virtual ~Triangle();
        
        virtual double Calc_Square();
        virtual Figure* Clone();

        void Set_Data(double,double,double);
        double Get_A();
        double Get_B();
        double Get_C();
};

class Star: public Figure
{
    private:

        double d;  

    public:

        Star();
        Star(double);

        virtual ~Star();

        virtual double Calc_Square();
        virtual Figure* Clone();

        void Set_D(double);
        double Get_D();
};

