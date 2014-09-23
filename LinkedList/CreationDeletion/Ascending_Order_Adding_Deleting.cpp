#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

struct node
{
       int data;
       struct node *link;
};

void add(struct node **q,int num)
{
     struct node *temp,*r;
     r = (struct node *)malloc(sizeof(struct node));
     r->data =  num;
     temp = *q;
     /**
      * Adding the first element
      * 	OR
      * Element added is less than first element
      */
     if(temp == NULL || temp->data>=num)
     {
		 r->link = temp;
		 *q = r;
		 return;
     }
     else
     {
         while(temp!=NULL)
         {                
			 if(temp->data<=num && (temp->link->data>num||temp->link == NULL))
			 {
				r->link = temp->link;
				temp->link = r;
				return;
			 }
			 temp = temp->link;
         }
     }
}

void Delete(struct node **q,int num)
{
     struct node *temp,*r;
     temp = *q;
     while(temp!= NULL)
     {                      
		if(temp->data==num)
		{
		   if(temp == *q)
		   {
			   *q = temp->link;
			   cout<<"Deleting element "<<num <<" in the list"<<endl;
			   free(temp);
			   return;
		   }
		   else if(temp->link == NULL)
		   {
			   r->link = NULL;
			   cout<<"Deleting element "<<num <<" in the list"<<endl;
			   free(temp);
			   return ;
		   }
		   else
		   {
				r->link = temp->link;
				cout<<"Deleting element "<<num<<" in the list"<<endl;
				free(temp);
				return;
		   }
		}
		else
		{
			r = temp;
			temp = temp->link;
		}
     }
     cout<<"Element not found in the list"<<endl;
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
    add(&p,8);
    add(&p,5) ;
    add(&p,4);
    add(&p,2);
    add(&p,7);
    display(p);
    cout<<"-------------------"<<endl;
    Delete(&p,2);
    add(&p,1);
    display(p);
    return 0;
}
