
// Min distance between two given nodes of a Binary Tree
// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1/


#include<bits/stdc++.h> 
using namespace std; 

class node 
{ 
	public: 
	int data; 
	node* left; 
	node* right; 
	
	/* Constructor that allocates a new node 
	with the given data and NULL left and right 
	pointers. */
	node(int data) 
	{ 
		this->data = data; 
		this->left = NULL; 
		this->right = NULL; 
	} 
}; 


////////////////////////////////////////////////////



node* LCA(node* root,int a,int b)
{
    if(root==NULL)
        return NULL;
    if(root->data==a || root->data==b)
        return root;
    node* left=LCA(root->left,a,b);
    node* right=LCA(root->right,a,b);
    
    if(left && right) return root;
    
    return left!=NULL ? left : right;
}

void distance(node* root,int x,int cur_len,int &len)
{
    if(root==NULL)
        return;
        
    if(root->data==x)
    {
        len=cur_len;
        return;
    }

    distance(root->left,x,cur_len+1,len);
    distance(root->right,x,cur_len+1,len);
}

int findDist(node* root, int a, int b) {
    node* Lc=LCA(root,a,b); // calculating lca of a and b
    
    int d1=0;
    int d2=0;
    distance(Lc,a,0,d1);
    distance(Lc,b,0,d2);
    
    return d1+d2;
}

int main() 
{ 
	node *root = new node(50); 
	root->left = new node(7); 
	root->right = new node(2); 
	root->left->left = new node(3); 
	root->left->right = new node(5); 
	root->right->left = new node(1); 
	root->right->right = new node(30); 

    int val1=50,val2=7;   // note val1 and val2 must be present otherwise use other technique to find lca
    cout<<"Minimum distance between "<< val1 <<" and "<< val2 <<" in Tree : ";
    cout<<findDist(root,val1,val2);

} 
