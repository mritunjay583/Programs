https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1
void solve(Node* root,Node* &node1,Node* &node2,Node* &prev){

    if(root==NULL){
        return;
    }
    solve(root->left,node1,node2,prev);

    if(prev==NULL||prev->data>=root->data)
    {
            if(node1==NULL)
                node1=prev;
            node2=root;
    }
    
    prev=root;
    solve(root->right,node1,node2,prev);
}

struct Node *correctBST( struct Node* root)
{
    Node* node1=NULL;
    Node* node2=NULL;
    Node* prev=NULL;
    solve(root,node1,node2,prev);
    swap(node1->data,node2->data);
    return root;

}