#include<bits/stdc++.h>
#include"Btree1.h"
using namespace std;

void re_preOrder(struct node* root)
{
    if(!root)return;
    cout<<root->data<<" ";
    re_preOrder(root->left);
    re_preOrder(root->right);
}

void preOrder(struct node *root)
{
    stack<struct node*> st;
    st.push(root);
    
    while(1)
    {
        struct node *temp=st.top();
        st.pop();
        cout<<temp->data<<" ";
        if(temp->right)
        st.push(temp->right);
        if(temp->left)
        st.push(temp->left);
        if(st.empty()==true)
        break;
    }

}

int main()
{
    Btree t;
    for(int i=1;i<=10;i++)
    t.insert(i);
    re_preOrder(t.root);
    cout<<" ----------- "<<endl;
    preOrder(t.root);
}