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


void increment(node* &root,int d)
{
    if(root==NULL)
        return;
    
    root->data+=d;
    if(root->left!=NULL)
        increment(root->left,d);
    else
        increment(root->right,d);
}

void convertTree(node* root)
{
    if(root==NULL)
        return;


    convertTree(root->left);
    convertTree(root->right);
    if(root->left!=NULL || root->right!=NULL)
    {
        int a=0,b=0,c=0;
        a=root->data;
        if(root->left!=NULL)
            b=root->left->data;
        if(root->right!=NULL)
            c=root->right->data;
        
        if(a>(b+c))
        {
            int d=a-(b+c);
            if(root->left!=NULL)
                increment(root->left,d);
            else
                increment(root->right,d);
        }
        else if(a<(b+c))
        {
            int d=(b+c)-a;
            root->data+=d;
        }
        
    }
}
/* Given a binary tree, 
printInorder() prints out its 
inorder traversal*/
void printInorder(node* node) 
{ 
	if (node == NULL) 
		return; 
	
	/* first recur on left child */
	printInorder(node->left); 
	
	/* then print the data of node */
	cout<<node->data<<" "; 
	
	/* now recur on right child */
	printInorder(node->right); 
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
	
	cout << "\nInorder traversal before conversion: " << endl; 
	printInorder(root); 
	
	convertTree(root); 
	
	cout << "\nInorder traversal after conversion: " << endl; 
	printInorder(root); 
	return 0; 
} 

// This code is contributed by rathbhupendra 
