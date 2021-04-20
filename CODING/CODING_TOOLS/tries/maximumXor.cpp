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

void make_trie(int arr[],int size,struct trienode* root)
{
    struct trienode* cur=root;
    for(int i=0;i<size;i++)
    {
        cur=root;    ///## after each insertion make cur = root
        
        for(int j=31;j>=0;j--)
        {
            int x=(arr[i]>>j)&1;
            if(x==1)
            {
                if(cur->right==NULL)
                    cur->right=new struct trienode();
                cur=cur->right;                
            }
            else
            {
                if(cur->left==NULL)
                    cur->left=new struct trienode();
                cur=cur->left;
            }   
        }
    }
}
int query(int arr[],int size,struct trienode* root)
{
    int max_xor=INT_MIN;
    for(int i=0;i<size;i++)
    {
        int b=arr[i];
        int cur_xor=0;
        struct trienode* cur=root;
        for(int j=31;j>=0;j--)
        {
           int val=(b>>j)&1;
           if(val==0)
           {
               if(cur->right!=NULL)
               {
                    cur_xor+=pow(2,j);
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
                    cur_xor+=pow(2,j);
                    cur=cur->left;
               }
               else
               {
                   cur=cur->right;
               }
           }  
        }
        if(max_xor<cur_xor)
        max_xor=cur_xor;
    }
    return max_xor;
}

int main()
{
    int arr[]={8,1,2,15,10,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    struct trienode *root =new struct trienode();
    make_trie(arr,size,root);
    int res=query(arr,size,root); 
    cout<<res;
}