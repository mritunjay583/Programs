#include<bits/stdc++.h>

using namespace std;
struct trie
{
    struct trie *next[26]; 
    trie()
    {
        for(int i=0;i<26;i++)
        {
            next[i]=NULL;
        }
    }
};

void insert(struct trie *root,string s)
{
    if(root==NULL)
    {
        root=new struct trie;
    }
    int len=s.size();
    int i=0;
    while(i<len)
    {
        if(root->next[s[i]-'a']==NULL)
        {
            root->next[s[i]-'a']=new struct trie;
            root=root->next[s[i]-'a'];
        }
        else
        {
            root=root->next[s[i]-'a'];
        }
        i++;
    }
}

bool find(struct trie *root,string s)
{
    if(root==NULL)
    return false;
    int len=s.size();
    int i=0;
    int flag=0;
    while(i<len)
    {
        if(root->next[s[i]-'a']!=NULL)
        {
            root=root->next[s[i]-'a'];
        }
        else
        {
            flag=1;
            break;
        }
        i++;
    }
    if(flag==1)
    return false;
    else
    return true;
    
}

int main()
{
    struct trie *root=new struct trie;
    
    vector<string> v{"the","a","there","answer","any","by","bye","their"};
    for(int i=0;i<v.size();i++)
    {
        insert(root,v[i]);
    }
    for(int i=0;i<v.size();i++)
    {
        if(find(root,v[i]))
        {
            cout<<v[i]<<" : "<<"Yes"<<endl;
        }
        else
        cout<<v[i]<<" : "<<"No"<<endl;
    }
}