#include<iostream>
using namespace std;

class arr
{
	public:
		void create();
		void display();
};
void arr::create()
{
	int i,n,flag=0,j;
 cout<<"enter the no. of elements in an array"<<endl;
	cin>>j;
	int a[j];
	cout<<"enter the "<<j<<" elements"<<endl;
	for(i=0;i<j;i++)
	{
	cin>>a[i];
    }		
}
void arr::display()
{
	int flag=0,n,i,j,a[100];
cout<<"enter no. to be checked"<<endl;
	cin>>n;
	for(i=0;i<j;i++)
	{
		if(a[i]==n)
		{
			flag=1;
			cout<<"index of no. is "<<i<<endl;
			break;
		}
		else{
			flag=0;
		}
	}
	if(flag==1)
	{
		cout<<"YES no. is present";

	}
	else
    {
 cout<<"NO no. is not present";
	}
}
int main()
{
	arr ll;
	ll.create();
	ll.display();
}

