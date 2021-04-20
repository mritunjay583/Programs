#include<bits/stdc++.h>
using namespace std;

struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
// A utility function to create a new Binary Tree node with given data 
struct Node* newNode(int data) 
{ 
    struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 
// struct Node *root=NULL;

struct Node* getRoot()
{
    struct Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->left->left->left = newNode(8); 
    root->left->left->right = newNode(9); 
    root->left->right->left = newNode(12); 
    root->right->right->left = newNode(10); 
    root->right->right->left->right = newNode(11); 
    root->left->left->right->left = newNode(13); 
    root->left->left->right->right = newNode(14); 
    root->left->left->right->right->left = newNode(15); 
    return root;
}
void inorder(Node* root,map<Node*,pair<int,int> > &ma,int cur_level,int cur_width,int &left_boundry,int &right_boundry,int &bottom_boundry)
{
    
    if(root==NULL)
    {
        left_boundry=max(cur_width,left_boundry);
        right_boundry=min(right_boundry,cur_width);
        bottom_boundry=max(cur_level,bottom_boundry); 
        return;
    }
    inorder(root->left,ma,cur_level+1,cur_width-1,left_boundry,right_boundry,bottom_boundry);
    ma[root]=make_pair(cur_level,cur_width);
    inorder(root->right,ma,cur_level+1,cur_width+1,left_boundry,right_boundry,bottom_boundry);
}

void print(Node* root)
{
    // if(root==NULL)
    //     return;
    // print(root->left);
    // cout<<root->data<<" ";
    // print(root->right);
    map<Node*,pair<int,int> > ma;
    int right_boundry=INT_MAX;
    int left_boundry=INT_MIN;
    int bottom_boundry=INT_MIN;
    inorder(root,ma,0,0,left_boundry,right_boundry,bottom_boundry);

    int row=bottom_boundry;
    int col=abs(left_boundry)+abs(right_boundry)+1;
    int **mat=new int*[row];
    
    for(int i=0;i<row;i++)
    {
        mat[i]=new int[col];
        for(int j=0;j<col;j++)
        {
            mat[i][j]=-1;
        }
    }
    
    for(auto x:ma)
    {
        mat[x.second.first][x.second.second+abs(left_boundry)]=x.first->data;
    }

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(mat[i][j]==-1)
                cout<<"  ";
            else
                cout<<mat[i][j]<<"  ";
        }
        cout<<endl<<endl;
    }
}
int main(){

    struct Node* root=getRoot();
    print(root);
}