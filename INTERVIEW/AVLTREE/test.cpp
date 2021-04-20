#include<bits/stdc++.h>

using namespace std;


struct node{
    string s;
    node* next;
    node(string x){
        s=x;
        next=NULL;
    }
};

node* rev(node* head){
    node* prev=NULL;
    node* cur=head;
    while(cur){
        node* next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}

int main(){
    int n;
    cin>>n;
    vector<string> vs;
    for(int i=0;i<n;i++){
        string t;
        cin>>t;
        vs.push_back(t);
    }
    sort(vs.begin(),vs.end(),[](string s,string t)->bool{
        return s.size()>t.size();
    });
    node* head=NULL;
    node* cur=NULL;
    for(auto x:vs){
        if(head==NULL){
            head=new node(x);
            cur=head;
        }else{
            cur->next=new node(x);
            cur=cur->next;
        }
    }
    cur=head;
    while(cur){
        cout<<cur->s<<" ";
        cur=cur->next;
    }
    cout<<endl;
    
    head=rev(head);
    cur=head;
    while(cur){
        cout<<cur->s<<" ";
        cur=cur->next;
    }
}