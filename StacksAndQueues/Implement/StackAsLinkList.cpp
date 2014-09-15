#include<iostream>
#include<stdlib.h>

using namespace std;

struct node 
{
   int data;
   struct node *link;
};

/*
 * keep changing the head as we need to implement stack using link list data structure.
 */
void push(struct node **q,int item)
{
	 struct node *temp;
	 temp = (struct node *)malloc(sizeof(struct node));
	 temp->data = item;
	 temp->link = *q;
	 *q = temp;
}

/**
 *
 */
int pop(struct node **q)
{
     int item;
     struct node *temp;
     if(*q == NULL)
     {
	   cout<<"Stack is Empty"<<endl;
	   return -1;
     }
     temp = *q;
     item = (*q)->data;
     cout<<"Item Removed  : "<<item<<endl;
     *q = (*q)->link;
     free(temp);
     return item;
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
    struct node *top;
    top = NULL;
    for(int i=1;i<6;i++)
    push(&top,i);
    display(top);
    pop(&top);
    display(top);
    pop(&top);
    display(top);
    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);
    system("Pause");
    return 0;
}
