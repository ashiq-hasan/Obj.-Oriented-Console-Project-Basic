/*
Task: H1
Family Name: Hasan
Given Name: Ashiq
Matriculation number: 3023634
Uni-Email: ashiq.hasan@stud.uni-due.de
Course of Studies: ISE CE
*/
#include <iostream>
#define A 100
using namespace std;

struct competetion{

string name;
int point;
int matchno;


};


void creatcompetetion( competetion teamlist[], int x )
{  cout<<"Inputs of teams :: \n";
   cout<<"===============\n";

    for(int i=0;i<x;i++)
    {   cout<<"Team "<<i+1<<": ";
        cin>>teamlist[i].name;
        teamlist[i].point=0;
        teamlist[i].matchno=0;
        cout<<"\n";
    }
    cout<<"Info about teams :: \n";
   cout<<"===============\n";
   cout<<"Points   Done matches    Name"<<endl;
    for(int i=0;i<x;i++)
    {
    cout<<teamlist[i].point<<"            "<<teamlist[i].matchno<<"            "<<teamlist[i].name <<endl;
    }
}


int indexnumber(competetion t[],int no)
{
    int i=0,p;
 cout<<"Teams "<<endl<<"======"<<endl;
    while(no>i)
    {
        cout<<i+1<<"  "<<t[i].name<<endl;
   i++;
   }
   cout<<"choose team by number:";
   cin>>p;
   return p-1;
}

void changepoint(competetion t[],int no,int index, int point)
{
    t[index].point=t[index].point+point;
    t[index].matchno=t[index].matchno+1;
}
void sortingbigTosmall(competetion t[],int no)
{
    bool x=true;
    while(x)
    {
        x=false;
        competetion temp;
        for(int i=0;i<no-1;i++)
        {cout<<"oops";
            if(t[i].point<t[i+1].point)
            {
                temp.matchno=t[i].matchno;
                temp.name=t[i].name;
                temp.point=t[i].point;
                t[i].matchno=t[i+1].matchno;
                t[i].name=t[i+1].name;
                t[i].point=t[i+1].point;
                t[i+1].matchno=temp.matchno;
                t[i+1].name=temp.name;
                t[i+1].point=temp.point;

                x=true;
            }
        }
    }
}

void reset(competetion t[],int no){
int i=0;
 while(no>i)
    {
        t[i].matchno=0;
        t[i].point=0;
   i++;
   }

}
 bool Process(competetion teamlist[], int i, int s,bool run)
 {
    switch(s)
    {
    case 0: run=false;break;
    case 1:
            {int index1,index2,point1,point2;
           cout<<"please choose team 1?"<<endl;
           index1=indexnumber(teamlist,i);
           cout<<"please choose team 2?"<<endl;
           index2=indexnumber(teamlist,i);
           if(index1==index2)
            {
                cout<<"Team needs to be different"<<endl;
           }
           else{
           cout<<"input as [ponts of "<<teamlist[index1].name<<"]  :   [points of "<<teamlist[index2].name<<"]   "<<endl;
           cin>>point1;cout<<":"<<endl;cin>>point2;cout<<endl;
           changepoint(teamlist,i,index1,point1);
           changepoint(teamlist,i,index2,point2);
           sortingbigTosmall(teamlist,i);
               }

           break;}


    case 2:
           {
            cout<<"Ranking \n";
            cout<<"===============\n";
             cout<<"Points        Done matches         Name"<<endl;
              for(int x=0;x<i;x++)
              {
             cout<<teamlist[x].point<<"               "<<teamlist[x].matchno<<"                     "<<teamlist[x].name <<endl;
              }
              break;
           }
    case 9:    {reset(teamlist,i);}
    }
 return run;}

int main()

{ int i;int s;bool run=true;
 competetion teamlist[A];
cout<<"Enter the number of team  :  ";
cin>>i;
cout<<endl;

creatcompetetion(teamlist,i);




while(run)
{cout<<"0 end"<<endl<<"1 add result of a match"<<endl<<"2 show ranking "<<endl<<"9 reset point"<<endl;
    cout<<"your choice :"; cin >>s;
    run=Process(teamlist,i,s,run);
}
return 0;
}
