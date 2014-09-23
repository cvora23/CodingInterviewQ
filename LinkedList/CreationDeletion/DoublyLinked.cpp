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


void add_data_after(struct node **q,int pos,int num)
{
	 struct node *r,*temp;
	 temp = *q;
	 if(pos == 0)
	 {
		r = (struct node *)malloc(sizeof(struct node));
		r->data = num;
		r->next = temp;
		r->prev = NULL;
		temp->prev = r;
		*q = r;
	 }
	 else
	 {
		 for(int i=1;i<pos;i++)
		 {
			  temp = temp->next;
			  if(temp == NULL)
			  {
				  cout<<"The number of nodes in the list are less than " <<pos<<endl;
				  return;
			  }
		 }
		 r = (struct node *)malloc(sizeof(struct node));
		 r->data = num;
		 r->next = temp->next;
		 temp->next = r;
		 r->prev = temp;
		 temp->next->prev = r;

	 }
}

void Delete(struct node **q,int num)
{
     struct node *temp;
     temp = *q;
     while(temp!=NULL)
     {
		  if(temp->data==num)
		  {
			 if(temp==*q)
			 {
				 *q = temp->next;
				 temp->next->prev = NULL;
				 cout<<"Deleting element "<<num <<" in the list"<<endl;
				 free(temp);
				 return;
			 }
			 else if(temp->next == NULL)
			 {
				  temp->prev->next = NULL;
				  cout<<"Deleting element "<<num <<" in the list"<<endl;
				  free(temp);
				  return;
			 }
			 else
			 {
				 temp->prev->next = temp->next;
				 temp->next->prev = temp->prev;
				 cout<<"Deleting element "<<num <<" in the list"<<endl;
				 free(temp);
				 return;
			 }
		  }
		  else
		  {
			  //r = temp;
			  temp = temp->next;
		  }
     }
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
    add_data_after(&p,3,3);
    add_data_after(&p,1,4);
    add_data_after(&p,0,5);
    display(p);
    cout<<"----------------------"<<endl;
    Delete(&p,1);
    //add_data_after()
    //append(&p,3);
    display(p);
    cout<<"--------------------------"<<endl;
    add_data_after(&p,4,7);
    append(&p,100);
    display(p);
    return 0;
}
