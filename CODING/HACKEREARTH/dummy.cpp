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
       BST *RooT=(BST *)malloc(sizeof(BST));
       RooT->data=da;
       RooT->right=NULL;
       RooT->left=NULL;
   }

   else if(da < RooT->data)
        RooT->left=insert(RooT->left,da);

   else
        RooT->right=insert(RooT->right,da);

  return RooT;
}

BST *minimum(BST *RooT)
{
    BST *tmp;
    tmp=RooT;
    if(tmp==NULL)
    {
        printf("NIL");
        return RooT;
    }

    if(tmp->left==NULL)
    {
        printf("%d",tmp->data);
        return RooT;
    }

    while(tmp->left!=NULL)
         tmp=tmp->left;

    printf("%d",tmp->data);

   return RooT;
}

void inorder(BST *RooT)
{
    BST *tmp;
    tmp=RooT;
    if(tmp!=NULL)
    {
        inorder(RooT->left);
        printf("%d",tmp->data);
        inorder(RooT->right);
    }
}

int main()
{
    BST *catch;
    int da;
    char string[10],mim[]="minm",max[]="maxm",in[]="inor",pr[]="prer",po[]="post",so[]="stop",ins[]="insr",del[]="delt",sea[]="srch",suc[]="succ",prede[]="pred";
      do
      {
        scanf("%s",&string);
       if(strcmp(string,ins)==0)
       {
          scanf("%d",&da);
          catch=insert(RooT,da);
       }
       if(strcmp(string,del)==0)
        {

        }
        if(strcmp(string,sea)==0)
        {

        }
        if(strcmp(string,suc)==0)
        {

        }
        if(strcmp(string,prede)==0)
        {

        }
       if(strcmp(string,mim)==0)
        {
            catch=minimum(RooT);
        }
       if(strcmp(string,max)==0)
        {

        }
       if(strcmp(string,in)==0)
       {
             inorder(RooT);
       }
       if(strcmp(string,pr)==0)
       {

       }
       if(strcmp(string,po)==0)
       {

       }
    } while(strcmp(string,so)!=0);
    return 0;
}
