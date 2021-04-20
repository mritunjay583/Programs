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
void inorder(struct node* root)
{
    stack<struct node* > st;
    struct node * crawl=root;
    st.push(crawl);
    crawl=crawl->left;
    while(1)
    {
        while(crawl!=NULL)
        {
            st.push(crawl);
            crawl=crawl->left;
        }
        if(st.empty()==true)
        break;
        struct node* temp=st.top();
        st.pop();
        cout<<temp->data<<" ";
        crawl=temp->right;
    }
}


int main()
{
    Btree t;
    for(int i=1;i<=10;i++)
    t.insert(i);
    re_inOrder(t.root);
    cout<<"\n---------------\n";
    inorder(t.root);
}