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

void Reverse1(struct node **q)
{
     struct node *temp,*r,*s;
     r = NULL;
     temp = *q;
     while(temp!= NULL)
     {   
         s = r;
         r = temp;
         temp = temp->link;
         r->link = s;
     }
     *q = r;
}

/* Function to reverse the linked list */
static void Reverse2(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void recursiveReverse3(struct node** head_ref)
{
    struct node* first;
    struct node* rest;

    /* empty list */
    if (*head_ref == NULL)
       return;

    /* suppose first = {1, 2, 3}, rest = {2, 3} */
    first = *head_ref;
    rest  = first->link;

    /* List has only one node */
    if (rest == NULL)
       return;

    /* reverse the rest list and put the first element at the end */
    recursiveReverse3(&rest);
    first->link->link  = first;

    /* tricky step -- see the diagram */
    first->link  = NULL;

    /* fix the head pointer */
    *head_ref = rest;
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
    cout<<"----------------"<<endl;
    Reverse1(&p);
    display(p);
    Reverse2(&p);
    display(p);
    recursiveReverse3(&p);
    display(p);
    return 0;
}
