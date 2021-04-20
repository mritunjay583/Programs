#include<bits/stdc++.h>
#include"singlyList.h"

using namespace std;

void reverse(struct node* &head)
{
    struct node* prev=NULL;
    struct node* cur=head;
    struct node* nex=head;
    while(cur!=NULL)
    {
        nex=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nex;
    }
    head=prev;
}

int main()
{
    int arr[]={1,2,3,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    SL_list l1;
    l1.make_list(arr,size);
    l1.print();
    reverse(l1.head);
    l1.print();
}