#include<iostream>
#include<stdlib.h>
using namespace std;

class cll
{
	struct node
	{
		int data;
	    struct node *next;		
	}*start,*last;

public:
cll()	
{
	start=NULL;	
}
    void create();
    void show();
    void insert_at_beg();
    void insert_at_end();
    void insert_before_element();
    void insert_after_element();
    void insert_at_specfic();
    void delete_at_beg();
    void delete_at_end();
    void delete_an_ele(int);
    void searching();
    void sorting();
};

void cll::create()
{
	int n;
	cout<<"Enter the number & end by -1"<<endl;
	cin>>n;
	while(n!=-1)
	{
		struct node * new_node,*ptr;
		new_node=new node;
		
		if(start==NULL)
		{
			new_node->data=n;
			new_node->next=new_node;
			start=new_node;
		}
			else
		{
		ptr=start;
		while(ptr->next!=start)
		{
			ptr=ptr->next;
		}
		//start=ptr;
	
			new_node->data=n;
			new_node->next=start;
			start=new_node;
			ptr->next=new_node;
		}
		cin>>n;
	}
}

void cll::insert_at_beg()
{
int num;
    struct node*new_node;
    new_node=new node;
    cout<<"insert element";
    cin>>num;
    new_node->data=num;
    new_node->next=start;
    start=new_node;
}
void cll::insert_at_end()
{
    int n;
    struct node*new_node,*ptr;
    new_node=new node;
    cout<<"insert element";
    cin>>n;
    ptr=start;
    while(ptr->next!=start)
    {
        ptr=ptr->next;
    }
    new_node->data=n;
    new_node->next=start;
    ptr->next=new_node;
}
void cll::insert_before_element()
{
    int num,item;
    struct node*ptr,*save;
    save=NULL;
    ptr=start;
    cout<<"enter posi and num";
    cin>>num;
	cin>>item;
    while(ptr->next!=start)
    {
        if(ptr->data==num)
        {
            if(save==start)
            {
                insert_at_beg();
            }
            else
                {
            struct node*new_node;
            new_node=new node;
            new_node->data=item;
            new_node->next=ptr;
            save->next=new_node;
            break;
            }
        }
        save=ptr;
        ptr=ptr->next;
    }
}
void cll::insert_after_element()
{
     int n,item;
    cout<<"enter posi and num";
    cin>>n>>item;
    struct node*ptr,*new_node;
    new_node=new node;
    ptr=start;
    while(ptr->next!=start)
    {
        if(ptr->data==n)
        {
            cout<<"After insert";
            new_node->next=ptr->next;
            ptr->next=new_node;
            new_node->data=item;
            break;
        }
    ptr=ptr->next;
    }	
}

void cll::show()
{
	struct node *ptr;
    ptr=start; 
    do
    {
	cout<<ptr->data<<endl;
	ptr=ptr->next;
	
	}
    while(ptr!=start);
}


void cll::searching()
{
	struct node* ptr;
    int n,flag=0;
    cout<<"Enter element to search"<<endl;
	cin>>n;
    ptr=start;
    if (ptr==start)
    {
      if (ptr->data==n)
      {
        flag=1;
      }
      else
      {
        flag=0;
      }
      if (flag==1)
      {   
        cout<<"Element exists in the list"<<endl;
      }
      else
      {
      ptr=ptr->next;
      while(ptr->next!=start)
       {
         if (ptr->data==n)
         {
            flag=1;
			break;
         }
         else
         {
            flag=0;
            ptr=ptr->next;
         }
       }
        if (flag==1)
        {
            cout<<"Element exists in the list"<<endl;
        }
      }
    }
      if (ptr->next==start)
      {
        if (ptr->data==n)
        {
            flag=1;
        }
        else
        {
            flag=0;
        }
        if (flag==1)
        {
            cout<<"Element exists in the list"<<endl;
        }
        else if (flag==0)
        {
            cout<<"Element doesnt exist in the list"<<endl;
        }
      }      
}
   void cll:: delete_at_beg()
    {
        struct node *ptr;
        ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        start=start->next;
        ptr->next=start;
    }
    void cll:: delete_at_end()
    {
        struct node *ptr,*save;
        ptr=start;
        save=NULL;
        while(ptr->next!=start)
        {
            save=ptr;
            ptr=ptr->next;
        }
        save->next=start;
    }

 void cll:: delete_an_ele(int n)
    {
        struct node *ptr,*save;
        ptr=start;
        save=NULL;
        do
        {
            if(save==NULL)
            {
                delete_at_beg();
            }
            else if(ptr->next==start)
            {
                delete_at_end();
            }
            else if(ptr->data==n)
            {
                save->next=ptr->next;
                delete ptr;
            }
            save=ptr;
            ptr=ptr->next;
        }
        while(ptr!=start);
    }
void cll::insert_at_specfic()
{
	struct node* node,*ptr,*new1;
	int node_no=1,insert_no,flag=0,count,i;
	node=start->next;
	ptr=start;
	count=i;
	printf("\n Enter position where you want to insert new node:-");
	scanf("%d",&insert_no);

	while(count)
	{
		if(node_no==insert_no)
		{
			//new1=(struct node *)malloc(sizeof(struct node));
			cout<<"\n Insert data for new node:-";
			cin>>new1->data;
			ptr->next=new1;
			new1->next=node;
			flag=1;
			break;
		}
		else
		{
			ptr=ptr->next;
			node=node->next;
		}
		node_no++;
		count--;
	}
	if(flag==0)
	{
		printf("\n Position not found");
	}
	else
	{
		i++;
    }
}
void cll::sorting()
{
	struct node* ptr,*ptr1,*ptr2;
	int i,j,temp,n=1;
	ptr=start;	
    do
    {
	ptr=ptr->next;
        n++;    	
	}
    while(ptr!=start);
	for(i=1;i<=n-1;i++)
	{
		ptr1=start;
		ptr2=ptr1->next;
	    for(j=1;j<=n-i;j++)
		{
			if(ptr1->data>ptr2->data)
			{
				temp=ptr1->data;
			    ptr1->data=ptr2->data;
			    ptr2->data=temp;
			    //ptr1=ptr1->next;
			    //ptr2=ptr2->next;
			}
				ptr1=ptr1->next;
			    ptr2=ptr2->next;
		}
	}
}
main()
{
    int ch;
	cll list;
	//list.create();
	//list.insert_at_beg();
	//list.insert_at_end();
	//list.insert_before_element();
	//list.insert_after_element();
	//list.searching();
	//list.sorting();
	//list.show();
	  while(1)
    {
        cout <<"\n1.Insert at beg\n2.Insert at End\n3.Insert in between a given number \n4.Delete an existing element \n5.Sorting \n6.Searching an element \n7.Display all the elements \n8.Exit\nEnter your choice : ";
        cin >> ch;
        switch(ch)
		{
            case 1:
			//cout<<"\nEnter the element : ";
            //cin >> ch;
            list.insert_at_beg();
            break;
            case 2:list.insert_at_end();  
			break;
			case 3:list.insert_at_specfic();
			break;
			case 4: int n;
            cout<<"Enter the element to be deleted\n";
            cin>>n;
            list.delete_an_ele(n);
            break;
			case 5:list.sorting();
			break;
			case 6:list.searching();
			break;
			case 7:list.show();
			break;
            case 8: exit(0);
        }
    }
	
}


