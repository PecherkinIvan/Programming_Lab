#include <iostream>
#include <fstream> 
#include <math.h>
#include <ctime>
using namespace std;

void Gauss(double **&, int, int, double *&);
void Accuracy(double **,double *&, int,int,double **);
void Det(double **,int);
void Inverse_Matrix(double **,int);                      // Обратная матрица

void Print2(double **,int , int);
void Print(double **,double*, int);
void Select(double**&,int ,int);             
void NewMatrix(double**&,int ,int);            // Выделение памяти для матрицы
void DelMatrix(double**&, int, int);
void Copy(double**&,double** ,int , int);     // Копирование массива
                                          
void Checking_File();                       // Проверка файла

int main()
{
    system("chcp 1251");  system("cls");
    Checking_File(); // Проверка на наличие файла

    int N;

    cout << "Введите размер матрицы.(Целое число) ";
    cin>>N; int M=N+1;

    double **A,**A1;    // Матрица коэфициентов (квадратная) 
    double *x = new double[N];   // Решение
    NewMatrix(A, N, M);
    Select(A, N, M);
    Print2(A,N, M);
    NewMatrix(A1, N, M);  // Создание копии матрицы;
    Copy(A, A1, N, M);

    Det(A,N);
    Copy(A1, A, N, M);    // Востоновим  матрицу A после  нахождения определителя
   
    Accuracy(A, x, N, M, A1);   // Метод Гаусса + вычисление точности
    Copy(A1, A, N, M);     // Востоновим  матрицу A после решения СЛАУ
    
    Inverse_Matrix(A,N);  // Обратная матрица

   // Print2(A,N, M);

   
    DelMatrix(A1, N, M);
    DelMatrix(A, N, M);
    delete [] x;  x=nullptr;

 return 0;
}

void Select(double**& a, int n, int m)
{
    cout<<"\n  _____________________________________________";
    cout<<"\n |                                             ||";
    cout<<"\n |  ** Выберите тип матрицы для задания: **    ||";
    cout<<"\n |  1.) Матрица, заданная явно                 ||";
    cout<<"\n |  2.) Матрица, заданная случайным образом    ||";
    cout<<"\n |  3.) Единичная матрица                      ||";
    cout<<"\n |  4.) Нулевая матрица                        ||";
    cout<<"\n |  5.) Матрица Гильберта                      ||";
    cout<<"\n |_____________________________________________||";
    cout<<"\n > ";
    int point;
    cin>>point;

    switch(point) {
        case 1:
        {
            fstream F("arr.txt", ios::in);//Матрица из файла
            for (int i = 0; i < n; i++)
              for (int j = 0; j < m; j++)
                F >> a[i][j];
             F.close();
              break;
        }      

         case 2:   
        {
          srand(time(NULL));
          for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                 a[i][j] = ((rand() % 40) - 20); 
            
        break;
        }

         case 3:
        {
           for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (i == j) a[i][j] = 1;
                else a[i][j] = 0;
        break;
        }

        case 4:
        {
           for (int i = 0; i < n; i++)//Вырожденная матрица
            for (int j = 0; j < m; j++)
                a[i][j] = 0;
            break;
        }

        case 5:
        {
        for (int i = 0; i < n; i++)    //Матрица Гильберта 
            for (int j = 0; j < m; j++)
                a[i][j] = 1./ (i + j + 1);
        break;
        }
        
        default:
           exit(EXIT_FAILURE);
        }


}

void Gauss(double **&a, int n, int m, double *&x) 
{
    double *y=new double[n];
     for(int k=0; k<n; k++)
       y[k]=a[k][n];
     
  double max;
  int k, index;
  const double eps = 0.000001;  // точность
  k = 0;
  while (k < n) 
  {
    // Поиск строки с максимальным a[i][k] (элементом по модулю)
    max = abs(a[k][k]);
    index = k;
    for (int i = k + 1; i < n; i++) 
    {
      if (abs(a[i][k]) > max)
      {
        max = abs(a[i][k]);
        index = i;
      }
    }
    // Перестановка строк
    if (max < eps) 
    {
      // нет ненулевых диагональных элементов
      cout << "Решение получить невозможно из-за нулевого столбца ";
      cout << index << " матрицы A" << endl;
      system("pause");
      exit(0);
    }
    for (int j = 0; j < n; j++) 
    {
      double temp = a[k][j];
      a[k][j] = a[index][j];
      a[index][j] = temp;
    }
    double temp = y[k];
    y[k] = y[index];
    y[index] = temp;
    // Нормализация уравнений
    for (int i = k; i < n; i++) 
    {
      double temp = a[i][k];
      if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
      for (int j = 0; j < n; j++) 
        a[i][j] = a[i][j] / temp;
      y[i] = y[i] / temp;
      if (i == k)  continue; // уравнение не вычитать само из себя
      for (int j = 0; j < n; j++)
        a[i][j] = a[i][j] - a[k][j];
      y[i] = y[i] - y[k];
    }
    k++;
  }
  // обратная подстановка
  for (k = n - 1; k >= 0; k--)
  {
    x[k] = y[k];
    for (int i = 0; i < k; i++)
      y[i] = y[i] - a[i][k] * x[k];
  }

  cout<<endl;  // Вывлод решения.
  for (int i = 0; i < n; i++) 
    cout << "x[" << i << "]=" << x[i] << endl;
    delete [] y;
   y=nullptr;

}
void Accuracy(double **a,double *&x, int n,int m,double **a1)
{
    Gauss(a, n, m, x);
    long double epsilon = 0;
    double s;
    for (int i = 0; i < n; i++)
    {
        s = 0;
        for (int k = 0; k < n; k++)
         s += a1[i][k] * x[k];

        if (fabs(a1[i][n] - s) > epsilon) 
            epsilon = fabs(a1[i][n] - s); 
    }
    cout<<"\nDelta:  "<<epsilon<<" (Погрешность)"<<endl;
}

