#include<iostream>
#include<string.h>
#include<stddef.h>
#include<stdlib.h>

using namespace std;

struct node
{
       int data;
       struct node *link;
};
void ascending(struct node **q,int num)
{
     struct node *temp,*r;
     temp = *q;
     r = (struct node *)malloc(sizeof(struct node));
     r->data = num;
     if(*q ==NULL || (*q)->data>num)
     {
             *q = r;
             (*q)->link = temp;
     }
     else
     {
         while(temp!=NULL)
         {
			  if(temp->data<=num&&(temp->link->data>num||temp->link==NULL))
			  {
				  r->link = temp->link;
				  temp->link = r;
				  return;
			  }
			  temp = temp->link;
          }
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
void merge(struct node*p,struct node*q,struct node**r)
{
     struct node *temp;
     temp = *r;
     if(p==NULL && q==NULL)
     return;
     while(p!=NULL && q!=NULL)
     {
                   if(*r==NULL)
                   {
                               *r = (struct node *)malloc(sizeof(struct node));
                               temp = *r;
                               
                   }
                   else
                   {
                       temp->link = (struct node *)malloc(sizeof(struct node));
                       temp = temp->link;
                   }
                   if(p->data<q->data)
                   {
                                      temp->data = p->data;
                                      p = p->link;
                   }
                   else if(p->data>q->data)
                   {
                        temp->data = q->data;
                        q = q->link;
                   }
                   else
                   {
                        temp->data = q->data;
                        p = p->link;
                        q = q->link;
                   }
     }
     while(p!=NULL)
     {
                   temp->link = (struct node *)malloc(sizeof(struct node));
                   temp = temp->link;
                   temp->data = p->data;
                   p = p->link;
     }
     while(q!=NULL)
     {             
                   temp->link = (struct node *)malloc(sizeof(struct node));
                   temp = temp->link;
                   temp->data = q->data;
                   q = q->link; 
     }
     temp->link = NULL;
}

int main()
{
 struct node *first,*second,*third;
 first = NULL;
 second = NULL;
 third = NULL;
 ascending(&first,15);
 ascending(&first,4);
 ascending(&first,3);
 ascending(&first,2);
 ascending(&first,1);
 ascending(&second,15);
 ascending(&second,11);
 ascending(&second,10);
 ascending(&second,9);
 ascending(&second,7);
 display(first);
 cout<<"------------------"<<endl;
 display(second);
 cout<<"------------------"<<endl;
 merge(first,second,&third);
 display(third);
 cout<<"------------------"<<endl;
 system("pause");
 return 0;
     
}
