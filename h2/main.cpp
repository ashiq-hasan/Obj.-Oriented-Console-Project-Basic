/*
Task: H2
Family Name: Hasan
Given Name: Ashiq
Matriculation number: 3023634
Uni-Email: ashiq.hasan@stud.uni-due.de
Course of Studies: ISE CE
*/
#include <iostream>
#define N 100
using namespace std;

struct obstacls{
string  name;
double x;
double y;
double distance;
obstacls* next;
};
double sqRt(double x)/*just for root. we can also use sqrt function using #include <math.h> on top*/
{   double i=0;

   while(i*i<x) {
        i=i+0.000001;
    }
    return i;
}
double distanceOf(double x1, double y1,double x2, double y2)
{
    return sqRt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}

obstacls* nearst(obstacls* head,obstacls* o)/*it will find the nearest obstacle from o in the List */
{
     obstacls* ans;
     obstacls* List;
     ans=nullptr;
     double distance[N],distanceTemp,key;
     int i=0;
     bool gate=true;

    if(head->next!=nullptr)/*checking if it is empty or not and list.next is also empty or not */
    {  List=head;
       while(List!=nullptr)
       {
       if(distanceOf(o->x,o->y,List->x,List->y)!=0)
       {
          distance[i]=distanceOf(o->x,o->y,List->x,List->y);
          i++;
       }
           List=List->next;
       }

       while(gate)
       {    gate=false;
           for(int l=0;l<i-1;l++)
           {
               if(distance[l]>distance[l+1])
               {
                   distanceTemp=distance[1];
                   distance[l]=distance[l+1];
                   distance[l+1]=distanceTemp;
                   gate=true;
               }
           }
       }
       key=distance[0];
        gate=true;
        List=head;
        while(List!=nullptr)
       {   if(key==distanceOf(o->x,o->y,List->x,List->y))
       {
           ans=List;break;
       }
           List=List->next;

       }



    }



return ans;}

obstacls* insertinList(obstacls* headOfsortedList,obstacls* o)
    {   obstacls* sortedList;
    obstacls* temp;



        if(headOfsortedList!=nullptr)
    {

    if(headOfsortedList->next==nullptr)
    {
        if((o->distance)<=(headOfsortedList->distance))
            {

              o->next=headOfsortedList;
              headOfsortedList=o;
            }else{

            headOfsortedList->next=o;

            }
    }else{
        if((headOfsortedList->distance)>(o->distance))
        {
            o->next=headOfsortedList;

              headOfsortedList=o;
        }
        else{
    sortedList=headOfsortedList;
         while(sortedList->next!=nullptr)
        {

             if((sortedList->distance)<=(o->distance) && (o->distance)<(sortedList->next->distance))
        {
            temp=sortedList->next;
            sortedList->next=o;
            o->next=temp;
            break;

        }
            sortedList=sortedList->next;
        }
        if(sortedList->next==nullptr)
        {

            sortedList->next=o;
        }
        }}
    }else{

    headOfsortedList=o;

    }

    return headOfsortedList;
    }

void printListOfObstacle(obstacls* List)
{   obstacls* obstacleList;
    obstacleList=List;
    while(obstacleList!=nullptr)
    {
        cout<<"obstacle "<<obstacleList->name<<": ("<<obstacleList->x<<", "<<obstacleList->y<<"), distance: "<<obstacleList->distance<<"m, nearest to this: ";
        if(nearst(List,obstacleList)!=nullptr)
        {
          cout<<nearst(List,obstacleList)->name;
        }else{cout<<" none ";}
        cout<<endl;
        obstacleList=obstacleList->next;
    }
}
void deletAllObstales(obstacls* obstacleList)
{   cout<<"delete:";
    while(obstacleList!=nullptr)
    {


        cout<<obstacleList->name<<" ";delete obstacleList;
        obstacleList=obstacleList->next;
    }
}
int main()
{
    obstacls* head;
    obstacls* temp;
    head=nullptr;
    int loopgate=1;
 while(loopgate)
 {
     obstacls* o =new obstacls;

     cout<<"string describing obstacle ('end' for end of input): ";
     cin>>o->name;
      if(o->name=="end")
     {
         loopgate=0;
     }
     if(loopgate==1)
     {
        cout<<"x and y coordinate:";
     cin>>o->x;
     cin>>o->y;
     o->distance=distanceOf(0,0,o->x,o->y);
     o->next=nullptr;cout<<" distance "<<distanceOf(0,0,o->x,o->y)<<endl;
     head=insertinList(head,o);

     }


 }
 temp=head;
 printListOfObstacle(temp);

 deletAllObstales(head);
    return 0;
}

