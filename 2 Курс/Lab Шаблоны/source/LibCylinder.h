#include <iostream>

using namespace std;

class Cylinder
{
    private:

        double h;
    
     protected:

        Figure* f;

    public:

        Cylinder(double);
        virtual ~Cylinder();

        double CalcValume();

};


class  CircleCylinder: public Cylinder
{
    private:

        CircleCylinder(Circle<double>*, double);

    public:

        virtual ~CircleCylinder();

        static CircleCylinder* CreateInstance(Circle<double>*, double);

};

class  TringleCylinder: public Cylinder
{
    private:

        TringleCylinder(Triangle<double>*, double);

    public:

        virtual ~TringleCylinder();

        static TringleCylinder* CreateInstance(Triangle<double>*, double);

};

class  StarCylinder: public Cylinder
{
    private:

        StarCylinder(Star<double>*, double);

    public:

        virtual ~StarCylinder();

        static StarCylinder* CreateInstance(Star<double>*, double);

};