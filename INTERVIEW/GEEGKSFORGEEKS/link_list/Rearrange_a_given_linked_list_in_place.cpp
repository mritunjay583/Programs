#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;



void reverse(struct node* head,struct node* prev)
{
    struct node* cur=head;
    struct node* nex=cur->next;
    struct node* pre=NULL;
    while(cur)
    {
        nex=cur->next;
        cur->next=pre;
        pre=cur;
        cur=nex;
    }
    prev->next=pre;
}
void rearrange_2(struct node* head)
{
    // getting mid of list
    if(head->next==NULL || head->next->next==NULL)
        return;
    struct node* slow=head;
    struct node* fast=head;
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    reverse(slow->next,slow);
    struct node* cur1=head;
    struct node* cur2=slow->next;
    struct node* start=NULL;
    struct node* end=NULL;
    while(cur2)
    {
        if(start==NULL)
        {
            start=cur1;
            end=start;
            cur1=cur1->next;
            end->next=cur2;
            end=end->next;
            cur2=cur2->next;
        }
        else
        {
            end->next=cur1;
            end=end->next;
            cur1=cur1->next;
            end->next=cur2;
            end=end->next;
            cur2=cur2->next;
        }
        
    }
    if(cur1->next==slow)
    {
        end->next=cur1;
        end=end->next;
    }
    end->next=slow;
    end=end->next;
    end->next=NULL;
    print(start);
}

void rearrange_1(struct node* head)
{
    vector<node* > v;
    node* cur=head;
    while(cur)
    {
        v.push_back(cur);
        cur=cur->next;
    }
    node* start=NULL;
    node* end=NULL;
    int i=0;
    int j=v.size()-1;
    while(i<=j)
    {
        if(start==NULL)
        {
            start=v[i++];
            end=start;
            if(i>j)
                break;
            end->next=v[j--];
            end=end->next;
        }
        else
        {
            end->next=v[i++];
            end=end->next;
            if(i>j)
                break;
            end->next=v[j--];
            end=end->next;
        }
    }
    end->next=NULL;
    print(start);
}

int main()
{
    int arr[]={1,2,3,4,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    SL_list l1;
    l1.make_list(arr,size);
    l1.print();
    // rearrange_1(l1.head);
    // rearrange_2(l1.head);
}