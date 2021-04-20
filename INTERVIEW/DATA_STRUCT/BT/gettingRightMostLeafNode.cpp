#include<bits/stdc++.h>
#include"Btree1.h"

using namespace std;

void _rightMostChild(struct node* root,int level,int &maxlevel,struct node* &res)
{
    if(root!=NULL)
    {
        _rightMostChild(root->left,++level,maxlevel,res);
        if(maxlevel<=level)
        {
            res=root;
            maxlevel=level;
            
        }
        _rightMostChild(root->right,level,maxlevel,res);
    }
}

struct node* rightMostChild(struct node *root)
{
    struct node* res=NULL;
    int maxlevel=-1;
    _rightMostChild(root,0,maxlevel,res);
    return res;
}


int main()
{
    Btree t;
    for(int i=1;i<=10;i++)
    t.insert(i);
    t.print(t.root);
    cout<<endl;
    struct node* res=rightMostChild(t.root);
    cout<<res->data<<endl;
}