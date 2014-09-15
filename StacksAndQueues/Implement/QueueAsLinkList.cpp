#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
       int data;
       struct node *link;
};

void addq(struct node **f,struct node **r,int item)
{
     struct node *q;
     q = (struct node *)malloc(sizeof(struct node));
     q->data = item;
     q->link = NULL;
     
     if(*f==NULL)
     *f = q;
     else
     (*r)->link = q;
     
     *r = q;
}

void delq(struct node **f,struct node **r)
{
	 struct node *q;
	 if(*f == NULL)
	 {
				 cout<<"Queue is Empty"<<endl;
				 return;
	 }
	 else
	 {
		 cout<<"Item Removed " <<(*f)->data<<endl;
		 q = *f;
		 *f = (*f)->link;
		 free(q);

		 if(*f==NULL)
		 *r = NULL;
	 }
}

void display(struct node *f)
{
     while(f!=NULL)
     {             
            cout<<f->data<<endl;
            f = f->link;
                   
     }
}

int main()
{   
    struct node *front,*rear;
    front = rear = NULL;    
    for(int i=1;i<6;i++)
    addq(&front,&rear,i);
    display(front);
    for(int i=1;i<7;i++)
    delq(&front,&rear);
    system("Pause");
    return 0;
}
