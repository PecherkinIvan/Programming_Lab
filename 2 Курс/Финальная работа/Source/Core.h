#include "LibShapes.h"
#include <vector>

class Cylinder
{
    protected:

        Figure* f;
        double h;

    public:

        Cylinder(double, Figure*);
        ~Cylinder(){ delete f; }

        virtual unsigned short getType() = 0;
        void setHeight(double);
        double getHeight();
        double getSquare();
        double CalcValume();
    
};

class CircleCyl: public Cylinder
{
    public:
        CircleCyl(double, Figure*);
        virtual unsigned short getType();
        void setRadius(double);
        double getRadius();
};
class TriangleCyl: public Cylinder
{
    public:
        TriangleCyl(double, Figure*);
        virtual unsigned short getType();
        void setData(double,double,double);
        double getA();
        double getB();
        double getC();
};
class StarCyl: public Cylinder
{
    public:
        StarCyl(double, Figure*);
        virtual unsigned short getType();
        void setD(double);
        double getD();
};




class CollectionCylinder

{
    private:

        unsigned short N=0; // Количство координат
        vector <Cylinder*> shape;

    public:

      // CollectionCylinder();
        ~CollectionCylinder();

       Cylinder* getCylinder(int);
       double getNumber();
       void delCylinder(int);
       void addCylinder(Cylinder*);

};
