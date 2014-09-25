#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;


struct node
{
       struct node *prev;
       int data;
       struct node *next;
};

void append(struct node **q,int num)
{
     struct node *temp,*r;
     temp = *q;
     if(temp == NULL)
     {
		 r = (struct node *)malloc(sizeof(struct node));
		 r->data = num;
		 r->next = NULL;
		 r->prev = NULL;
		 *q = r;
     }
     else
     {
         while(temp->next != NULL)
         temp = temp->next;
         r = (struct node *)malloc(sizeof(struct node));
         r->data = num;
         r->next = NULL;
         r->prev = temp;
         temp->next = r;
        
        
     }
}

void ReverseDoublyLink(struct node **q)
{
     struct node *temp,*r,*s;
     temp = *q;
     r = NULL;
     while(temp!=NULL)
     {                
		  s = r;
		  r = temp;
		  temp = temp->next;
		  r->prev = temp;
		  r->next = s;
     }
     *q = r;
}

void display(struct node *q)
{
     while(q!=NULL)
     {
		   cout<<q->data<<endl;
		   q = q->next;
     }
}

int main()
{   
    struct node *p;
    p = NULL;
    append(&p,1);
    append(&p,2);
    append(&p,4);
    append(&p,3);
    append(&p,5);
    display(p);
    cout<<"-------------------"<<endl;
    ReverseDoublyLink(&p);
    display(p);
    return 0;
}
