#include<iostream>
using namespace std;
class DLL
{
    struct node
    {
        int data;
        struct node *next;
        struct node *prev;
    }*start,*last;
public:
    DLL()
    {
        start=NULL;
        last=NULL;
    }
    void create()
    {
        int n;
        struct node *ptr;
        cout<<"Enter a number\n";
        cin>>n;
        while(n!=-1)
        {
            struct node *new_node;
            new_node=new node;
            if(start==NULL)
            {
                new_node->data=n;
                new_node->next=NULL;
                new_node->prev=NULL;
                start=new_node;
                last=new_node;
            }
            else
            {
                new_node->data=n;
                new_node->next=start;
                new_node->prev=NULL;
                start->prev=new_node;
                start=new_node;
            }
            cout<<"Enter a number\n";
            cin>>n;
        }
    }
    void display()
    {
        cout<<"The list is\n";
        struct node *ptr;
        ptr=start;
        while(ptr!=NULL)
        {
            cout<<ptr->data<<endl;
            ptr=ptr->next;
        }
    }
    /*void rdisplay()
    {
        cout<<"The reverse of the list is\n";
        struct node *ptr;
        ptr=last;
        while(ptr!=NULL)
        {
            cout<<ptr->data<<endl;
            ptr=ptr->prev;
        }
    }*/ 
	void insert_at_beg(int n)
    {
        struct node *new_node;
        new_node=new node;
        struct node *ptr;
        ptr=start;
            if(ptr->prev==NULL)
            {
                new_node->data=n;
                new_node->next=start;
                new_node->prev=NULL;
                ptr->prev=new_node;
                start=new_node;
            }
    }
    void insert_at_end(int n)
    {
        struct node *new_node;
        new_node=new node;
        struct node *ptr,*save;
        ptr=start;
        save=NULL;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        new_node->data=n;
        new_node->next=NULL;
        new_node->prev=ptr;
        ptr->next=new_node;
    }
   /* void insert_before(int ele,int n)
    {
        struct node *new_node;
        struct node *ptr;
        new_node=new node;
        ptr=start;
        while(ptr->next!=NULL)
        {
            if(ptr->data==ele)
            {
                if(ptr->prev==NULL)
                {
                    insert_at_beg(n);
                }
                else
                {
                    new_node->data=n;
                    new_node->next=ptr;
                    new_node->prev=ptr->prev;
                    ptr->prev=new_node;
                    new_node->prev->next=new_node;
                }
            }
            ptr=ptr->next;
        }
    }*/
    void insert_after(int ele,int n)
    {
        struct node *new_node;
        struct node *ptr;
        new_node=new node;
        ptr=start;
        while(ptr!=NULL)
        {
            if(ptr->data==ele)
            {
                if(ptr->next==NULL)
                {
                    insert_at_end(n);
                }
                else
                {
                    new_node->data=n;
                    new_node->next=ptr->next;
                    new_node->prev=ptr;
                    ptr->next=new_node;
                    new_node->next->prev=new_node;
                }
            }
            ptr=ptr->next;
        }
    }
    void insert_at_proper(int num)
    {
        int flag=0;
        struct node *ptr;
        struct node *new_node;
        new_node=new node;
        ptr=start;
        while(ptr!=NULL)
        {
            if(ptr->data>num)
            {
                if(ptr->prev==NULL)
                {
                    insert_at_beg(num);
                    flag=1;
                    break;
                }
                else
                {
                    new_node->data=num;
                    new_node->next=ptr;
                    new_node->prev=ptr->prev;
                    ptr->prev=new_node;
                    new_node->prev->next=new_node;
                    flag=1;
                    break;
                }
            }
            ptr=ptr->next;
        }
            if(flag==0)
            {
                insert_at_end(num);
            }
    }
    void delete_beg()
    {
     struct node* ptr=start;
     start=ptr->next;
    }

    void delete_end()
    {
      struct node* ptr=start;
      while(ptr->next!=NULL)
      {
          ptr=ptr->next;
      }
      struct node* temp;
      temp=ptr->prev;
      temp->next=NULL;
      last=temp;
    }

    void delete_given(int x)

    {
      struct node* ptr= start;
      while(ptr->next!=NULL)
      {
        if(ptr->data==x)
        {
            break;
        }
        ptr=ptr->next;
      }
      struct node* temp;
      temp=ptr->prev;
      temp->next=ptr->next;
      ptr->prev=temp;

    }

 void searching(int x)

 {

  struct node* ptr=start;
  while(ptr->next!=NULL)
  {
      if(ptr->data==x)
      {
          cout<<"element exists";
      }
      ptr=ptr->next;
  }
 }

 void sorting(int c)

 {

   struct node* ptr1=start;
    struct node* ptr2= ptr1->next;
    int  temp;
    int i=0;
   while(i!=c)
   {
       ptr1=start;
       ptr2= ptr1->next;
       while(ptr2!=NULL)
       {
           if(ptr1->data > ptr2->data )
           {
               temp= ptr1->data;
               ptr1->data=ptr2->data;
               ptr2 ->data = temp;
            }
            ptr1= ptr1->next;
            ptr2= ptr2->next;
        }
        i++;
    }
}
};
main()
{
    int ch;
    int tt;
    DLL list1;
    list1.create();
    while(1)
    {
        cout<<"1.Insert an element in the beginning\n";
        cout<<"2.Insert an element in the end\n";
        cout<<"3.Insert at proper position\n";
        cout<<"4.Delete an existing Element\n";
        cout<<"5.Display the list\n";
        cout<<"6.Sorting an Element\n";
        cout<<"7.Searching all Element\n";
        cout<<"8.To exit\n";
        cin>>ch;
        switch(ch)
        {
        case(1):
            {
                int n;
                cout<<"Enter the element to be inserted in the beginning\n";
                cin>>n;
                list1.insert_at_beg(n);
                break;
            }
        case(2):
            {
                int n;
                cout<<"Enter the element to be inserted in the end\n";
                cin>>n;
                list1.insert_at_end(n);
                break;
            }
        case(3):
            {
                int n;
                cout<<"Enter an element to be inserted\n";
                cin>>n;
                list1.insert_at_proper(n);
                break;
            }
            case(4):
            {
	cout<<"enter any number";
				int c;
                cin>>c;
                list1.delete_given(c);
			}
        case(5):
            {
                list1.display();
                break;
            }
        case(6):
        {
	list1.sorting(tt);
	break;
		}
		case(7):
		{
			cout<<"enter the number you want to search";
            int d;
            cin>>d;
			list1.searching(d);
			break;
		}
         case 8:
		 {
			exit(0);
		} 
        }
    }
}










