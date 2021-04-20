// https://leetcode.com/problems/lru-cache/submissions/

#include<bits/stdc++.h>

using namespace std;

struct node{   //node of dubly linked list
    int value;
    int key;
    struct node* next;
    struct node* prev;
    node(int key,int value){
        this->key=key;
        this->value=value;
        next=NULL;
        prev=NULL;
    }
};

class LRUCache {
private:

    int size;  //size of LRU cache
    struct node *head,*tail;  //head and tail pointer of dll
    unordered_map<int,struct node* > ma;  //hash map to store node of dll which corresponds to key means : -  ma[key]=node address of dll which has key as data filed

public:

    LRUCache(int capacity) {  // initialization of LRU cache
        size=capacity;
        head=NULL;
        tail=NULL;
    }
    
    void bringNodeToFront(struct node* &cur){
        //if node is already head node means it is begining of dll so no need to do simply return
        if(cur==head)
            return;
        if(cur==tail)
        {  //if node is tail node so bring that node to front of dll
            tail=tail->prev;
            tail->next=NULL;
            cur->prev=NULL;
            head->prev=cur;
            cur->next=head;
            head=head->prev;
        }
        else
        {  //if node is not tail node is different method will be used to bring node to front of dll
            cur->prev->next=cur->next;
            cur->next->prev=cur->prev;
            cur->next=head;
            cur->prev=NULL;
            head->prev=cur;
            head=head->prev;
        }
    }

    int get(int key) {
        //key is not present in map it means it is not present in cache so return -1
        if(ma.count(key)==0){
            return -1;
        }
        //if key is present in map then it is also present in dll so
        //move node to begining of list
        struct node* cur=ma[key];
        bringNodeToFront(cur);
        return cur->value;  //finally return value
    }
    
    void put(int key, int value) {
        // key is already present in DLL(cache)
        if(ma.count(key)>0){
            struct node* cur=ma[key];
            cur->value=value;  //update value present in cache
            bringNodeToFront(cur);
            return;
        }
        //if key is not present in cache
        //so we need to insert in cache
        //first step to check is cache is full or not
        
        //if it is full then remove tail node and update tail node of DLL
        if(ma.size()==size){ 
            int x;
            if(head==tail){ //if head and tail are same
                x=head->key;
                head=NULL;
                tail=NULL;
            }else{  //if head and tail are not same
                x=tail->key;
                tail=tail->prev;
                tail->next->prev=NULL;
                tail->next=NULL;
            }
            ma.erase(x);  // also erase entry of deleted node from map 
        } // removal done till now

        //inserttion in DLL;
        if(head==NULL){
            head=new struct node(node(key,value));
            tail=head;
        }else{
            struct node* cur=new struct node(node(key,value));
            cur->next=head;
            head->prev=cur;
            head=head->prev;
        }
        ma[key]=head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */