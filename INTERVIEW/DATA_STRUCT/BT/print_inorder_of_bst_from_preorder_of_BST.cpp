#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;
// Data structure to store a Binary Tree node
struct Node
{
	int key;
	struct Node *left, *right;
};

// Function to create a new binary tree node having given key
struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->key = key;
	node->left = node->right = NULL;

	return node;
}

// Recursive function to perform inorder traversal of a binary tree
void inorder(struct Node* root)
{
	if (root == NULL)
		return;

	inorder(root->left);
	printf("%d ", root->key);
	inorder(root->right);
}

// Recursive function to build a BST from a preorder sequence
void constructBST(int preorder[], int &start, int min,int max,int n)
{
   if(start==n)
   return ;
   
   int val=preorder[start];
   
   if(val<min||val>max)
   return ;
   
  
   start++;
   constructBST(preorder,start,min,val-1,n);
   constructBST(preorder,start,val+1,max,n);
   cout<<val<<" ";

}

int main(void)
{
	/* Construct below BST
			  15
			/	\
		   /	  \
		  10	   20
		 /  \	 /  \
		/	\   /	\
	   8	 12 16	25
	*/

	int preorder[] = {40, 30, 35, 80, 100 };
	int n = sizeof(preorder)/sizeof(preorder[0]);

	// construct the BST
	int start=0;
	
constructBST(preorder, start, INT_MIN,INT_MAX,n);

	// print the BST
	printf("Inorder Traversal of BST is : ");

	// inorder on the BST always returns a sorted sequence


	return 0;
}