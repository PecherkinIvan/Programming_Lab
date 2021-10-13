#include "Date.h"



void Date::SetAdd(int sd, int me, int hr, int dy, int mh, int yr)
{
    if( sd >= 0 && sd < 60)
        second = sd;
    else
        cout<<"\n* Function SetAdd: Error invalid seconds values! ";


    if( me >= 0 && me < 60)    
        minute = me;
    else
        cout<<"\n* Function SetAdd: Error invalid minute values! ";


    if( hr >= 0 && hr < 24)
        hour   = hr;
    else
        cout<<"\n* Function SetAdd: Error invalid hour values! ";


    if( dy >= 1 && dy < 32)
        day    = dy;
    else    
        cout<<"\n* Function SetAdd: Error invalid day values! ";

    
    if( mh >= 1 && mh < 13)
        month = mh;
    else
        cout<<"\n* Function SetAdd: Error invalid month values! ";


    if( yr >= 0)
        year   = yr;
    else
        cout<<"\n* Function SetAdd: Error invalid year values! ";
}

void DateExt::SetAdd(int ms, int sd, int me, int hr, int dy, int mh, int yr)
{
    Date::SetAdd(sd, me, hr, dy, mh, yr);

    if( ms >= 0 && ms <= 999)
        msecond = ms;
    else
        cout<<"\n* Function SetAdd: Error invalid mseconds values! ";
}

/*
Date::Date(int sd, int me, int hr, int dy, int mh, int yr)
{
    Date::SetAdd(sd,me,hr,dy,mh,yr);
    cout<<"\n - Конострукотор Date-\n";
}

DateExt::DateExt(int ms, int sd, int me, int hr, int dy, int mh, int yr):Date(sd,me,hr,dy,mh,yr)
{
    DateExt::SetAdd(ms,sd,me,hr,dy,mh,yr);
    cout<<"
}
*/

void Date::GetSecond(int& v)
{
    if( second >= 0 && second < 60)
        v = second;

    else cout<<"\n* The second field is not filled in! ";
}

void Date::GetMinute(int& v)
{
    if( minute >= 0 && minute < 60)
        v = minute;

    else cout<<"\n* The minute field is not filled in! ";
}

void Date::GetHour(int& v)
{
    if( hour >= 0 && hour <= 23)
        v = hour;

    else cout<<"\n* The hour field is not filled in! ";
}

void Date::GetDay(int& v)
{
    if( day >= 0 && day <= 31)
        v = day;

    else cout<<"\n* The day field is not filled in! ";
}

void Date::GetMonth(int& v)
{
    if( month >= 0 && month <= 12)
        v = month;

    else cout<<"\n* The month field is not filled in! ";
}

void Date::GetYear(int& v)
{
    if( year >= 0)
        v = year;

    else cout<<"\n* The year field is not filled in! ";
}

void DateExt::GetMsecond(int& v)
{
    if( msecond >= 0 && msecond <= 999)
        v = msecond;

    else cout<<"\n* The msecond field is not filled in! ";
}



Node::Node()
{
    date = new DateExt;

    cout<<"\n- Конструктор Node -\n";
}

NodeExt::NodeExt():Node()
{
    cout<<"\n- Конструкотор NodeExt -\n";
}

void Node::DisplayDate()
{
    int sd, me, hr, dy, mh, yr;

    date->GetSecond(sd);
    date->GetMinute(me);
    date->GetHour(hr);
    date->GetDay(dy);
    date->GetMonth(mh);
    date->GetYear(yr);

    cout<<sd<<":"<<me<<":"<<hr
        <<"  "<<dy<<"."<<mh<<"."<<yr;
}

void NodeExt::DisplayDate()
{
    int ms, sd, me, hr, dy, mh, yr;

    date->GetMsecond(ms);
    date->GetSecond(sd);
    date->GetMinute(me);
    date->GetHour(hr);
    date->GetDay(dy);
    date->GetMonth(mh);
    date->GetYear(yr);


    cout<<sd<<","<<ms<<":"<<me<<":"<<hr
        <<"  "<<dy<<"."<<mh<<"."<<yr;
    
}

void Node::DisplayNode()
{

    cout<<n<<".\t";  DisplayDate();  // Выводит дату


        cout<<"\t\t";

    if(next != NULL)                     // Выводит след. дату               
    {   
        next->DisplayDate();
    }
    else
    {
        cout<<"__"<<":"<<"__"<<":"<<"__"
        <<"  "<<"__"<<"."<<"__"<<"."<<"__";
    }
        cout<<"\t\t";


    if(prev != NULL)                  // Выводит пред. дату    
    {
        prev->DisplayDate();
    }
    else
    {
        cout<<"__"<<":"<<"__"<<":"<<"__"
        <<"  "<<"__"<<"."<<"__"<<"."<<"__";
    }
        
    cout<<endl;
}

void NodeExt::DisplayNode()
{

    Node::DisplayNode();
}