#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;

struct node *reverse_in_groups_of_K_2(struct node *head, int k)
{ 
    node *prevFirst=NULL;
    bool flag=true;
    node *cur=head;
    while(cur)
    {
        node *tail=cur;
        node *rev=NULL;
        
        for(int cnt=k;(cnt!=0)&&cur!=NULL;cnt--)
        {
            node *next=cur->next;
            cur->next=rev;
            rev=cur;
            cur=next;
        }
        
        if(flag)
        {
            head=rev;
            flag=false;
        }
        else {
             prevFirst->next=rev;
        }
        prevFirst=tail;
        
    }
    return head;
}


void reverse(struct node* head,struct node* end)
{
    struct node* cur=head;
    struct node* prev=NULL;
    struct node* next=NULL;
    while(cur!=end)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
}

struct node *reverse_in_groups_of_K_1(struct node *head, int k)
{ 
    struct node* prev1=NULL;
    struct node* cur1=head;
    struct node* cur2=head;
    struct node* prev2=NULL;
    while(cur1!=NULL)
    {
        int i=0;
        
        while(i<k && cur2!=NULL)
        {
            prev2=cur2;
            cur2=cur2->next;
            i++;
        }
        reverse(cur1,cur2);
        if(prev1==NULL)
        {
            head=prev2;
            cur1->next=cur2;
            prev1=cur1;
            cur1=cur2;
        }
        else
        {
            prev1->next=prev2;
            cur1->next=cur2;
            prev1=cur1;
            cur1=cur2;
        }
    }
    print(head);
    return head;
}


int main()
{
    int arr[]={1,2,2,4,5,6,7,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    SL_list l1;
    l1.make_list(arr,size);
    reverse_in_groups_of_K_1(l1.head,k);
    
}