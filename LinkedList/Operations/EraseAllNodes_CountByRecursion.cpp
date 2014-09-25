#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct node
{
 int data;
 struct node *link;
};      

void append(struct node **q,int num)
{
     struct node *temp,*r;
     temp = *q;
     if(temp == NULL)
     {
             temp = (struct node *)malloc(sizeof(struct node));
             temp->data = num;
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
         r->link = NULL;
         temp->link = r;
     }
}

struct node * EraseAll(struct node **q)
{
     struct node *temp,*r;
     temp = *q;
     while(temp!=NULL)
     {
		  r = temp;
		  temp = temp->link;
		  free(r);
     }
     return NULL;
}

int  Count(struct node *q)
{    
     if(q == NULL)
     return 0;
     else
     return 1+Count(q->link) ;
}

int main()
{
    struct node *p;
    p = NULL;
    for(int i=1;i<16;i++)
    append(&p,i);
    cout<<"The number of elements in the list are : "<<Count(p)<<endl;
    p = EraseAll(&p);
    cout<<"The number of elements in the list after erasing it completely : "<<Count(p)<<endl;
    return 0;
    
}
