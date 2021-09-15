#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include <malloc.h>

using namespace std;
int Select();
void All_Func(int*&,int&);
void MakeArr(int);
void ReadArr(int*,int);
void PrintArr(int*,int);
void Push_end_Element(int*&,int&);
void Push_begin_Element(int*&,int&);
void Push_k_Element(int*&,int&);
void Delete_end_Element(int *&,int&);
void Delete_begin_Element(int *&,int&);
void Delet_k_Element(int*&,int&);
void Push_value_Element(int*&,int&);
void Delete_value_Arr(int*&,int&);

int main()
{ 
    int size;
    cout<<"> "; cin>>size;
    int *arr=(int*)malloc(size*sizeof(int));

    MakeArr(size);
    ReadArr(arr,size);
    PrintArr(arr,size);
    All_Func(arr,size);
    
    free(arr);
    
    return 0;
}

int Select()
{
    cout<<"|---------------------------------------|";
    cout<<"\n  1.) add an element to the end of the array";
    cout<<"\n  2.) add an element to the beginning of the array";
    cout<<"\n  3.) add an element to the k-th position in the array";
    cout<<"\n  4.) delete the last element of the array";
    cout<<"\n  5.) delete the first element of the array";
    cout<<"\n  6.) delete the k-th element of the array";
    cout<<"\n  7.) add an array element after the first encountered element with the specified value, if there is no such value, then issue a warning message";
    cout<<"\n  8.) delete all elements of the array with the specified value, if there is no such value, then issue a warning message";
    cout<<"\n\n 0.)Exit\n";
    cout<<"|---------------------------------------|\n >";
    int point;
    cin>>point;
    return point;
}

void All_Func(int*&arr,int&n)
{
    int point=Select();

   while(point!=0)
   {    
        switch(point) {
        case 1:
            Push_end_Element(arr,n);
            break;
        case 2:
            Push_begin_Element(arr,n);
            break;
        case 3:
            Push_k_Element(arr,n);
            break;
        case 4:
            Delete_end_Element(arr,n);
            break;
        case 5:
            Delete_begin_Element(arr,n);
            break;
        case 6:
            Delet_k_Element(arr,n);
            break;
        case 7:
            Push_value_Element(arr,n);
            break;
        case 8:
            Delete_value_Arr(arr,n);
            break;

        default:
           
            exit(EXIT_FAILURE);
        }
        PrintArr(arr,n);
        point=Select();
   }
}
    
void MakeArr(int n) {
 srand(time(NULL));
 fstream f_out("arr.txt", ios::out);
    for (int i = 0; i < n; i++){
    f_out<< rand() % 10<<" ";
    }
 f_out.close();
}
void ReadArr(int *arr, int n) {
 fstream f_in("arr.txt", ios::in);
    if (f_in) {
        for (int i = 0; i < n; i++) {
 f_in >> arr[i];
        }
 f_in.close();
    }
}

void PrintArr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "]: "<< arr[i] << endl;
        
    }

}

void Push_end_Element(int *&arr, int &n) 
{
    int k;
    cout << "How many array elements to add to the end of the array: ";
    cin >> k;
    
    if(k>0)
    {
     arr=(int*)realloc(arr,(n+k)*sizeof(int));
    
     cout << "Enter the items to add, " << k << " pieces: " << endl;
     for (int i = n; i < (n + k); i++) cin >> arr[i];
         n+= k;
    }
    else{ cout<<"\nError! (The value is not set correctly)\n\n";}

}

void Push_begin_Element(int *&arr,int &n)
{
    int k;
    cout << "How many array elements to add to the end of the array: ";
    cin>>k;

    if(k>0)
    {
     arr=(int*)realloc(arr,(n+k)*sizeof(int));
     for(int i=n-1;i>=0;i--) arr[i+k]=arr[i];
    
     cout << "Enter the items to add, " << k << " pieces: " << endl;
     for(int i=0;i<k;i++) cin>>arr[i];

        n+=k;
    }
    else{ cout<<"\nError! (The value is not set correctly)\n\n";}

}

void Push_k_Element(int *&arr,int &n)
{
    int k;
    cout << "To which place (total places " << n << ") of the array to add the element:";
    cin>>k;

    if(k<n && k>=0)
    {
     arr=(int*)realloc(arr,(n+1)*sizeof(int));

     cout<<"Enter the item to add:";
     int add_k;
     cin>>add_k;
     
     for(int i=n+1;i>=k && i>0;i--) arr[i]=arr[i-1];
    
     arr[k]=add_k;
        
        n++;
    }
    else{ cout<<"\nError! (The value is not set correctly)\n\n";}

}

void Delete_end_Element(int *&arr,int &n){

    int k;
    cout << "How many array elements to delete at the end of the array: ";
    cin >> k;

    if(k>=0 && k<=n)
    {
     arr=(int*)realloc(arr,(n-k)*sizeof(int));
        
       n-=k;
    }
    else{ cout<<"\nError! (The value is not set correctly)\n\n";}
}

void Delete_begin_Element(int *&arr,int &n)
{
    int k;
    cout << "How many array elements to delete at the beginning of the array: ";
    cin >> k;

    if(k>=0 && k<=n)
    {
     for(int i=0;i<=n-k;i++) arr[i]=arr[i+k];
     arr=(int*)realloc(arr,(n-k)*sizeof(int));

        n-=k;
    }
    else{ cout<<"\nError! (The value is not set correctly)\n\n";}
}

void Delet_k_Element(int *&arr,int &n)
{
    int k;
    cout << "To which place (total places " << n << ") of the array to add the element: ";
    cin >> k;

    if(k<n && k>=0)
    {
     for(int i=k;i<(n-1); i++) arr[i]=arr[i+1];
     arr=(int*)realloc(arr,(n-1)*sizeof(int));

        n--;
    }
    else{ cout<<"\nError! (The value is not set correctly)\n\n";}

}

void Push_value_Element(int *&arr,int &n)
{
    int k, num, flag=0;
    cout<<"After what value is found in the array, add the element: ";
    cin>>k;

    for(int i=0;i<n;i++)
    { if(arr[i]==k)
      {
          flag=1; num=i; break;
      } 
    }

    if(flag)
    {
        arr=(int*)realloc(arr,(n+1)*sizeof(int));
        for(int i=n; i>(num+1) ;i--)
        {
            arr[i]=arr[i-1];
        }

        cout<<" Enter the item to add: ";
        cin>>arr[num+1];
        
        n++;
    }
    else{ cout<<"\nError! (The value is not set correctly)\n\n"<< endl;}

}

void Delete_value_Arr(int *&arr,int &n)
{
    int k, flag_k=1, x,  buf=0;
    cout << "Elements with what value to delete: ";
    cin >> k;

    for (int i=0; i<n; i++)
    { 
      if(arr[i]==k) buf++;
    }

    if(buf)
    {
        while(flag_k!=0)
        {
            flag_k=0;
            
            for(int i=1;i<n;i++)
            {
             if(arr[i-1]==k && k!=arr[i]){x=arr[i]; arr[i]=k; arr[i-1]=x; flag_k=1;}
            }
        }
         
        arr=(int*)realloc(arr,(n-buf)*sizeof(int));

        n-=buf;
    }
    else{ cout<<"\nError! (The value is not set correctly)\n\n"<< endl;}

}

