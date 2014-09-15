#include<iostream>
#include<stdlib.h>

// Cracking the Coding Interview Solution 3.2

using namespace std;

int MinValue = 0;
struct node 
{
       int data;
       struct node *link;
}*top1;


void push1(struct node **q,int item)
{
         struct node *temp;
         temp = (struct node *)malloc(sizeof(struct node));
         temp->data = item;
         temp->link = *q;
         *q = temp;
}

int pop1(struct node **q)
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
     MinValue = (*q)->data;
     free(temp);
     return item;
}

void push(struct node **q,int item)
{
         struct node *temp;
         temp = (struct node *)malloc(sizeof(struct node));
         temp->data = item;
         if(*q==NULL)
         {
			 MinValue = item;
			 push1(&top1,MinValue);
         }
         else
         {
             if(item<=MinValue)
             {
				 MinValue = item;
				 push1(&top1,MinValue);
             }
         }
         temp->link = *q;
         *q = temp;
}

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
     if(item == MinValue){
         pop1(&top1);
     }
     cout<<"Item Removed  : "<<item<<endl;
     *q = (*q)->link;
     free(temp);
     return item;
}

void FindMinValue()
{
     cout<<"Minimum Value in stack is "<<MinValue<<endl;
}

int main()
{   
    struct node *top;
    top = top1 = NULL;
    push(&top,1);
    push(&top,4);
    push(&top,3);
    push(&top,2);
    push(&top,5);
    FindMinValue(); // Min value should be 1
    pop(&top); 		// Popped 5
    FindMinValue(); // Min value should be 1
    push(&top,1);
    FindMinValue();// Min value should be 1
    pop(&top);
    FindMinValue();
    return 0;
}
