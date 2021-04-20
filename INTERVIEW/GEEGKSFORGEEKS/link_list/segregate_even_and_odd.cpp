#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;

void segregate2(struct node* &head)
{
    struct node* cur=head;
    struct node* even_start=NULL;
    struct node* even_end=NULL;
    struct node* odd_start=NULL;
    struct node* odd_end=NULL;
    
    while(cur!=NULL)
    {
        int val=cur->data;
        if(val%2==0)
        {
            if(even_start==NULL)
            {
                even_start=cur;
                even_end=even_start;
            }
            else
            {
                even_end->next=cur;
                even_end=even_end->next;
            }
            
        }
        else
        {
            if(odd_start==NULL)
            {
                odd_start=cur;
                odd_end=odd_start;
            }
            else
            {
                odd_end->next=cur;
                odd_end=odd_end->next;
            }
            
        }
        cur=cur->next;
    }
    head=even_start;
    even_end->next=odd_start;
    odd_end->next=NULL;
    print(head);
}

void segregate1(struct node* &head)
{
    struct node* cur=head;
    struct node* prev=cur;
    struct node* tail=head;
    while(tail->next!=NULL){tail=tail->next;}
    struct node* end=tail;
    while(cur!=end)
    {
        if(cur->data%2!=0)
        {
            if(cur==head)
            {
                tail->next=head;
                head=head->next;
                tail=tail->next;
                tail->next=NULL;
                cur=head;
            }
            else
            {
                tail->next=cur;
                prev->next=cur->next;
                tail=tail->next;
                tail->next=NULL;
                cur=prev->next;
            }    
        }
        else
        {
            prev=cur;
            cur=cur->next;
        }  
    }
    if(cur->data%2!=0)
    {
        tail->next=cur;
        prev->next=cur->next;
        tail=tail->next;
        tail->next=NULL;
        cur=prev->next;
    }
    print(head);
}


int main()
{
    int arr[]={1,3,5,7,2,4,6,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    SL_list l1;
    l1.make_list(arr,size);
    l1.print();
    // segregate1(l1.head);
    segregate2(l1.head);
}