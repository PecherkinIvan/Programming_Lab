#include <iostream>
#include <fstream>
using namespace std;

class Date
{
    private:

        int second;
        int minute;
        int hour;
        int day;
        int month;
        int year;

    public:

       // Date(int sd, int me, int hr, int dy, int mh, int yr);

        void GetSecond(int&);
        void GetMinute(int&);
        void GetHour(int&);
        void GetDay(int&);
        void GetMonth(int&);
        void GetYear(int&);
        void SetAdd(int sd, int me, int hr, int dy, int mh, int yr);
        //bool Check();
        
        virtual int Func() 
        {
		    cout << "\nDate::Func" << endl;  

		    int x;
            GetYear(x);
            return x;
	    }	

};

class DateExt: public Date
{
    private:

        int msecond;

    public:

        /*DateExt();
        DateExt(int ms, int sd, int me, int hr, int dy, int mh, int yr);*/

        void GetMsecond(int&);
        void SetAdd(int ms, int sd, int me, int hr, int dy, int mh, int yr);

        virtual int Func() 
        {
		    cout << "\nDateExt::Func" << endl;  

		    int x;
            GetYear(x);
            return x;
	    }	

};

class Node
{
    public:

        unsigned int n;
        DateExt* date;

        Node* next;
        Node* prev;

        Node();

        virtual void DisplayDate();
        virtual void DisplayNode();
};

class NodeExt: public Node
{
    public:
        NodeExt();

        virtual void DisplayDate();
        virtual void DisplayNode();
};
