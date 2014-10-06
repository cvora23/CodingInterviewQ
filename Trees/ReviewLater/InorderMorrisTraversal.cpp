#include<stdio.h>
#include<stdlib.h>


struct tNode
{
   int data;
   struct tNode* left;
   struct tNode* right;
};

void MorrisTraversal(struct tNode *root)
{
  struct tNode *current,*pre;

  if(root == NULL)
     return;

  current = root;
  while(current != NULL)
  {
    if(current->left == NULL)
    {
      printf(" %d ", current->data);
      current = current->right;
    }
    else
    {
      pre = current->left;
      while(pre->right != NULL && pre->right != current)
        pre = pre->right;

      if(pre->right == NULL)
      {
        pre->right = current;
        current = current->left;
      }
      else
      {
        pre->right = NULL;
        printf(" %d ",current->data);
        current = current->right;
      }
    }
  }
}

struct tNode* newtNode(int data)
{
  struct tNode* tNode = (struct tNode*)
                       malloc(sizeof(struct tNode));
  tNode->data = data;
  tNode->left = NULL;
  tNode->right = NULL;

  return(tNode);
}

int main()
{

  struct tNode *root = newtNode(16);
  root->left        = newtNode(5);
  root->right       = newtNode(7);
  root->left->left  = newtNode(3);
  root->right->left = newtNode(6);
  root->right->right = newtNode(9);

  MorrisTraversal(root);

  getchar();
  return 0;
}
