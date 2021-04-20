#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;

void pairwise_swap(struct node* &head)
{
    struct node* dummy=new struct node(-1);  // very useful if use 
    dummy->next=head;       // dummy node 
    head=dummy;
    struct node* cur1=head->next;
    struct node* cur2=cur1->next;
    while(true)
    {
        cur1->next=cur2->next;
        cur2->next=dummy->next;
        dummy->next=cur2;
        dummy=cur1;
        cur1=cur1->next;
            if(cur1==NULL)
                break;
        cur2=cur1->next;
    }
    head=head->next;
}
void rec_pairwise_swap(struct node* &head,struct node* prev)
{                    // we are recieving refrnce of head
                    // because we are changing head
    if(head==NULL) 
        return;


    struct node* cur1=head;
    struct node* cur2=head->next;
    
    cur1->next=cur2->next;
    cur2->next=cur1;
    if(prev==NULL)
    {
        head=cur2;
    }
    else
    {
        prev->next=cur2;
    }
    prev=cur1;
    rec_pairwise_swap(cur1->next,prev);
}


int main()
{
    int arr[]={1,2,3,4,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    SL_list l1;
    l1.make_list(arr,size);
    l1.print();
    pairwise_swap(l1.head);
    l1.print();
    rec_pairwise_swap(l1.head,NULL);
    l1.print();
}