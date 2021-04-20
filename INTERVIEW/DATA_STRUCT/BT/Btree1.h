#include<bits/stdc++.h>

using namespace std;

struct node
{
    struct node *left;
    int data;
    struct node *right;
    node(int v)
    {
        left=NULL;
        data=v;
        right=NULL;
    }
};

class Btree
{
    public:
    struct node *root;
    int numOfNode;
    Btree()
    {
        root=NULL;
        numOfNode=0;
    }
    ~Btree()
    {
        delete root;
    }
    void insert(int);
    void print(struct node*);
};

void Btree::print(struct node* crawl)
{
    if(crawl==NULL)
    {
        return;
    }
    cout<<crawl->data<<" ";
    print(crawl->left);
    print(crawl->right);
}
void Btree::insert(int val)
{
    struct node *temp=new struct node(val);
    if(root==NULL)
    {
        root=temp;
        this->numOfNode++;
        return;
    }
    else
    {
        queue<struct node*> q;
        q.push(root);
        while(1)
        {
            struct node* crawl=q.front();   
            q.pop();
            if(crawl->left==NULL)
            {
                crawl->left=temp;
                this->numOfNode++;
                break;
            }
            else
            {
                q.push(crawl->left);
            }
            if(crawl->right==NULL)
            {
                crawl->right=temp;
                this->numOfNode++;
                break;
            }
            else
            {
                q.push(crawl->right);
            }
        }
    }
    return;
}