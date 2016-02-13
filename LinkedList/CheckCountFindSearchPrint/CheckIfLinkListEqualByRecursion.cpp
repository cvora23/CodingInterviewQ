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
int CheckIfEqual(struct node *p,struct node *q)
{    
     int flag;
     /**
      * Reached the end of linked list so Equal
      */
     if((p == NULL) && (q == NULL))
     flag = 1;
     else
     {
         if(p == NULL || q == NULL)
         flag = 0;
         else if(p->data != q->data)
         flag = 0;
         else
         flag = CheckIfEqual(p->link,q->link);
     }
     return flag;
     
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
    cout<<"---------------"<<endl;
    for(int i=1;i<6;i++)
    append(&q,i);
    display(q);
    cout<<"------------------"<<endl;
    int Equal = CheckIfEqual(p,q);
    if(Equal == 1)
    cout<<"Both the list are Equal"<<endl;
    else
    cout<<"Both the list are UnEqual"<<endl;
    return 0;
}
