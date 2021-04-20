#include<bits/stdc++.h>
#include"Btree1.h"
using namespace std;

void morrisTraversal(struct node * root)
{
    struct node * cur=root;
    while(cur!=NULL)
    {
        //if left child of cur is not NULL
        if(cur->left)
        {
            //findng inorder predecessor if there is left child
            struct node *pred = cur->left; 
            while (pred->right != NULL && pred->right != cur) 
                pred = pred->right; 
            //if predecessor is not connected to cur then connect it 
            if(pred->right==NULL)
            {
                pred->right=cur;
                cur=cur->left;
            }
            else //if predecessor is connected to cur then its time to restore tree
            {   // by making right pointer of pred to NULL and move cur to cur->right
                pred->right=NULL;
                cout<<cur->data<<" ";
                cur=cur->right;
                
            }
            
        }
        else // if left child of cur is NULL then just simply move to right subtree
        {
            cout<<cur->data<<" ";
            cur=cur->right;
        }
    }
    
}
void inorder(struct node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    Btree t;
    for(int i=1;i<=10;i++)
    t.insert(i);
    inorder(t.root);
    cout<<"\n--------\n";
    morrisTraversal(t.root);
    
}