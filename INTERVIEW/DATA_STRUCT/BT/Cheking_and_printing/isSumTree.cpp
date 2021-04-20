#include <stdio.h> 
#include <stdlib.h> 

/* A binary tree node has data, left child and right child */
struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 

//////////////////////////////////////////////////////////////////////////////////////////////////

//////Method 1 ///////////////////////

int cum(node* &root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return root->data;
    
    root->data+=(cum(root->left)+cum(root->right));
    
    return root->data;
}

bool isSumTree(node* root)
{
     if(root==NULL)
        return true;
    
    cum(root);  // cummulative sum  of all nodes   

    int c=0;
    int b=0;
    if(root->left)
        b=root->left->data;
    if(root->right)
        c=root->right->data;
    
    if(root->data!=2*(b+c))
        return false;
    return true;
    
}





/////////////////////////////////////////////////////////////////////////////////////////////////////


////Method 2////////////////////////////////////////////

// bool isSumTree(node* root)
// {
//      if(root==NULL)
//         return true;
    
//     if(root->left==NULL && root->right==NULL)
//         return true;
//     if(isSumTree(root->left) && isSumTree(root->right))
//     {
//         int b=0;
//         int c=0;

//         if(root->left)
//             b=root->left->data;
//         if(root->right)
//             c=root->right->data;
        
//         if(root->data!=(b+c))
//             return false;
            
//         root->data+=(b+c);
//         return true;
//     }
//     return false;
    
// }


/////////////////////////////////////////////////////////////////////////////////////////////////

//////////method 3 /////////////////////////////////////////


/* Utillity function to check if the given node is leaf or not */
// int isLeaf(struct node *node) 
// { 
// 	if(node == NULL) 
// 		return 0; 
// 	if(node->left == NULL && node->right == NULL) 
// 		return 1; 
// 	return 0; 
// } 

// int isSumTree(struct node* node) 
// { 
// 	int ls; // for sum of nodes in left subtree 
// 	int rs; // for sum of nodes in right subtree 

// 	/* If node is NULL or it's a leaf node then 
// 	return true */
// 	if(node == NULL || isLeaf(node)) 
// 		return 1; 

// 	if( isSumTree(node->left) && isSumTree(node->right)) 
// 	{ 
// 		// Get the sum of nodes in left subtree 
// 		if(node->left == NULL) 
// 			ls = 0; 
// 		else if(isLeaf(node->left)) 
// 			ls = node->left->data; 
// 		else
// 			ls = 2*(node->left->data); 

// 		// Get the sum of nodes in right subtree 
// 		if(node->right == NULL) 
// 			rs = 0; 
// 		else if(isLeaf(node->right)) 
// 			rs = node->right->data; 
// 		else
// 			rs = 2*(node->right->data); 

// 		/* If root's data is equal to sum of nodes in left 
// 		and right subtrees then return 1 else return 0*/
// 		return(node->data == ls + rs); 
// 	} 

// 	return 0; 
// } 
////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Helper function that allocates a new node 
with the given data and NULL left and right 
pointers. 
*/
struct node* newNode(int data) 
{ 
	struct node* node = 
		(struct node*)malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
} 

/* Driver program to test above function */
int main() 
{ 
	struct node *root = newNode(26); 
	root->left		 = newNode(10); 
	root->right	 = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(6); 
	root->right->right = newNode(3); 


	if(isSumTree(root)) 
		printf("The given tree is a SumTree "); 
	else
		printf("The given tree is not a SumTree "); 

	getchar(); 

	return 0; 
} 
