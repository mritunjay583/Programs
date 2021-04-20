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

int i=0;
bool Ancestors_of_x(node* root,int val)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==val)
    {
        return true;
    }

   if(Ancestors_of_x(root->left,val) || Ancestors_of_x(root->right,val))
   {
       cout<<(++i)<<" : "<<root->data<<endl;
       return true;
   }
    return false;
    
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

    int x=1;
    Ancestors_of_x(root,x);
} 

// This code is contributed by rathbhupendra 
