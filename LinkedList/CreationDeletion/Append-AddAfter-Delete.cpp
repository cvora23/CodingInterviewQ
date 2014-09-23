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

void add_data_after(struct node **q,int pos,int num)
{    
     struct node *temp,*r;
     if(pos == 0)
     {
             temp = (struct node *)malloc(sizeof(struct node));
             temp->data = num;
             temp->link = *q;
             *q = temp;
     }
     else
     {   
         temp = *q;
         for(int i=1;i<pos;i++)
         {
        	 temp = temp->link;
			 if(temp == NULL)
			 {
				 cout<<"There are less than "<<pos<<" elements in the list "<<endl;
				 return;
			 }
         }
         r = (struct node *)malloc(sizeof(struct node));
         r->data = num;
         r->link = temp->link;
         temp->link = r;
         
     }
}

void Delete(struct node **q,int num)
{
     struct node *temp,*prev;
     temp = *q;
     while(temp!= NULL)
     {                      
		if(temp->data==num)
		{
		   if(temp == *q)
		   {
			   /**
			    * Deleting first element
			    */
			   *q = temp->link;
			   cout<<"Deleting element "<<num <<" in the list"<<endl;
			   free(temp);
			   return;
		   }
		   else if(temp->link == NULL)
		   {
			   /**
			    * Deleting last element
			    */
			   prev->link = NULL;
			   cout<<"Deleting element "<<num <<" in the list"<<endl;
			   free(temp);
			   return ;
		   }
		   else
		   {
			   /**
			    * Deleting element in the middle
			    */
			   prev->link = temp->link;
				cout<<"Deleting element "<<num<<" in the list"<<endl;
				free(temp);
				return;
		   }
		}
		else
		{
			prev = temp;
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
