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

        CircleCylinder(Circle*, double);

    public:

        virtual ~CircleCylinder();

        static CircleCylinder* CreateInstance(Circle*, double);

};

class  TringleCylinder: public Cylinder
{
    private:

        TringleCylinder(Triangle*, double);

    public:

        virtual ~TringleCylinder();

        static TringleCylinder* CreateInstance(Triangle*, double);

};

class  StarCylinder: public Cylinder
{
    private:

        StarCylinder(Star*, double);

    public:

        virtual ~StarCylinder();

        static StarCylinder* CreateInstance(Star*, double);

};