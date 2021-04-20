#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int x){
        data=x;
        height=1;
        left=NULL;
        right=NULL;
    }
};

//function to calculate height of binary tree
int height(Node* cur){
    if(cur==NULL)
        return 0;
    return 1+max(height(cur->left),height(cur->right));
}

//function to calculate balance factor of Node
//simply bf= H(left) - H(right)
int balanceFactor(Node* cur){
    if(cur==NULL)
        return 0;
    return height(cur->left)-height(cur->right);
}


//ROTATIONS  
//right rotation

            //         c
            //       /  \
            //      b   T4 
            //     / \
            //    a   T3
            //   / \
            // T1  T2   
//here c is imbalance Node so make rotation from there
                //         b
                //      /    \
                //     a      c
                //    / \     / \
                //   T1  T2  T3 T4
Node* rightRotate(Node* c){
    Node* b=c->left;
    Node* T3=b->right;

    b->right=c;
    c->left=T3;

    //update height
    c->height=max(height(c->left),height(c->right))+1;
    b->height=max(height(b->left),height(b->right))+1;
}

//left rotation
                //     c
                //    / \
                //   T1  b
                //      / \
                //     T2  a
                //        / \
                //       T3  T4
//here c is imbalance Node so make rotation from there
                //         b
                //      /    \
                //     c      a
                //    / \     / \
                //   T1  T2  T3 T4
Node* leftRotate(Node* c){
    Node* b=c->right;
    Node* T2=b->left;

    b->left=c;
    c->right=T2;

    //update height
    c->height=max(height(c->left),height(c->right))+1;
    b->height=max(height(b->left),height(b->right))+1;
}


Node* insert(Node* root,int x){

    //do as we do in BST insertion
    ///////////////////////////////////////
    if(root==NULL){
        return new Node(x);
    }
    if(x>root->data)
        root->right=insert(root->right,x);
    else
        root->left=insert(root->left,x);
    ////////////////////////////////////////

    //here main concept of AVL INSERTION starts........

    //update height of Node
    root->height=max(height(root->left),height(root->right))+1;
    
    //calculate balance factor of Node
    int bf=balanceFactor(root);

    //L L imbalance -- > do right rotation
    if(bf>1 && x<root->left->data){
        return rightRotate(root);
    }

    //R R imbalance -- > do left rotation
    if(bf<-1 && x>root->right->data){
        return leftRotate(root);
    }

    //L R imbalance -- > do left right rotation
    if(bf>1 && x>root->left->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }

    //R L imbalance -- > do right left rotation
    if(bf<-1 && x<root->right->data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    //if Node is not imbalance just return
    return root;
}   

//simple inorder traversal
void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    int bf=balanceFactor(root);
    cout<<root->data<<" : "<<bf<<endl;
    inorder(root->right);
}
int main(){
    struct Node* root=NULL;
    root=insert(root,5);
    root=insert(root,10);
    root=insert(root,7);
    root=insert(root,6);
    root=insert(root,11);
    root=insert(root,1);
    inorder(root);cout<<endl;
    cout<<root->height<<endl;
    cout<<root->data<<endl;
}