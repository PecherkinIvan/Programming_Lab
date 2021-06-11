#include "LibTree.h"
using namespace std;

void Add_Num(Tree*& T, DATA data, short int p)  
{
    if(!T) 
    {
        T = new Tree;
        T->data = data;
        T->left = NULL;
        T->right = NULL;
        return;
    }

    if( (data.size < T->data.size && p==-1) ||     // Если выбраны страницы
        (data.year < T->data.year && p==-2)   )  //  Если выбран год
        Add_Num(T->left, data, p);

    else
        Add_Num(T->right, data, p);

}
 
void Add_String(Tree*& T, DATA data, short int p)
{
    if(!T) 
    {
        T = new Tree;
        T->data = data;
        T->left = NULL;
        T->right = NULL;
        return;
    }

    string s1, s2;
    

    if(p == 1)
    {
        s1 = data.name;
        s2 = T->data.name;
    }
    else
    {
        s1 = data.author;
        s2 = T->data.author;
    }
    
    if( int(s1[0]) > int(s2[0]) )
        Add_String(T->right, data, p);
    

    else
        Add_String(T->left, data, p);
    

}

void GetFail(Tree*& T, short int p)
{
  DATA new_data;

  ifstream fin("INPUT.txt");

    string simbol; 
    unsigned int line=1;

    while ( !fin.eof())
    {
        if( fin>>simbol && fin.get()=='\n')
            line++;
    }
    line--; 
    fin.clear();  // Возврат курсора на начало
    fin.seekg(0);

    for (line; line>0 ; line--)
    {
        fin>> new_data.name;      
        fin>> new_data.author; 
        fin>> new_data.size;   
        fin>> new_data.year;

        if(p>0)
            Add_String(T, new_data, p);
        else
            Add_Num(T, new_data, p);
    }
    
  fin.close();
}

void PrintLRR(Tree* T)
{
    if(!T) return;

    PrintLRR(T->left);

    cout<<endl<<T->data.name<<"    "
        <<T->data.author<<"    "
        <<T->data.size<<"стр.   "
        <<T->data.year<<"г.";

    PrintLRR(T->right);
}

void PrintVelue(Tree* T, int velue, short int p)
{
    if(!T) return;

    PrintVelue(T->left, velue, p);

    if(T->data.size < velue && p == 1  ||
       T->data.year < velue && p == 2   )
    {
       cout<<endl<<T->data.name<<"    "
        <<T->data.author<<"    "
        <<T->data.size<<"стр.   "
        <<T->data.year<<"г.";
    }

    PrintVelue(T->right, velue, p);
}

void PrintLetter(Tree* T, char latter, short int p)
{
   if(!T) return;
   
   PrintLetter(T->left, latter, p);

   string s;
   if(p == 1)
        s = T->data.name;
    else
        s = T->data.author;

   if( int(s[0]) == int(latter) && p == 1 ||
       int(s[0]) == int(latter) && p == 2  ) 
    {
      cout<<endl<<T->data.name<<"    "
          <<T->data.author<<"    "
          <<T->data.size<<"стр.   "
          <<T->data.year<<"г.";
    }

    PrintLetter(T->right, latter, p);
}

void Delete(Tree*& T)
{
    if(T)
    {
        if(T->left) Delete(T->left);
        if(T->right) Delete(T->right);

        delete T; 
        T=NULL;
    }

}
