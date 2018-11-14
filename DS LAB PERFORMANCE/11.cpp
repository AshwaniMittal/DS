#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
class node
{
public:
    node *left;
    char name[20];
    node *right;
};
 node *root;
class bst
{
    public:
    node *prev;
    node *temp;
    bst()
    {
        root=NULL;
    }
    void insertnode(char*);
    void deletenode(char*);
    void preorder(node*);
};
int main()
{
    bst b1;
    int choice;
    char name[100];
    while(1)
    {
        cout<<"Enter choice"<<endl<<"1.insertion"<<endl<<"2.deletion"<<endl<<"3.traverse"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
        cout<<"enter string"<<endl;
        cin>>name;
            b1.insertnode(name);
            break;
        case 2:
        cout<<"enter string"<<endl;
        cin>>name;
            b1.deletenode(name);
            break;
        case 3:
            b1.preorder(root);
            break;
        default:
            exit(0);
        }
    }
}
void bst::insertnode(char *str)
{
    node *ptr;
    ptr=new node;
    ptr->left=NULL;
    ptr->right=NULL;
    strcpy(ptr->name,str);
    if(root==NULL)
    {
        root=ptr;
    }
    else
    {
        temp=root;
        while(temp!=NULL)
        {
            prev=temp;
            if(strcmp(temp->name,str)>0)
            {
                temp=temp->left;
            }
            else
            {
                temp=temp->right;
            }
        }
        if(strcmp(prev->name,str)>0)
        {
            prev->left=ptr;
        }
        else
        {
            prev->right=ptr;
        }
    }
}
void bst::deletenode(char *str)
{
    char x[20];
    node *base;
    if(root==NULL)
    {
        cout<<"underflow"<<endl;
        return;
    }
    temp=root;
    while(temp!=NULL && strcmp(temp->name,str)!=0)
    {
        prev=temp;
        if(strcmp(temp->name,str)>0)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
        if(temp==NULL &&strcmp(temp->name,str)!=0)
        {
            cout<<"not found"<<endl;
            return;
        }
    if(temp->left==NULL && temp->right==NULL)
    {
        if(temp==root)
        {
            root=NULL;
            delete temp;
        }
        else
        {
            if(strcmp(prev->name,temp->name)>0)
            {
                prev->left=NULL;
            }
            else
            {
                prev->right=NULL;
            }
            delete temp;
        }
    }
    else if(temp->left!=NULL && temp->right!=NULL)
    {
        base=temp;
        temp=temp->right;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        strcpy(x,temp->name);
        deletenode(x);
        strcpy(base->name,x);
    }
    else
    {
        if(temp==root)
        {
            if(temp->left!=NULL)
               {
                   root=temp->left;
               }
               else
                {
                    root=temp->right;
                }
                delete temp;

        }

        else if(strcmp(prev->name,temp->name)>0)
            {
                if(temp->left!=NULL)
                {
                    prev->left=temp->left;
                }
                else
                {
                    prev->left=temp->right;
                }

                delete temp;
            }
            else
            {
                if(temp->left!=NULL)
                {
                    prev->right=temp->left;
                }
                else
                {
                    prev->right=temp->right;
                }
            }
        }
    }
void bst::preorder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->name;
        preorder(root->left);
        preorder(root->right);
    }
}

