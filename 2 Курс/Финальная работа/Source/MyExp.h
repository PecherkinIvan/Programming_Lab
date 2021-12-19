//////**** Класс для обработки ошибок ******//////
///
///
class MyEx
{
    private:

        const char* msg;

    public:

        MyEx(const char* m): msg(m){ };

        const char* GetMessage() {return msg;}
};
