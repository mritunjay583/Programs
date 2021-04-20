// C++ program to construct ancestor matrix for 
// given tree. 
#include<bits/stdc++.h> 
using namespace std; 
#define MAX 100 

/* A binary tree node */
struct Node 
{ 
	int data; 
	Node *left, *right; 
	Node(int x)
	{
		data=x;
		left=NULL;
		right=NULL;
	}
}; 

void helper2(int pa,int chi,int **mat)
{
    if(mat[chi]==0)
        return;
    mat[pa][chi]=1;
    for(int i=0;i<6;i++)
    {
        if(mat[chi][i]==1)
        {
            helper2(pa,i,mat);
        }
    }
}
void helper(Node* parent,Node* child,int **mat)
{
    if(child==NULL)
        return;
    helper(child,child->left,mat);
    helper(child,child->right,mat);
    mat[parent->data][child->data]=1;
    helper2(parent->data,child->data,mat);
}

void ancestorMatrix(Node* root,int n,int **mat)
{
    mat[root->data][root->data]=0;
    helper(root,root->left,mat);
    helper(root,root->right,mat);
}
Node* newnode(int data) 
{ 
    Node* node = new Node(data); 
    return (node); 
} 
/* Driver program to test above functions*/
int main() 
{ 
	/* Construct the following binary tree 
				5 
			/ \ 
			1	 2 
		/ \ / 
		0 4 3 */
	Node *root	 = newnode(5); 
	root->left	 = newnode(1); 
	root->right	 = newnode(2); 
	root->left->left = newnode(0); 
	root->left->right = newnode(4); 
	root->right->left = newnode(3); 
	
	int **mat=new int*[6];
	for(int i=0;i<6;i++)
	{
	    mat[i]=new int[6];
	    for(int j=0;j<6;j++)
	    {
	        mat[i][j]=0;
	    }
	}


	ancestorMatrix(root,6,mat); 

    for(int i=0;i<6;i++)
	{
	    for(int j=0;j<6;j++)
	    {
	        cout<<mat[i][j]<<" ";
	    }
	    cout<<endl;
	}

	return 0; 
} 