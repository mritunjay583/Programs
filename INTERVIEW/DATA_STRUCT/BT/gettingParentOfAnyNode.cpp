#include<bits/stdc++.h>
#include"Btree1.h"


////complexity is O(n)  n=number of nodes

using namespace std;

void _parentOfX(struct node* root,int child,struct node *&res)
{
    if(!root)return;
    if(root->left)
    if(root->left->data==child)
    {
        res=root;
    }
    if(root->right)
    if(root->right->data==child)
    {
        res=root;
    }
    _parentOfX(root->left,child,res);
    _parentOfX(root->right,child,res);
}

struct node* parentOfX(struct node *root,int child)
{
    struct node *res=NULL;
    _parentOfX(root,child,res);
    return res;
}

int main()
{
    Btree t;
    for(int i=1;i<=10;i++)
    t.insert(i);
    t.print(t.root);
    cout<<endl;
    int x=3;
    for(int i=1;i<=11;i++)
    {
        struct node* res=parentOfX(t.root,i);
        if(res!=NULL)
        cout<<res->data<<endl;    
        else
        cout<<"-1"<<endl;
        
    }
    
}

