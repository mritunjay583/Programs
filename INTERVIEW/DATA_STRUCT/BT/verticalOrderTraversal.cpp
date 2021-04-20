#include<bits/stdc++.h>
#include"Btree1.h"

using namespace std;


void _preOrder(struct node *root,int pos,map<int,vector<int> > &m)
{
    if(root==NULL)
    return;
    m[pos].push_back(root->data);
    _preOrder(root->left,pos-1,m);
    _preOrder(root->right,pos+1,m);

}

// nodes printed using this function may not print in correct order as they 
//appear in real tree vertically(top to bottom)
//probelem is we are traversing the tree in preorder manner in _
void verticalOrder1(struct node *root)
{
    map<int,vector<int> > m;
    _preOrder(root,0,m);
    for(auto x:m)
    {
        cout<<x.first<<" : ";
        for(auto y:x.second)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
}

void verticalOrder2(struct node * root)
{
    int hd=0;
    map<int,vector<int> > m;
    queue<pair<struct node *,int> > q;
    q.push(make_pair(root,hd));
    while(!q.empty())
    {
        pair<struct node *,int> temp=q.front();
        q.pop();
        m[temp.second].push_back(temp.first->data);
        if(temp.first->left)
        q.push(make_pair(temp.first->left,temp.second-1));
        if(temp.first->right)
        q.push(make_pair(temp.first->right,temp.second+1));
    }
    for(auto x:m)
    {
        cout<<x.first<<" : ";
        for(auto y:x.second)
        cout<<y<<" ";
        cout<<endl;
    }
}

int main()
{
    Btree t;
    for(int i=1;i<=10;i++)
    {
        t.insert(i);
    }
    verticalOrder1(t.root);  /// print but not in correct order vertically
    cout<<"\n--------------------\n";
    verticalOrder2(t.root); ///// prints in correct order vertically
}
