#include<iostream>
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

void CopyRecursion(struct node *p,struct node **q)
{
     if(p!=NULL)
     {
	   *q = (struct node *)malloc(sizeof(struct node));
	   (*q)->data = p->data;
	   (*q)->link = NULL;
	   CopyRecursion(p->link,&((*q)->link));
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
    struct node *p,*q;
    p=q=NULL;
    for(int i=1;i<6;i++)
    append(&p,i);
    display(p);
    CopyRecursion(p,&q);
    cout<<"---------------------"<<endl;
    display(q);
    return 0;
}
