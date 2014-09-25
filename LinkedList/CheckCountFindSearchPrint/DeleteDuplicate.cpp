#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct node
{
 int data;
 struct node *link;
};      

int Array[100] = {0};

void append(struct node **q,int num)
{
     struct node *temp,*r;
     temp = *q;
     if(temp == NULL)
     {
             temp = (struct node *)malloc(sizeof(struct node));
             temp->data = num;
             Array[num]++;
             temp->link = NULL;
             *q = temp;
     }
     else
     {   
         //temp = *q;
         while(temp->link != NULL)
         temp = temp->link;
         r = (struct node *)malloc(sizeof(struct node));
         r->data = num;
         Array[num]++;
         r->link = NULL;
         temp->link = r;
     }
}

void DeleteDuplicate(struct node **q)
{
     struct node *temp,*temp1,*r;
     temp  = *q;
     while(temp!=NULL && temp->link!=NULL)
     {
      temp1 = temp;
      while(temp1->link!=NULL)
      {
        if(temp->data==temp1->link->data)
        {
         r = temp1->link;
         temp1->link = temp1->link->link;
         free(r);
        }
        else
        {
            temp1 = temp1->link;
        }
      }
      
      temp = temp->link;
    }
}

void display(struct node *q)
{    
     while(q!=NULL)
     {
                   cout<<q->data<<endl;
                   q = q->link;
     }
}

int main()
{
    struct node *p;
    p = NULL;
    append(&p,1);
    append(&p,2);
    append(&p,3);
    append(&p,1);
    append(&p,5);
    append(&p,7);
    append(&p,3);
    display(p);
    cout<<"------------------"<<endl;
   // for(int i=0;i<10;i++)
   // cout<<Array[i]<<endl;
    DeleteDuplicate(&p);
    display(p);
    return 0;
}
