#include<bits/stdc++.h>
#include"Btree1.h"

using namespace std;

void _rec_levelOrder(struct node * root,int level,unordered_map<int,vector<int>> &m)
{
    if(root!=NULL)
    {
        _rec_levelOrder(root->left,++level,m);
        m[level].push_back(root->data);
        _rec_levelOrder(root->right,level,m);
    }
}

void rec_levelOrder(struct node *root)
{
    unordered_map<int,vector<int> > m;
    _rec_levelOrder(root,-1,m);
    cout<<endl;
    for(auto x:m)
    {
        cout<<x.first<<" :- ";
        for(auto y:x.second)
        cout<<y<<" ";
        cout<<endl;
    }
}

void levelOrder(struct node *root)
{
    queue<struct node*> q;
    q.push(root);
    while(1)
    {
       int nodecnt=q.size();
       while(nodecnt>0)
       {
           struct node *temp=q.front();
           q.pop();
           cout<<temp->data<<" ";
           if(temp->left)
           q.push(temp->left);
           if(temp->right)
           q.push(temp->right);
           nodecnt--;
       }
       cout<<endl;
       if(q.empty()==true)
       break;
    }
}

int main()
{
    Btree t;
    for(int i=1;i<=10;i++)
    t.insert(i);
    t.print(t.root);
    rec_levelOrder(t.root);
    levelOrder(t.root);
}