// https://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property/


/* C++ Program to convert an aribitary 
binary tree to a tree that hold 
children sum property */
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

bool helper(node* root,int val,vector<node* > &path)
{
    if(root==NULL)
    {
        return false;
    }
    path.push_back(root);
    if(root->data==val)
    {
        return true;
    }

   if(helper(root->left,val,path) || helper(root->right,val,path))
   return true;

    path.pop_back();
    return false;
    
}

void find_path_of(node* root,int val)
{
    if(root==NULL)
        return;
    
    vector<node* > path;
    helper(root,val,path);

    for(auto x:path)
        cout<<x->data<<" ";
    cout<<endl;
}

/* Driver code */
int main() 
{ 
	node *root = new node(50); 
	root->left = new node(7); 
	root->right = new node(2); 
	root->left->left = new node(3); 
	root->left->right = new node(5); 
	root->right->left = new node(1); 
	root->right->right = new node(30); 

    int x=5;
    find_path_of(root,30);
} 

// This code is contributed by rathbhupendra 
