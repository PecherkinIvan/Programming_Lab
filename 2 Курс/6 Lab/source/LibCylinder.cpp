#include "LibShapes.h"
#include "LibCylinder.h"

///////   Methods for Cylinder   ///////

Cylinder::Cylinder(double new_h)
{
    cout<<"\n- ����������� Cylinder() -";
    
    if( new_h > 0)
    {
        h = new_h;
    }

    else throw " * �������� �������� ������!!! ";
}

Cylinder::~Cylinder()
{
    cout<<"\n- ���������� Cylinder() -";
    delete f; 
}

double Cylinder::CalcValume()
{
    return h *(f->Calc_Square());
}

/////////////////<    CircleCylinder   >////////////////////


CircleCylinder::CircleCylinder(Circle* figure, double new_h):Cylinder(new_h)
{
    cout<<"\n- ����������� CircleCylinder() -";
    f = new Circle(figure->GetRadius());
}

CircleCylinder* CircleCylinder::CreateInstance(Circle* figure, double new_h)
{
    CircleCylinder* CirCyl = new CircleCylinder(figure, new_h);
    return CirCyl;
}

CircleCylinder::~CircleCylinder()
{
    cout<<"\n- ���������� CircleCylinder() -";
}


////////////////<    TringleCylinder   >////////////////////


TringleCylinder::TringleCylinder(Triangle* figure, double new_h):Cylinder(new_h)
{
    cout<<"\n- ����������� TringleCylinder() -";
    f = new Triangle(figure->GetSideA(), figure->GetSideB(), figure->GetSideC() );
}

TringleCylinder* TringleCylinder::CreateInstance(Triangle* figure, double new_h)
{
    TringleCylinder* TriCyl = new TringleCylinder(figure, new_h);
    return TriCyl;
}

TringleCylinder::~TringleCylinder()
{
    cout<<"\n- ���������� TringleCylinder() -";
}


////////////////<    StarCylinder   >////////////////////


StarCylinder::StarCylinder(Star* figure, double new_h):Cylinder(new_h)
{
    cout<<"\n- ����������� StarCylinder() -";
    f = new Star(figure->GetBaseRay());
}

StarCylinder* StarCylinder::CreateInstance(Star* figure, double new_h)
{
    StarCylinder* StaCyl = new StarCylinder(figure, new_h);
    return StaCyl;
}

StarCylinder::~StarCylinder()
{
    cout<<"\n- ���������� StarCylinder() -";
}
