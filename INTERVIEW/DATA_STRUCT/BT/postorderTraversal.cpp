#include<bits/stdc++.h>
#include"Btree1.h"
using namespace std;

void re_postOrder(struct node* root)
{
    if(!root)return;
    re_postOrder(root->left); 
    re_postOrder(root->right);
    cout<<root->data<<" ";
}

void nr_postorder(struct node* root){
  if(root==NULL)
  return ;

  stack<node*> s;
  node *pre=NULL;

  while(root||s.empty()==false)
  {
      if(root)
      {
          s.push(root);
          root=root->left;
      }
      else
      {
          root=s.top();
          
          if(root->right==NULL||root->right==pre)
          {
              cout<<root->data<<" ";
              s.pop();
              pre=root;
              root=NULL;
          }
          else
          {
              root=root->right;
          }
      }
  }
  cout<<endl;
  return;
}


int main()
{
    Btree t;
    for(int i=1;i<=10;i++)
    t.insert(i);
    re_postOrder(t.root);
    cout<<endl;
    nr_postorder(t.root);
    cout<<"\n---------------\n";
}