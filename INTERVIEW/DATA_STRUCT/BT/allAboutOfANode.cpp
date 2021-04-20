/////////////////////////////////////////////////////////////////////////////////
//                                        1                -----------0 
//                                      /   \              
//                                    2       3            -----------1
//                                  /   \    /  \                         HORIZONTAL LEVEL/LINES
//                                4     5   6    7         -----------2
//                              /  \   /
//                             8   9  10                   -----------3
                                
//                             | |   |    |   |  |
//                            -3 -2  -1   0   1  2
//                                VERTICAL LINES/LEVEL








#include<bits/stdc++.h>
#include"Btree1.h"

using namespace std;


void _HlevelOfNodeX(struct node *root,int level,int &final,int X)
{
    if(root==NULL)
    return;
    if(root->data==X)
    {
        final=level;
    }
    _HlevelOfNodeX(root->left,level+1,final,X);
    _HlevelOfNodeX(root->right,level+1,final,X);
}

int HlevelOfNodeX(struct node *root,int val)
{
    int level=-1;
    _HlevelOfNodeX(root,0,level,val);
    return level;
}


void _VlevelOfNodeX(struct node *root,int pos,int &final,int X)
{
    if(root==NULL)
    return;
    if(root->data==X)
    {
        final=pos;
    }
    _VlevelOfNodeX(root->left,pos-1,final,X);
    _VlevelOfNodeX(root->right,pos+1,final,X);
}

int VlevelOfNodeX(struct node *root,int val)
{
    int level=-1;
    _VlevelOfNodeX(root,0,level,val);
    return level;
}

/// nodes printed using this function will print as they appear in real tree horizontally(left to right)
void printnodesofsamehorizontalline(struct node *root,int lvl,int thislevel)
{
    if(root==NULL)
    return;
    if(lvl==thislevel)
    {
        cout<<root->data<<" ";
    }
    printnodesofsamehorizontalline(root->left,lvl+1,thislevel);
    printnodesofsamehorizontalline(root->right,lvl+1,thislevel);
}

// nodes printed using this function may not print in correct order as they appear in real tree
//vertically(top to bottom)
void printnodesofsameverticalline(struct node *root,int pos,int thispos)
{
    if(root==NULL)
    return;
    if(pos==thispos)
    {
        cout<<root->data<<" ";
    }
    printnodesofsameverticalline(root->left,pos-1,thispos);
    printnodesofsameverticalline(root->right,pos+1,thispos);
}
int main()
{
    Btree t;
    for(int i=1;i<=10;i++)
    {
        t.insert(i);
    }
    int lvl=HlevelOfNodeX(t.root,5);
    int vtl=VlevelOfNodeX(t.root,5);
    printnodesofsamehorizontalline(t.root,0,lvl);
    cout<<endl;
    printnodesofsameverticalline(t.root,0,vtl);
    cout<<endl;

}