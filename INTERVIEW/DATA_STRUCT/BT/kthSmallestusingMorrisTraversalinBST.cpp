int KthSmallestElement(Node *root, int K)
{
    Node* cur=root;
    while(cur){
        if(cur->left){
            Node* right=cur->left;
            Node* l=cur->left;
            while(right->right){
                right=right->right;
            }
            right->right=cur;
            cur->left=NULL;
            cur=l;
        }else{
            K--;
            if(K==0){
                return cur->data;
            }
            cur=cur->right;
        }
    }
    return -1;
}

int kthLargest(Node *root, int K)
{
    Node* cur=root;
    while(cur){
        if(cur->right){
            Node* left=cur->right;
            Node* r=cur->right;
            while(left->left){
                left=left->left;
            }
            left->left=cur;
            cur->right=NULL;
            cur=r;
        }else{
            K--;
            if(K==0){
                return cur->data;
            }
            cur=cur->left;
        }
    }
}