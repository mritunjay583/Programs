#include<bits/stdc++.h>
#include"Btree1.h"

using namespace std;

void _deepestNode(struct node* root,int level,int &maxlevel,int &res)
{
    if(root!=NULL)
    {
        _deepestNode(root->left,++level,maxlevel,res);
        if(maxlevel<=level) /// for deepest rightmost node
        { //if(maxlevel<level) // for deepest leftmost node
            res=root->data;
            maxlevel=level;
        }
        _deepestNode(root->right,level,maxlevel,res);
    }
}


int deepestNode(struct node *root)
{
    int maxlevel=-1;
    int res=-1;
    _deepestNode(root,0,maxlevel,res);
    return res;
}

int main()
{
    Btree t;
    for(int i=1;i<=10;i++)
    t.insert(i);
    t.print(t.root);
    cout<<endl;
    cout<<deepestNode(t.root)<<endl;
}