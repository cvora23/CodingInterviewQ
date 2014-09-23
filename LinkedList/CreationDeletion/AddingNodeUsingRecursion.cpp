#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
     int data;
     struct node *link;  
};

void append(struct node **q,int item)
{
     if(*q == NULL)
     {
           *q = (struct node *)malloc(sizeof(struct node));
           (*q)->data = item;
           (*q)->link = NULL;
     }
     else
     {
         append(&((*q)->link),item);
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
    p= NULL;
    for(int i=1;i<6;i++)
    	append(&p,i);
    display(p);
    return 0;
}
