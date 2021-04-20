// https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/


/* C++ program to construct a binary tree from 
the given string */
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to left 
child and a pointer to right child */
struct Node { 
	int data; 
	Node *left, *right; 
}; 
/* Helper function that allocates a new node */
Node* newNode(int data) 
{ 
	Node* node = (Node*)malloc(sizeof(Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

/* This funtcion is here just to test */
void preOrder(Node* node) 
{ 
	if (node == NULL) 
		return; 
	printf("%d ", node->data); 
	preOrder(node->left); 
	preOrder(node->right); 
} 

Node* treeFromString(string input,int start,int end)
{
    if(start>end)
        return NULL;
    
    Node* root=newNode(input[start]-'0');

    if(start==end)
        return root;

    int i=start+1;

    stack<char> st;
    st.push(input[i]);
    while(st.empty()==false)
    {
        i++;
        if((input[i]=='(') || (input[i] == ')'))
        {
            if(input[i]==')')
            {
                st.pop();
            }
            else
            {
                st.push(input[i]);
            }  
        }
    }

    root->left=treeFromString(input,start+2,i-1);
    root->right=treeFromString(input,i+2,end-1);
    
    return root;
}

// Driver Code 
int main() 
{ 
	string str = "4(2(1))(6(5))"; 
	Node* root = treeFromString(str, 0, str.length() - 1); 
	preOrder(root); 
} 
