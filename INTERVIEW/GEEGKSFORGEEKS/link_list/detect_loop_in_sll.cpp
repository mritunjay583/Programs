#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;

bool isLoop2(struct node* head)
{
    struct node* cur=head;
    struct node* dummy;
    while(cur!=NULL)
    {
        struct node *temp=cur->next;
        if(cur->next==dummy)
            return true;
        cur->next=dummy;
        cur=temp;
    }
    return false;
}

bool isLoop1(struct node* head)
{
    struct node *slow=head;
    struct node *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    SL_list l1;
    l1.make_list(arr,size);
    
    //loop
    l1.get_tail()->next=l1.head->next->next->next;
    
    bool res=isLoop2(l1.head);
    if(res)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}