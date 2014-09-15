#include<iostream>
#include<stdlib.h>

using namespace std;


struct node 
{
       int data;
       struct node *link;
}*top2,*top,*top1;

void push(struct node **q,int item)
{
         struct node *temp;
         temp = (struct node *)malloc(sizeof(struct node));
         temp->data = item;
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
    // cout<<"Item Removed  : "<<item<<endl;
     *q = (*q)->link;
     free(temp);
     return item;
}
void addLargeNo(struct node **p,struct node **q)
{    
     struct node *temp1 ,*temp2;
     temp1 = *p;
     temp2 = *q;
     int no1,no2,sum = 0,carry = 0;
     while(*p!=NULL && *q!=NULL)
     {
	   no1 = pop(p);
	   //cout<<no1<<endl;
	   no2 = pop(q);
	   //cout<<no2<<endl;
	   sum+= no1+no2;
	   //cout<<sum<<endl;

	   if(sum>9)
	   {
		   sum = sum%10;
		   carry = 1;
	   }
	   else
	   {
		   carry = 0;
	   }
	   push(&top2,sum);
	   sum = 0;
	   sum+=carry;
                   
     }
     while(*p!=NULL)
     {
           no1 = pop(p);
           sum+= no1;   
           push(&top2,sum)      ;
     }
     while(*q!=NULL)
     {
      no2 = pop(q);
      sum+=no2;
      push(&top2,sum);
     }
}

int main()
{   
    top = top1 = top2 = NULL;
    int item;
    push(&top,3);
    push(&top,7);
    push(&top,8);
    push(&top,4);
    push(&top1,5);
    push(&top1,9);
    push(&top1,2);
    addLargeNo(&top,&top1);
    while(top2!=NULL)
    {
		item = pop(&top2);
		cout<<item;
    }
    cout<<endl;
    return 0;
}

