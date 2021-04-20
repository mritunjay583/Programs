

#include<bits/stdc++.h>
#include"Btree1.h"


////complexity is O(n)  n=number of nodes

void nodeOfLevelK(struct node * root,int level)
{
    static int flag=1;
    if(!root)return;
    
     nodeOfLevelK(root->left,level-1);
    
    if(level==0 && flag)
    {
        flag=0;
        cout<<root->data<<" ";
    }
    nodeOfLevelK(root->right,level-1);

}

using namespace std;

int main()
{
    Btree t;
    for(int i=1;i<=10;i++)
    t.insert(i);
    t.print(t.root);
    cout<<endl;
    int k=3;
    nodeOfLevelK(t.root,k);
    cout<<endl;
}

