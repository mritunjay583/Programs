#include<bits/stdc++.h>
#include"Btree1.h"

using namespace std;

void re_inOrder(struct node* root)
{
    if(!root)return;
    re_inOrder(root->left);
    cout<<root->data<<" ";
    re_inOrder(root->right);
}

struct node* predecessor(struct node* root)
{
    struct node * pre=root->left; 
    while (pre->right != NULL && pre->right != root) 
                pre = pre->right; 
    return pre;
}

void predecessorsOfAll(struct node *root,vector<struct node*> &v)
{
    if(root==NULL)
    return;
    predecessorsOfAll(root->left,v);
    v.push_back(root);
    predecessorsOfAll(root->right,v);
}

int main()
{
    Btree t;
    for(int i=1;i<=10;i++)
    t.insert(i);
    re_inOrder(t.root);
    cout<<"\n--------\n";
    vector<struct node*> v;
    predecessorsOfAll(t.root,v);
    cout<<"pred : node : success"<<endl;
    cout<<"0"<<" : "<<v[0]->data<<" : "<<v[1]->data<<endl;
    for(int i=1;i<v.size()-1;i++)
    {
        cout<<v[i-1]->data<<" : "<<v[i]->data<<" : "<<v[i+1]->data<<endl;
    }
    cout<<v[v.size()-2]->data<<" : "<<v[v.size()-1]->data<<" : "<<"0"<<endl;
    
}