void Det(double **a,int n)
{   
    double det=1;
   
    for(int i=0; i<n; i++)
    {
        bool flag=false;
        if(a[i][i]==0)
        {
            flag=true;
            for(int j=i;j<n;++j)
            {
                if(a[j][i]!=0)
                {
                    det*=-1;
                    for(int k=0;k<n;k++){  //???
                        double temp=a[i][k];
                        a[i][k]=a[j][k];
                        a[j][k]=temp;
                        flag=false;
                    }
                }
             }
        }
    

     if (flag==true){ det=0; break; }
     else{
         
         for(int j=i+1; j<n; j++)
         {
            double store=a[j][i];
            for(int k=i; k<n; k++)
            {
                a[j][k] -= (a[i][k]*store)/a[i][i];
            }
          }
         det*=a[i][i];
         }
    }

    cout<<"\n Определитель= "<<det<<endl;
}

void Inverse_Matrix(double **a1,int N) 
{
    int M=N*2;
    double **a;
    NewMatrix(a, N, M);  // A:E
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            a[i][j]=a1[i][j];
  
    for (int i = 0 ; i < N; ++i) {
        for (int j = N; j < M; ++j) 
        {                                 //Создаю с боку еденичную
            a[i][j]=0;
            if(j-i==N) a[i][j]=1;
        }
    }


    for (int i = 0; i < N; ++i) 
    {
        bool flag = false; // Проверка на ступенчатость, треугольную матрицу
        if (a[i][i] == 0) 
        {
            flag = true;
            for (int j = i; j < N; ++j)
            {                                    
                if (a[j][i] != 0) {
                    for (int k = 0; k < M; ++k) { 
                        double t = a[i][k]; 
                        a[i][k] = a[j][k];  
                        a[j][k] = t;
                        flag = false;
                    }
                }
            }
        }

      if (flag == true) {
            cout<<"---> None"<<endl;
            break;
        }

      else 
       {
          

               for (int j = 0; j < N; j++)
               {
                   if(j!=i && a[j][i]!=0 )
                   {
                       double store = a[j][i], vedush=a[i][i];
                       for (int k = i; k < M; ++k) 
                       {
                         a[j][k] -= (a[i][k]*store)/vedush;
                         a[i][k]=a[i][k]/vedush;
                       } 
                   }
                        
               }

         }
    
    }

        cout<<endl;
    for(int i=0;i<N;i++)
    {
     for(int j=N;j<M;j++)
        cout<<a[i][j]<<"  ";
     cout<<endl;
    }


   DelMatrix(a,N,N);
}

void Print(double **a,double*y, int n)
{
  cout<<endl;
   for (int i = 0; i < n; i++) 
  {
    for (int j = 0; j < n; j++) 
    {
      cout << a[i][j] << " ";
    }
    cout<<endl;
  }

}
void Print2(double **a,int n, int m)
{
        cout<<endl;
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<m;j++)
        cout<<a[i][j]<<"       ";
     cout<<endl;
    }
}

void NewMatrix(double**& Mat, int n,int m)
{
    Mat = new double* [n];
   for (int i = 0; i < n; i++)
        Mat[i] = new double[m];
}
void DelMatrix(double**& a, int n, int m)
{
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    a=nullptr;
}
void Copy(double**& a,double** a1,int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a1[i][j] = a[i][j];
}
void Checking_File()
{   double a;
    int k = 0;
    fstream F("arr.txt", ios::in);
    while (F >> a)k++;
    F.close();
    if (!k)
    {
        cout << "Данные файла неверны" << endl;
        system("pause"); exit(1);
    }
}
