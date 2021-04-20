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
    void deleteNode(struct node*,int);
    struct node *find(struct node*,int val);
    struct node* getLeaf(struct node*);
    struct node* parent(struct node*,struct node*);
    int getMax(struct node*);
    int height(struct node*);
    int diameter(struct node*);
};

int Btree::diameter(struct node* crawl)
{
    // static int dia=0;
    if(crawl==NULL)
    {
        return 0;
    }
    int left=diameter(crawl->left);
    int right=diameter(crawl->right);
    return max(height(crawl),left+right+1); 
}

int Btree::height(struct node* crawl)
{
    if(crawl==NULL)
    return 0;
    
    int left=height(crawl->left);
    int right=height(crawl->right);
    return 1+max(left,right);
}

int Btree::getMax(struct node* crawl)
{
    static int temp=INT_MIN;
    if(crawl==NULL)
    {
        return INT_MIN;
    }
    if(temp<crawl->data)
    temp=crawl->data;
    getMax(crawl->left);
    getMax(crawl->right);
    return temp;

}

struct node* Btree::parent(struct node *crawl,struct node* target)
{
    if(crawl==NULL)
    {
        return NULL;
    }
    if(crawl->left==target || crawl->right==target || crawl==target)
    {
        return crawl;
    }
    struct node* l=parent(crawl->left,target);
    if(l!=NULL)
    return l;
    parent(crawl->right,target);
}

struct node* Btree::getLeaf(struct node* crawl)
{
    if(crawl==NULL)
    {
        return NULL;
    }
    queue<struct node*> q;
    q.push(crawl);
    struct node* leafNode=NULL;
    while(!q.empty())
    {
        struct node* temp=q.front();
        leafNode=temp;
        q.pop();
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
    return leafNode;
}

struct node* Btree::find(struct node* crawl,int val)
{
    if(crawl==NULL)
    {
        return NULL;
    }
    if(crawl->data==val)
    {
        return crawl;
    }
    struct node* l=find(crawl->left,val);
    if(l!=NULL)
    return l;
    find(crawl->right,val);
}

void Btree::deleteNode(struct node* crawl,int target)
{
    if(crawl->left==NULL && crawl->right==NULL)
    {
        this->root=NULL;
        this->numOfNode--;
        return;
    }
    struct node* target_add=find(crawl,target);
    struct node* leaf=this->getLeaf(this->root);
    target_add->data=leaf->data;
    struct node* pt=this->parent(this->root,leaf);
    if(pt->right!=NULL)
    {
        delete pt->right;
        this->numOfNode--;
        pt->right=NULL;
    }
    else
    {
        delete pt->left;
        this->numOfNode--;
        pt->left=NULL;
    }
}

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