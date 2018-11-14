#include<iostream>
using namespace std;
class insertsort
{
	int a[100],k,ptr,n,i,temp;
	public:
		void in()
		{

	cout<<"Enter the no. of elements in array"<<endl;
	cin>>n;
	cout<<"Enter array elements"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
	void sort();
	void out()
	{
	    cout<<"Sorted array is:";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}
};
void insertsort::sort()
{
	for(k=1;k<n;k++)
	{
		temp=a[k];
		ptr=k-1;
		while(temp<a[ptr] && ptr>=0)
		{
			a[ptr+1]=a[ptr];
			ptr--;
		}
		a[ptr+1]=temp;
	}
}
int main()
{
	insertsort s1;
	s1.in();
	s1.sort();
	s1.out();
}

