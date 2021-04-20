#include <bits/stdc++.h>

using namespace std;

void helper(Node *root, Node *&pre, Node *&suc, int key)
{
    if (root == NULL)
        return;
    helper(root->left, pre, suc, key);
    if (root->data > key && !suc)
        suc = root;
    if (root->data < key)
        pre = root;
    helper(root->right, pre, suc, key);
}

Node *inOrderSuccessor(Node *root, Node *x)
{
    Node *pre = NULL;
    Node *suc = NULL;
    helper(root, pre, suc, x->data);
    return suc;
}

int main()
{
}
