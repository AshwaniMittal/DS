#include<iostream>
#include<conio.h>
using namespace std;
int arr[10],lower,upper,i,j;
void quick(int *,int,int);
int  main()
{
cout<<"enter 5 elements";
for(i=0;i<5;i++)
cin >> arr[i];
lower=0;
upper=4;
quick(arr,lower,upper);
cout <<"sorted elements: ";
for(i=0;i<5;i++)
cout << arr[i] <<" \t";
}
void quick(int arr[],int lower,int upper)
{
   int p,temp;
   if(lower<upper)
   {
   p=arr[lower];
   i=lower;
   j=upper;
    while(i<j){
      while(arr[i] <= p && i<j )
 i++;
      while(arr[j]>p && i<=j )
	   j--;
      if(i<=j) {
      temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;}
  }
  temp=arr[j];
  arr[j]=arr[lower];
  arr[lower]=temp;
  cout <<"\n";
  for(i=0;i<5;i++)
  cout <<arr[i]<<" ";
  quick(arr,lower,j-1);
  quick(arr,j+1,upper);
 }
}

