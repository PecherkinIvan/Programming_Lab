#include <iostream>

class MyEx
{
    private:

        int value;
        const char* msg;

    public:

        MyEx(int v, const char* m): value(v), msg(m) 
        {
		    std::cout << "\n- Конструктор MyEx() -"; 
	    }
	    
        int GetValue()   {return value;}
	    const char* GetMessage() {return msg;}	

};