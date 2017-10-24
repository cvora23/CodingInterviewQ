#include<iostream>
#include<stdlib.h>

using namespace std;


struct node
{
       int data;
       struct node *link;
};

void addQueue(struct node **f,struct node **r, int item)
{
     struct node *q;
     q = (struct node *)malloc(sizeof(struct node));
     q->data = item;
     if(*f == NULL)
     *f = q;
     else
     (*r)->link = q;
     
     *r = q;
     (*r)->link = *f;
}

int DelQueue(struct node **f,struct node **r)
{    
     int item;
     struct node *q;
     if(*f == NULL)
     {
           cout<<"Queue is Empty"<<endl;
     }
     // Only one item remaining
     else if(*f == *r)
     {
          item = (*f)->data;
          free(*f);
          *f = NULL;
          *r = NULL;
     }
     else
     {   
         q = *f;
         item = (*f)->data;
         *f = (*f)->link;
         (*r)->link = *f;
         free(q);
         
     }
     return (item);
}

void display(struct node *f)
{
     struct node *q;
     q = f;
 do
 {
     cout<<q->data<<endl;
     q = q->link;
     
 }while (q!=f);
}

int main()
{   
    struct node *front,*rear;
    front=rear=NULL;  
    addQueue(&front,&rear,10);
    addQueue(&front,&rear,17);
    addQueue(&front,&rear,18);
    addQueue(&front,&rear,5);
    addQueue(&front,&rear,30);
    display(front);
    cout<<"After Removing element from Queue"<<endl;
    int item = DelQueue(&front,&rear);
    cout<<"Item Deleted is : "<<item<<endl;
    display(front);
    return 0;
}
