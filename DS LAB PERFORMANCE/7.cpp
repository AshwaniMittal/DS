#include<iostream>
using namespace std;
class queue
{
public:
int info;
queue *next;
queue *f=NULL;
queue *rear=NULL;
void inserting(int item);
void deleting();
void traverse();
};
void queue::inserting(int item)
{
queue *temp,*ptr;
ptr=new queue;
ptr->info=item;
ptr->next=NULL;
if(f==NULL && rear==NULL)
{    f=ptr;
rear=ptr;
    }
else
    {
rear->next=ptr;
rear=ptr;
    }
}
void queue::deleting()
{
queue *temp;
if(f==NULL)
    {
cout<<"underflow"<<endl;
return;
    }
else if(f==rear)
    {
        temp=f;
        f=NULL;
        rear=NULL;
        delete temp;
    }
else
    {
        temp=f;
        f=f->next;
        delete temp;
    }
}
void queue::traverse()
{queue *temp;
if(f==NULL)
    {
      cout<<"empty"<<endl;
    }
else
    {
      temp=f;
      while(temp->next!=NULL)
        {
          cout<<temp->info;
          temp=temp->next;
        }
        cout<<temp->info;
    }
}
int main()
{
int ch,item;
queue q1;
while(1)
    {
cout<<"Enter choice"<<endl;
cout<<"1.insert"<<endl;
cout<<"2.delete"<<endl;
cout<<"3.traverse"<<endl;
cin>>ch;
switch(ch)
        {
case 1:
cout<<"Enter the item"<<endl;
cin>>item;
q1.inserting(item);
break;
case 2:
q1.deleting();
break;
case 3:
q1.traverse();
break;
default:cout<<"wrong choice";
break;
        }
    }
}

