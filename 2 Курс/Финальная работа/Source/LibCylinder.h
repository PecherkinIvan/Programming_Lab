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

        virtual unsigned short getType() = 0;  // Получение типа фигуры под указателем 0-Круг 1-Треугольник ...
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


/////////**** Класс для работы с коллекцией *********/////

class CollectionCylinder

{
    private:

        unsigned short N=0;        // Количство Фигур
        vector <Cylinder*> shape;

    public:

       ~CollectionCylinder();

       Cylinder* getCylinder(int);  // Получение фигуры по номеру
       double getNumber();           // Узнать общее количесво фигур
       void delCylinder(int);        // Удаление фигуры по номеру
       void addCylinder(Cylinder*);  // Добавление новой фигуры

};
