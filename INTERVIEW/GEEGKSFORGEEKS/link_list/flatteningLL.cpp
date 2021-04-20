/* Let us create the following linked list 
       5 -> 10 -> 19 -> 28 
       |    |     |     | 
       V    V     V     V 
       7    20    22    35 
       |          |     | 
       V          V     V 
       8          50    40 
       |                | 
       V                V 
       30               45 
    */
// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
//this problem is very similar to merge k sorted linked list
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
/*  Function which returns the  root of 
    the flattened linked list. */
struct cmp{
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
};

Node *flatten(Node *root)
{
   Node* st=NULL;
   Node* en=NULL;
   priority_queue<Node*,vector<Node*>,cmp> pq;
   Node* cur=root;
   while(cur){      //first making starting node of each bottom linked list
       v.push_back(cur);
       pq.push(cur);
       cur=cur->next;
       
   }
   //same algorithm to megre k sorted linked list
   while(pq.empty()==false){
       Node* t=pq.top();
       pq.pop();
       if(t->bottom!=NULL)
        pq.push(t->bottom);
        if(st==NULL){
           st=t;
           en=st;
       }else{
           en->bottom=t;
           en=en->bottom;
       }
   }
   en->bottom=NULL;
   return st;
   
}

