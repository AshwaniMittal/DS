#include<iostream>
using namespace std;
class arr
{
    int n,a[100];
public:
    void particular(int b[], int &n, int size);
    void deleteavalue(int b[], int &n, int size);
    void search(int b[], int &n, int size);
    void display(int b[],int &n,int size);
    void deleteatpos(int b[],int &n,int size);
};
void arr::particular(int b[], int &n, int size)
{
    if(n>size)
    {
        cout<<"overflow";
    }
    else
    {
     cout<<"enter the number and index number which you want to insert?";
        int no=0, index=0;
        cin>>no;
        cin>>index;
        for(int i=n;i>=index;i--)
        {
            b[i+1]=b[i];
        }
        b[index]=no;
        n=n+1;
    }
}
void arr::deleteavalue(int b[], int &n, int size)
{
    int s;
   cout<<"enter the no you want to delete.";
   int no;
   cin>>no;
   for(int i=0;i<n;i++)
   {
       if(b[i]==no)
       {
           s=i;
           break;
       }
   }
   for(int i=s;i<n;i++)
   {

       b[i]=b[i+1];
   }
   n=n-1;
}
void arr::search(int b[], int &n, int size)
{
    int item;
    cout<<"enter the item to be searched:\n";
    cin>>item;
    int i;
    int flag=0,loc=0;
    for(i=0;i<=n;i++)
    {
        if(b[i]==item)
        {


        flag=1;
        loc=i;
        break;
        }
    }
    if(flag==1)
        cout<<" element found at index: "<<loc;
    else
        cout<<"not found";

}
void arr::display(int b[],int &n,int size)
{
    for(int i=0;i<n;i++)
{
    cout<<b[i]<<endl;
}
}
void arr::deleteatpos(int b[],int &n,int size)
{
int s;
   cout<<"enter the position at which you want to delete.";
   int pos;
   cin>>pos;
   for(int i=pos;i<=n;i++)
        {
            b[i]=b[i+1];
        }
        n=n-1;
}
      int main()
{
    arr ll;
    cout<<"enter the size of array"<<endl;
    int size;
    cin>>size;
    int a[size];
    cout<<"how many elements you want to enter in an array?";
        int n;
        cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
cout<<"enter your choice "<<endl;
cout<<"1.Insertion at specified position"<<endl;
cout<<"2.Delete an element whose position is given"<<endl;
cout<<"3.Delete an element whose value is given"<<endl;
cout<<"4.find location of given element"<<endl;
cout<<"5.Display elements of a given array"<<endl;
int choice;
cin>>choice;
while(choice!=-1)
{
switch(choice)
{
case 1:
    ll.particular(a,n,size);
    break;
case 2:
    ll.deleteatpos(a,n,size);
    break;
case 3:
    ll.deleteavalue(a,n,size);
    break;
case 4:
    ll.search(a,n,size);
    break;
case 5:
    ll.display(a,n,size);
    break;
}
cin>>choice;
}
}

