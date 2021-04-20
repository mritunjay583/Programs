#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;

struct node* deleteDuplicates(struct node* head)
    {
        if(head==NULL)
            return head;
        
        struct node* prev=NULL;
        struct node* cur=head;
        
        while(cur)
        {
            if(cur->next && cur->next->data==cur->data)
            {
                while(cur->next && cur->next->data==cur->data)
                {
                    cur=cur->next;
                }
                
                if(prev)
                {
                    prev->next=cur->next;
                }
                else
                {
                    head=cur->next;
                } 
            }
            else
            {
                prev=cur;
              
            }
             cur=cur->next;
        }      
        return head;    
}

void remove_duplicates(struct node* head)
{
    struct node* cur=head;
    while(cur!=NULL)
    {
        struct node* cur2=cur->next;
        while(cur2!=NULL && cur2->data==cur->data)
        {
            cur2=cur2->next;
        }
        if(cur2==NULL)
            cur->next=NULL;
        else
            cur->next=cur2;
        cur=cur->next;   
    }
}

void rec_remove_duplicates(struct node* head)
{
    if(head==NULL)
        return;
    struct node* cur=head;
    while(cur!=NULL && cur->data==head->data)
        cur=cur->next;

    head->next=cur;
    rec_remove_duplicates(cur);
}


int main()
{
    int arr[]={2,2,2,2,2,2,3,3,3,3,3,4,4,4,4,5,6,6,6,6,7,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    SL_list l1;
    l1.make_list(arr,size);
    l1.print();
    // remove_duplicates(l1.head);

    // l1.print();
    struct node* cur=deleteDuplicates(l1.head);
    
    // rec_remove_duplicates(l1.head);
    while(cur){
        cout<<cur->data<<" ";
        cur=cur->next;
    }
}