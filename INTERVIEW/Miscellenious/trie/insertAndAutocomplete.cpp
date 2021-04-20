#include<bits/stdc++.h>

using namespace std;

struct trie{
    bool end;
    struct trie* child[26];
    trie(){
        end=false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};
void insert(struct trie* root,string s){
    struct trie* cur=root;
    for(int i=0;i<s.size();i++){
        int idx=s[i]-'a';
        if(cur->child[idx]==NULL)
            cur->child[idx]=new struct trie();
        cur=cur->child[idx];
    }
    cur->end=true;
}
void print(struct trie* root,string &prefix,vector<string> &temp){
    if(temp.size()==3)
        return;
    if(root->end==true)
    {
        temp.push_back(prefix);
    }
    for(int i=0;i<26;i++){
        if(root->child[i]!=NULL){
            prefix+=(char)(i+'a');
            print(root->child[i],prefix,temp);
            prefix.pop_back();
        }
    }
}

void printTrie(struct trie* root,string x){
    if(root->end==true)
    {
        cout<<x<<" ";
    }
    for(int i=0;i<26;i++){
        if(root->child[i]!=NULL){
            x+=(char)(i+'a');
            printTrie(root->child[i],x);
            x.pop_back();
        }
    }
}

vector<vector<string>> suggestedProducts(struct trie *root,string searchWord) {
    vector<vector<string> > res;
    string prefix="";
    struct trie* cur=root;
    for(int i=0;i<searchWord.size();i++){
        vector<string> temp;
        prefix+=searchWord[i];
        int idx=searchWord[i]-'a';
        if(cur->child[idx]!=NULL){
            print(cur->child[idx],prefix,temp);
            cur=cur->child[idx];
        }else{
            while(res.size()!=searchWord.size())
                res.push_back(temp);
            break;
        }
        res.push_back(temp);
    }
    return res;
}

int main(){
    vector<string> dict{"mobile","mouse","moneypot","monitor","mousepad"};
    
    struct trie* root=new struct trie();
    for(int i=0;i<dict.size();i++){
        insert(root,dict[i]);
    }
    cout<<"content in trie : "<<endl;
    printTrie(root,"");
    cout<<"\n-------------------"<<endl;

    //auto completion
    string searchWord = "mouse";
    cout<<"Auto suggestion of : "<<searchWord<<endl;
    vector<vector<string> > res=suggestedProducts(root,searchWord);
    for(auto x:res){
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
}