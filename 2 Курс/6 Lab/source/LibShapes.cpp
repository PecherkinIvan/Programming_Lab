#include "LibShapes.h"

//////   Methods for Circle   /////

Circle::Circle()
{  
    cout<<"\n- РљРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ Circle -";
    r = 4;      
}

Circle::Circle(double new_r)
{
    if( new_r > 0)
    {
        cout<<"\n- РљРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ Circle() -";
        r = new_r;
    }
    else
    {
        throw "РќРµРІРµСЂРЅРѕРµ Р·РЅР°С‡РµРЅРёРµ СЂР°РґРёСѓСЃР°! ";
    }
}

Circle::~Circle()
{
    cout<<"\n- Р”РµСЃС‚СЂСѓРєС‚РѕСЂ Circle() -";
}

double Circle::Calc_Square()
{
    return r*r * Pi;
}



//////   Methods for Triangle   /////

bool Triangle::Check(double a, double b, double c)
{
    if ( c<a+b && a<b+c && b<c+a)
    {
        return true;
    }
    
    else return false;
}

Triangle::Triangle()
{
     cout<<"\n- РљРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ Tringle -";
     a=3;
     b=4;
     c=5;
}

Triangle::Triangle(double new_a, double new_b, double new_c)
{
    if( Check(new_a,new_b,new_c) )
    {
        cout<<"\n- РљРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ Tringle() -";
        a=new_a;
        b=new_b;
        c=new_c;
    }

    else  throw " * Р—РЅР°С‡РµРЅРёСЏ С‚СЂРµСѓРіРѕР»СЊРЅРёРєР° РЅРµРІРµСЂРЅС‹Рµ! ";
    
}

Triangle::~Triangle()
{
    cout<<"\n- Р”РµСЃС‚СЂСѓРєС‚РѕСЂ Triangle() -";
}

double Triangle::Calc_Square()
{   
    double p = (a+b+c) / 2;

    return sqrt( p* (p-a)*(p-b)*(p-c) );  // Р¤РѕСЂРјСѓР»Р° Р“РµСЂРѕРЅР°
}



//////   Methods for Star  /////

Star::Star()
{
    cout<<"\n- РљРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ Star -";
    d = 5;
}

Star::Star(double new_d)
{
    if( new_d > 0)
    {
        cout<<"\n- РљРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ Star() -";
        d = new_d;
    }
    
    else  throw " РќРµРІРµСЂРЅРѕРµ Р·РЅР°С‡РµРЅРёРµ РґР»РёРЅРЅС‹ РѕСЃРЅРѕРІР°РЅРёСЏ Р»СѓС‡Р°! ";
 
}

Star::~Star()
{
    cout<<"\n- Р”РµСЃС‚СЂСѓРєС‚РѕСЂ Star() -";
}

double Star::Calc_Square()
{
    
    double AreaPentagon = (5 * d * d) / (4 * tan(Pi/5) );  // РџР»РѕС‰Р°РґСЊ РІРЅСѓС‚СЂРµРЅРЅРµРіРѕ РїСЏС‚РёСѓРіРѕР»СЊРЅРёРєР°


    double c = Fi * d;           // Р РµР±СЂРѕ Р»СѓС‡Р°

    double p = (d+c+c) / 2;   // РџРѕР»СѓРїРµСЂРёРјРµС‚СЂ

    double AreaTriangle = sqrt( p * (p-c)*(p-c)*(p-d) );   // Р¤РѕСЂРјСѓР»Р° Р“РµСЂРѕРЅР°

    
    return AreaPentagon + AreaTriangle * 5;
    
}




