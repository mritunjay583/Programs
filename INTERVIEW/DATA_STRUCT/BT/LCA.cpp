
// Lowest Common Ancestor in a Binary Tree
// https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/


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

void LCA1(node* root,int val1,int val2)
{
    if(root==NULL)
        return;
    
    vector<node* > path1;
    vector<node* > path2;
    bool b1=helper(root,val1,path1);
    bool b2=helper(root,val2,path2);

    if(b1==false || b2==false)
    {
        cout<<"LCA DOES NOT EXISTS"<<endl;
        return;
    }
    int i=0;
    int j=i;
    while(i<path1.size() && i<path2.size())
    {
        if(path1[i]!=path2[i])
            break;
        
        j=i;
        i++;
    }

    cout<<"LCA("<<val1<<" , "<<val2<<") = "<<path1[j]->data<<endl;
}

////////////////////////////////////////////////////////
node* LCA2(node* root,int n1,int n2)
{
    if(root==NULL)
        return NULL;
    
    if(root->data==n1 || root->data==n2)
        return root;
    
    node* left=LCA2(root->left,n1,n2);
    node* right=LCA2(root->right,n1,n2);

    if(left&&right) return root;

    return left!=NULL ? left : right;

}
////////////////////////////////////////////////////

node* LCA3_util(node* root,int val1,int val2,bool &isVal1_inTree,bool &isVal2_inTree)
{
    if(root==NULL)
        return NULL;
    
    if(root->data==val1)
    {
        isVal1_inTree=true;
        return root;
    }
    if(root->data==val2)
    {
        isVal2_inTree=true;
        return root;
    }

    node* left=LCA3_util(root->left,val1,val2,isVal1_inTree,isVal2_inTree);
    node* right=LCA3_util(root->right,val1,val2,isVal1_inTree,isVal2_inTree);

    if(left&&right) return root;

    return left!=NULL ? left : right;
}
bool find(node* root,int val)
{
    if(root==NULL)
        return false;
    
    if(root->data==val || find(root->left,val) || find(root->right,val))
        return true;
    
    return false;
}

void LCA3(node* root,int val1,int val2)
{
    bool isVal1_inTree=false;
    bool isVal2_inTree=false;

    node* LCA=LCA3_util(root,val1,val2,isVal1_inTree,isVal2_inTree);

    if( isVal1_inTree && isVal2_inTree || isVal1_inTree && find(LCA,val2) || isVal2_inTree && find(LCA,val1))
    {
        cout<<"LCA("<<val1<<" , "<<val2<<") = "<<LCA->data<<endl;
        return;
    }
    else
    {
        cout<<"LCA DOES NOT EXISTS"<<endl;
        return;
    }
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

    int val1=30,val2=8;
    LCA1(root,val1,val2);

    cout<<"LCA("<<val1<<" , "<<val2<<") = "<<LCA2(root,val1,val2)->data<<endl; // make sure val1 and val2 present in tree

    LCA3(root,val1,val2);
} 
