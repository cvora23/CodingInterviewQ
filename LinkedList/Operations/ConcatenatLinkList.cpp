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

void Concatenate(struct node **p,struct node **q)
{
     struct node *temp1,*temp2;
     temp1 = *p;
     temp2 = *q;
     while(temp1->link!=NULL)
     temp1 = temp1->link;
     temp1->link =  temp2;
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
    p = q = NULL;
    for(int i=1;i<6;i++)
    append(&p,i);
    cout<<"Link 1"<<endl;
    display(p);
    cout<<"------------------------"<<endl;
    for(int i=6;i<11;i++)
    append(&q,i);
    cout<<"Link 2"<<endl;
    display(q);
    cout<<"------------------------"<<endl;
    Concatenate(&p,&q);
    cout<<"After Concatenation of 2 links"<<endl;
    display(p);
    cout<<"--------------------------"<<endl;
    return 0;
}
