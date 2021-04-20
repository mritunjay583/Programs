#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct BST
{
    int data;
    struct BST *right;
    struct BST *left;
};
typedef struct BST BST;

BST *RooT;

BST *insert(BST *RooT,int da)
{
   if(RooT==NULL)
   {
       BST *temp=(BST *)malloc(sizeof(BST));
       temp->data=da;
       temp->right=NULL;
       temp->left=NULL;
       RooT=temp;
   }

   else if(da < RooT->data)
        RooT->left=insert(RooT->left,da);

   else
        RooT->right=insert(RooT->right,da);

  return RooT;
}

void inorder(BST *RooT)
{
    BST *tmp;
    tmp=RooT;
    if(tmp!=NULL)
    {
        inorder(RooT->left);
        printf("%d ",tmp->data);
        inorder(RooT->right);
    }
}

int main()
{

    RooT=insert(RooT,23);
    RooT=insert(RooT,10);
    RooT=insert(RooT,10);
    inorder(RooT);
    return 0;
}
