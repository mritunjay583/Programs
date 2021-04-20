#include<bits/stdc++.h>

using namespace std;
struct trienode
{
    struct trienode* left;
    struct trienode* right;
    trienode()
    {
        left=NULL;
        right=NULL;
    }
};

void insert(struct trienode* root,int x)
{
    struct trienode* cur=root;
    for(int i=31;i>=0;i--)
    {
        int val=(x>>i)&1;
        if(val==0)
        {
            if(cur->left==NULL)
                cur->left=new struct trienode();
            cur=cur->left;
        }
        else
        {
            if(cur->right==NULL)
                cur->right=new struct trienode();
            cur=cur->right;
        }
        
    }

}
int query(struct trienode* root,int x)
{
    struct trienode* cur=root;
    int cur_xor=0;
    for(int i=31;i>=0;i--)
    {
        int val=(x>>i)&1;
        if(val==0)
        {
            if(cur->right!=NULL)
            {
                cur_xor+=pow(2,i);
                cur=cur->right;
            }
            else
            {
                cur=cur->left;
            }
            
        }
        else
        {
            if(cur->left!=NULL)
            {
                cur_xor+=pow(2,i);
                cur=cur->left;
            }
            else
            {
                cur=cur->right;
            }
            
        }
        
    }
    return cur_xor;
}


int main()
{
    int arr[]={1,2,4,12,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    struct trienode* root=new struct trienode();
    insert(root,0);
    
    int res=0;
    int cur_xor=0;
    int max_xor=INT_MIN;
    for(int i=0;i<size;i++)
    {
        cur_xor=cur_xor^arr[i];

        insert(root,cur_xor);

        int res=query(root,cur_xor);

        if(max_xor<res)
            max_xor=res;
    }
    cout<<max_xor<<endl;    
}
