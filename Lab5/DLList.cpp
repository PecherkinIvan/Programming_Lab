#include "DLList.h"

/// �������� ������� ///

//*����������� ������
void DLList::Show()
{
    if(!F) {
        cout<<"\n * ������ ����\n";
        return;
    }

    Node* temp = F;
    int n=1;

    cout<<"\n ________������________\n\n";
    do
    {
        
        cout<<n<<". "<<temp->data.name<<"   "
            <<temp->data.cost
            <<"���.   "<<temp->data.weight<<"��.   "
            <<temp->data.diameter<<"��.   "
            <<endl;
        temp = temp->next;
        n++;

    } while(temp);

    cout<<endl;
}

//*������������ ���������(�)
bool DLList::MoveNext()
{
    if(!F)  return false;
    if(!C)  {C=F; return true;}
    if(!C->next) return false;
    C=C->next;
    return true;
}
bool DLList::MovePrev()
{
    if(!F) return false;
    if(!C) {C=F; return true;}
    if(!C->prev) return false;
    C=C->prev;
    return true;
}
bool DLList::MoveFirst()
{
    if(!F) return false;
    C=F;
    return true;
}
bool DLList::MoveLast()
{
    if(!L) return false;
    C=L;
    return true;
}

//*���������� ���������
bool DLList::Init(DATA data)
{
    if(!F)
    {
        F = new Node;
        L=F; C=F;
        F->prev=NULL;
        F->next=NULL;
        F->data = data;
        count=1;
        return true;
    }
    else  return false;
}
bool DLList::AddNext(DATA data)
{
    if(!F) return Init(data);

    Node* temp = C->next;  // ����� ��� ����������� ��.
    C->next = new Node;    // �������� ������ 
    C->next->next = temp; // ������� ������� 
    C->next->prev = C;    // ��������� ���������� ������� � �

    if(!temp)
        L=C->next;   // ���� ������� �� ������� ��� ���������
    else
        temp->prev = C->next;  // ����� ������� ��������� � ���������


    C = C->next;     // ������� ��� ����������
    C->data = data; // ��������� 
    count++;
    return true;
}
bool DLList::AddPrev(DATA data)
{
    if(!F) return Init(data);

    Node* temp = C->prev;
    C->prev = new Node;
    C->prev->next = C;
    C->prev->prev = temp;

    if(!temp)
        F = C->prev;
    else 
        temp->next = C->prev;

    C = C->prev;
    C->data = data;
    count++;
    return true;
    cout<<"��������";
}
bool DLList::AddFirst(DATA data)
{
    if(MoveFirst()) return AddPrev(data);
    else return Init(data);
}
bool DLList::AddLast(DATA data)
{
    if(MoveLast()) return AddNext(data);
    else return Init(data);
}

//*��������
bool DLList::DelFirst()
{
    if(!F) return false;
    if(C!=F) MoveFirst();

    Node* temp = C->next;

    if(temp) temp->prev = NULL;
    free(C);
    C=temp;
    F=temp;
    count--;
    if(!temp) {L=NULL; return false;}
    return true;
}
bool DLList::DelLast()
{
    if(!F) return false;
    if(C!=L) MoveLast();

    Node* temp = C->prev;

    if(temp) temp->next = NULL;
    free(C);
    C=temp;
    L=temp;
    count--;

    if(!temp) {F=NULL; return false;}
    return true;

}
bool DLList::DelCurrent()
{
    if(!F) return false;
    if(!C) return false;

    if(C==F) return DelFirst();
    if(C==L) return DelLast();

    Node* temp = C->next;

    C->prev->next = C->next;
    C->next->prev = C->prev;

    free(C);
    C=temp;
    count--;
    return true;
}
void DLList::Clear()
{
    if(!MoveFirst())
    {
        cout<<"\n * ������ ��� ����"<<endl;
        return;
    }
    while(DelCurrent());

    count = 0;
    cout<<"\n * ������ ������.";
}

//*�����
void DLList::GetFail()
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
    count = line;
    fin.clear();  // ������� ������� �� ������
    fin.seekg(0);

    cout<<" ���������� �����: "<< line;

    for (line; line>0 ; line--)
    {
        fin>> new_data.name;      
        fin>> new_data.cost; 
        fin>> new_data.weight;   
        fin>> new_data.diameter;

        DLList::AddNext(new_data);
    }
    
  fin.close();
}
void DLList::GiveFail()
{

     cout<<"\n         ** �������� �������� **       "
        <<"\n 1.) ������������ �������� ����.       "
        <<"\n 2.) �������� � ����� ���� OUTPUT.txt  "
        <<"\n 0.) ���������  "
        <<"\n\n  > ";

            int p;  cin>>p;
            string FAIL_NAME;

            switch(p) {

                case 1:
                {
                FAIL_NAME = "INPUT.txt";
                break;
                }   
                case 2:
                {
                    FAIL_NAME = "OUTPUT.txt";
                    break;
                } 

                case 0:
                {
                 return;
                 break;
                } 
                default:
                {
                    cout<<"\n ������� ������ �����";
                    GiveFail();
                    break;
                }  

            }



    ofstream fout(FAIL_NAME);
    MoveFirst();
    
    do
    {
        fout <<  C->data.name<<' ';      
        fout <<  C->data.cost<<' '; 
        fout <<  C->data.weight<<' ';   
        fout <<  C->data.diameter<<endl;

    } while(MoveNext());

    fout.close();

    cout<<"\n ..������ ������� � "<<FAIL_NAME;
}

//*����������

void DLList::Swap()
{  ///������ �������� � ���������� �������.
    Node* temp = C->prev;
    temp->next = C->next;
    C->prev = temp->prev;

    if(temp->next)
        temp->next->prev = temp;

    if(C->prev)
        C->prev->next = C;

    C->next = temp;
    temp->prev = C;


    if(!temp->next) L=temp;
    if(!C->prev) F=C;
    C=temp;
}

void DLList::SortAlfo()
{
    if(count==1 || count==0 ) return;
    string s1,s2;
    bool flag= true;

    while(flag)
    {
        flag = false;
        MoveFirst();
        while(MoveNext())
        {
            s1= C->prev->data.name;
            s2= C->data.name;
            if(int(s2[0])<int(s1[0]))
            {
                /*AddNext(C->prev->data);
                MovePrev();
                MovePrev();
                DelCurrent();*/

                Swap();

                count--;
                flag = true;
            }

        }
    }
    
}

void DLList::Sort(int point, short int v)
{
    if(count==1 || count==0 ) return;
    bool flag= true;

    switch (v)
    {
    case 1:   // ��������
        {
             while(flag)
            {
                flag = false;
                MoveFirst();
                while(MoveNext())
                {

                    if( (C->prev->data.cost < C->data.cost && point==2)  || 
                        (C->prev->data.weight < C->data.weight && point==3) ||
                        (C->prev->data.diameter < C->data.diameter && point==4) )
                    {
                        Swap();
                        count--;
                        flag = true;
                    }

                }
            }

            break;
        }

    case 2:    // �����������
        {
            while(flag)
            {
                flag = false;
                MoveFirst();
                while(MoveNext())
                {

                    if( (C->prev->data.cost > C->data.cost && point==2)  || 
                        (C->prev->data.weight > C->data.weight && point==3) ||
                        (C->prev->data.diameter > C->data.diameter && point==4) )
                    {
                        Swap();
                        count--;
                        flag = true;
                    }

                }
            }

            break;
        }
    
    default:
        break;
    }
    
}


