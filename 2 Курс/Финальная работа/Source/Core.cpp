#include <iostream>
#include <math.h>

#include "Core.h"

using namespace std;


Cylinder::Cylinder(double new_h, Figure* new_f)
{
    if(h>=0)
    {
        h = new_h;
        f = new_f->Clone();
    }
    else
    {
        MyEx e(" Отрицательное значение высоты недопустимо!!! ");
        throw e;
    }
}

double Cylinder::getHeight()
{
    return h;
}

double Cylinder::getSquare()
{
    return f->Calc_Square();
}
double Cylinder::CalcValume()
{
    return h *(f->Calc_Square());
}

void Cylinder::setHeight(double new_h)
{
    if(h>=0)
    {
        h = new_h;
    }
    else
    {
        MyEx e(" Отрицательное значение высоты недопустимо!!! ");
        throw e;
    }

}


//***** Типизированные наследники Cylinder *******************************//

CircleCyl::CircleCyl(double new_h, Figure* new_f):Cylinder(new_h,new_f){ }
double CircleCyl::getRadius()
{
    Circle* c = static_cast<Circle*>(f);
    return c->Get_Radius();
}

unsigned short CircleCyl::getType()
{
    return 0;
}

void CircleCyl::setRadius(double new_r)
{
    Circle* c = static_cast<Circle*>(f);
    c->Set_Radius(new_r);
}

TriangleCyl::TriangleCyl(double new_h, Figure* new_f):Cylinder(new_h,new_f){ }
double TriangleCyl::getA()
{
    Triangle* t = static_cast<Triangle*>(f);
    return t->Get_A();
}
double TriangleCyl::getB()
{
    Triangle* t = static_cast<Triangle*>(f);
    return t->Get_B();
}
double TriangleCyl::getC()
{
    Triangle* t = static_cast<Triangle*>(f);
    return t->Get_C();
}

unsigned short TriangleCyl::getType()
{
    return 1;
}

void TriangleCyl::setData(double new_a, double new_b, double new_c)
{
    Triangle* t = static_cast<Triangle*>(f);
    t->Set_Data(new_a,new_b,new_c);
}


StarCyl::StarCyl(double new_h, Figure* new_f):Cylinder(new_h,new_f){ }
double StarCyl::getD()
{
    Star* s = static_cast<Star*>(f);
    return s->Get_D();
}

unsigned short StarCyl::getType()
{
    return 2;
}

void StarCyl::setD(double new_d)
{
    Star* s = static_cast<Star*>(f);
    s->Set_D(new_d);
}



//*************************************************************************////

Cylinder* CollectionCylinder::getCylinder(int n)
{
   return shape[n];
}

double CollectionCylinder::getNumber()
{
    return N;
}
void  CollectionCylinder::addCylinder(Cylinder* new_shape)
{
     N++;

     shape.emplace_back(new_shape);
}

void CollectionCylinder::delCylinder(int number)
{

       shape.erase(shape.cbegin()+number);
       N--;

}

CollectionCylinder::~CollectionCylinder()
{
    shape.clear();
    shape.shrink_to_fit();
}
