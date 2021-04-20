#include<bits/stdc++.h>
#include"Btree1.h"


using namespace std;

int heightOfTree(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return max(heightOfTree(root->left),heightOfTree(root->right))+1;
}

int main()
{
    Btree t;
    for(int i=1;i<=10;i++)
    t.insert(i);
    t.print(t.root);
    cout<<endl;
    cout<<heightOfTree(t.root);
}