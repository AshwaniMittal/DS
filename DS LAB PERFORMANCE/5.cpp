#include<iostream>
using namespace std;
class pqueue
{
public:
int info;
int priority;
pqueue *next;
pqueue *front=NULL;
pqueue *rear=NULL;
void insertpq(int,int);
void deletepq();
void traverse();
};
void pqueue::insertpq(int item,int item_priority)
{
pqueue *ptr;
pqueue *q;
ptr=new pqueue;
ptr->info=item;
ptr->priority=item_priority;
if(front==NULL || item_priority<front->priority)
  {
ptr->next=front;
front=ptr;
  }
else
  {
      q=front;
while(q->next!=NULL && q->next->priority<=item_priority)
      {
          q=q->next;
      }
ptr->next=q->next;
      q->next=ptr;
  }
}
void pqueue::deletepq()
{ pqueue *temp;
if(front==NULL)
    {
cout<<"underflow"<<endl;
return;
    }
else if(front==rear)
    {
temp=front;
front=NULL;
rear=NULL;
delete temp;
    }
else
    {
temp=front;
front=front->next;
delete temp;
    }
}
void pqueue::traverse()
{pqueue *temp;
if(front==NULL)
    {
cout<<"empty"<<endl;
    }
else
    {
temp=front;
while(temp->next!=NULL)
        {
cout<<temp->info<<endl;
temp=temp->next;
        }
cout<<temp->info<<endl;
    }
}
main()
{
int ch,item,item_priority;
pqueue pq;
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
cout<<"Enter priority"<<endl;
cin>>item_priority;
pq.insertpq(item,item_priority);
break;
case 2:
pq.deletepq();
break;
case 3:
pq.traverse();
break;
default:cout<<"wrong choice";
break;
        }
    }
}

