#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;

// this is simple function to merge to linked list
struct node* merge(struct node* left,struct node* right)
{
    struct node* start=NULL;
    struct node* end=NULL;
    while(left!=NULL && right!=NULL)    
    {
        if(left->data<right->data)
        {
            if(start==NULL)
            {
                start=left;
                end=start;
                left=left->next;
            }
            else
            {
                end->next=left;
                end=end->next;
                left=left->next;
            }  
        }
        else
        {
            if(start==NULL)
            {
                start=right;
                end=start;
                right=right->next;
            }
            else
            {
                end->next=right;
                end=end->next;
                right=right->next;
            } 
        }
    }
    if(left==NULL)
        end->next=right;
    else
        end->next=left;
    
    return start;
}

struct node* merge_sort(struct node* head)
{
    if(head==NULL || head->next==NULL)
        return head;
    
    struct node* temp=head;
    struct node* slow=head;
    struct node* fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    temp->next=NULL;  // very important you may miss this

    struct node* left=merge_sort(head);
    struct node* right=merge_sort(slow);

    return merge(left,right);
}

int main()
{
    int arr[]={4,2,1,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    SL_list l1;
    l1.make_list(arr,size);
    l1.print();
    struct node *res=merge_sort(l1.head);
    print(res);
}
